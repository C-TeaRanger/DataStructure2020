const int MAXVEX = 100;

typedef struct EdgeNode{
    int adjvex;
    int weight;
    struct EdgeNode * next;
} EdgeNode;

typedef struct VertexNode{
    int in;
    int data;
    struct EdgeNode * firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct{
    AdjList adjlist;
    int numEdges, numVertexes;
} graphAdjList, * GraphAdjList;

typedef struct Activity{
    int from;
    int to;
    int data;
} Activity;

enum Status{
    SUCCESS, 
    ERROR
};