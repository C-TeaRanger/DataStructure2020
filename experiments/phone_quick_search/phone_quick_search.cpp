#include <iostream>
using std::cout;
using std::cin;
using std::endl;

typedef struct node
{
    char name[8];
    char address[20];
    char tel[11];
    struct node * next;
} node;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
