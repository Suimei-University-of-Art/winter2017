#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
ll a[200001],d[200001],tmp;
int i,j,k,n,m,b[200001],q[200001],t1,t2;
struct scmp{
	bool operator() (int x,int y){
		return a[x]>a[y]||a[x]==a[y]&&x<y;
	}
};
set<int,scmp> h;
set<int,scmp>::iterator it;
set<int> h1,h2;
set<int>::iterator p1,p2;
int main(){
	while (scanf("%d%d",&n,&m)!=EOF){
		h.clear();h1.clear();h2.clear();
		for (i=1;i<=n;i++) scanf("%d",&b[i]);
		for (i=1;i<n;i++) a[i]=b[i]+b[i+1],d[i]=b[i],h.insert(i),h1.insert(i),h2.insert(-i);
		for (i=k=1;i<n;i++){
			it=h.begin();j=*it;h.erase(j);h1.erase(j);h2.erase(-j);q[i]=j;
			p1=h1.lower_bound(j);p2=h2.lower_bound(-j);t1=-(*p2);t2=*p1;
			if (a[j]<m){
				k=0;break;
			}
			if (p1!=h1.end()){
				h.erase(t2);tmp=a[j]-d[t2];
				a[t2]+=tmp;d[t2]+=tmp;h.insert(t2);
			}
			if (p2!=h2.end()){
				h.erase(t1);
				a[t1]+=a[j]-d[j];h.insert(t1);
			}
		}
		if (!k) puts("Impossible");else{
			puts("Possible");
			for (i=n-1;i;i--) printf("%d\n",q[i]);
		}
	}
	return 0;
}