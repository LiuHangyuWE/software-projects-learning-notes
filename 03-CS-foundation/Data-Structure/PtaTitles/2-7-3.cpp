#include <stdio.h>

void putinElem(int* L, int len) {
    int ch;
    for(int i = 0; i < len; i++) {
        while((ch = getchar()) != ' ' && ch != '\n');
        scanf("%d", &L[i]);
    }
}

void intergrate(int* C, int* A, int* B, int len) {
    int i = 0, j = 0, k = 0;
    while(i < len && j < len) {
        if(A[i] < B[j]) {
            C[k++] = A[i++];
        }
        else {
            C[k++] = B[j++];
        }
    }
    while(i < len) {
        C[k++] = A[i++];
    }
    while(j < len) {
        C[k++] = B[j++];
    }
}

int main() {
    int len;
    scanf("%d", &len);
    int A[len], B[len], C[len + len];
    putinElem(&A, len);
    putinElem(&B, len);
    intergrate(&C, &A, &B, len);
    //mind the ACTUAL length of the linear group C
    printf("%d", C[(2 * len - 1) / 2]);
    return 0;
}