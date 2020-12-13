#include<cstring>

typedef struct
{
    int set[MAX_SIZE * MAX_SIZE];
} DisjointSet;

DisjointSet NewDisjointSet(int count)
{
    DisjointSet result;
    memset(&result, 0, sizeof(DisjointSet));
    int i;
    for (i = 0; i < count; i++)
        result.set[i] = i;
    return result;
}

void unionSet(DisjointSet* pSet, int x, int y)
{
    if ((x = findSet(pSet, x)) == (y = findSet(pSet, y)))
        return;
    if (pSet->set[x] < pSet->set[y])
    {
        pSet->set[x] += pSet->set[y];
        pSet->set[y] = x;
    }
    else
    {
        pSet->set[y] += pSet->set[x];
        pSet->set[x] = y;
    }
}

int findSet(DisjointSet* pSet, int x)
{
    if (x < 0)
        return -1;

    int root = x, t;
    while (pSet->set[root] > 0)
        root = pSet->set[root];
    while (x != root)
    {
        t = pSet->set[x];
        pSet->set[x] = root;
        x = t;
    }
    return x;
}