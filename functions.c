#ifndef _FUNCTIONS
#define _FUNCTIONS

#include "functions.h"

int push(NODE **head, unsigned digit){
	NODE *temp = (NODE *)malloc(sizeof(NODE));

	if (!temp){
		perror("Error:can`t allocate memory!\n");
		fprintf(stderr, strerror(errno));
		perror("\n");
		return 1;
	}

	temp->next = *head;
	temp->data = digit;
	*head = temp;

	return 0;
}

int insert(NODE **head, unsigned digit){
	if (*head == NULL || ((*head)->data > digit)){
		NODE *temp = (NODE *)malloc(sizeof(NODE));

		if (!temp){
			perror("Error:can`t allocate memory!\n");
			fprintf(stderr, strerror(errno));
			perror("\n");
			return 1;
		}

		temp->next = *head;
		temp->data = digit;
		*head = temp;

		return 0;
	}
	else{
		NODE *temp = *head;
		while (temp->next){

			if (((temp->next->data) > digit)){
				NODE *tmp = (NODE *)malloc(sizeof(NODE));

				if (!tmp){
					perror("Error:can`t allocate memory!\n");
					fprintf(stderr, strerror(errno));
					perror("\n");
					return 1;
				}

				tmp->next = temp->next;
				tmp->data = digit;
				temp->next = tmp;

				return 0;
			}

			temp = temp->next;
		}

		NODE *tmp = (NODE *)malloc(sizeof(NODE));

		if (!tmp){
			perror("Error:can`t allocate memory!\n");
			fprintf(stderr, strerror(errno));
			perror("\n");
			return 1;
		}

		tmp->next = temp->next;
		tmp->data = digit;
		temp->next = tmp;

		return 0;
	}
}

unsigned pop(NODE **head){
	if (head == NULL){
		perror("Error:there is no elements in list!\n");
		exit(1);
	}

	unsigned buf = (*head)->data;
	NODE *temp = (*head);
	(*head) = (*head)->next;
	free(temp);
	return buf;
}

int find_element(NODE *head, unsigned digit){
	if (head == NULL){
		return 0;
	}

	if (head->data == digit){
		return 1;
	}

	while ((head->next) && ((head->next->data) <= digit)){
		if (head->next->data == digit){
			return 1;
		}

		head = head->next;
	}

	return 0;
}

void delete_elem(NODE **head, unsigned digit){
	if (*head == NULL){
		return;
	}

	if ((*head)->data == digit){
		NODE  *temp = *head;
		*head = (*head)->next;
		free(temp);
		return;
	}

	NODE *ptr = *head;
	while (ptr->next){
		if (ptr->next->data == digit){
			NODE *temp = ptr->next;
			ptr->next = ptr->next->next;
			free(temp);
			return;
		}
		ptr = ptr->next;
	}
}

void delete_list(NODE **head){
	if (*head == NULL){
		return;
	}

	while ((*head)->next){
		NODE *temp = (*head)->next;
		free(*head);
		*head = temp;
	}

	free(*head);
	*head = NULL;
}

int put_in_list(NODE **list, char operator_symbol, unsigned digit){
	if (operator_symbol == '+'){

		if (!find_element(*list, digit)){
			if (insert(list, digit)){
				return 1;
			}
		}

	}
	else if (operator_symbol == '-'){
		delete_elem(list, digit);	
		return 0;
	}
	else if (operator_symbol == '?'){
		int status = find_element(*list, digit);
		switch (status)
		{
		case 1:
			printf("%u : yes\n", digit);
			break;
		case 0:
			printf("%u : no\n", digit);
			break;
		}
	}

	return 0;
}

void read_f(FILE *InputFile, NODE **list){
	char operator_symbol = '\0';
	unsigned digit = 0;
	while (!feof(InputFile)){
		fscanf(InputFile, " %c%u ", &operator_symbol, &digit);
		int status = put_in_list(list, operator_symbol, digit);
		if (status){
			delete_list(list);
			fclose(InputFile);
			exit(status);
		}
	}
}

#endif
