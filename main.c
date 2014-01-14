#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int evaluate(char* command){
	printf("%s\n",command);	
	
	if (strcmp(command, "quit") == 0){
		exit(0);
	}
	else{
		return 1;
	}
}

int main() {
	char  line[81], character;
	int   c;
	do{
		c = 0;
		printf("root@c64: ");

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
