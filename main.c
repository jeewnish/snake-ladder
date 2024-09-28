#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Dice roll function
int dice() {
    int ranNum = rand() % 6 + 1;
    printf("Your dice rolled to: %d\n", ranNum);
    return ranNum;
}

// Snake function
int snake(int score) {
    int original_score = score;
    switch (score) {
        case 33: score = 22; break;
        case 42: score = 20; break;
        case 57: score = 48; break;
        case 90: score = 32; break;
        case 95: score = 78; break;
    }
    if (score != original_score) {
        printf("Bad Luck. Snake got you!\n");
    }
    return score;
}

// Ladder function
int ladder(int score) {
    int original_score = score;
    switch (score) {
        case 18: score = 22; break;
        case 36: score = 43; break;
        case 40: score = 60; break;
        case 62: score = 100; break;
        case 80: score = 98; break;
    }
    if (score != original_score) {
        printf("Hurrah! It's a ladder.\n");
    }
    return score;
}

// Function to remove newline from fgets input
void remove_newline(char *str) {
    str[strcspn(str, "\n")] = 0;
}

int main(void) {
    char name1[30], name2[30];
    int score1 = 0, score2 = 0, dice_roll;

    srand(time(NULL)); // Seed the random number generator

    printf("Enter first player's name: ");
    if (fgets(name1, sizeof(name1), stdin) == NULL) {
        fprintf(stderr, "Error reading Name.\n");
        return 1;
    }
    remove_newline(name1);

    printf("Enter second player's name: ");
    if (fgets(name2, sizeof(name2), stdin) == NULL) {
        fprintf(stderr, "Error reading Name.\n");
        return 1;
    }
    remove_newline(name2);

    printf("Both players start with 0 scores.\n");

    while (score1 < 100 && score2 < 100) {
        printf("%s rolls the dice. ", name1);
        dice_roll = dice();
        score1 += dice_roll;
        score1 = snake(score1);
        score1 = ladder(score1);
        if (score1 > 100) score1 = 100;
        printf("%s score - %d\n%s score - %d\n", name1, score1, name2, score2);

        if (score1 >= 100) break;

        printf("%s rolls the dice. ", name2);
        dice_roll = dice();
        score2 += dice_roll;
        score2 = snake(score2);
        score2 = ladder(score2);
        if (score2 > 100) score2 = 100;
        printf("%s score - %d\n%s score - %d\n", name1, score1, name2, score2);
    }

    printf("%s wins!\n", score1 >= 100 ? name1 : name2);

    return 0;
}