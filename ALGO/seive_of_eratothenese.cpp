#include<iostream>
#include<math.h>

using namespace std;

bool prime[1000000000];

void seive_of_eratothenese(int m, int n){
    int lim = floor(sqrt(n)), i;
    for(int p=2; p<=lim; p++){
        if(prime[p]==false){
            i=p+p;
            while(i<=n){
                prime[i]=true;
                i+=p;
            }
        }
    }
    if(m==1)
        m=2;
    for(int p=m; p<=n; p++){
        if(prime[p]==false)
            cout<<p<<endl;
    }
}

int main(){
    int q, m, n;
    cin>>q;
    while(q--){
        cin>>m>>n;
        seive_of_eratothenese(m,n);
        cout<<endl;
    }
    return 0;
}