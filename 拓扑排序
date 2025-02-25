#include <stdio.h>
#include <stdlib.h>

typedef int VertextType;
typedef int EdgeType;

#define MAXSIZE 100

typedef struct {
    VertextType vertex[MAXSIZE];
    EdgeType arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
}Mat_Gragh;

typedef struct EdgeNode {
    int edge_vex;
    struct EdgeNode* next;
}EdgeNode;

typedef struct VertextNode {
    int in;    //入度数量
    VertextType data;
    EdgeNode* head;
}VertextNode;

typedef VertextNode Adj_List[MAXSIZE];    //Adj_List（邻接表）是VertextNode类型的数组

typedef struct {
    Adj_List adj_list;
    int vertex_num;
    int edge_num;
}Adj_Graph;

typedef Adj_Graph* Adj_List_Graph;

int top = -1;
int stack[MAXSIZE];

void push(int e) {
    if(top > MAXSIZE) {
        printf("栈已满\n");
        return;
    }
    stack[++top] = e;
}

int pop() {
    if (top == -1) {
        printf("栈已空\n");
        return 0;
    }
    int elem = stack[top--];
    return elem;
}

int is_empty() {
    if (top == -1)    return 1;
    return 0;
}

void create_graph(Mat_Gragh* G) {    //造一个特定节点和边的拓扑图
    G->vertex_num = 14;
    G->edge_num = 20;

    for (int i = 0; i < G->vertex_num; i++)
        G->vertex[i] = i;

    for (int i = 0; i < G->vertex_num; i++)
        for(int j = 0; j < G->vertex_num; j++)
            G->arc[i][j] = 0;

    G->arc[0][4] = 1;
    G->arc[0][5] = 1;
    G->arc[0][11] = 1;
    G->arc[1][2] = 1;
    G->arc[1][4] = 1;
    G->arc[1][8] = 1;
    G->arc[2][3] = 1;
    G->arc[2][5] = 1;
    G->arc[2][6] = 1;
    G->arc[2][9] = 1;
    G->arc[3][13] = 1;
    G->arc[4][7] = 1;
    G->arc[5][6] = 1;
    G->arc[5][8] = 1;
    G->arc[5][12] = 1;
    G->arc[7][8] = 1;
    G->arc[9][10] = 1;
    G->arc[9][11] = 1;
    G->arc[9][12] = 1;
    G->arc[10][13] = 1;

}

void create_adj_graph(Mat_Gragh G, Adj_List_Graph* ALG) {
    *ALG = (Adj_List_Graph)malloc(sizeof(Adj_Graph));
    (*ALG)->vertex_num = G.vertex_num;
    (*ALG)->edge_num = G.edge_num;
    //初始化邻接表
    for (int i = 0; i < G.vertex_num; i++) {
        (*ALG)->adj_list[i].in = 0;
        (*ALG)->adj_list[i].data = G.vertex[i];
        (*ALG)->adj_list[i].head = NULL;
    }

    EdgeNode* e;
    for (int i = 0; i < G.vertex_num; i++) {
        for (int j = 0; j < G.vertex_num; j++) {
            if (G.arc[i][j] == 1) {
                e = (EdgeNode*)malloc(sizeof(EdgeNode));
                e->edge_vex = j;
                e->next = (*ALG)->adj_list[i].head;    //头插法
                (*ALG)->adj_list[i].head = e;
                (*ALG)->adj_list[j].in++;
            }
        }
    } 
}

void topological_sort(Adj_List_Graph ALG) {
    EdgeNode* e;
    int curr;
    int k;

    for (int i = 0; i < ALG->vertex_num; i++)
        if(ALG->adj_list[i].in == 0)    push(i);

    while(!is_empty()) {
        curr = pop();
        printf("V%d -> ", ALG->adj_list[curr].data);
        e = ALG->adj_list[curr].head;

        while(e != NULL) {
            k = e->edge_vex;
            ALG->adj_list[k].in--;
            if (ALG->adj_list[k].in == 0)    push(k);
            e = e->next;
        }
    }
}

int main(int argc, char const *argv[]) {
    Mat_Gragh G;
    Adj_List_Graph ALG;
    create_graph(&G);
    create_adj_graph(G, &ALG);    //把邻接矩阵转化为邻接表
    topological_sort(ALG);    //拓扑排序
    return 0;
}