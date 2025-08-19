//判断共同祖先，编号从1开始
#include <stdio.h>

int main (int argc, char const *argv[]) {
    short n;
    scanf("%hd", &n);
    
    int treeArray[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &treeArray[i]);
    }
   
    short i, j;
    scanf("%hd %hd", &i, &j);
    
    if (treeArray[i - 1] == 0) {
        printf("ERROR: T[%hd] is NULL", i);
        return 0;
    }
    if (treeArray[j - 1] == 0) {
        printf("ERROR: T[%hd] is NULL", j);
        return 0;
    }
    
    short conAncestor, nowLeftAncestor = i, nowRightAncestor = j;
    
    //性质1:以编号i运算，2*i是左孩子，2*i+1是右孩子。计算用到。
    //性质2:除开根结点，奇数是右孩子，偶数是左孩子。倒推用到。
    while (1) {
        //谁大谁返回，一次只返回一者，一样时找到答案
        if (nowLeftAncestor > nowRightAncestor) {
            nowLeftAncestor = nowLeftAncestor / 2;
        }
        if (nowLeftAncestor < nowRightAncestor) {
            nowRightAncestor = nowRightAncestor / 2;
        }
        
        if (nowLeftAncestor == nowRightAncestor) {
            conAncestor = nowLeftAncestor;
            break;
        }
    }
    
    printf("%hd %d", conAncestor, treeArray[conAncestor - 1]);
    return 0;
}
