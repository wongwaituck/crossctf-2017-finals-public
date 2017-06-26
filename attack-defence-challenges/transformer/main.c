#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


void stealth()
{
    system("/bin/sh");
}

bool transcheck(char * a, char * b)
{
    if (strlen(a) != strlen(b))
        return false;

    int * x = (int *) calloc(26, sizeof(int));
    int * y = (int *) calloc(26, sizeof(int));

    char * i;
    char * j;
    for (i = a, j = b; *i != 0; i++, j++) {
        x[*i%26]++;
        y[*j%26]++;
    }

    bool flag = true;
    for (int i = 0; i < 26; i++)
        if (x[i] != y[i])
            flag = false;

    return flag;
}

int main(int argc, char * argv[])
{
    char name[128];
    char i[128];
    char j[128];

    puts(" _____                      __                                     ");
    puts("/__   \\_ __ __ _ _ __  ___ / _| ___  _ __ _ __ ___   ___ _ __     ");
    puts("  / /\\/ '__/ _` | '_ \\/ __| |_ / _ \\| '__| '_ ` _ \\ / _ \\ '__|");
    puts(" / /  | | | (_| | | | \\__ \\  _| (_) | |  | | | | | |  __/ |      ");
    puts(" \\/   |_|  \\__,_|_| |_|___/_|  \\___/|_|  |_| |_| |_|\\___|_|    ");
    puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    puts("        ~ Anagram Checker w/o any Steganography bullshit ~         ");
    puts("             (Too bad this isn't worth 2999 points)                ");
    puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    fflush(stdout);

    printf("Word #1: ");
    fflush(stdout);
    scanf("%s", i);

    printf("Word #2: ");
    fflush(stdout);
    scanf("%s", j);

    fflush(stdout);

    if (transcheck(i, j)) {
        printf("%s and %s are anagrams\n", i, j);
        fflush(stdout);
    } else {
        printf("%s and %s are not anagrams\n", i, j);
        fflush(stdout);
    }

    return 0;
}
