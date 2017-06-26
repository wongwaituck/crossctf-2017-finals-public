#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_customer();
void print_banner();
void srv_americano();
void srv_espresso();
void srv_mocha();
void srv_latte();
void take_order();

int main(int argc, char * argv[])
{
	setvbuf(stdin, NULL, _IONBF,0);
	setvbuf(stdout, NULL, _IONBF,0);
    print_banner();

    puts("Good day sir, what can I get for you today?");
    // fflush(stdout);

    handle_customer();
    // fflush(stdout);

    return 0;
}

void handle_customer()
{
    char order[256];

    take_order(order);

    if (strcmp("AMERICANO", order) == 0) {
        srv_americano();
    } else if (strcmp("ESPRESSO", order) == 0) {
        srv_espresso();
    } else if (strcmp("MOCHA", order) == 0) {
        srv_mocha();
    } else if (strcmp("LATTE", order) == 0) {
        srv_latte();
    } else {
        printf("Sorry sir, we don't sell that!\n");
    }
}

void take_order(char * order)
{
    char input[256];

    gets(input);

    if (strlen(input) > 256)
        exit(1);

    strcpy(order, input);
}


void print_banner()
{
    puts("                 ██████╗ ██╗  ██╗ ██████╗ █████╗ ███████╗███████╗");
    puts("                ██╔═████╗╚██╗██╔╝██╔════╝██╔══██╗██╔════╝██╔════╝");
    puts("                ██║██╔██║ ╚███╔╝ ██║     ███████║█████╗  █████╗");
    puts("                ████╔╝██║ ██╔██╗ ██║     ██╔══██║██╔══╝  ██╔══╝");
    puts("                ╚██████╔╝██╔╝ ██╗╚██████╗██║  ██║██║     ███████╗");
    puts("                 ╚═════╝ ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚═╝     ╚══════╝");
    puts("                          ~ Freshly Roasted Coffee ~");
    puts("================================================================================");
    puts("                                    MENU                                        ");
    puts("================================================================================");
    puts("                                 AMERICANO                                      ");
    puts("                                 ESPRESSO                                       ");
    puts("                                 MOCHA                                          ");
    puts("                                 LATTE                                          ");
    puts("================================================================================");
    puts("");

}

void srv_americano()
{
    puts("Here you go! Please enjoy!");
    puts("        / / /");
    puts("    ____\\_\\_\\____");
    puts("   /    / / /    \\");
    puts("   \\_____________/ ___");
    puts("   |             |/   \\");
    puts("   |             |    /");
    puts("   |   murica    |   /");
    puts("   |             |  /");
    puts("   |             |_/");
    puts("   \\_____________/");
}

void srv_espresso()
{
    puts("Here you go! Please enjoy!");
    puts("        / / /");
    puts("    ____\\_\\_\\____");
    puts("   /    / / /    \\");
    puts("   \\_____________/ ___");
    puts("   |             |/   \\");
    puts("   |             |    /");
    puts("   |   esprso    |   /");
    puts("   |             |  /");
    puts("   |             |_/");
    puts("   \\_____________/");
}

void srv_mocha()
{
    puts("Here you go! Please enjoy!");
    puts("        / / /");
    puts("    ____\\_\\_\\____");
    puts("   /    / / /    \\");
    puts("   \\_____________/ ___");
    puts("   |             |/   \\");
    puts("   |             |    /");
    puts("   |   mocha     |   /");
    puts("   |             |  /");
    puts("   |             |_/");
    puts("   \\_____________/");
}

void srv_latte()
{
    puts("Here you go! Please enjoy!");
    puts("        / / /");
    puts("    ____\\_\\_\\____");
    puts("   /    / / /    \\");
    puts("   \\_____________/ ___");
    puts("   |             |/   \\");
    puts("   |             |    /");
    puts("   |   latte     |   /");
    puts("   |             |  /");
    puts("   |             |_/");
    puts("   \\_____________/");
}
