// WAP tofor bank simulation of its tellers operation to see how waiting time would be affected by another teller.
#include <iostream>
#define cons 15
#define MAX 26
using namespace std;
class Queue
{
    char g[MAX];
    char h[MAX];
    int front1, rear1, front2, rear2;

public:
    Queue()
    {
        front1 = -1;
        rear1 = -1;
    }
    bool Q1Emp();
    void addQ1(char c);
    bool Q1FULL();
    char delQ1();
} f, o;
void Queue::addQ1(char c)
{
    if (rear1 >= MAX - 1)
    {
        cout << "\nQueue full!" << endl;
    }
    else
    {
        h[++rear1] = c;
    }
}
char Queue::delQ1()
{
    if (rear1 == front1)
    {
        cout << "\nQueue Empty!";
    }
    else
    {
        char Y = h[++front1];
        return Y;
    }
}
bool Queue::Q1FULL()
{
    return (rear1 == MAX - 1);
}
bool Queue::Q1Emp()
{
    return (front1 == rear1);
}
// TO FIND TIME WHEN ONLY ONE TELLER
int time()
{
    int i = 0;
    int n = 0;
    while (!f.Q1Emp())
    {
        f.delQ1();
        n = n + 15;
        cout << "The Waiting time for " << i + 1 << "'s  task: " << n - cons << endl;
        i++;
    }
    return n;
}
int time2()
{
    int t1, t2;
    t1 = 0;
    t2 = 0;
    int i = 0;
    while (!o.Q1Emp())
    {
        if (i % 2 == 0)
        {
            o.delQ1();
            t1 += 15;
            cout << "The Waiting time for " << i + 1 << "'s task is:" << t1 - cons << endl;
        }
        else
        {
            o.delQ1();
            t2 += 15;
            cout << "The Waiting time for " << i + 1 << "'s task is:" << t1 - cons << endl;
        }
        i++;
    }
    if ((MAX - 1) % 2 == 0)
    {
        return t2;
    }
    else
    {
        return t1;
    }
}
int main()
{
    int count, opt, i;
    char token;
    i = 0;
    char momo[26];
    count = 0;
    do
    {
        cout << "Enter correct option number:1. Add More elements to Queue\t2. Stop adding";
        cin >> opt;
        if (opt == 1)
        {
            cout << "Enter token value of customer:";
            cin >> token;
            momo[i] = token;
            f.addQ1(token);
            i++;
            count++;
        }
        else
        {
            break;
        }
    } while (opt != 2 || !f.Q1FULL());
    cout << "The Waiting time taken per task when only one teller:\n ";
    int h = time();
    for (i = 0; i < count; i++)
    {
        o.addQ1(momo[i]);
    }
    cout << "The Waiting time taken per task when two tellers:\n ";
    int y = time2();
    cout << "\nIf there is only one teller then the last person in the Queue (Person at last of las queue) takes time: " << h;
    cout << "\nIf another teller is added then the last person in the queue takes time: " << y;
    cout << "\nHence the time optimisation provided by the adding second teller is: " << (h - y);
    return 0;
}