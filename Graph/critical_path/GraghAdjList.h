const int MAX_N = 100;

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
    VertexNode adjlist[MAX_N];
    int numEdges, numVertexes;
} graphAdjList, * PtrGraphAdjList;

typedef struct EdgedActivity{
    int from;
    int to;
    int weight;
} EdgedActivity;

enum Status{
    SUCCESS, 
    ERROR
};