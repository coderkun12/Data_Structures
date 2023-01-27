#include <iostream>

using namespace std;
#define MAX 30
class STACK
{
    int top;

public:
    char a[MAX];
    STACK() { top = -1; }
    bool push(char x);
    char pop();
    bool isEmpty();
} po;
bool STACK ::push(char x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack overflow";
        return false;
    }
    else
    {
        a[++top] = x;
    }
}
char STACK ::pop()
{
    if (top < 0)
    {
        cout << "\nStack Underflow!" << endl;
        return 0;
    }
    else
    {
        char x = a[top--];
        return x;
    }
}
bool STACK ::isEmpty()
{
    return (top < 0);
}
int main()
{
    int i;
    char str[25];
    cout << "Enter a string:" << endl;
    cin >> str;
    i = 0;
    while (str[i] != '\0')
    {
        po.push(str[i]);
        i++;
    }
    cout << "The reversed string is:" << endl;
    while (!po.isEmpty())
    {
        cout << po.pop();
    }
    return 0;
}