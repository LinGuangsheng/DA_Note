#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 10
#define LISTINCREMENT 5

typedef int ListData; 

//���嶯̬�洢�ṹ 
typedef struct{
	ListData *data;
	int length;
	int listSize;
}SqList;

//��ʼ����̬�洢�ṹ 
int initList(SqList &L){
	L.data = (int*)malloc(LIST_INIT_SIZE*sizeof(ListData));
	if(!L.data){
		exit(0);
	}
	L.length = 0;
	L.listSize = LIST_INIT_SIZE;
	return 1;
}

//���ٶ�̬�洢�ṹ 
int destroyList(SqList &L){
	free(L.data);
	L.length = 0;
	L.listSize = 0;
	return 1;
}

//��ն�̬�洢�ṹ 
int clearList(SqList &L){
	L.length = 0;
	return 1;
}

//�Ƿ�Ϊ��
int listEmpty(SqList L){
	return (L.length == 0);
} 

//���س���

int listLength(SqList L){
	return L.length;
} 

//�õ���i��Ԫ�� 
ListData getElem(SqList L, int i){
	if(i<1||i>L.length){
		return -1;
	}
	return *(L.data+i-1);
}

//���Ԫ�ص�λ��
int locateElem(SqList L, ListData data){
	int count = 1;
	while((count<L.length+1)&&(*(L.data+count-1)!=data)){
		count++;
	}
	if(count==L.length+1){
		return -1;
	}
	return count;
} 

//�ж��Ƿ�����
int isIn(SqList L, ListData data){
	int count = 1;
	while((count<L.length+1)&&(*(L.data+count-1)!=data)){
		count++;
	}
	if(count==L.length+1){
		return -1;
	}
	return 1;
} 

//��ֱ�Ӻ��
ListData nextElem(SqList L, ListData data){
	int count = 1;
	while((count<L.length)&&(*(L.data+count-2)!=data)){
		count++;
	}
	if(count==L.length){
		return -1;
	}
	else{
		return count;
	}
} 

//��ֱ��ǰ��
ListData priorElem(SqList L, ListData data){
	int count = 1;
	while((count < L.length-1)&&(*(L.data+count)!=data)){
		count++;
	}
	if(count==L.length-1){
		return -1;
	}
	else{
		return count;
	}
}

//����Ԫ��
int listInsert(SqList &L, int i, ListData data){
	if(i<1||i>L.length+1){
		return -1;
	}
	if(L.length == L.listSize){
		int *newList = (int*)realloc(L.data,(L.listSize+LISTINCREMENT)*sizeof(ListData));
		if(!newList){
			exit(0);
		}
		L.data = newList;
		L.listSize = L.listSize + LISTINCREMENT;
	}
	for(int j = L.length;j>i-1;j--){
		*(L.data+j) = *(L.data+j-1);
	}
	*(L.data+i-1) = data;
	L.length++;
	return 1;
}

//ɾ��Ԫ��
int deleteElem(SqList &L, int i){
	if(i<1||i>L.length){
		return -1;
	}
	for(i;i<L.length;i++){
		*(L.data+i-1) = *(L.data+i);
	}
	L.length--;
	return 1;
} 

int main(){
	SqList L;
	initList(L);
	for(int i=0;i<100;i++){
		listInsert(L, i+1, i);
	}
	//���Բ��� 
	for(int i=0;i<L.length;i++){
		printf("%d\t",*(L.data+i));
	}
}

