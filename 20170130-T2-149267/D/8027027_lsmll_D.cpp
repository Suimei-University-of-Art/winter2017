#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int i,j,k,n,m,b[200001],l,r,lim,t,p1,p2;
int main(){
	while (scanf("%d%d",&n,&m)!=EOF){
		memset(b,0,sizeof(b));lim=trunc(sqrt(m));t=m/(lim+1);
		for (i=1;i<=n;i++){
			scanf("%d%d",&l,&r);
			k=r-l+1;b[1]++;b[k+1]--;
			for (j=k+1;j<=lim;j++)
			 if ((l/j!=r/j||l%j==0||r%j==0)&&r/j>t) b[j]++,b[j+1]--;
			for (j=1;j<=t;j++){
				p1=l/j;p2=r/j;
				if (l%j) p1++;
				p1=max(p1,k+1);
				if (p1<=p2) b[p1]++,b[p2+1]--;
			}
		}
		for (k=0,i=1;i<=m;i++) k+=b[i],printf("%d\n",k);
	}
	return 0;
}