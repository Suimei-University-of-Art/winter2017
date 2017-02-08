#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ans,i,j,k,n,m,a[11],b[11][11],p[11];
void work(int x,int y){
	int i;
	if (x==1&&y>a[1]){
		ans++;return;
	}
	for (i=max(b[x][y-1],b[x-1][y]+1);i<=m-(p[y]-x);i++)
	 if (x==n||y>a[x+1]) b[x][y]=i,work(1,y+1);else b[x][y]=i,work(x+1,y);
}
int main(){
	while (scanf("%d",&n)!=EOF){
		for (i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d",&m);memset(b,0,sizeof(b));
		for (i=1;i<=a[1];i++)
		 for (p[i]=n;a[p[i]]<i;p[i]--);
		ans=0;work(1,1);
		printf("%d\n",ans);
	}
	return 0;
}