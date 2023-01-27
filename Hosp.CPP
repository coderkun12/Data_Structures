#include <iostream>
#include <string.h>
using namespace std;
#define MAX 5
class Queue
{
    string Q[MAX];
    int rear, front;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty();
    void delQ();
    void addQ(string name);
} g;
bool Queue::isEmpty()
{
    return (rear == MAX - 1 && front == MAX - 1);
}
void Queue::addQ(string name)
{
    if (rear == MAX - 1)
    {
        cout << "\n"
             << name << " Please Reschedule as doctor is busy for given time slot! " << endl;
        return;
    }
    else
    {
        Q[++rear] = name;
        cout << "\nYour name was added successfully to the Queue for current slot " << name << " !" << endl;
    }
}
void Queue::delQ()
{
    if (front == MAX - 1)
    {
        return;
    }
    else
    {
        string h;
        h = Q[++front];
        cout << endl
             << h << " Please head to Doctors cabin!" << endl;
        cout << h << " has left the doctors cabin! Next please enter the cabin!\n";
    }
}
int main()
{
    cout << "********** WELCOME TO VEGA CLINIC **********" << endl;
    g.addQ("Mohan");
    g.addQ("Ishan");
    g.addQ("Rohan");
    g.addQ("Ganesh");
    g.addQ("Tara");
    g.addQ("Lokesh");
    while (!g.isEmpty())
    {
        g.delQ();
    }
    cout << "\nThe current batch of patients is now over!" << endl;
    return 0;
}