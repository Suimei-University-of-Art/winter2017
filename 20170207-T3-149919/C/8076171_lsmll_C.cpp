#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,d,i,j,k,t1,t2;
int gcd(int a,int b){
	int r;
	do{
		r=a%b;a=b;b=r;
	}while (r);
	return a;
}
int main(){
	while (scanf("%d%d%d",&d,&a,&b)!=EOF){
		t1=a*d;t2=b-a;i=gcd(t1,t2);
		printf("%d/%d\n",t1/i,t2/i);
	}
	return 0;
}