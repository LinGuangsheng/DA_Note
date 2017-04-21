#include <stdio.h>

void conversion(){
	initStack(S);
	scanf("%d%d",&N,&D);
	while(N){
		PUSH(S,N%D);
		N = N/D;
	}
	while(!StackEmpty(S)){
		Pop(S,e);
		printf("%d",e);
	}
}
