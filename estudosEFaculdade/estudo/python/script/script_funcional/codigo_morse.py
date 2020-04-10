#script para código morse
palavra = input('Informe uma palavra para que possa ser impresso o código:')
for i in range(0, len(palavra)):
    if(palavra[i] == 'a' or palavra[i] == 'A'):
        print('.-',end='')
    elif(palavra[i] == 'b' or palavra[i] == 'B'):
        print('-...',end='')
    elif(palavra[i] == 'c' or palavra[i] == 'C'):
        print('-.-.', end='')
    elif(palavra[i] == 'd' or palavra[i] == 'D'):
        print('-..',end='')
    elif(palavra[i] == 'e' or palavra[i] == 'E'):
        print('.', end='')
    elif(palavra[i] == 'f' or palavra[i] == 'F'):
        print('..-.', end='')
    elif(palavra[i] == 'g' or palavra[i] == 'G'):
        print('--.',end='')
    elif(palavra[i] == 'h' or palavra[i] == 'H'):
        print('....', end='')
    elif(palavra[i] == 'i' or palavra[i] == 'I'):
        print('..',end='')
    elif(palavra[i] == 'j' or palavra[i] == 'J'):
        print('.---',end='')
    elif(palavra[i] == 'k' or palavra[i] == 'K'):
        print('-.-', end='')
    elif(palavra[i] == 'l' or palavra[i] == 'L'):
        print('.-..',end='')
    elif(palavra[i] == 'm' or palavra[i] == 'M'):
        print('--',end='')
    elif(palavra[i] == 'n' or palavra[i] == 'N'):
        print('-.',end='')
    elif(palavra[i] == 'o' or palavra[i] == 'O'):
        print('---',end='')
    elif(palavra[i] == 'p' or palavra[i] == 'P'):
        print('.--.',end='')
    elif(palavra[i] == 'q' or palavra[i] == 'Q'):
        print('--.-',end='')
    elif(palavra[i] == 'r' or palavra[i] == 'R'):
        print('.-.',end='')
    elif(palavra[i] == 's' or palavra[i] == 'S'):
        print('...',end='')
    elif(palavra[i] == 't' or palavra[i] == 'T'):
        print('-',end='')
    elif(palavra[i] == 'u' or palavra[i] == 'U'):
        print('..-',end='')
    elif(palavra[i] == 'v' or palavra[i] == 'V'):
        print('...-',end='')
    elif(palavra[i] == 'w' or palavra[i] == 'W'):
        print('.--',end='')
    elif(palavra[i] == 'x' or palavra[i] == 'X'):
        print('-..-',end='')
    elif(palavra[i] == 'y' or palavra[i] == 'Y'):
        print('-.--',end='')
    elif(palavra[i] == 'z' or palavra[i] == 'Z'):
        print('--..', end='')
    
