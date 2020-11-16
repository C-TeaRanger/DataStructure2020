#include<iostream>
using namespace std;

const int SIZE = 100;

int rand_int(int i, int j)
{
    if(i >= j)
        return 0;
    return (rand() % (j - i + 1)) + i;
}

void rand_swap_B(int (&data)[SIZE], int n)
{
    //init
    int book[SIZE] = {0};

    //fill the array after looking up the book
    for(int i = 0;i < n;i++)
    {
        int tmp;
        do
        {
            tmp = rand_int(1,n);
        } while(book[tmp]);
        book[tmp] = 1;
        data[i] = tmp;
    }

}

void rand_swap_A(int (&data)[SIZE], int n)
{
    //fill the array before compare with each former item
    for(int i = 0;i < n;i++)
    {
        //init
        int tmp;
        bool found;
        
        //fill the array
        do
        {
            found = true;
            tmp = rand_int(1,n);

            //compare with former item
            for(int j = 0;j <i;j++)
            {
                if(tmp == data[j])
                {
                    found = false;
                    break;
                }
            }
        } while (!found);

        data[i] = tmp;
    }

}

void rand_swap_C(int (&data)[SIZE], int n)
{
    //init

    //fill the array
    for (int i = 0;i < n;i++)
    {
        data[i] = i;
    }

    //random swap with Shuffle Algorithm
    int tmp,index;
    for (int i = 1;i < n;i++)
    {
        index = rand_int(0,i);
        tmp = data[i];
        data[i] = data[index];
        data[index] = tmp;
    }

}

void print_data(int (&data)[SIZE], int n)
{
    for(int i = 0;i<n;i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    //init
    int data[SIZE] = {0};
    int n;

    //input data
    cin >> n;

    //output data
    rand_swap_A(data, n);
    print_data(data,n);
    rand_swap_B(data, n);
    print_data(data,n);
    rand_swap_C(data, n);
    print_data(data,n);

    return 0;
}