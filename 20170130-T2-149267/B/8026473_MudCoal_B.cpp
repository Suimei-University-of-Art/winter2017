#include<stdio.h>
#define N (100010)
int s[N];
int main(){	
	int n;
	scanf("%d",&n);
	for (int i=0,a;i<n;i++){
		scanf("%d",&a);
		s[a]++;
	}
	int cnt=0;
	for (int i=1;i<N;i++){
		if (s[i]>1) cnt+=s[i]-1;
	}
	printf("%d\n",n-cnt-(cnt&1));
}