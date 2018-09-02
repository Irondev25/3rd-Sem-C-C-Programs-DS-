#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    char str[30], str2[500];
    //using the setw manipulator you can adjust the input
    //in a variable to prevent crash
    cin>>setw(4)>>str;
    cout<<str<<endl;
    //using the cin.get function you can specify the 
    //max_length(to prevent overflow) and the deliminator
    cin.get(str2, 500, '$');
    cout<<str2;
    return 0;
}