#include <iostream>

using namespace std;

class stack
{
    int arr[10000];
    int tos;

  public:
    stack()
    {
        tos = -1;
    }

    void push(int data)
    {
        arr[++tos] = data;
    }

    void pop()
    {
        if(tos>=0)
            tos--;
    }

    int top()
    {
        return arr[tos];
    }

    int size()
    {
        return (tos + 1);
    }

    bool empty()
    {
        if (tos == -1)
        {
            return true;
        }
        return false;
    }
    int getTop(){
        return arr[0];
    }
};

int main()
{
    stack s1, s2;
    double qno, data, top = 0;
    int ch;
    cin >> qno;
    while (qno)
    {
        cin >> ch;
        switch (ch)
        {
        case 1:
            cin >> data;
            s1.push(data);
            if (s1.size() == 1)
                top = s1.top();
            break;
        case 2:
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
            if (!s2.empty())
                top = s2.top();
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            break;
        case 3:
            cout << s1.getTop()<<endl;
            break;
        }
        --qno;
    }
    return 0;
}