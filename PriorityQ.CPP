#include <bits/stdc++.h>
using namespace std;
item pr[100000];
int siz = -1;
struct item
{
    int value;
    int priority;
};
void enqueue(int value, int priority)
{
    siz++;
    pr[siz].value = value;
    pr[siz].priority = priority;
}
int peek()
{
    int highestPriority = 0;
    int ind = -1;
    for (int i = 0; i <= siz; i++)
    {
        if (highestPriority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value)
        {
            highestPriority = pr[i].priority;
            ind = i;
        }
        else if (highestPriority < pr[i].priority)
        {
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}
void dequeue()
{
    int ind = peek();
    for (int i = ind; i < siz; i++)
    {
        pr[i] = pr[i + 1];
    }
    siz--;
}
int main()
{
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(16, 4);
    enqueue(12, 3);
    int ind = peek();
    cout << pr[ind].value << endl;
    dequeue();
    ind = peek();
    cout << pr[ind].value << endl;
    dequeue();
    ind = peek();
    cout << pr[ind].value << endl;
    return 0;
}
