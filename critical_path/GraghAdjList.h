const int MAXVEX = 100;

typedef struct EdgeNode{
    int adjvex;
    int weight;
    struct EdgeNode * next;
} EdgeNode;

typedef struct VertexNode{
    int in;
    struct EdgeNode * firstedge;
} VertexNode;

typedef struct{
    VertexNode adjlist[MAXVEX];
    int numEdges, numVertexes;
} graphAdjList, * PtrGraphAdjList;

typedef struct Activity{
    int from;
    int to;
    int weight;
} Activity;

enum Status{
    SUCCESS, 
    ERROR
};