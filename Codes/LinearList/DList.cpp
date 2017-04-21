#include <stdio.h>
#include <stdlib.h>

typedef int ListData;
typedef struct DNode{
	ListData data;
	struct DNode *prior, *next;
} DNode;

typedef DNode* DList;

void initList(DList &l){
	l = (DNode*)malloc(sizeof(DNode));
	if(!l){
		printf("´æ´¢·ÖÅä³ö´í£¡\n");
		exit(1); 
	}
	l->prior = l;
	l->next = l;
}

void clearList(DList &l){
	DNode *node = l->next;
	while(node!=l){
		DNode *tem = node;
		node = node->next;
		free(tem);
	}
}

void destroyList(DList &l){
	DNode *node = l->next;
	while(node!=l){
		DNode *tem = node;
		node = node->next;
		free(tem);
	}
	free(l);
}

int listEmpty(DList l){
	return (l->next==l);
}

void listLength(DList l){
	DNode *node = l->next;
	int count = 0;
	while(node!=l){
		node = node->next;
		count++;
	}
}

ListData getElem(DList l, int i){
	DNode *node = l->next;
	int count = 1;
	while(node!=l&&count<=i){
		node = node->next;
		count++;
	}
	if(count>i||node==l){
		return NULL;
	}
	else{
		return node->data;
	}
}

int locate(DList l, ListData data){
	DNode *node = l->next;
	int count = 0;
	while(node!=l&&node->data!=data){
		count++;
		node = node->next;
	}
	if(node==l){
		return -1;
	}
	else{
		return count;
	}
}

int isIn(DList l, ListData data){
	DNode *node = l->next;
	while(node!=l&&node->data!=data){
		node = node->next;
	}
	if(node==l){
		return -1;
	}
	else{
		return 1;
	}
}

DNode* nextElem(DList l, ListData data){
	DNode *node = l->next;
	while(node!=l&&node->data!=data){
		node = node->next;
	}
	if(node==l||node->next==l){
		return NULL;
	}
	return node->next;
}

DNode* priorElem(DList l, ListData data){
	DNode *node = l->next;
	while(node!=l&&node->next->data!=data){
		node = node->next;
	}
	if(node==l||node->next==l){
		return NULL;
	}
	return node;
}

int insert(DList l, ListData data, int i){
	int count = 0;
	DNode *node = l->next;
	
}
