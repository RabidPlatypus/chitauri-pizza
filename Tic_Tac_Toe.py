r1=[' ',' ',' ']
r2=[' ',' ',' ']
r3=[' ',' ',' ']
gameboard = [r1,r2,r3]

def display(gameboard):
    for row in gameboard:
        print(row)

def choose_position():
    choice = 'wrong'
    
    while not choice.isdigit() or int(choice) not in range (1,4):
        choice = input('Enter a number (1-3): ')
        
        if not choice.isdigit():
            print("That's not a number.")
            continue
        
        if int(choice) not in range (1,4):
            print('Not in range (1-3.')
            continue
        
    return int(choice)
    
def x_turn(gameboard):
    is_x = True
    print('X Turn')
    
    while is_x:
        print('1st choose a row')
        row = choose_position()-1
    
        print('Now chose a column')
        column = choose_position()-1
        
        if gameboard[row][column] == 'X' or gameboard[row][column] == 'O':
            print('Space taken. Try again')
        else:
            is_x = False
    
    if row == 0:
        gameboard[0][column] = 'X'
    elif row == 1:
        gameboard[1][column] = 'X'
    elif row == 2:
        gameboard[2][column] = 'X'
    
    display(gameboard)
    return gameboard
    
def o_turn(gameboard):
    is_o = True
    print('O Turn')
    
    while is_o:
        print('1st choose a row')
        row = choose_position()-1
    
        print('Now chose a column')
        column = choose_position()-1
        
        if gameboard[row][column] == 'X' or gameboard[row][column] == 'O':
            print('Space taken. Try again')
        else:
            is_o = False
    
    if row == 0:
        gameboard[0][column] = 'O'
    elif row == 1:
        gameboard[1][column] = 'O'
    elif row == 2:
        gameboard[2][column] = 'O'
    
    display(gameboard)
    return gameboard

def tie_check(gameboard):
    r1=gameboard[0]
    r2=gameboard[1]
    r3=gameboard[2]
    count=0
    
    for i in r1:
        if i != ' ':
            count += 1
    for i in r2:
        if i != ' ':
            count += 1
    for i in r3:
        if i != ' ':
            count += 1
    if count == 9:
        return True
    else:
        return False
            
def winner_check(gameboard):
    if gameboard[0][0] == gameboard[0][1] == gameboard [0][2] == gameboard[1][0] == gameboard[1][1] == gameboard[1][2] == gameboard[2][0] == gameboard[2][1] == gameboard[2][2]:
        return False
    elif gameboard[0][0] == gameboard[0][1] == gameboard[0][2] == 'X':
        print('X Wins!')
        return True
    elif gameboard[0][0] == gameboard[0][1] == gameboard[0][2] == 'O':
        print('O Wins!')
        return True
    elif gameboard[1][0] == gameboard[1][1] == gameboard[1][2] == 'X':
        print('X Wins!')
        return True
    elif gameboard[1][0] == gameboard[1][1] == gameboard[1][2] == 'O':
        print('O Wins!')
        return True    
    elif gameboard[2][0] == gameboard[2][1] == gameboard[2][2] == 'X':
        print('X Wins!')
        winner = True
    elif gameboard[2][0] == gameboard[2][1] == gameboard[2][2] == 'O':
        print('O Wins!')
        return True
    elif gameboard[0][0] == gameboard[1][1] == gameboard[2][2] == 'X':
        print('X Wins!')
        return True
    elif gameboard[0][0] == gameboard[1][1] == gameboard[2][2] == 'O':
        print('O Wins!')
        return True
    elif gameboard[0][2] == gameboard[1][1] == gameboard[2][0] == 'X':
        print('X Wins!')
        return True
    elif gameboard[0][2] == gameboard[1][1] == gameboard[2][0] == 'O':
        print('O Wins!')
        winner = True    
    elif gameboard[0][0] == gameboard[1][0] == gameboard[2][0] == 'X':
        print('X Wins!')
        winner = True
    elif gameboard[0][0] == gameboard[1][0] == gameboard[2][0] == 'O':
        print('O Wins!')
        return True
    elif gameboard[0][2] == gameboard[1][2] == gameboard[2][2] == 'X':
        print('X Wins!')
        return True
    elif gameboard[0][2] == gameboard[1][2] == gameboard[2][2] == 'O':
        print('O Wins!')
        return True
    elif gameboard[0][1] == gameboard[1][1] == gameboard[2][1] == 'X':
        print('X Wins!')
        return True
    elif gameboard[0][1] == gameboard[1][1] == gameboard[2][1] == 'O':
        print('O Wins!')
        return True
    elif tie_check(gameboard):
        print("It's a tie!")
        return True
    else:
        return False
    
display(gameboard)

while winner_check(gameboard) == False:
    gameboard = x_turn(gameboard)
    if winner_check(gameboard) == True:
        continue
    gameboard = o_turn(gameboard)
    
    
    
    
