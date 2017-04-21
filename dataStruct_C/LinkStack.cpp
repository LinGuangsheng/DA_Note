#include <stdio.h>
#include <stdlib.h>

typedef int StackData;
typedef struct node{
	StackData data;
	struct node *link;
} StackNode; 

typedef StackNode *LinkStack;

void initStack(LinkStack &S){
	S->link = NULL;
}

int Push(LinkStack &S, StackData data){
	StackNode *node = (StackNode*)malloc(sizeof(StackNode));
	node->data = data;
	node->link = S->link;
	S->link = node;
	return 1;
}

int StackEmpty(LinkStack S){
	return (S->link == NULL);
} 

int Pop(LinkStack &S, StackData &data){
	if(S->link==NULL){
		return 0;
	}
	StackNode *tem = S->link;
	S->link = tem->link;
	data = tem->data;
	free(tem);
	return 1;
}

int getTop(LinkStack S, StackData &data){
	if(S->link==NULL){
		return 0;
	}
	data = S->link->data;
	return 1;
}

int makeEmpty(LinkStack &S){
	while(S->link){
		StackNode *tem = S->link;
		S->link = S->link->link;
		free(tem);
	}
	return 1;
}
