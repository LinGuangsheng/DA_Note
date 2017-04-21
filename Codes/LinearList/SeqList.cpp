#define ListSize 100
typedef int ListData;

//���Ա�Ľṹ���壬�����0��ʼ 
typedef struct{
	ListData data[ListSize];
	int length;
} SeqList;

//��ʼ�����Ա�ṹ
void initList(SeqList &l){
	l.length = 0;
} 

//�������Խṹ 
void destroyList(SeqList &l){
	l.length = 0;
}

//������Խṹ�е�Ԫ��
void clearList(SeqList &l){
	l.length = 0;
} 

// ���Ա��Ƿ�Ϊ��
int listEmpty(SeqList l){
	return (!l.length);
} 

// �����Ա�ĳ��� 
int listLength(SeqList l){
	return l.length;
}

// ������Ա��е�i��Ԫ�ص�ֵ 
ListData getElem(SeqList l, int i){
	if(i>=1&&i<=l.length){
		return l.data[i-1];
	}
	else{
		return NULL;
	}
} 

// ��λ��������Ա��е�λ�����
// ������������Ա��У����ؽ��λ�ã����򷵻�-1 
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

// �鿴����Ƿ�������Ա��У������ڣ��򷵻�1�����췵��0 
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

// ��λԪ�������Ա��е�ֱ�Ӻ�� 
// ������ֱ�Ӻ�̴��ڣ��򷵻���ֱ�Ӻ�̵�λ�ã����򷵻�-1 
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

// ��λԪ�������Ա��е�ֱ��ǰ��
// ������ֱ��ǰ�� ���ڣ��򷵻���ֱ��ǰ����λ�ã����򷵻�-1 
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

// �������뵽���Ա��еĵ�i��λ�ã���ԭ���Ա�ĵ�i��λ��֮ǰ���룩
// ����ɹ��򷵻�1�����ɹ�����-1 
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

// ɾ�����Ա��еĵ�i��Ԫ��
// ɾ�� �ɹ�����1�����򷵻�-1 
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
