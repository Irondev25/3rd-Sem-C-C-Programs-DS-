#include<iostream>
#include<math.h>
#include<string.h>

using namespace std;

int main(){
    short int i,j,k, len;
    double a,b;
    bool terminate;
    char str[82], str2[82], matrix[9][9]={'\0'}, prev='a';
    cin.getline(str,82);
    j=0;
    for(i=0; str[i]!='\0'; i++){
        if(str[i]!=' '){
            str2[j]=str[i];
            j++;
        }
    }
    str2[j]='\0';
    cout << strcmp(str, str2) << endl;
    len=j;
    a=floor(sqrt(len));
    b=ceil(sqrt(len));
    if(a*b<len)
        a++;
    if(a!=b){
        if(a*a>=len){
            b=a;
        }
    }
    k=0;
    terminate=false;
    for(i=0; i<a; i++){
        for(j=0; j<b; j++){
            if(str2[k]!='\0'){
                matrix[i][j] = str2[k];
                k++;
            }
            else{
                terminate=true;
                break;
            }
        }
        if(terminate==true)
            break;
    }
    for(j=0;j<b; j++){
        for(i=0; i<a; i++){
            if(matrix[i][j]!='\0'){
                cout << matrix[i][j];
            }
            else
            {
                continue;
            }
            
        }
        cout<<" ";
    }
    return 0;
}