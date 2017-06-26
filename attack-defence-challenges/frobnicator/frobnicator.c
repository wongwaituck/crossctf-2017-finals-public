#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void magic(char *dest, char *src, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        dest[i] = src[i] - 42;
        if (!src[i]) return;
    }
    dest[n-1] = '\0';
}

typedef struct ss {
    char *p0[5];
    char secret[16];
    char pad[2048];
    char s1[16];
} __attribute__((packed)) ss;

ss ss1 = {
    .s1 = { 0xc4, 0xde, 0xea, 0xdc, 0xe8, 0xf2, 0x40,
            0xd0, 0xea, 0xdc, 0xe8, 0xca, 0xe4, 0x42, 0x42, 0x0 }
};

int main()
{
    puts("Frobbing inputs ...");
    fflush(stdout);

    ss1.p0[2] = (char *)malloc(0x60);
    ss1.p0[3] = (char *)malloc(0x80);
    ss1.p0[4] = (char *)malloc(0x90);
    ss1.p0[1] = (char *)malloc(0x70);

    char bufs[5][0x100];
    int i;
    for (i = 0; i < 5; i++) {
        puts("Enter string:");
        fflush(stdout);
        fgets(bufs[i], 0x100, stdin);
    }

    magic(ss1.p0[2], bufs[0], 0x60);
    magic(ss1.p0[4], bufs[2], 0x80);
    magic(ss1.p0[1], bufs[3], 0x70);
    magic(ss1.p0[3], bufs[4], 0x90);

    free(ss1.p0[4]);
    char *cp;
    for (cp = ss1.p0[1]; cp && *cp; cp++)
        *cp ^= 42;
    for (cp = ss1.p0[2]; cp && *cp; cp++)
        *cp ^= 0x42;
    magic(ss1.p0[3], bufs[2], 0x38);

    for (i = 0; i < 16 && (unsigned char)ss1.secret[i] == ((unsigned char)ss1.s1[i])/2; i++);
    if (i == 16) {
        puts("good job~~!");
        fflush(stdout);
        FILE *f = fopen("flag.txt", "r");
        char str[24];
        if (f && fgets(str, 24, f))
            printf("The flag is: %s\n", str);
    } else {
        puts("Frobbed output:");
        fflush(stdout);
        for (i = 0; i < 10; i++) {
            printf("%c%c%c", ss1.p0[1][i], ss1.p0[2][i], ss1.p0[3][i]);
        }
        puts("");
    }
    fflush(stdout);

    printf("Press any key to continue...");
    fflush(stdout);
    getchar();
}
