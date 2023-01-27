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
        front = 0;
        rear = 0;
    }
    int addfro(int x);
    int delrear();
    int delfro();
    int addrear(int l);
    bool isEmpty();
    bool isFull();
    void displayQ();
} f;
bool DQ::isEmpty()
{
    return rear == front;
}
bool DQ::isFull()
{
    return rear == MAX - 1 && front == 0;
}
int DQ::addfro(int x)
{
    if (front == 0)
    {
        cout << "\nAddition of element not possible!" << endl;
    }
    else
    {
        ar[--front] = x;
        cout << x << " added to Queue!" << endl;
    }
    return 0;
}
int DQ::delrear()
{
    if (rear == 0)
    {
        cout << "\nDeletion from rear not possible!" << endl;
    }
    else
    {
        int k;
        k = ar[rear--];
        return k;
    }
    return 0;
}
int DQ::delfro()
{
    if (rear == front)
    {
        cout << "\nQueue empty!" << endl;
    }
    else
    {
        int g;
        g = ar[front++];
        return g;
    }
    return 0;
}
void DQ::displayQ()
{
    if (front == rear)
    {
        cout << "\nThe Queue is Empty!" << endl;
        return;
    }
    else
    {
        cout << endl;
        for (int i = front; i < rear; i++)
        {
            cout << ar[i] << "\t";
        }
    }
}
int DQ::addrear(int l)
{
    if (rear == MAX - 1)
    {
        cout << "\nQueue full!" << endl;
    }
    else
    {
        ar[rear++] = l;
        cout << l << " is added to queue!" << endl;
    }
    return 0;
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
    cout << "\nThe Existing Queue is:";
    f.displayQ();
    return 0;
}