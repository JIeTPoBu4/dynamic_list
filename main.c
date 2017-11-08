#include "functions.h"

/*
    InputFile - desriptor of input file
    list - dynamic list
    read_f - function, read symbols from input file
    put_in_list - function, calculate commands from input file
    find_element - function, seek value in dynamic list
    push - function, put value in dynamic list
    pop - function, get value from dynamic list
    delete_elem - function, delete value from dynamic list
    delete_list - function, free memory and delete dynamic list
*/

int main(int argc, char *argv[]){
	if (argc != 2){
	perror("Wrong number of input parameters!\n");
	return 2;
	}

	FILE *InputFile = NULL;

	if ((InputFile = fopen(argv[1], "r")) == NULL){
		perror("Error:can`t open file!\n");
		fprintf(stderr, strerror(errno));
		perror("\n");
		return 3;
	}

	NODE *list = NULL;
	read_f(InputFile, &list);

	fclose(InputFile);
	delete_list(&list);

	return 0;
}
