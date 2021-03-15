// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
class _stack
{
    stack<int> s;
    int minEle;

public:
    int getMin();
    int pop();
    void push(int);
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        _stack *a = new _stack();
        while (q--)
        {

            int qt;
            cin >> qt;

            if (qt == 1)
            {
                //push
                int att;
                cin >> att;
                a->push(att);
            }
            else if (qt == 2)
            {
                //pop
                cout << a->pop() << " ";
            }
            else if (qt == 3)
            {
                //getMin
                cout << a->getMin() << " ";
            }
        }
        cout << endl;
    }
}
// } Driver Code Ends

/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack ::getMin()
{
    if (s.size() > 0)
        return minEle;
    else
        return -1;
}

/*returns poped element from stack*/
int _stack ::pop()
{
    int x = -1;
    if (s.size() > 0)
    {
        x = s.top();
        s.pop();
        if (x < minEle)
        {
            int temp = x;
            x = minEle;
            minEle = 2 * minEle - temp;
        }
    }
    return x;
}

/*push element x into the stack*/
void _stack::push(int x)
{
    if (s.size() == 0)
    {
        s.push(x);
        minEle = x;
    }
    else
    {
        if (minEle > x)
        {
            s.push(2 * x - minEle);
            minEle = x;
        }
        else
            s.push(x);
    }
}
