#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "directory.h"
#include "os.h"

unsigned char current_drive;

int evaluate(char* command){
	if (strcmp(command, "quit") == 0){
		exit(0);
	} else if (strcmp(command, "ls") == 0) {
		return list_directory(current_drive);
	} else if (strcmp(command, "cpu") == 0) {
		return os_getcpu();
	}
	else{
		printf("unknown command: %s\n",command);	
		return 1;
	}
}

int main() {
	char  line[81], character;
	int   c;
	current_drive=8;
	do{
		c = 0;
		printf("%d#:", current_drive);

		do {
			character = getchar();
			line[c]   = character;
			c++;
		}while(character != '\n');

		c = c - 1;
		line[c] = '\0';
		evaluate(line);
	}while(1);

	return 1;
}
