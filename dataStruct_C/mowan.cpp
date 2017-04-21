#include <stdio.h>
#include <stdlib.h>


#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

//��̬˳��ջ 
typedef char StackData;

 typedef struct{
 	StackData *base;
 	StackData *top;
 	int stacksize;
 } SeqStack;
 
 int StackEmpty(SeqStack S){
 	return (S.top == S.base);
 }
 
 int StackFull(SeqStack S){
 	return (S.top - S.base == S.stacksize);
 }
 
 void InitStack(SeqStack &S){
 	S.base = (StackData*)malloc(STACK_INIT_SIZE*sizeof(StackData));
 	
 	if(!S.base){
 		exit(1);
	 }
	 S.top = S.base;
	 S.stacksize = STACK_INIT_SIZE;
 }
 
 int Push(SeqStack &S, StackData data){
 	if(StackFull(S)){
 		S.base = (StackData*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(StackData));
 		if(!S.base){
	 		return 0;
		}
		 S.top = S.base+S.stacksize;
		 S.stacksize+=STACKINCREMENT;
	 }
	 *(S.top)= data;
	 S.top++;
	 return 1;
 }
 
 int getTop(SeqStack S, StackData &data){
 	if(StackEmpty(S)){
 		return 0;
	 }
	 else{
	 	data = *(S.top-1);
	 	return 1;
	 }
 }
 
 int pop(SeqStack &S, StackData &data){
 	if(StackEmpty(S)){
 		return 0;
	 }
	 else{
	 	S.top--;
	 	data = *(S.top);
	 	return 1;
	 }
 }
 
 
 
 
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 
 
#define MAXSIZE 100
typedef char QueueData;
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
	return (Q.rear == Q.front);
}

int queueFull(SeqQueue Q){
	return ((Q.rear+1)%MAXSIZE == Q.front);
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
//	printf("Here");
	return 1;
}

int getFront(SeqQueue Q, QueueData &data){
	if(queueEmpty(Q)){
		return 0;
	}
	data = Q.data[Q.front];
	return 1;
}
 
 
void insertToStack(SeqStack &resultStack, StackData data, int flag){
	if(flag == 0){
		Push(resultStack,'e');
		Push(resultStack,'a');
		Push(resultStack,'s');
	}
	else if(flag == 1){
		Push(resultStack,'e');
		Push(resultStack,'a');
		Push(resultStack,'s');
		Push(resultStack,'d');
		Push(resultStack,'e');
		Push(resultStack,'a');
		Push(resultStack,'s');
		Push(resultStack,'t');
	}
	else{
		Push(resultStack,data);
	}
}
 
 
 
 
 
 
 
 int main(){
 	SeqStack stack;//��ȡ�ַ������õ�ջ 
 	InitStack(stack);
 	char c;
 	int i=0;
 	printf("����������ַ�����");
 	while((c=getchar())!='\n'){
 		Push(stack,c);
 		i++;
	}
	
	int intoQueueFlag = 0;//�Ƿ��ȡ���ݵ������� 
//	


	SeqStack stackTem;
	InitStack(stackTem); 
	SeqStack resultStack;
	InitStack(resultStack);
	for(int j=0;j<i;j++){
		pop(stack,c);
		if(intoQueueFlag){
			if(c==40){
				intoQueueFlag = 0;
				char tem;
				
				char f1;
				pop(stackTem,f1);
				
				int insertFlag = -1;
				
				if(f1==65){
					insertFlag = 0;
				}
				else if(f1==66){
					insertFlag = 1;
				}
				else{
					insertFlag = -1;
				}
				insertToStack(resultStack,f1,insertFlag);
				while(pop(stackTem,tem)!=0){
					if(tem==65){
						Push(resultStack,'e');
						Push(resultStack,'a');
						Push(resultStack,'s');
						insertToStack(resultStack,f1,insertFlag);
//						Push(resultStack,f1);
					}
					else if(tem==66){
						Push(resultStack,'e');
						Push(resultStack,'a');
						Push(resultStack,'s');
						Push(resultStack,'d');
						Push(resultStack,'e');
						Push(resultStack,'a');
						Push(resultStack,'s');
						Push(resultStack,'t');
						insertToStack(resultStack,f1,insertFlag);
//						Push(resultStack,f1);
					}
					else{
						Push(resultStack,tem);
						insertToStack(resultStack,f1,insertFlag);
//						Push(resultStack,f1);
					}
				}
//				insertToStack(resultStack,f1,insertFlag);
			}
			else{
				Push(stackTem,c); 
			}
		}
		else{
			if(c==41){
				intoQueueFlag = 1;
			}
			else if(c==65){
				Push(resultStack,'e');
				Push(resultStack,'a');
				Push(resultStack,'s');
			}
			else if(c==66){
				Push(resultStack,'e');
				Push(resultStack,'a');
				Push(resultStack,'s');
				Push(resultStack,'d');
				Push(resultStack,'e');
				Push(resultStack,'a');
				Push(resultStack,'s');
				Push(resultStack,'t');
			}
			else{
				Push(resultStack,c);
			}
			
		}
	}
	printf("���Ϊ��");
	while(pop(resultStack,c)!=0){ 
//		printf("%c\t",c);
		switch (c) {
		case 't':
			printf("��");
//			demon[i] = '��';
			break;
		case 'd':
			printf("��");
//			demon[i] = '��';
			break;
		case 's':
			printf("��");
//			demon[i] = '��';
			break;
		case 'a':
			printf("һ��"); 
//			demon[i] = 'һ��';
//			i++;
			break;
		case 'e':
			printf("��");
//			demon[i] = '��';
			break;
		case 'z':
			printf("׷");
//			demon[i] = '׷';
			break;
		case 'g':
			printf("��"); 
//			demon[i] = '��';
			break;
		case 'x':
			printf("��");
//			demon[i] = '��';
			break;
		case 'n':
			printf("��");
//			demon[i] = '��';
			break;
		case 'i':
			printf("��");
//			demon[i] = '��';
			break;
		default:
			break;
}
//printf("\n"); 
	}
	
	printf("\n\n");
	main();
 }
