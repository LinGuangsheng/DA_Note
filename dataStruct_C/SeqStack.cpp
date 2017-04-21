#include <stdio.h>
#include <stdlib.h>


#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

//¶¯Ì¬Ë³ÐòÕ» 
typedef int StackData;

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
		 *(S.top)= data;
		 S.top++;
		 return 1;
	 }
	 else{
	 	return 0;
	 }
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
 
 int main(){
 	
 }
