#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

char key[32] = "\xcd\x87\xff\x7c\x28\xe0\x24\x32";

int intro(){
	setvbuf(stdout,0,2,0);
	setvbuf(stdin,0,2,0);
}

int getflag(){
//	FILE *fp = fopen("/home/ctfd/crackme1/share/flag.txt", "r");
//	if(fp == NULL){
//		perror("Error opening flag.txt");
//		exit(EXIT_FAILURE);
//	}
//
//	char file_buffer[100];
//	fgets(file_buffer, sizeof(file_buffer), fp);
//	printf("%s\n", file_buffer);
//	fclose(fp);
	system("/bin/sh");

	return 0;
}

void crack_pwd(char *password){
	char buffer[9];
	char keypwd[9] = "BSC2023!";

	for(int i = 0; i < 9; i++){
		buffer[i] = password[i] ^ key[i];
	}
	if(!strcmp(keypwd, buffer)){
		printf("congrat!!");
		getflag();
	}
	else {
		printf("wrong...:(");
		exit(-1);
	}
}


int main(int argc, char**argv[]){
	intro();
	char password[9];
	password[9] = '\0';

	printf("Crack My Password!!\n");
	printf("Password > ");
	fgets(password, 9, stdin);
	crack_pwd(password);
	return 0;
}

