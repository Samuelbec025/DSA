#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;
    srand(time(0));
    number = rand() % 100 + 1;
    printf("Guess a number between 1 and 100\n");
    do {
        printf("Enter guess: ");
        scanf("%d", &guess);
        attempts++;
        if (guess > number) {
            printf("Too high\n");
        } else if (guess < number) {
            printf("Too low\n");
        }
    } while (guess != number);
    printf("Congratulations! You guessed the number in %d attempts\n", attempts);
    return 0;
}
