//模拟有序1开头数列出入栈的可能元素

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1001

int stack[MAX_SIZE];
int sequence[MAX_SIZE];

int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);

    for (int p = 0; p < k; p++) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &sequence[i]);
        }

        int top = -1;
        int num = 1;
        int i = 0;
        int valid = 1;

        while (i < n && valid) {
            //将有序数字按序依次压栈，else是栈溢出
            if (top < m - 1) {
                stack[++top] = num++;
            } else {
                valid = 0;
                break;
            }
            
            while (top >= 0 && stack[top] == sequence[i]) {
                //出栈
                top--;
                i++;
                if (i == n)    break;
            }

            //数字已经用完了还没匹配完序列，不合题意
            if (num > n + 1) {
                valid = 0;
                break;
            }
        }

        if (valid && i == n) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}