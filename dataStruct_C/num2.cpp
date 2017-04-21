#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义数据类型 
typedef int ListData;

//定义节点结构体 
typedef struct node{
	ListData data;
	struct node *prior,*next;
} ListNode; 

//定义链表 
typedef ListNode* LinkList;

//初始化链表 
void initList(LinkList &list){
	list = (ListNode*)malloc(sizeof(ListNode));
	if(!list){
		exit(1);
	}
	list->data = 0;
	list->prior = list;
	list->next = list;
}


//在头结点的下一个位置插入 
void insertBefore(LinkList &list, ListData data){
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	if(!newNode){
		exit(1);
	}
	newNode->data = data;
	
	newNode->next = list->next;
	newNode->prior = list;
	list->next->prior = newNode;
	list->next = newNode;
	
	//根据插入的节点，设置头结点的值 
	ListData c = list->data;
	if(c<0){
		list->data--;
	}
	if(c>0){
		list->data++;
	}
	if(c==0){
		if(data>=0){
			list->data = 1;
		}
		if(data<0){
			list->data = -1;
		}
	}
}


//正常从头结点前面插入 
void insertList(LinkList &list, ListData data){
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	if(!newNode){
		exit(1);
	}
	newNode->data = data;
	
	newNode->next = list;
	list->prior->next = newNode;
	newNode->prior = list->prior;
	list->prior = newNode;
	
	//根据插入的节点，设置头结点的值 
	ListData c = list->data;
	if(c<0){
		list->data--;
	}
	if(c>0){
		list->data++;
	}
	if(c==0){
		if(data>=0){
			list->data = 1;
		}
		if(data<0){
			list->data = -1;
		}
	}
}


//加法运算 
void add(LinkList &list, LinkList listA, LinkList listB){
	
	//得到链表的长度 
	int a = abs(listA->data);
	int b = abs(listB->data);
	int length;
	
	
	//使用最大长度来初始化结构的链表 
	if(a>b){
		length = a;
		for(int i=0;i<a-b;i++){
			insertBefore(listB,0);
		}
	}
	else{
		length = b;
		for(int i=0;i<b-a;i++){
			insertBefore(listA,0);
		}
	} 
	for(int i=0;i<length;i++){
		insertList(list,0);
	}
	
	list->data = 0;
	ListNode *nodeB = listB->prior;
	ListNode *nodeA = listA->prior;
	ListNode *node = list->prior;
	
	//先使用两个正整数相加的规则，对数进行相加，使得每个位置都是正数 
	for(int i=0;i<length;i++){
		//节点的数据相加，范围在-19998到19998之间 
		node->data = nodeA->data+nodeB->data+node->data;
		node = node->prior;
		nodeA = nodeA->prior;
		nodeB = nodeB->prior;
		//结果在0到9999之间，没有借位也没有进位 
		if(node->next->data>=0&&node->next->data<10000){
			
		}
		//结果在10000到19998之间，进一位 
		else if(node->next->data>=10000){
			node->data+=1;
			node->next->data-=10000;
		}
		//结果在-10000到0之间，借一位 
		else if(node->next->data<0&&node->next->data>=-10000){
			node->data-=1;
			node->next->data+=10000;
		}
		//结果在-19998到-10000之间，借两位 
		else if(node->next->data<-10000){
			node->data-=2;
			node->next->data+=20000;
		}
	}
	//在进行最高位的计算的时候，node(最高位)->prior是头结点，如果在这里发生进位或者借位，需要调整 
	if(list->data!=0){
		//借位的情况 
		if(list->data<0){
			
			
			ListNode *node = list->prior;
			
			//由于用10000和9999来减（原本数字的范围是-1到9999），可能有10000的情况 
			
			//从最低一位开始，用10000来减，得到应该的数字 
			while(node!=list){
				node->prior->data++;
				node->data = 10000-node->data;
				if(node->data>=10000){
					node->data = node->data-10000;
					node->prior->data--;
				}
				node = node->prior;
			}
			
			
//			
//			
//			node->data = 10000-node->data;
//			if(node->data>=10000){
//				node->prior->data--;
//				node->data = node->data-10000;
//			}
//			//从最低一位到最高一位之间 
//			for(int i=0;i<length-1;i++){
//				node = node->prior;
//				node->data = 9999-node->data;
//				//10000的情况，进行进位 
//				if(node->data>=10000){
//					if(i<length-2){
//						node->prior->data--;
//					}
//					else{
//						listA->data--;
//					}
//					node->data = node->data-10000;
//					
//				}
//			}
			//最高一位 
//			node = node->prior;
//			node->data = 9999-node->data;
//			if(listA->data-tem==-2){
//				insertBefore(list,-1);
//			}
//			else if(listA)
//			if(node->data>=10000){
//				node->data = node->data-10000;
//				node->prior->data++;
//			}
			if(0!=list->data){
				insertBefore(list,list->data);
			}
			
//			对数据进行规范化
			ListNode *nodeNew = list->next;
			list->data = 0;
			while(nodeNew!=list){
				nodeNew->data = -abs(nodeNew->data);
				nodeNew = nodeNew->next;
				list->data--;
			} 
//			
			
		}
		//进位的情况，直接添加新的节点 
		else{
			insertBefore(list,1);
			//对数据进行规范化
			ListNode *nodeNew = list->next;
			list->data = 0;
			while(nodeNew!=list){
				nodeNew = nodeNew->next;
				list->data++;
			} 
		}
	}
	
	//去除首位为0的情况 
	ListNode *nodeTem = list->next;
	while(nodeTem!=list&&nodeTem->data==0){
		nodeTem->prior->next = nodeTem->next;
		nodeTem->next->prior = nodeTem->prior;
		nodeTem = nodeTem->next;
	}
}






int main(){
//	int n;
//	printf("请输入测试数据组数：");
//	scanf("%d",&n);
//	getchar(); 
//	printf("\n");
//	for(int i=0;i<n;i++){
//	while(1){
		LinkList list;
		initList(list);
		
		LinkList listA;
		initList(listA);
		
		LinkList listB;
		initList(listB);
		
		//获得文本 
		printf("请输入数字1：");
		char input1[200];
		int i1=0;
		while((input1[i1]=getchar())!=';'){
			i1++;
		}
		
		getchar();
//		getchar();
		//获得文本 
		printf("请输入数字2：");
		char input2[200];
		int i2=0;
		while((input2[i2]=getchar())!=';'){
			i2++;
		}
		getchar();
//		getchar();
		
		//将文本1分割，存进链表 
		int lengthA = strlen(input1);
		char temA[20];
		int kA=0;
		int flagA = 0;
		for(int i = 1;i<=lengthA;i++){
			if(input1[i-1]!=','&&input1[i-1]!=';'){
				temA[kA]=input1[i-1];
				kA++;
			}
			else{
				kA=0; 
				int num = atoi(temA);
				
				if(input1[0]=='-'){
					flagA=1;
				}
				
				if(flagA){
					insertList(listA,-abs(num));
				}
				else{
					insertList(listA,abs(num));
				}
				memset(temA,0,20);
			}
		}
		
		//将文本2分割，存进链表 
		int lengthB = strlen(input2);
		char temB[20];
		int kB=0;
		int flagB = 0;
		for(int i = 1;i<=lengthB;i++){
			if(input2[i-1]!=','&&input2[i-1]!=';'){
				temB[kB]=input2[i-1];
				kB++;
			}
			else{
				kB=0; 
				int num = atoi(temB);
				if(input2[0]=='-'){
					flagB=1;
				}
				
				if(flagB){
					insertList(listB,-abs(num));
				}
				else{
					insertList(listB,abs(num));
				}
				memset(temB,0,20);
			}
		}
		
		
		//测试使用，打印A，B的结果 
//		ListNode *nodeA = listA->next;
//		ListNode *nodeB = listB->next;
//		
//		printf("%d\t",listA->data);
//		
//		while(nodeA!=listA){
//			printf("%d\t",nodeA->data);
//			nodeA=nodeA->next;
//		}
//		
//		printf("\n");
//		
//		printf("%d\t",listB->data);
//		while(nodeB!=listB){
//			printf("%d\t",nodeB->data);
//			nodeB=nodeB->next;
//		}
//		
//		printf("\n");
		
		//进行加法运算 
		add(list,listA,listB);
		
		//打印相加的结果 
//		printf("%d\t",list->data);
//		ListNode *node = list->next;
//		printf("%d\t",node->data);
//		printf("Here");
//		node = node->next;
//		while(node!=list){
//			if(node->data>=100&&node->data<1000){
//				printf("0");
//			}
//			else if(node->data>=10&&node->data<100){
//				printf("00");
//			}
//			else if(node->data>0&&node->data<10){
//				printf("000");
//			}
//			
//			if(node->data<=-100&&node->data>-1000){
//				printf("0");
//			}
//			else if(node->data<=-10&&node->data>-100){
//				printf("00");
//			}
//			else if(node->data<0&&node->data>-10){
//				printf("000");
//			}
//			
//			if(node->data==0){
//				printf("000");
//			}
			
//			printf("%d\t",node->data);
//			node=node->next;
//		}
		printf("结果为：");
		ListNode *node = list->next;
		printf("%d",node->data);
		if(node->next!=list){
			printf(",");
		}
		node = node->next;
		while(node!=list){
			if(abs(node->data)>=0&&abs(node->data)<10){
				printf("000");
			}
			else if(abs(node->data)<100){
				printf("00");
			}
			else if(abs(node->data)<1000){
				printf("0");
			}
			printf("%d",abs(node->data));
			node = node->next;
			if(node!=list){
				printf(",");
			}
//			printf("%d\t",node->data);
//			node = node->next;
		}
		printf(";\n\n");
//	}
		main();
}
