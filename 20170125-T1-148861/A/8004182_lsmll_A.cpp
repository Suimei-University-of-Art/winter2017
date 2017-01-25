#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int i,j,k,n,m,a,b,c,d;
int main(){
	while (scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
		printf("%d\n",max(a*b,c*d));
	}
	return 0;
}