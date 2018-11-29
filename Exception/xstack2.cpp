#include <iostream>

using namespace std;
const int MAX = 3;

class Stack
{
    int st[MAX];
    int top;

  public:
    class Full
    {
    };
    class Empty
    {
    };
    Stack()
    {
        top = -1;
    }
    void push(int var)
    {
        if (top >= MAX - 1)
            throw Full();
        st[++top] = var;
    }
    int pop()
    {
        if (top < 0)
            throw Empty();
        return st[top--];
    }
};

int main()
{
    Stack s1;

    try
    {
        s1.push(11);
        s1.push(22);
        s1.push(33);
        //s1.push(44);
        cout << "1 : " << s1.pop() << endl;
        cout << "2 : " << s1.pop() << endl;
        cout << "3 : " << s1.pop() << endl;
        cout << "4 : " << s1.pop() << endl;
    }
    catch (Stack::Full)
    {
        std::cout << "Stack Full" << '\n';
    }
    catch (Stack::Empty)
    {
        cout << "Stack Empty" << "\n";
    }
    cout << "Arive here after catch" << endl;
    return 0;
}