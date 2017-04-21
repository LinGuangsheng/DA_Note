const int MaxSize = 100;
typedef int ListData;
typedef struct node{
	ListData data;
	int link;
}SNode;

typedef struct{
	SNode Nodes[MaxSize];
	in newptr;
}SLinkList;

void initSpace(SLinkList &space){
	space.newptr = 0;
	for(int i=0;i<MaxSize-1;i++){
		space.Nodes[i].link = i+1;
	}
	space.Nodes[MaxSize-1].link = -1;
}

void initList(SLinkList &space, int SLink){
	if(space.newptr!=-1){
		SLink = space.newptr;
		space.newptr = space.Nodes[space.newptr].link;
		space.Nodes[SLink].link = -1;
	}
}

void destroyList(SLinkList &space, int SLink){
	int tem = SLink;
	while(space.Nodes[tem].link!=-1){
		tem = space.Nodes[tem].link;
	}
	space.Nodes[tem].link = space.newptr;
	space.newptr = SLink;
	SLink = -1;
}

void clearList(SLinkList &space, int SLink){
	int tem = space.Nodes[SLink].link;
	while(space.Nodes[tem].link!=-1){
		tem = space.Nodes[tem].link;
	}
	space.Nodes[tem].link = space.newptr;
	space.newptr = space.Nodes[SLink].link;
	
	space.newptr[SLink].link = -1;
}

int listEmpty(SLinkList &space, int SLink){
	return (space.Nodes[SLink].link==-1);
}


int listLength(SLinkList space, int SLink){
	int count = 0;
	int tem = SLink;
	while(space.Nodes[tem].link!=-1){
		tem = space.Nodes[tem].link;
		count++;
	}
	return count;
}

ListData getElem(SLinkList space, int SLink, int i){
	int count = 0;
	int tem = SLink;
	if(SLink<0||SLink>MaxSize-1){
		return NULL;
	}
	while(space.Nodes[tem].link!=-1&&count<i){
		tem = space.Nodes[tem].link;
		count++;
	}
	if(space.Nodes[tem].link==-1||count>i){
		return NULL;
	}
	return space.Nodes[count].data;
}


//特殊，返回的不是元素在链表中的位置，而是元素在静态数组中的位置 
int locateElem(SLinkList space, int SLink, ListData data){
	int count = 0;
	int tem = SLink;
	while(space.Nodes[tem].link!=-1&&space.Nodes[tem].data!=data){
		tem = space.Nodes[tem].link;
		count++;
	}
	if(space.Nodes[tem].link==-1){
		return NULL;
	}
	return tem;
}

int isIn(SLinkList space, int SLink, ListData data){
	int tem = SLink;
	while(tem!=-1&&space.Nodes[tem].data!=data){
		tem = space.Nodes[tem].link	;
	}
	if(tem==-1){
		return -1;
	}
	return tem;
} 

int nextElem(SLinkList space, int SLink, ListData data){
	int tem = SLink;
	while(tem!=-1&&space.Nodes[tem].link!=-1&&space.Nodes[tem].data!=data){
		tem = space.Nodes[tem].link;
	}
	if(tem==-1||space.Nodes[tem].link==-1){
		return -1;
	}
	return space.Nodes[tem].link
}

int priorElem(SLinkList space, int SLink, ListData data){
	int tem = SLink;
	while(tem!=-1&&space.Nodes[tem].link!=-1&&space.Nodes[space.Nodes[tem].link].data!=data){
		tem = space.Nodes[tem].link;
	}
	if(tem==-1||space.Nodes[tem].link==-1){
		return -1;
	}
	return tem;
}

int listInsert(SLinkList &space, int SLink, int i, ListData data){
	int count = 0;
	int tem = SLink;
	while(tem!=-1&&count<i-1){
		tem = space.Nodes[tem].link;
	}
	if(tem==-1||count>i-1){
		return -1;
	}
	if(space.newptr!=-1){
		int newNode = space.newptr;
		space.Nodes[newNode].data = data;
		space.Nodes[newNode].link = space.Nodes[tem].link;
		space.Nodes[tem].link = newNode;
		return 1
	}
	else{
		return -1;
	}
}

int listDelete(SLinkList &space, int SLink, ListData data){
	int count = 0;
	int tem = SLink;
	while(tem!=-1&&space.Nodes[tem].link!=-1&&space.Nodes[space.Nodes[tem].link].data!=data){
		tem = space.Nodes[tem].link;
	}
	if(tem==-1||space.Nodes[tem].link==-1){
		return -1;
	}
	int freeNode = space.Nodes[tem].link;
	space.Nodes[tem].link = space.Nodes[freeNode].link;
	space.Nodes[freeNode].link = space.newptr;
	space.newptr = freeNode;
	return 1;
}
