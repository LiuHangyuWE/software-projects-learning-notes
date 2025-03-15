#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
//存储密度高低和内存对齐量有关，在结构体中，不同数据类型内存对齐。顺序表的存储密度为1，链表则<1
typedef struct {
	ElemType *data;
	int length;
}SeqList;
SeqList* initList() {
	SeqList *L = (SeqList*)malloc(sizeof(SeqList));
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	L->length = 0;
	return L;
}
/*    //基于栈内存分配内存地址初始化
void initList(SeqList* L) {
	L->length = 0;
}
*/
int appendElem(SeqList* L, ElemType e) {
	if (L->length >= MAXSIZE) {
		printf("顺序表已满\n");
		return 0;
	}
	L->data[L->length] = e;
	L->length++;
	return 1;
}
int insertElem(SeqList* L, int pos, ElemType e) {
	/*
	if (L->length >= MAXSIZE) {
		printf("表已经满了\n");
		return 0;
	}
	if (pos < 1 || pos > L->length) {
		printf("插入位置错误");
		return 0;
	}
	*/
	if (pos <= L->length) {
		for (int i = L->length - 1; i >= pos - 1; i--)
			L->data[i + 1] = L->data[i];
		L->data[pos - 1] = e;
		L->length++;
	}
	return 1;
}
int deleteElem(SeqList* L, int pos, ElemType* e) {
	*e = L->data[pos - 1];
	if (pos < L->length) {
		for (int i = pos; i < L->length; i++)
			L->data[i - 1] = L->data[i];
		L->length--;
		return 1;
	}
	return 0;
}
int findElem(SeqList* L, ElemType e) {
	for (int i = 0; i < L->length; i++)
		if (L->data[i] == e)    return i + 1;    //just find the first position
	return 0;
}
void listElem(SeqList* L) {
	for (int i = 0; i < L->length; i++)
		printf("%d ", L->data[i]);
	printf("\n");
}
int main(int argc, char const *argv[]) {
	SeqList* list = initList();
	//initList(&list);    栈内存的声明函数接口
	printf("初始化成功，目前长度占用%d\n目前占用内存%zu字节\n", list->length, sizeof(list->data));
	appendElem(list, 88);
	appendElem(list, 66);
	appendElem(list, 77);
	listElem(list);
	insertElem(list, 1, 18);
    listElem(list);
	ElemType delData;
	deleteElem(list, 2, &delData);
	listElem(list);
	printf("%d\n", findElem(list, 40));
	printf("目前长度占用%d\n目前占用内存%zu字节\n", list->length, sizeof(list->data));
	free(list);
	return 0;
}