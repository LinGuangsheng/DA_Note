#include <stdio.h>
#include <stdlib.h>


#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

//动态顺序栈 
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
 	SeqStack stack;//读取字符串所用的栈 
 	InitStack(stack);
 	char c;
 	int i=0;
 	printf("请输入测试字符串：");
 	while((c=getchar())!='\n'){
 		Push(stack,c);
 		i++;
	}
	
	int intoQueueFlag = 0;//是否存取数据到队列中 
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
	printf("结果为：");
	while(pop(resultStack,c)!=0){ 
//		printf("%c\t",c);
		switch (c) {
		case 't':
			printf("天");
//			demon[i] = '天';
			break;
		case 'd':
			printf("地");
//			demon[i] = '地';
			break;
		case 's':
			printf("上");
//			demon[i] = '上';
			break;
		case 'a':
			printf("一个"); 
//			demon[i] = '一个';
//			i++;
			break;
		case 'e':
			printf("鹅");
//			demon[i] = '鹅';
			break;
		case 'z':
			printf("追");
//			demon[i] = '追';
			break;
		case 'g':
			printf("赶"); 
//			demon[i] = '赶';
			break;
		case 'x':
			printf("下");
//			demon[i] = '下';
			break;
		case 'n':
			printf("蛋");
//			demon[i] = '蛋';
			break;
		case 'i':
			printf("恨");
//			demon[i] = '恨';
			break;
		default:
			break;
}
//printf("\n"); 
	}
	
	printf("\n\n");
	main();
 }
