#include <stdio.h>
#include <stdlib.h>

typedef int QueueData;

typedef struct node{
	QueueData data;
	struct node* link;
} QueueNode;

typedef struct{
	QueueNode *rear, *front;
} LinkQueue;

void initQueue(LinkQueue &Q){
	Q.rear = NULL;
	Q.front = Q.rear;
}

int queueEmpty(LinkQueue Q){
	return (Q.front==NULL);
}

int getFront(LinkQueue Q, QueueData &data){
	if(queueEmpty(Q)){
		return 0;
	}
	data = Q.front->data;
	return 1;
}

int enQueue(LinkQueue &Q, QueueData data){
	QueueNode *tem = (QueueNode*)malloc(sizeof(QueueNode));
	tem->data = data;
	tem->link = NULL;
	if(Q.front==NULL){
		Q.front = Q.rear = teml
	}
	else{
		Q.rear->link = tem;
	}
	Q.rear = tem;
	return 1;
}

int deQueue(LinkQueue &Q, QueueData data){
	if(QueueEmpty(Q)){
		return 0;
	}
	QueueNode *node = Q.front;
	data = node->data;
	Q.front = Q.front->link;
	free(node);
	return 1;
}
