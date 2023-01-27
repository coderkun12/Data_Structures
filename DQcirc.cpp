#include <iostream>
#define MAX 10
using namespace std;
class DQ
{
    int ar[MAX];
    int rear, front;

public:
    DQ()
    {
        front = -1;
        rear = -1;
    }
    void addfro(int x);
    int delrear();
    int delfro();
    void addrear(int l);
    bool isEmpty();
    bool isFull();
} f;
bool DQ::isFull()
{
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}
bool DQ::isEmpty()
{
    return front == -1;
}
void DQ::addrear(int l)
{
    if (isFull())
    {
        cout << "The Queue is full! Cant add element." << endl;
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        ar[rear] = l;
        cout << l << " added onto queue!" << endl;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
        ar[rear] = l;
        cout << l << " added onto queue!" << endl;
    }
    else
    {
        ar[++rear] = l;
        cout << l << " added onto queue!" << endl;
    }
}
int DQ::delfro()
{
    if (f.isEmpty())
    {
        cout << "Queue Underflow!" << endl;
        return 0;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            int j = ar[front++];
            return j;
        }
    }
}
void DQ::addfro(int d)
{
    if (f.isFull())
    {
        cout << "Cannot add element" << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
        cout << "\nCannot ADD!";
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        ar[--front] = d;
        cout << d << " added to queue!" << endl;
    }
}
int DQ::delrear()
{
    if (f.isEmpty())
    {
        cout << "\nUnderflow" << endl;
        return 0;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        int y = ar[rear--];
        return y;
    }
}
int main()
{
    int num, k;
    do
    {
        cout << "Enter optio you wish to perform:\n0.Exit \n1. To add element to queue from rear \n2. To retrieve element from queue from front \n3. To add element from front \n4. To retrieve element from rear\n";
        cin >> k;
        switch (k)
        {
        case 1:
            cout << "Enter a number:" << endl;
            cin >> num;
            f.addrear(num);
            break;
        case 2:
            cout << "The number removed is: " << f.delfro() << endl;
            break;
        case 3:
            cout << "\nEnter a number:" << endl;
            cin >> num;
            f.addfro(num);
            break;
        case 4:
            cout << "The number removed is:" << f.delrear() << endl;
            break;
        default:
            break;
        }
    } while (k != 0);
    return 0;
}