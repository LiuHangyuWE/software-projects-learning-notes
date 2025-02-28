#include <stdio.h>
typedef int ElemType;
#define MAXSIZE 100
typedef struct {
    ElemType data[MAXSIZE];
    int length;
}seqList;

void create1(seqList* list) {
    list->data[0] = 11;
    list->data[1] = 34;
    list->data[2] = 34;
    list->data[3] = 78;
    list->data[4] = 110;
    list->data[5] = 110;
    list->data[6] = 1152;
    list->data[7] = 11113;
    list->length = 8;
}

void create2(seqList* list) {
    list->data[0] = 11;
    list->data[1] = 34;
    list->data[2] = 77;
    list->data[3] = 78;
    list->data[4] = 770;
    list->data[5] = 1156;
    list->data[6] = 8900;
    list->length = 7;
}

void incorporate(seqList listA, seqList listB, seqList* list) {
    list->length = listA.length + listB.length;
    int i, j, k;
    for(i = 0; j < listA.length && k < listB.length; ) {
        if(listA.data[j] < listB.data[k])
            list->data[i++] = listA.data[j++];
        else
            list->data[i++] = listB.data[k++];
    }
    while(j < listA.length)
        list->data[i++] = listA.data[j++];
    while(k < listB.length)
        list->data[i++] = listB.data[k++];
}

int main() {
    seqList listA, listB, list;
    create1(&listA);
    create2(&listB);
    incorporate(listA, listB, &list);
    for(int i = 0; i < list.length; i++)
        printf("%d ",list.data[i]);
    return 0;
}