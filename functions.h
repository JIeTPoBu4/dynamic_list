#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "node.c"

int push(NODE **head, unsigned digit);
unsigned pop(NODE **head);
int find_element(NODE *head, unsigned digit);
void delete_elem(NODE **head, unsigned digit);
void delete_list(NODE **head);
int put_in_list(NODE **list, char operator_symbol, unsigned digit);
void read_f(FILE *InputFile, NODE **list);
int insert(NODE **head, unsigned digit);

#endif
