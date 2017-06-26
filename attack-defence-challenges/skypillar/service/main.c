#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <sys/ptrace.h>

bool levelone()
{
    char code[] = "I w@nn@ be the very best";
    char input[32];

	puts("====================================================================");
	puts("                          LEVEL 01                                  ");
	puts("====================================================================");
    printf("Enter code: ");

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    if (strcmp(code, input) == 0)
        return true;

    return false;
}

bool leveltwo()
{
    int x[5];

	puts("====================================================================");
	puts("                          LEVEL 02                                  ");
	puts("====================================================================");
    printf("Enter code: ");

    scanf("%d %d %d %d %d", &x[1], &x[2], &x[3], &x[4], &x[5]);
    x[0] = 1;

    int y = 7;
    int z = 10;

    for (int i = 1; i < (sizeof(x)/sizeof(int)); i++, y ^= z ^= y)
        if (x[i] != (x[i-1]*y)+z)
            return false;

    return true;
}

int magic(char v)
{
    int c = 0;
    for (c = 0; v; v >>= 1)
        c += v & 1;

    return c;
}

bool levelthree()
{
    char v, w, x, y, z;
	puts("====================================================================");
	puts("                          LEVEL 03                                  ");
	puts("====================================================================");
    printf("Enter Code: ");
    scanf("%c %c %c %c %c", &v, &w, &x, &y, &z);

    switch(magic(v)) {
        case 2: goto mindeff01;
        case 3: goto mindeff02;
        case 4: goto mindeff03;
        case 5: goto mindeff04;
        default: return false;
    }
mindeff01:
    if (magic(w) == 1)
        if (magic(x) == 3)
            if (magic(y) == 2)
                if (magic(z) == 4)
                    return true;
                else
                    goto mindeff03;
            else
                return false;
        else
            goto mindeff04;
    else
        return false;

mindeff02:
    if (magic(w) == 3)
        if (magic(x) == 5)
            if (magic(y) == 2)
                if (magic(z) == 2)
                    goto mindeff01;
                else
                    return false;
            else
                goto mindeff03;
        else
            return false;
    else
        return false;

mindeff03:
    if (magic(w) == 2)
        if (magic(x) == 1)
            if (magic(y) == 5)
                if (magic(z) == 1)
                    return false;
                else
                    goto mindeff04;
            else
                return false;
        else
            goto mindeff02;
    else
        return false;

mindeff04:
    if (magic(w) == 5)
        if (magic(x) == 3)
            if (magic(y) == 5)
                if (magic(z) == 4)
                    goto mindeff02;
                else
                    return false;
            else
                return false;
        else
            goto mindeff01;
    else
        return false;
}

int rabbit_hole(int x)
{
    if (x <= 0)
        return 1;

    return rabbit_hole(x-2)+rabbit_hole(x-4);
}

bool levelfour()
{
    int x;
	puts("====================================================================");
	puts("                          LEVEL 04                                  ");
	puts("====================================================================");
    printf("Enter Code: ");
    scanf("%d", &x);

    if (rabbit_hole(x>>3) != 63245986)
        return false;

    return true;
}

float ayylmao( float number )
{
    long i;
    float x2, y;
    const float what = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;
    i  = 0x5f3759df - ( i >> 1 );
    y  = * ( float * ) &i;
    y  = y * ( what - ( x2 * y * y ) );

    return y;
}

typedef struct {
    int y;
    float x;
} block;

bool levelfive()
{
    block blocks[5];

    blocks[0].y = 3;
    blocks[1].y = 1;
    blocks[2].y = 3;
    blocks[3].y = 3;
    blocks[4].y = 7;

	puts("====================================================================");
	puts("                          LEVEL 05                                  ");
	puts("====================================================================");
    printf("Enter Code: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &blocks[i].x);
    }

    for (int i = 0; i < 5; i++) {
        if ((int) round(ayylmao(blocks[i].x)) != blocks[i].y)
            return false;
    }

    return true;
}

int main()
{
    setvbuf(stdin, NULL, _IONBF,0);
    setvbuf(stdout, NULL, _IONBF,0);
    puts("                                 Welcome to                                    ");
    puts(" ______     __  __     __  __        ______   __     __         __         ______     ______");
    puts("/\\  ___\\   /\\ \\/ /    /\\ \\_\\ \\      /\\  == \\ /\\ \\   /\\ \\       /\\ \\       /\\  __ \\   /\\  == \\");
    puts("\\ \\___  \\  \\ \\  _\"-.  \\ \\____ \\     \\ \\  _-/ \\ \\ \\  \\ \\ \\____  \\ \\ \\____  \\ \\  __ \\  \\ \\  __<");
    puts(" \\/\\_____\\  \\ \\_\\ \\_\\  \\/\\_____\\     \\ \\_\\    \\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\");
    puts("  \\/_____/   \\/_/\\/_/   \\/_____/      \\/_/     \\/_/   \\/_____/   \\/_____/   \\/_/\\/_/   \\/_/ /_/");
    puts("================================================================================");
    puts("                    Home of the legendary Pokemon, Rayquaza                          ");
    puts("================================================================================");
    puts("There are 5 Levels to climb. Each level requires a specifc code to unlock the next level.");
    puts("Your goal is to reach the top, and catch the legendary Rayquaza... Good luck!");

    if (levelone())
        puts("CrossCTF{p1k4_p1k4_chuuuu}");
    else
        exit(0);

    if (leveltwo())
        puts("CrossCTF{w41l0rd_0n_sk1tty_act10n}");
    else
        exit(0);

    if (levelthree())
        puts("CrossCTF{r0gg3nr0l4_b3_r0ll1n}");
    else
        exit(0);

    if (levelfour())
        puts("CrossCTF{p5yduck_15_m3t4l_af}");
    else
        exit(0);

    if (levelfive())
        puts("CrossCTF{y0ur3_4_p0k3m45t3r}");
    else
        exit(0);

}
