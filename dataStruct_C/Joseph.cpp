#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int position;
	int num;
	struct node* next;
}Node;

typedef node* LinkList;

void initList(LinkList &list){
	Node* first = (Node*)malloc(sizeof(Node));
	first->position = 0;
	first->num = 0;
	list = first;
	first->next = list;
}

void listInsert(LinkList &list, int num){
	Node* tem = list;
	while(tem->next!=list){
		tem=tem->next;
	}
	list->position++;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->position = list->position;
	newNode->num = num;
	tem->next = newNode;
	newNode->next = list;
}


void deleteNode(LinkList &list, Node* node){
	Node* tem = list;
	while(tem->next!=node){
		tem = tem->next;
	}
	tem->next = tem->next->next;
	list->position--;
}


void Joseph(LinkList &list, int num){
	
	Node* node = list->next;
	while(node!=list){
		int N = num%list->position;
		for(int i=0;i<N-1;i++){
			node = node->next;
			if(node==list){
				node = node->next;
			}
		}
		printf("%d\t",node->position);
		num = node->num;
		deleteNode(list, node);
//		printf("%d\n",list->position);
		node = node->next;
		if(node==list){
			node = node->next;
		}
	}
} 

int main(){
//	int n;
//	printf("请输入测试数据组数：");
//	scanf("%d",&n);
//	printf("\n");
//	for(int i=0;i<n;i++){
		LinkList list = (LinkList)malloc(sizeof(Node));
		initList(list);
		int upNum;
		printf("请输入上限：");
		scanf("%d",&upNum);
		
		int n;
		printf("请输入个数n：");
		scanf("%d",&n);
		
		for(int i=0;i<n;i++){
			int num;
			printf("请输入第%d个数：",i+1);
			scanf("%d",&num);
			listInsert(list, num);
			 
		}
		Node* node = list;
		Joseph(list,upNum);
		printf("\n\n"); 
//	} 
main(); 
}


