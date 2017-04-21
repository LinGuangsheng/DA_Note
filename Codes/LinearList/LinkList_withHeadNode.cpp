#include <stdio.h>
#include <stdlib.h>

typedef int ListData;

typedef struct node{
	ListData data;
	node* next;
}ListNode; 

typedef ListNode* LinkList;

void initList(LinkList &first){
	first = (LinkList)malloc(sizeof(ListNode));
	if(!first){
		exit(0);
	}
	first->next = NULL;
}

void destroyList(LinkList &first){
	ListNode* tem = first;
	while(first){
		tem = first;
		first = first->next;
		free(tem);
	}
}

void clearList(LinkList &first){
	ListNode* tem = first->next;
	ListNode* freeNode = first->next;
	while(tem){
		freeNode = tem;
		tem = freeNode->next;
		free(freeNode);
	}
	first->next = NULL;
}

int listEmpty(LinkList first){
	return (first->next==NULL);
}

int listLength(LinkList first){
	int count = 1;
	ListNode* node = first->next;
	while(node){
		node=node->next;
		count++;
	}
	return (count-1);
}

ListData getElem(LinkList first, int i){
	int count = 1;
	ListNode* node = first->next;
	while(node&&count<i){
		node=node->next;
		count++;
	}
	if(!node||count>i){
		return NULL;
	}
	return node->data;
}

int locateElem(LinkList first, ListData data){
	int count = 1;
	ListNode* node = first->next;
	while(node&&node->data!=data){
		node = node->next;
		count++;
	}
	if(!node){
		return NULL;
	}
	return count;
}

int isIn(LinkList first, ListData data){
	ListNode *node = first->next;
	while(node&&node->data!=data){
		node = node->next;
	}
	if(!node){
		return -1;
	}
	return 1;
}

ListData nextElem(LinkList first, ListData data){
	ListNode* node = first->next;
	while(node&&node->next&&node->data!=data){
		node = node->next;
	}
	if(!node||!node->next){
		return NULL;
	}
	return node->next->data;
}

ListData priorElem(LinkList first, ListData data){
	ListNode* node = first->next;
	while(node&&node->next&&node->next->data!=data){
		node = node->next;
	}
	if(!node||!node->next){
		return NULL;
	}
	return node->data;
}

int listInsert(LinkList first, int i, ListData data){
	ListNode* node = first;
	int count = 0;
	while(node&&count < i-1){
		node = node->next;
		count++;
	}
	if(!node||count>i-1){
		return -1;
	}
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = node->next;
	node->next = newNode;
	return 1;
}


int listDelete(LinkList first, int i){
	int count = 0;
	ListNode* node = first;
	while(node&&node->next&&count<i-1){
		node = node->next;
		count++;
	}
	if(!node||!node->next||i<1){
		return -1;
	}
	
	ListNode* freeNode = node->next;
	node->next = freeNode->next;
	free(freeNode);
	return 1;
}


int main(){
	LinkList list;
	initList(list);
	for(int i=0;i<100;i++){
		printf("%d\t",listInsert(list,i+1,i));
	}
	printf("\n");
	//²âÊÔ 
}







