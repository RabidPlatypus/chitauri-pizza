from random import randint

gameOn = True

while gameOn:
    x = randint(0,99)
    y = randint(0,99)

    print(f'{x} X {y} =')
    answer = int(input('Answer: '))
    
    if answer == x * y:
        print('Good job!')
        continue
    else:
        while answer != x * y:
            print('Try again.')
            answer = int(input('Answer:'))
