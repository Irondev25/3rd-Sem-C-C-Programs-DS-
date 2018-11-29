#include<iostream>
#include<stdlib.h>

using namespace std;

int main(int argc, char const *argv[])
{
    const unsigned long SIZE = 100000;
    char* ptr;
    try{
        ptr = new char[SIZE];
    }
    catch(bad_alloc){
        cout<<"\nbad_alloc exception: can't allocate memory.\n";
        return(1);
    }
    delete[] ptr;
    cout<<"\nMemory Use successfull!!";
    return 0;
}
