#include <stdio.h>
#include <time.h>
#include<stdlib.h>

int game(char you, char computer) {
    if (you == computer) {
        return 0; 
    }

    if ((you == 'r' && computer == 's') ||
        (you == 's' && computer == 'p') ||
        (you == 'p' && computer == 'r')) {
        return 1; 
    } else {
        return 2; 
    }
}

int main() {
    char you, computer;
    int result;

    srand(time(NULL)); 

    printf("******* Rock-Paper-Scissors *******\n");
    printf("1. r for Rock\n");
    printf("2. p for Paper\n");
    printf("3. s for Scissors\n");
    

   
    do {
        printf("Your choice: ");
        scanf(" %c", &you); 
    } while (you != 'r' && you != 'p' && you != 's');

    int n = rand() % 100;
    if (n < 33) {
        computer = 'r';
    } else if (n < 66) {
        computer = 'p';
    } else {
        computer = 's';
    }

    result = game(you, computer);
    printf("You choosed %c and computer choose %c\n",you,computer);
    if(result==0)
    {
        printf("Game Draw");
    }
    else if(result==1)
    {
        printf("Hooray *******----You win----*******");
    }
    else
    {
        printf("Better luck next time you loose");
    }
  

}