#include<iostream>

using namespace std;


long factorial(int);


int main(){
    int a;
    cout<<"Enter a number:\n";
    cin>>a;
    cout<<"Factorial of "<<a<<" is "<<factorial(a);
    return 0;
}