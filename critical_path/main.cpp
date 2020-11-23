#include <iostream>
#include "GraghAdjList.h"

using std::cout;
using std::endl;

const int MAX_N = 100;

PtrGraphAdjList newGraphAdjList(const Activity a[], int n)
{
    //init GraghAdjList
    PtrGraphAdjList GL = new graphAdjList();
    for(int i = 0;i < n;i++)
    {        
        GL->adjlist[i].in = 0;
        GL->adjlist[i].data = 0;
        GL->adjlist[i].firstedge = nullptr;
    }

    //add activities to graph
    for(int i = 0; i < n; i++)
    {
        addActivity(GL, a[i]);
    }

    //calculate numEdges and numVertexes
    GL->numEdges = n;
    //TODO

    return GL;
}

void addActivity(GraghAdjList GL, Activity a)
{
    //point tmp to the last EdgeNode
    EdgeNode * tmp = GL->adjlist[a[i].from].firstedge;
    while(tmp != nullptr)
        tmp = tmp->next;  //TODO:check duplicated edge
     
    //add activity on "from"
    tmp = new EdgeNode();
    tmp->adjvex = a.to;
    tmp->weight = a.weight;
    tmp->next = nullptr;

    //add activity on "to"
    GL->adjlist[a[i].to].in += 1;
}

Status topoSort(PtrGraphAdjList GL, int(&topoOrder)[MAX_N])
{
    int n = GL->numVertexes;


    return ERROR;
}

void getCriticalPath(PtrGraphAdjList GL, Activity (&criticalPath)[MAX_N])
{
    //init
    int topoOrder[MAX_N] = {0};
    int etv[MAX_N] = {0}, ltv[MAX_N] = {0}, ete = 0, lte = 0;
    int top = 0;
    Activity a = {0};
    
    //get topological order of graph
    topoSort(GL, topoOrder);

    //get etv and ltv of aoe graph
    getEtvAndLtv(GL, topoOrder, etv,ltv);

    //figure ete and lte for each edge, and update critical path
    for(int i = 0; i < GL->numVertexes; i++)
    {
        for(EdgeNode * e = GL->adjlist[i].firstedge; e != nullptr; e = e->next)
        {
            ete = etv[j];
            lte = ltv[e->adjvex] - e->weight;
            if (0 == lte - ete)
            {
                a.from = i;
                a.to = e->adjvex;
                a.weight = e->weight;
                criticalPath[top++] = a;
            }
        }
    }

}

void getEtvAndLtv(PtrGraphAdjList GL,const int(&topoOrder)[MAX_N], int(&etv)[MAX_N], int (&ltv)[MAX_N])
{
    int n = GL->numVertexes;
    for(int i = 0; i < n; i++)
    {
        for(EdgeNode * e = GL->adjlist[topoOrder[i]].firstedge; e != nullptr; e = e->next)
        {
            if(etv[topoOrder[i]] + e->weight > etv[e->adjvex])
                etv[e->adjvex] = etv[topoOrder[i]] + e->weight;
        }
        for(EdgeNode * e = GL->adjlist[topoOrder[n-i]].firstedge; e != nullptr;e = e->next)
        {
            if(ltv[topoOrder[n-i]] + e->weight > ltv[e->adjvex])
                ltv[topoOrder[n-i]] = ltv[e->adjvex] - e->weight;
        }
    }
}

int main() 
{
    return 0;
}

