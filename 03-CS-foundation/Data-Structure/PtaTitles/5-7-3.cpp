#include <stdio.h>
#include <string.h>

typedef struct {
    char ch;
    int weight;
    int parent;
    int lchild;
    int rchild;
} HuffmTree;

typedef struct {
    char ch;
    char code[64];
}TestNode;


int N; //哈夫曼树叶结点的数量

//约定：牺牲第0个元素，方便计算
//前N个元素是带权叶结点，后面N - 1个元素存非叶结点的权值
void Huffman (HuffmTree *T) {
    //初始化双亲和左右孩子
    for (int i = 1; i <= 2 * N - 1; i++) {
        T[i].parent = 0;
        T[i].lchild = T[i].rchild = 0;
    }
    
    //每次找两个权值最小的结点
    //设small2大于small1，小于small1时依次顶替覆盖
    for (int i = N + 1; i <= 2 * N - 1; i++) {
        
        int p1 = 1, p2 = 1; //两个小权值的索引
        int small1 = 32767, small2 = 32767; //两个小权值
        
        //每次新结点选择也要判断合成的结点！！！注意j的范围
        for (int j = 1; j <= i - 1; j++) {
            if (T[j].parent == 0) {
                if (T[j].weight < small1) {
                    small2 = small1;
                    p2 = p1;
                    small1 = T[j].weight;
                    p1  = j;
                } else if (T[j].weight < small2){
                    small2 = T[j].weight;
                    p2 = j;
                }
            }
        }
        // 合并两个最小节点
        T[i].weight = T[p1].weight + T[p2].weight;
        T[i].lchild = p1;
        T[i].rchild = p2;
        T[p1].parent = i;
        T[p2].parent = i;
    }
}

int JudgePrefixCode (char ch1[],char ch2[]) {
    int len1 = (int)strlen(ch1);
    int len2 = (int)strlen(ch2);
    for (int i = 0; i < len2 && i < len1; i++) {
        if(ch1[i] != ch2[i]) {
            return 1;
        }
    }
    return 0;
}

void Print (int flags[], int n) {
    for (int i = 0; i < n; i++) {
        if(flags[i])    printf("Yes\n");
        else   printf("No\n");
    }
}

int main (void) {
    scanf("%d", &N);
    HuffmTree HT[2 * N]; //当前还只是普通树
    
    //读入叶结点
    for (int i = 1; i <= N; i++) {
        getchar();
        scanf("%c %d", &HT[i].ch, &HT[i].weight);
    }
    
    //造哈夫曼树
    Huffman(HT);
    
    //计算标准带权路径长度
    //性质：非叶结点的权值和为带权路径长度
    int Value = 0;
    for (int i = N + 1; i <= 2 * N - 1; i++) {
        Value += HT[i].weight;
    }
    
    int M;
    scanf("%d", &M);
    int flags[M];
    TestNode exam[N + 1];
    
    for (int k = 0; k < M; k++) {
        flags[k] = 0;
        int score = 0; //后续比对带权路径长度
        for (int m = 1; m <= N; m++) {
            getchar();
            scanf("%c %s", &exam[m].ch, exam[m].code);
            score += HT[m].weight * strlen(exam[m].code);
        }
        
        if (score != Value) {
            flags[k] = 0; //不是最短路径
            continue;
        }
        
        //还需判断前缀编码
        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j <= N; j++) {
                flags[k] = JudgePrefixCode(exam[i].code, exam[j].code);
                if (!flags[k])    break; //一旦不是前缀编码，立刻退出循环
            }
            if(!flags[k])    break; //一旦不是前缀编码，立刻退出循环
        }
    }
    
    Print(flags, M);
    
    return 0;
}
