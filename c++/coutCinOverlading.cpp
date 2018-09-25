#include <iostream>

using namespace std;

class Time
{
    int hrs;
    int min;
    int sec;

  public:
    Time() : hrs(0), min(0), sec(0) {}
    void ShowTime();
    Time operator+(Time);
    friend ostream &operator<<(ostream &out, Time &a);
    friend istream &operator>>(istream &in, Time &a);
};

ostream &operator<<(ostream &out, Time &a)
{
    out << a.hrs << ":" << a.min << ":" << a.sec << endl;
    return out;
}

void Time::ShowTime()
{
    cout << this->hrs << ":" << this->min << ":" << this->sec << endl;
}

istream &operator>>(istream &in, Time &a)
{
    cout << "Hrs: ";
    in >> a.hrs;
    cout << "Min: ";
    in >> a.min;
    cout << "Sec: ";
    in >> a.sec;
    return in;
}

Time Time::operator+(Time B)
{
    Time temp;
    temp.hrs = this->hrs + B.hrs + (this->min + B.min) / 60;
    temp.min = (this->min + B.min) % 60 + (this->sec + B.sec) / 60;
    temp.sec = (this->sec + B.sec) % 60;
    return temp;
}

int main()
{
    Time t1, t2, t3;
    cout << "Enter Time:" << endl;
    cin >> t1;
    cout << "Enter Time again: " << endl;
    cin >> t2;
    t3 = t1 + t2;
    cout << t3;
    return 0;
}