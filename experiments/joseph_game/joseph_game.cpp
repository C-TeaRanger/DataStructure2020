#include<iostream>
using std::cout;
using std::endl;

const int NUM = 30;
const int MIN_NUM = 15;

typedef struct Node{
    int data;
    struct Node* next;
} Node;
typedef Node* CircleList;

CircleList getNewCircleList(int n)
{
    //init
    auto head = new Node;
    head->next = new Node;
    CircleList tmp = head->next;

    //create n nodes
    for(int i = 1; i <= n; i++)
    {
        tmp->data = i;
        tmp->next = new Node();
        tmp = tmp->next;
        tmp->data = 0;
        tmp->next = nullptr;
    }
    tmp->next = head->next;

    return head;
}

int deleteNinth(CircleList head)
{
    //init
    CircleList p8 = head,p9 = nullptr,p10 = nullptr;
    int result = 0;

    //look up for the (8,9,10)th nodes
    for(int i = 1;i <= 8; i++)
    {
        p8 = p8->next;
        if(head->next == p8->next)
        {
            return -1;   //Node amount not enough
        }
    }
    p9 = p8->next;
    p10 = p9->next;

    //get data of ninth node and delete
    p8->next = p10;
    result = p9->data;
    delete p9;

    //redirect the head node to p10
    head->next = p10;

    cout << result << " has been deleted" << endl;
    return result;
}

int main()
{
    //init
    int isNodeDeleted[NUM] = {0};
    int count = NUM;
    CircleList list = getNewCircleList(NUM);

    //loop until count decrease to 15
    while(count > MIN_NUM)
    {
        isNodeDeleted[deleteNinth(list)] = 1;
        count--;
    }

    //print missing node data
    for(int i = 0; i < NUM; i++)
    {
        if(isNodeDeleted[i])
            cout << i << " ";
    }

    return 0;
}