#include <iostream>
#include "GraghAdjList.h"

using std::cout;
using std::endl;

//prototypes
Status addActivity(PtrGraphAdjList GL, EdgedActivity a);
void getEtvAndLtv(PtrGraphAdjList GL,const int(&topoOrder)[MAX_N], int(&etv)[MAX_N], int (&ltv)[MAX_N]);
PtrGraphAdjList newGraphAdjList(const EdgedActivity a[], int numEdges);
Status topoSort(PtrGraphAdjList GL, int(&topoOrder)[MAX_N]);
void getCriticalPath(PtrGraphAdjList GL, EdgedActivity (&criticalPath)[MAX_N]);

int main()
{
    return 0;
}

PtrGraphAdjList newGraphAdjList(const EdgedActivity a[], int numEdges)
{
    //init GraphAdjList
    auto GL = new graphAdjList();
    bool enabledVertex[MAX_N] = {};
    for(int i = 0; i < numEdges; i++)
    {        
        GL->adjlist[i].in = 0;
        GL->adjlist[i].firstedge = nullptr;
    }
    GL->numEdges = numEdges;
    GL->numVertexes = 0;

    //add activities to graph
    for(int i = 0; i < numEdges; i++)
    {
        addActivity(GL, a[i]);
        enabledVertex[a[i].from] = true;
        enabledVertex[a[i].to] = true;
    }

    //count numVertexes
    for(bool shot : enabledVertex)
        if(shot)
            GL->numVertexes += 1;
    

    return GL;
}

Status addActivity(PtrGraphAdjList GL, EdgedActivity a)
{
    //point tmp to the last EdgeNode
    EdgeNode * tmp = GL->adjlist[a.from].firstedge;
    bool isVisited[MAX_N] = {};
    while(tmp != nullptr)
    {
        //if duplicated edge visited, return error
        if(isVisited[tmp->adjvex])
            return ERROR;
        isVisited[tmp->adjvex] = true;

        //go to next edge
        tmp = tmp->next;
    }
     
    //add activity by "from"
    tmp = new EdgeNode();
    tmp->adjvex = a.to;
    tmp->weight = a.weight;
    tmp->next = nullptr;

    //add activity by "to"
    GL->adjlist[a.to].in += 1;

    return SUCCESS;
}

void getCriticalPath(PtrGraphAdjList GL, EdgedActivity (&criticalPath)[MAX_N])
{
    //init
    int topoOrder[MAX_N] = {0};
    int etv[MAX_N] = {0}, ltv[MAX_N] = {0}, ete = 0, lte = 0;
    int top = 0;
    
    //get topological order of AOE graph
    topoSort(GL, topoOrder);

    //get etv and ltv of aoe graph
    getEtvAndLtv(GL, topoOrder, etv,ltv);

    //figure ete and lte for each edge, and update critical path when ete == lte
    for(int i = 0; i < GL->numVertexes; i++)
    {
        for(EdgeNode * e = GL->adjlist[i].firstedge; e != nullptr; e = e->next)
        {
            ete = etv[i];
            lte = ltv[e->adjvex] - e->weight;
            if (0 == lte - ete)
            {
                EdgedActivity a = {i, e->adjvex, e->weight};
                criticalPath[top++] = a;
            }
        }
    }

}

Status topoSort(PtrGraphAdjList GL, int(&topoOrder)[MAX_N])
{
    return ERROR;
}

void getEtvAndLtv(PtrGraphAdjList GL, const int(&topoOrder)[MAX_N], int(&etv)[MAX_N], int (&ltv)[MAX_N])
{
    int n = GL->numVertexes;
    
    //figure etv
    for(int i = 0; i < n; i++)
    {
        for(EdgeNode * e = GL->adjlist[topoOrder[i]].firstedge; e != nullptr; e = e->next)
        {
            if(etv[topoOrder[i]] + e->weight > etv[e->adjvex])
                etv[e->adjvex] = etv[topoOrder[i]] + e->weight;
        }
    }

    //figure ltv
    ltv[n-1] = etv[n-1];
    for(int i = 0; i < n;i++)
    {
        for(EdgeNode * e = GL->adjlist[topoOrder[n-i]].firstedge; e != nullptr;e = e->next)
        {
            if(ltv[topoOrder[n-i]] > ltv[e->adjvex] - e->weight)
                ltv[topoOrder[n-i]] = ltv[e->adjvex] - e->weight;
        }
    }
}



