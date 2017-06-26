#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "sha256.h"

bool passed = true;
unsigned char* key = "\xe5\xaf\x6e\xb2\x2b\xce\x17\xb2\x7f\xd5\x5e\xd3\x2d\x72\xc6\xd4\xe1\xa7\x9c\x7e\x9c\x83\x91\x4a\xcf\x8f\x33\xf5\x12\xae\x69\x07";

const int CHALLENGE_SIZE = 6;
const int CHALLENGE_FREQ = 10;


void print_hash(unsigned char hash[]){
   int idx;
   for (idx = 0; idx < 32; idx++){
      printf("%02x", hash[idx]);
   }
   printf("\n");	
   fflush(stdout);
}

void get_hash(unsigned char hash[], char hexhash[]){
	unsigned char *temp = (unsigned char *)malloc(10 * sizeof(unsigned char));
	int idx;
	for (idx = 0; idx < 32; idx++){
		sprintf(temp, "%02x", hash[idx]);
		strcat(hexhash, temp);
	}
}

void print_me() {
    system("/bin/cat /flag");
}

int check_otp() {
	//create a random string
	unsigned char *randStr = (unsigned char *)malloc((CHALLENGE_SIZE + 1) * sizeof(unsigned char));
	
	int i;
	for (i = 0; i < CHALLENGE_SIZE; i++){
		char buffer[2];
		int random_number = rand() % 10 + 0;
		itoa(random_number, buffer, 10);
		randStr[i] = buffer[0];
	}
	
	//print to user
	printf("Challenge issued: %s\n", randStr);
	fflush(stdout);
	
	//retrieve their key
	char buffer[128] = {0};
    printf("Please enter the OTP: ");
    read(0, buffer, 128);
	buffer[strcspn(buffer, "\n")] = 0;
	
	//create local string for hashing
	unsigned char *local_copy = (unsigned char *)malloc(50 * sizeof(unsigned char));
	memset(local_copy, 0, 50);
	sprintf(local_copy, "%s%s", randStr, key);

	SHA256_CTX ctx;
	unsigned char hash[32];
	
	sha256_init(&ctx);
	sha256_update(&ctx,local_copy,strlen(local_copy));
	sha256_final(&ctx,hash);

	char* hexhash = (char *)malloc(64 * sizeof(unsigned char));
	memset(hexhash, 0, 64);
	get_hash(hash, hexhash);
	
	if(strcmp(hexhash, buffer) != 0){
		passed = false;
		puts("YOU FAILED");
		exit(-1);
	}
}

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
	srand(time(NULL));
	int j;
	
	puts("WELCOME TO CROSSCTF BANK OTP SERVER");
	for(j = 0; j < CHALLENGE_FREQ; j++){
		check_otp();
	}
		
    if (passed) {
        print_me();
    }
    else {
        puts("Incorrect!");
    }
}