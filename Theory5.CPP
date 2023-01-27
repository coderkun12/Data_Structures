#include <iostream>
#include <bits.h>
using namespace std;
#define MAX 10
string op[3];
class STACK
{
    int top, top2;

public:
    string a[MAX];
    string b[MAX];
    STACK()
    {
        top = -1;
        top2 = -1;
    }
    bool push(string x);
    string pop();
    string pop2();
    string peek();
    bool isEmpty();
    bool push2(string x);
} z;
bool STACK ::push(string x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << " pushed into stack!" << endl;
    }
}
string STACK ::pop()
{
    if (top < 0)
    {
        cout << "\nStack Underflow!" << endl;
        return 0;
    }
    else
    {
        string x = a[top--];
        return x;
    }
}
string STACK ::peek()
{
    if (top < 0)
    {
        cout << "\nThe stack is empty!" << endl;
    }
    else
    {
        string x = a[top];
        return x;
    }
}
bool STACK ::isEmpty()
{
    return (top < 0);
}
bool STACK::push2(string g)
{
    if (top2 == MAX - 1)
    {
        cout << "Stack full" << endl;
    }
    else
    {
        b[++top2] = g;
    }
}
string STACK::pop2()
{
    if (top2 == -1)
    {
        cout << "\nStack empty!" << endl;
    }
    else
    {
        string g;
        g = b[top2--];
        return g;
    }
}
void separate()
{
    string j;
    j = z.pop();
    op[0] = j;
    j = z.pop();
    z.push2(j);
    j = z.pop();
    op[1] = j;
    j = z.pop2();
    op[2] = j;
}
int main()
{
    string name;
    cout << "Enter your first name:" << endl;
    cin >> name;
    z.push(name);
    cout << "Enter your middle name:" << endl;
    cin >> name;
    z.push(name);
    cout << "Enter your last name:" << endl;
    cin >> name;
    z.push(name);
    separate();
    int i = 0;
    while (i < 3)
    {
        cout << op[i];
        cout << "\t";
        i++;
    }
    return 0;
}