#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int lim=1005,mm=1000000007;
int i,j,k,n,m,l1,l2,r1,r2,c[1101][1101],f[1101][1101],fac[1101],faci[1101];
ll pw(ll b,ll p){
	ll res=1;
	for (;p;p>>=1,b=b*b%mm)
	 if (p&1) res=res*b%mm;
	return res;
}
ll work(ll n,ll m,ll x){
	ll res=1,i;
	for (i=1;i<=x;i++) res=res*c[n-(i-1)*m][m]%mm;
	return res*faci[x]%mm;
}
int main(){
	for (i=0;i<=lim;i++)
	 for (c[i][0]=c[i][i]=1,j=1;j<i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mm;
	for (i=1,fac[0]=faci[0]=1;i<=lim;i++) fac[i]=fac[i-1]*(ll)i%mm,faci[i]=pw(fac[i],mm-2);
	while (scanf("%d%d%d%d%d",&n,&l1,&r1,&l2,&r2)!=EOF){
		memset(f,0,sizeof(f));
		f[l1-1][0]=1;
		for (i=l1;i<=r1;i++){
			for (j=0;j<=n;j++) f[i][j]=f[i-1][j];
			for (j=l2;j<=r2;j++)
			 for (k=0;k<=n-i*j;k++)
			  f[i][k+i*j]=(f[i][k+i*j]+(ll)f[i-1][k]*work(n-k,i,j)%mm)%mm;
		}
		printf("%d\n",f[r1][n]);
	}
	return 0;
}