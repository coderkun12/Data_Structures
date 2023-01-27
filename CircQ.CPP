// code to implement circular queue
#include <iostream>
using namespace std;
#define max 15
class queue
{
    int rear, front;
    int circ[max];

public:
    queue()
    {
        front = -1;
        rear = -1;
    }
    void enq(int value);
    int deq();
    void displayq();
} h;
void queue::enq(int value)
{
    if ((rear == max - 1 && front == 0) || (rear == (front - 1) % (max - 1)))
    {
        cout << "Queue Full!" << endl;
    }
    else if (front == -1)
    {
        rear = 0;
        front = 0;
        circ[rear] = value;
    }
    else if (rear == max - 1 && front != 0)
    {
        rear = 0;
        circ[rear] = value;
    }
    else
    {
        circ[++rear] = value;
    }
}
int queue::deq()
{
    if (front == -1)
    {
        cout << "Queue Empty!" << endl;
    }
    int data = circ[front++];
    return data;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == max - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return data;
}
void queue::displayq()
{
    cout << endl;
    if (front == -1)
    {
        cout << "\nQueue Empty" << endl;
        return;
    }
    cout << "\nElements of circular queue are:" << endl;
    for (int i = front; i <= rear; i = (i + 1) % max)
        cout << circ[i] << "\t";
    cout << endl;
}
int main()
{

    int num, opt1;
    do
    {
        cout << "Enter optio you wish to perform:0.Exit 1. To add element to queue 2. To retrieve element from queue\n3. View queue\n";
        cin >> opt1;
        switch (opt1)
        {
        case 1:
            cout << "Enter a number:" << endl;
            cin >> num;
            h.enq(num);
            break;
        case 2:
            cout << "The number removed is: " << h.deq() << endl;
            break;
        case 3:
            h.displayq();
            break;
        default:
            break;
        }
    } while (opt1 != 0);
    return 0;
}