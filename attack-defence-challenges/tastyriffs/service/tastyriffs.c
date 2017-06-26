#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char * SECRET = "b7c1f4662";

struct rockstar {
    char * name;
    int age;
    char * type;
    char * description;
    char notes[1024];
    int (*selector)(char *);
};

int classicrocker(char * description) {
    puts("Classic");
    puts(description);
    return 0;
}

int goth(char * description) {
    puts("Goth");
    puts(description);
    return 0;
}

int hairrocker(char * description) {
    puts("Hair");
    puts(description);
    return 0;
}

int punkrocker(char * description) {
    puts("Punk");
    puts(description);
    return 0;
}

int speedrocker(char * description) {
    puts("Speed");
    puts(description);
    return 0;
}

int deathrocker(char * message) {
    char * cmd = calloc(strlen(message) + 6, 1);
    strcpy(cmd, "echo ");
    strcat(cmd, message);
    system(cmd);
    return 0;
}

int (* plist[5])(char * message) = {classicrocker, goth, hairrocker, punkrocker,
                                    speedrocker};

int main(int argc, char *argv[]) {
    if (argc < 6) {
        return 1;
    }

    struct rockstar rock;
    rock.type = argv[4];
    rock.selector = plist[4];
    rock.name = argv[1];
    rock.age = atoi(argv[2]);
    int len = 1025;
    if (strlen(argv[3]) < 1025) {
        len = strlen(argv[3]);
    }
    memcpy(rock.notes, argv[3], len);
    rock.description = argv[5];

    return rock.selector(rock.name);
}
