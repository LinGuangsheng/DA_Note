#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 10
#define LISTINCREMENT 5

typedef int ListData; 

//定义动态存储结构 
typedef struct{
	ListData *data;
	int length;
	int listSize;
}SqList;

//初始化动态存储结构 
int initList(SqList &L){
	L.data = (int*)malloc(LIST_INIT_SIZE*sizeof(ListData));
	if(!L.data){
		exit(0);
	}
	L.length = 0;
	L.listSize = LIST_INIT_SIZE;
	return 1;
}

//销毁动态存储结构 
int destroyList(SqList &L){
	free(L.data);
	L.length = 0;
	L.listSize = 0;
	return 1;
}

//清空动态存储结构 
int clearList(SqList &L){
	L.length = 0;
	return 1;
}

//是否为空
int listEmpty(SqList L){
	return (L.length == 0);
} 

//返回长度

int listLength(SqList L){
	return L.length;
} 

//得到第i个元素 
ListData getElem(SqList L, int i){
	if(i<1||i>L.length){
		return -1;
	}
	return *(L.data+i-1);
}

//获得元素的位置
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

//判断是否在内
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

//求直接后继
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

//求直接前驱
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

//插入元素
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

//删除元素
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
	//测试操作 
	for(int i=0;i<L.length;i++){
		printf("%d\t",*(L.data+i));
	}
}

