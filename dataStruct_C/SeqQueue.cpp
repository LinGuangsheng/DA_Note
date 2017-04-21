#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int QueueData;
typedef struct{
	QueueData *data;
	int front;
	int rear;
} SeqQueue;

void initQueue(SeqQueue &Q){
	Q.data = (QueueData*)malloc(MAXSIZE*sizeof(QueueData));
	if(!Q.data){
		exit(1);
	}
	Q.rear = Q.front = 0;
}

int queueEmpty(SeqQueue Q){
	return Q.rear = Q.front;
}

int queueFull(SeqQueue Q){
	return ((Q.rear+1)%MAXSIZE == Q.front)
}

int enQueue(SeqQueue &Q, QueueData data){
	if(queueFull(Q)){
		return 0;
	}
	Q.data[Q.rear] = data;
	Q.rear = (Q.rear+1)%MAXSIZE;
}

int deQueue(SeqQueue &Q,QueueData &data){
	if(queueEmpty(Q)){
		return 0;
	}
	data = Q.data[Q.front];
	Q.front = (Q.front+1)%MAXSIZE;
	return 1;
}

int getFront(SeqQueue Q, QueueData &data){
	if(queueEmpty(Q)){
		return 0;
	}
	data = Q.data[Q.front];
	return 1;
}
