#define ListSize 100
typedef int ListData;

//线性表的结构定义，数组从0开始 
typedef struct{
	ListData data[ListSize];
	int length;
} SeqList;

//初始化线性表结构
void initList(SeqList &l){
	l.length = 0;
} 

//销毁线性结构 
void destroyList(SeqList &l){
	l.length = 0;
}

//清空线性结构中的元素
void clearList(SeqList &l){
	l.length = 0;
} 

// 线性表是否为空
int listEmpty(SeqList l){
	return (!l.length);
} 

// 求线性表的长度 
int listLength(SeqList l){
	return l.length;
}

// 获得线性表中第i个元素的值 
ListData getElem(SeqList l, int i){
	if(i>=1&&i<=l.length){
		return l.data[i-1];
	}
	else{
		return NULL;
	}
} 

// 定位结点在线性表中的位置序号
// 如果结点存在线性表中，返回结点位置，否则返回-1 
int locateElem(SeqList l, ListData data){
	int count = 1;
	while((count<=l.length)&&(l.data[count-1]!=data)){
		count++;
	}
	if(count<=l.length){
		return count;
	}
	else{
		return -1;
	}
} 

// 查看结点是否存在线性表中，若存在，则返回1，构造返回0 
int isIn(SeqList l, ListData data){
	int count = 1;
	while((count<=l.length)&&(l.data[count-1]!=data)){
		count++;
	}
	if(count<=l.length){
		return 1;
	}
	else{
		return 0;
	}
} 

// 定位元素在线性表中的直接后继 
// 若结点的直接后继存在，则返回其直接后继的位置，否则返回-1 
int nextElem(SeqList l, ListData data){
	int count = 1;
	while((count<=l.length-1)&&(l.data[count-1]!=data)){
		count++;
	}
	if(count<=l.length-1){
		return (count+1);
	}
	else{
		return -1;
	}
} 

// 定位元素在线性表中的直接前驱
// 若结点的直接前驱 存在，则返回其直接前驱额位置，否则返回-1 
int priorElem(SeqList l, ListData data){
	int count= 2;
	while((count<=l.length)&&(l.data[count-1]!=data)){
		count++;
	}
	if(count<=l.length){
		return (count-1);
	}
	else{
		return -1;
	}
} 

// 将结点插入到线性表中的第i个位置（在原线性表的第i个位置之前插入）
// 插入成功则返回1，不成功返回-1 
int listInsert(SeqList &l, int i, ListData data){
	if((i<1)||i>(l.length+1)||(l.length==ListSize)){
		return -1;
	}
	else{
		for(int j=l.length;j>=i;j--){
			l.data[j] = l.data[j-1];
		}
		l.data[i-1] = data;
		l.length++;
		return 1;
	}
} 

// 删除线性表中的第i个元素
// 删除 成功返回1，否则返回-1 
int listDelete(SeqList &l, int i){
	if((i<1)||(i>l.length)){
		return -1;
	}
	else{
		for(int j=i+1;j<=l.length;j++){
			l.data[j-2] = l.data[j-1];
		}	
		l.length--;
		return 1;
	}
}
