#include<cstdio>
#define N (200010)
int nor[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int tot,sa[N],sb[N],a[N],b[N];
int julia(int y, int m, int d){
    return sa[(y-1)*12+m-1]+d;
}
void init(void){
    int cura=0,curb=0;
    for (int i=1;i<=10000;i++){
        for (int j=1;j<=12;j++){
            tot++;
            if (j!=2){
                sa[tot]=cura+=a[tot]=nor[j];
                sb[tot]=curb+=b[tot]=nor[j];
            }
            else {
                sa[tot]=cura+=a[tot]=28+(i%4==0);
                sb[tot]=curb+=b[tot]=28+(i%4==0&&i%100!=0||i%400==0);
            }
        }
    }
    /*for (int i=1;i<=48;i++){
        printf("%d %d\n",i,b[i]);
    }*/
}
void getGre(int x){
    int l=0,r=tot+1;
    while (l+1<r){
        int mid=l+r>>1;
        if (sb[mid]<x){
            l=mid;
        }
        else {
            r=mid;
        }
    }
    printf("%04d-%02d-%02d\n",(r-1)/12+1,(r-1)%12+1,x-sb[l]);
}
int main(){
    init();
    int y,m,d;
    while (~scanf("%d-%d-%d",&y,&m,&d)){
        int t=julia(y,m,d);
        getGre(t-1);
    }
}