#include<iostream>
#include<math.h>

using namespace std;

bool kaprekar(int n){
    long long int num=n,n_num=0,n_sqr=0,power=1;
    unsigned long long int sqr=num*num,l,r;
    while(num!=0){
        num=num/10;
        n_num++;
        power=power*10;
    }
    while(sqr!=0){
        sqr=sqr/10;
        n_sqr++;
        //cout<<"bla"<<endl;
    }
    num=n;
    sqr=num*num;
    l=sqr/power;
    r=sqr-l*power;
    if(l+r==n)
        return true;
    return false;
}

int main(){
    int p,q,i;
    bool valid=false;
    cin>>p>>q;
    for(i=p;i<=q;i++){
        if (kaprekar(i)){
            cout<<i<<" ";
            valid=true;
        }
    }
    if(valid==false)
        cout<<"INVALID RANGE";
    return 0;
}