#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef double ft;
char ch[11];
ft f[5001];
int i,j,k,n,m,a[5001],num;
int main(){
	while (scanf("%d%d",&num,&n)!=EOF){
		memset(a,0,sizeof(a));
		for (i=1;i<=num;i++){
			scanf("%s",ch);
			if (ch[0]=='1'||ch[0]=='J'||ch[0]=='Q'||ch[0]=='K') a[n]=10;
			if (ch[0]=='A') a[n]=11;
			if ('2'<=ch[0]&&ch[0]<='9') a[n]=ch[0]-'0';
			if (i<num) n+=a[n];
		}
		for (i=1;i<=n;i++) f[i]=((i<=10)?0.1:0);
		for (i=1;i<n;i++){
			if (a[i]){
				f[i+a[i]]+=f[i];
				continue;
			}
			for (j=2;j<=9;j++)
			 if (i+j<=n) f[i+j]+=f[i]/13;
			if (i+10<=n) f[i+10]+=f[i]*4/13;
			if (i+11<=n) f[i+11]+=f[i]/13;
		}
		printf("%.9f\n",f[n]);
	}
	return 0;
}