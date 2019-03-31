#include<iostream>
#include<math.h>

using namespace std;

void printPowerset(char *set, int set_size){
    unsigned int pow_set_size=1ll<<set_size;
    int counter,j;
    for(counter=0;counter<pow_set_size;counter++){
        for(j=0;j<set_size; j++){
            if(counter&(1<<j)){
                cout<<set[j];
            }
        }
        cout << endl;
    }
}

int main(){
    char set[]={'a','b','c','d','e','f'};
    printPowerset(set,6);
    return 0;
}