#include <stdio.h>
typedef char VertexType;    //顶点
typedef int EdgeType;    //边
#define MAXSIZE 100

typedef struct {
	VertexType vertex[MAXSIZE];    //放置顶点
	EdgeType arc[MAXSIZE][MAXSIZE];    
	int vertex_num;
	int edge_num;
}Mat_Grph;    //邻接矩阵图

int visited[MAXSIZE];    //顶点是否被访问过

int front = 0;
int rear = 0;
int queue[MAXSIZE];    //存储字母对应数值

void create_graph(Mat_Grph* G) {
	G->vertex_num = 9;
	G->edge_num = 15;
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';

	for (int i = 0; i < G->vertex_num; i++)
		for (int j = 0; j < G->vertex_num; j++)
			G->arc[i][j] = 0;
    
    //A-B A-F
    G->arc[0][1] = 1;
    G->arc[0][5] = 1;
    //B-C B-G B-I
    G->arc[1][2] = 1;
    G->arc[1][6] = 1;
    G->arc[1][8] = 1;
    //C-D C-I
    G->arc[2][3] = 1;
    G->arc[2][8] = 1;
    //D-E D-G D-H D-I
    G->arc[3][4] = 1;
    G->arc[3][6] = 1;
    G->arc[3][7] = 1;
    G->arc[3][8] = 1;
    //E-F E-H
    G->arc[4][5] = 1;
    G->arc[4][7] = 1;
    //F-G
    G->arc[5][6] = 1;
    //G-H
    G->arc[6][7] = 1;

    for (int i = 0; i < G->vertex_num; i++)
    	for (int j = 0; j < G->vertex_num; j++)
    		G->arc[j][i] = G->arc[i][j];
}

void dfs(Mat_Grph G, int i)    //深度优先,从顶点A（下标为0，int类型）开始搜索,类似前序遍历
{
    visited[i] = 1;
    printf("%c ", G.vertex[i]);

    for (int j = 0; j < G.vertex_num; j++)
    	if (G.arc[i][j] == 1 && visited[j] == 0)    dfs(G, j);
}

void bfs(Mat_Grph G, int i)    //广度优先
{
    visited[i] = 1;
    printf("%c ", G.vertex[i]);
    queue[rear++] = i;
    while(front != rear)    //队列不为空则出队
	{	
		i = queue[front++];
    	for (int j = 0; j < G.vertex_num; j++) {
    		if (G.arc[i][j] == 1 && visited[j] == 0) {
    			visited[j] = 1;
    			printf("%c ",G.vertex[j]);
    			queue[rear++] = j;
    		}
    	}
    }
}

int main(int argc, char const *argv[]) {
	Mat_Grph G;
	create_graph(&G);

	for (int i = 0; i < G.vertex_num; i++)
		visited[i] = 0;

	dfs(G, 0);
    putchar('\n');
    
	for (int i = 0; i < G.vertex_num; i++)
		visited[i] = 0;

    bfs(G, 0);
    putchar('\n');
    return 0;
}