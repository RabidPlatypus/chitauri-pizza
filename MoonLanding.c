#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

#ifdef _WIN32
#include <process.h> 
#define keypress() system("pause")
#else
#define keypress() //printf("Press [Enter] to continue . . .\n"); getchar()
#endif

struct _lander
{
	double v; //velocity
	double a; //altitude
	double m; //mass
	double fuel;
};
typedef struct _lander Lander;

const double g = -1.6;

//Update lander variables
void statUpdate(Lander* x, int thrust)
{
	int t = thrust*1000;
	double acceleration = (t / x->m + g);

	x->m -= t / 3000;
	x->fuel -= t / 3000;
	x->v += acceleration;
	x->a += x->v;

}

//Autopilot thrust function
double autoThrust(Lander x)
{
	double vf = -0.9;
	double hf = 3.0;

	if (x.a > hf)
	{
		double ad = ((x.v * x.v) - (vf * vf)) / (2 * (x.a - hf));
		double T = x.m * (ad - g);
		if (T > 45000)
			return 45000;		
		else
			return T;
	}

	else if (x.a < hf)
	{
		double T = (-x.m) * g * (x.v / vf);
		if (T > 45000)
			return 45000;
		else
			return T;
	}

}
int thrustAllowed(Lander x)
{
	if (x.fuel < 15)
		return (3000 * x.fuel)/1000;
	else
		return 45;
}

int main()
{
	//Initialize variables and open file for writing
	Lander apollo = { -325.0, 15000,9000.0,1800.0 };
	int i = 0, t = 0;

	FILE* output = fopen("output.csv", "wt");
	if (!output)
		printf("Unable to open file");

	//Ask for user input to determine mode
	char c;
	printf("Autopilot mode (y/n)? ");
	scanf("%c", &c);

	//Print a message for chosen game mode and initial game values
	if (c == 'n' || c == 'N')
	{
		printf("\nYou chose game mode!\n\n");
		printf("Rules:\nGet the lander to the ground with a velocity between -1m/s and 0m/s.\n");
		printf("You must enter a thrust amount less than or equal to 45kN.\n");
		printf("Thrust amount cannot exceed the amountallowed by the remaining fuel.\n");
		printf("Good luck!\n\n");
	}
	else
		printf("\nYou chose autopilot mode!\n\n");

	printf("Initial values: Altitude:15000m   Velocity:-325m/s  Total Mass:9000kg   Fuel:1800kg\n\n");

	//Int t differs between game modes. Other than that they are the same
	while (apollo.a >= 0)
	{
		if (c == 'n' || c == 'N')
		{
			printf("Thrust? (kN) ");
			scanf("%i", &t);

			//Make sure the chose thrust is within the allowed parameters
			if (t > 45)
				printf("Thrust exceeds limit.\nMax thrust allowed=45kN\n");
			else if (t > thrustAllowed(apollo))
				printf("Thrust exceeds limit.\nMax thrust allowed =%ikN\n", thrustAllowed(apollo));
		}
		else
			t = autoThrust(apollo) / 1000;

		//If thrust is within parameters, run update function and print to the screen and file
		if (t <= thrustAllowed(apollo))
		{
			statUpdate(&apollo, t);

			printf("Thrust: %-10i Altitude: %-10.1lf Velocity: %-10.1lf Mass: %-10.1lf Fuel: %.2lf\n",
				t*1000, apollo.a, apollo.v, apollo.m, apollo.fuel);
			fprintf(output, "%i,%i,%.1lf,%.1lf\n", i, t * 1000, apollo.a, apollo.v * -100);
			i++;
		}

		if (apollo.fuel == 0 && apollo.a > 0.625)
		{
			printf("Fuel empty.\n");
			break;
		}
	}

	//Let the user know if they were succesful or not
	if (-1 <= apollo.v && apollo.a < 0.625)
		printf("Safe Landing! (:\n");
	else
		printf("You crashed ):\n Please try again.\n");

	
	fclose(output); 

	keypress();
	return 0;
}
