#ifndef _NODE
#define _NODE

struct node{
	struct node *next;
	unsigned data;
};

typedef struct node NODE;

#endif