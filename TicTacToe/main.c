#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printBoard(void);
void usrInput(short x, short y, char usrTurn);
short checkIfWin(void);
short checkIfRowWin(void);
short checkIfColumnWin(void);
short checkIfDiagonalWin(void);

char usrTurn = 'X';
short turnCount = 0;
short isGameOver = 0;
char board[3][3];
const short FIRST_ARR_LENGTH = sizeof(board) / sizeof(board[0]);
const short SECOND_ARR_LENGTH = sizeof(board[0]) / sizeof(board[0][0]);

int main(int argc, const char * argv[])
{
    
    printf("Player 1 is 'X' \nPlayer 2 is 'O' \n\n");
    printBoard();
    
    while(!isGameOver)
    {
        short tempX = 0;
        short tempY = 0;
        short isValid = 0;
        int c;
        while(!isValid)
        {
            printf("\nRow coordinate of the '%c' player '1 - 3': ", usrTurn);
            scanf("%hd", &tempX);
            if(tempX < 1 || tempX > 3)
            {
                printf("\nThe input is not valid, please try again!");
                while ((c = getchar()) != '\n' && c != EOF){}
            }
            else
                isValid = 1;
        }
        isValid = 0;
        while(!isValid)
        {
            printf("\nColumn coordinate of the '%c' player '1 - 3': ", usrTurn);
            scanf("%hd", &tempY);
            if(tempY < 1 || tempY > 3)
            {
                printf("\nThe input is not valid, please try again!");
                while ((c = getchar()) != '\n' && c != EOF){}
            }
            else
                isValid = 1;
        }
        if(board[tempX - 1][tempY - 1] != '\0')
        {
            printf("\nPosition has been already played.\n");
            continue;
        }
        usrInput(tempX, tempY, usrTurn);
        printBoard();
        if (checkIfWin() == 1) {
            printf("\n%c wins!\n", usrTurn);
            break;
        }
        if(turnCount > 7)
        {
            printf("\nNo more available moves. Game Over\n");
            break;
        }
        usrTurn = (usrTurn == 'X') ? 'O' : 'X';
        turnCount++;
    }
    
    return 0;
}

void printBoard(void)
{
    printf("-------------\n");
    for (short i = 0; i < FIRST_ARR_LENGTH; i++)
    {
        printf("|");
        for (short j = 0; j < SECOND_ARR_LENGTH; j++) {
            printf(" %c |", board[i][j] == '\0' ? ' ' : board[i][j]);
        }
        printf("\n-------------\n");
    }
    printf("\n");
}

void usrInput(short x, short y, char usrTurn)
{
        board[x - 1][y - 1] = usrTurn;
}

short checkInput(short inputOneToCheck, short inputTwoToCheck)
{
    if( inputOneToCheck >= 1 &&
        inputOneToCheck <= 3 &&
        inputTwoToCheck >= 1 &&
        inputTwoToCheck <= 3 )
        return 1;
    else
        return 0;
}

short checkIfWin(void)
{
    if( checkIfRowWin() == 1 ||
        checkIfColumnWin() == 1 ||
        checkIfDiagonalWin() == 1 )
        return 1;
    
    else
        return 0;
}

short checkIfRowWin(void)
{
    for (short i = 0; i < FIRST_ARR_LENGTH; i++) {
        if ((board[i][0] == board[i][1]) &&
            (board[i][1] == board[i][2]) &&
            board[i][0] != '\0')
            return 1;
    }
    return 0;
}

short checkIfColumnWin(void)
{
    for (short i = 0; i < SECOND_ARR_LENGTH; i++) {
        if ((board[0][i] == board[1][i]) &&
            (board[1][i] == board[2][i]) &&
            board[0][i] != '\0')
            return 1;
    }
    return 0;
}

short checkIfDiagonalWin(void)
{
        if(board[1][1] != '\0')
        {
            if(((board[0][0] == board[1][1]) &&
                (board[1][1] == board[2][2])) ||
                ((board[0][2] == board[1][1]) &&
                 (board[1][1]== board[2][0])) )
                return 1;
            else
                return 0;
        }
        else
        return 0;
}
