#include<stdio.h>
#include<stdlib.h>

float mod(float num, float ans){
    float tol = ans*ans-num;
    if(tol<0)
        return -tol;
    return tol;
}

float newton_sqrt(float num,float ans, float tol){
    float curr_tol = mod(num, ans);
    if(curr_tol<=tol){
        printf("%f\n", curr_tol);
        return ans;
    }
    return newton_sqrt(num, ans-(((ans*ans)-num)/(2*ans)), tol);
}

int main(){
    printf("%f", newton_sqrt(5,5,0.00001));
    return 0;
}