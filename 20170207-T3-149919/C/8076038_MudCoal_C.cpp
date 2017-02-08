#include<stdio.h>
int gcd(int x, int y){
    while (y){
        int t=x%y;
        x=y;
        y=t;
    }
    return x;
}
int main(){
    int a,b,c;
    while (~scanf("%d%d%d",&a,&b,&c)){
        int x=a*b;
        int y=c-b;
        int z=gcd(x,y);
        printf("%d/%d\n",x/z,y/z);
    }
}