#include <stdio.h>
#define MAXSIZE 100000

typedef struct {
    int group[MAXSIZE];
    int length;
} lineargroup;

int maxAdd[MAXSIZE];

int main() {
    lineargroup L;
    char ch;
    scanf("%d", &L.length);
    //Special condition, return in advance to reduce the time complexity
    if(L.length == 0)    return 0;
    for(int i = 0; i < L.length; i++) {
        while((ch = getchar()) != ' ' && ch != '\n');
        scanf("%d", &L.group[i]);
    }
    int j;
    for(int i = 0; i < L.length; i++) {
        maxAdd[i] = 1;
        j = i;
        //Don't overuse j more than the border
        while(L.group[j] < L.group[j + 1] && j < L.length - 1) {
            maxAdd[i]++;
            j++;
        }
    }
    int max = 0, maxflag = 0;
    //Attention: prime i = 0 rather than 1
    for(int i = 0; i < L.length; i++) {
        if(maxAdd[i] > max) {
            max = maxAdd[i];
            maxflag = i;
        }
    }
    printf("%d", L.group[maxflag]);
    for(int i = maxflag + 1; i < maxflag + max; i++) {
        printf(" %d", L.group[i]);
    }
    printf("\n");
    return 0;
}