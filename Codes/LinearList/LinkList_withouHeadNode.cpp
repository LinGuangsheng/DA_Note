#include <stdio.h>
#include <stdlib.h>

typedef int ListData;

typedef struct node{
	ListData data;
	node* next;
}ListNode;

typedef ListNode* LinkList;

//��ʼ�������� 
void initList(LinkList &first){
	first = NULL;
}

//���ٵ�����
void destroyList(LinkList &first){
	ListNode* tem;
	while(first){
		tem = first;
		first = first->next;
		free(tem);
	}
} 

//��յ�����
void clearList(LinkList &first){
	ListNode* tem;
	while(first){
		tem = first;
		first = first->next;
		free(tem);
	}
} 

//�����Ƿ�Ϊ��
int listEmpty(LinkList &first){
	return (first==NULL);
} 

//������ĳ���
int listLength(LinkList first){
	int count = 1;//=0??????
	ListNode* tem = first;
	while(tem){
		tem = tem->next;
		count++;
	}
	return count-1;
} 

//�������ĵ�i��Ԫ��
ListData getElem(LinkList &first, int i){
	ListNode *tem = first;
	int count = 1;
	while(tem&&count<i){
		tem=tem->next;
		count++;
	}
	if(!tem||count > i){
		return NULL;
	}
	return tem->data;
	
} 

//��λ���
int locateElem(LinkList first, ListData data){
	int count = 1;
	ListNode* tem = first;
	while(tem&&tem->data!=data){
		tem = tem->next;
		count++;
	}
	if(!tem){
		return -1;
	}
	return count;
} 

//�Ƿ�����
int isIn(LinkList first, ListData data){
	ListNode* tem = first;
	while(tem&&tem->data!=data){
		tem=tem->next;
	}
	if(!tem){
		return -1;
	}
	return 1;
} 

//��ֱ�Ӻ��
ListData nextElem(LinkList first, ListData data){
	ListNode* tem = first;
	while(tem&&tem->next&&tem->data!=data){
		tem = tem->next;
	}
	if(!tem||!tem->next){
		return NULL;
	}
	return tem->next->data;
}

//��ֱ��ǰ��
ListData priorElem(LinkList first, ListData data){
	ListNode* tem = first;
	while(tem&&tem->next&&tem->next->data!=data){
		tem = tem->next;
	}
	if(!tem||!tem->next){
		return NULL;
	}
	return tem->data;
}

//������ 
int listInsert(LinkList &first, int i, ListData data){
	int count = 1;
	ListNode* tem = first;
	if(i == 1){
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->data = data;
		newNode->next = first;
		first = newNode;
		return 1;
	}
	while(tem&&count<i-1){
		tem = tem->next;
		count++;
	}
	if(!tem||count>i){
		return -1;
	}
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = tem->next;
	tem->next = newNode;
	return 1;
}

//ɾ�����
int listDelete(LinkList &first, int i){
	if(first&&i == 1){
		ListNode* freeNode = first;
		first = first->next;
		free(freeNode);
		return 1;
	}
	int count = 1;
	ListNode* tem = first;
	while(tem&&count<i-1){
		tem = tem->next;
		count++;
	}
	if(!tem||!(tem->next)||i<1){
		return -1;
	}
	ListNode* freeNode = tem->next;
	tem->next = freeNode->next;
	free(freeNode);
	return 1;
} 

int main(){
	LinkList list;
	initList(list);
	for(int i=0;i<100;i++){
		printf("%d\t",listInsert(list,i+1,i));
	}
	//���� 
}
