#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t1,t2,t3,t4,ans,i,j,k,n,m,a[601],g[601][601],e[2001][2];
int main(){
	while (scanf("%d%d",&n,&m)!=EOF){
		memset(g,0,sizeof(g));ans=0;
		for (i=1;i<=n;i++) scanf("%d",&a[i]);
		for (i=1;i<=m;i++) scanf("%d%d",&e[i][0],&e[i][1]),g[e[i][0]][e[i][1]]=g[e[i][1]][e[i][0]]=1,ans=max(ans,a[e[i][0]]+a[e[i][1]]);
		for (i=1;i<=m;i++){
			t1=e[i][0];t2=e[i][1];
			for (j=1;j<=n;j++)
			 if (t1!=j&&t2!=j&&g[t1][j]&&g[t2][j]) ans=max(ans,a[t1]+a[t2]+a[j]);
		}
		for (i=1;i<=m;i++)
		 for (j=i+1;j<=m;j++){
		 	t1=e[i][0];t2=e[i][1];t3=e[j][0];t4=e[j][1];
		 	if (t1==t3||t1==t4||t2==t3||t2==t4) continue;
		 	if (g[t1][t3]&&g[t1][t4]&&g[t2][t3]&&g[t2][t4]) ans=max(ans,a[t1]+a[t2]+a[t3]+a[t4]);
		 }
		 printf("%d\n",ans);
	}
	return 0;
}