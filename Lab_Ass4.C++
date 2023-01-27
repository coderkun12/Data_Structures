// Write a program to implement push and pop in a stack
#include <iostream>
using namespace std;
#define MAX 10
class STACK
{
    int a[MAX] = {1, 45, 67, 78, 9};
    int top;

public:
    STACK() { top = 4; }
    bool push(int x);
    int pop();
};
bool STACK::push(int x)
{
    if (top > (MAX - 1))
    {
        cout << "Stack overflow!";
    }
    else
    {
        a[++top] = x;
        cout << x << " pushed into stack!";
    }
}
int STACK::pop()
{
    if (top < 0)
    {
        cout << "Stack underflow!";
    }
    else
    {
        int x = a[top--];
        cout << x << " popped out of stack" << endl;
        return x;
    }
}
int main()
{
    class STACK s;
    int num, opt;
    do
    {
        cout << "\nDo you wish to pop or push? Input 1 for push, 2 for pop, 0 to exit" << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "Enter a number you wish to add to stack:" << endl;
            cin >> num;
            s.push(num);
            break;
        case 2:
            s.pop();
            break;
        default:
            break;
        }
    } while (opt != 0);
    return 0;
}