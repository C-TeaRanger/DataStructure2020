#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int MAX_N = 20;

typedef struct Node
{
    string name;
    string address;
    string tel;
    struct Node * next{};

    Node & operator =(const Node& right)
    {
        if(this == &right)
            return *this;
        this->tel = right.tel;
        this->address = right.address;
        this->name = right.name;
        this->next = right.next;
        return *this;
    }
} Node;


int getHashByName(const string& name)
{
    int result = 0;
    for(char i : name)
        result += i - '0';
    return (result % 17);
}

int getHashByTel(const string& tel)
{
    int result = 0;
    if(tel.length() < 11)
        for(char i : tel)
            result += i - '0';
    else
        result = tel[2] + tel[3] + tel[5] + tel[7] + tel[8] + tel[9] + tel[10] - '0' * 7;
    return result % 17;
}

void copyToHashTable(Node * pNode, int hash, Node ** hashTable)
{
    //copy to hash table
    Node * e = new Node;
    e = pNode;
    e->next = hashTable[hash];
    hashTable[hash] = e;
}

Node * searchByName(const string& name, Node** hashTable)
{
    //init
    Node * result = nullptr;
    int hash = getHashByName(name);

    //search node on hash table
    for(Node * e = hashTable[hash];e != nullptr; e = e->next)
    {
        if(name == e->name)
            result = e;
    }

    return result;
}

Node* searchByTel(const string& tel, Node** hashTable)
{
    //init
    Node * result = nullptr;
    int hash = getHashByTel(tel);

    //search node on hash table
    for(Node * e = hashTable[hash]; e != nullptr; e = e->next)
    {
        if(tel == e->tel)
            result = e;
    }

    return result;
}

void printNodeInfo(Node * pNode)
{
    if(nullptr == pNode)
        cout << "NULL" << endl;
    else
        cout << pNode->name << '_' << pNode->address << '_' << pNode->tel << endl;
}

/*
void showWelcomeMsg()
{
    cout << "0. Add a record" << endl;
    cout << "1. Search by name" << endl;
    cout << "2. Search by telephone" << endl;
    cout << "3. Print all records by name" << endl;
    cout << "4. Print all records by telephone" << endl;
    cout << "5. exit the program" << endl;
    cout << "please select an option from above: ";
}
*/

Node * readRecordFromConsole()
{
    Node* result = new Node;
    result->next = nullptr;
    //cout << "Please input name: ";
    cin >> result->name;
    //cout << "Please input address: ";
    cin >> result->address;
    //cout << "Please input telephone: ";
    cin >> result->tel;
    return result;
}

int main() 
{
    //init
    Node* nameHashTable[MAX_N], *telHashTable[MAX_N];
    memset(nameHashTable,0, sizeof(Node*) * MAX_N);
    memset(telHashTable, 0, sizeof(Node*) * MAX_N);
    int input_index;
    string tmpName,tmpTel;
    Node * tmpRecord = nullptr;

    while(true)
    {
        //showWelcomeMsg();
        cin >> input_index;
        switch(input_index)
        {
            case 0:  //add a node
                tmpRecord = readRecordFromConsole();
                copyToHashTable(tmpRecord, getHashByName(tmpRecord->name), nameHashTable);
                copyToHashTable(tmpRecord, getHashByTel(tmpRecord->tel),telHashTable);
                break;
            case 1: //search by name
                //cout << "Please input name: ";
                cin >> tmpName;
                tmpRecord = searchByName(tmpName,nameHashTable);
                printNodeInfo(tmpRecord);
                break;
            case 2: //search by tel
                //cout << "Please input telephone: ";
                cin >> tmpTel;
                tmpRecord = searchByTel(tmpTel,telHashTable);
                printNodeInfo(tmpRecord);
                break;
            case 3: //print all nodes by name
                for(auto e : nameHashTable)
                {
                    for(; e != nullptr; e = e->next)
                    {
                        printNodeInfo(e);
                    }
                }
                break;
            case 4: //print all nodes by tel
                for(auto e : telHashTable)
                {
                    for(; e != nullptr; e = e->next)
                    {
                        printNodeInfo(e);
                    }
                }
                break;
            case 5: //exit
                exit(0);
            default:
                break;
        }
        cout << endl;
    }
}
