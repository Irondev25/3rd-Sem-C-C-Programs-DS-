#include<iostream>
#include<iomanip>


using namespace std;

int main(){
    int pop1=2425785, pop2=47, pop3=9761;
    char str[20], str2[20];
    cout<<setw(8)<<"Location"<<setw(12)<<"Population"<<endl;
    cout<<setw(8)<<"Portcity"<<setw(12)<<pop1<<endl;
    cout<<setw(8)<<"Hightown"<<setw(12)<<pop2<<endl;
    cout<<setw(8)<<"Lowville"<<setw(12)<<pop3<<endl;
    return 0;
}