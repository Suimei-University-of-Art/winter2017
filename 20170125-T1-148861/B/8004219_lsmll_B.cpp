#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1111];
int i,j,k,n,m,a,b,c,d;
int main(){
	while (scanf("%d",&n)!=EOF){
		scanf("%s",s);
		for (k=i=j=0;i<n;i++){
			if (s[i]=='I') j++;else j--;
			k=max(j,k);
		}
		printf("%d\n",k);
	}
	return 0;
}