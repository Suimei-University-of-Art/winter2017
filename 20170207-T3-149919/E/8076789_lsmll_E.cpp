#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1000000000;
char s[20001];
int ans,i,j,k,n,m,num,a[3001],f[3001][3001],w[3001],g[3001][2];
void build(int p,int l,int r){
	int i,k;
	if (l>=r-2){
		if (l==r-1) a[p]=0;else a[p]=1,num++;
		g[p][0]=g[p][1]=0;w[p]=1;
		return;
	}
	for (i=l+2,k=1;k;i++){
		if (s[i]=='(') k++;
		if (s[i]==')') k--;
	}
	g[p][0]=++n;build(n,l+1,i-1);
	g[p][1]=++n;build(n,i,r-1);
	w[p]=w[g[p][0]]+w[g[p][1]];
}
int work(int x,int y){
	if (f[x][y]!=-1) return f[x][y];
	if (!g[x][0]) return f[x][y]=max(0,a[x]-y);
	int l=g[x][0],r=g[x][1];
	if (w[l]>w[r]) swap(l,r);
	if (w[l]+1<y-w[l]) return f[x][y]=inf;
	if (y&1){
		f[x][y]=min(inf,work(l,y/2)+work(r,y/2+1));
		if (w[l]>=y/2+1) f[x][y]=min(f[x][y],work(l,y/2+1)+work(r,y/2));
	}else f[x][y]=min(work(l,y/2)+work(r,y/2),inf);
	return f[x][y];
}
int main(){
	while (scanf("%s",s)!=EOF){
		m=strlen(s);n=1;num=0;
		build(1,0,m-1);
		for (i=1;i<=n;i++)
		 for (j=0;j<=num;j++) f[i][j]=-1;
		ans=work(1,num);
		if (ans==inf) puts("impossible");else printf("%d\n",ans);
	}
	return 0;
}