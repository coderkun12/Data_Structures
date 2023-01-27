// Implementation of Queue using array
#include <iostream>
#define Max 5
using namespace std;
class Queue
{
    int rear, front;
    int ar[Max];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool QEmpty();
    int addQ(int e);
    int delQ();
} q;
int Queue::addQ(int e)
{
    if (rear >= Max - 1)
    {
        cout << "\nQueue full!";
    }
    else
    {
        ar[++rear] = e;
        cout << e << " Added to Queue!" << endl;
    }
}
bool Queue::QEmpty()
{
    return (rear == front);
}
int Queue::delQ()
{
    if (rear == front)
    {
        cout << "\nStack empty!";
    }
    else
    {
        int x = ar[++front];
        return x;
    }
}
int main()
{
    int num, k;
    do
    {
        cout << "Enter optio you wish to perform:0.Exit 1. To add element to queue 2. To retrieve element from queue\n";
        cin >> k;
        switch (k)
        {
        case 1:
            cout << "Enter a number:" << endl;
            cin >> num;
            q.addQ(num);
            break;
        case 2:
            cout << "The number removed is: " << q.delQ() << endl;
            break;
        default:
            break;
        }
    } while (k != 0);
    while (!q.QEmpty())
    {
        cout << "Removed " << q.delQ() << endl;
    }
    return 0;
}