#include <iostream>

#define MAX_VERTEX_NUM 20
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
    // int info;  //边权值
} ArcNode;
typedef struct VNode
{
    int data;
    ArcNode *firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

int main()
{
    ALGraph G;
    G.vexnum = 5;
    G.arcnum = 5;
    for (int i = 0; i < G.vexnum; i++)
    {
        G.vertices[i].data = i;
        G.vertices[i].firstarc = NULL;
    }
    for (int i = 0; i < G.arcnum; i++)
    {
        int v1, v2;
        std::cin >> v1 >> v2;
        ArcNode *p = new ArcNode;
        p->adjvex = v2;
        p->nextarc = G.vertices[v1].firstarc;
        G.vertices[v1].firstarc = p;
        ArcNode *q = new ArcNode;
        q->adjvex = v1;
        q->nextarc = G.vertices[v2].firstarc;
        G.vertices[v2].firstarc = q;
    }
    for (int i = 0; i < G.vexnum; i++)
    {
        std::cout << G.vertices[i].data << " ";
        ArcNode *p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            std::cout << p->adjvex << " ";
            p = p->nextarc;
        }
        std::cout << std::endl;
    }
    return 0;
}