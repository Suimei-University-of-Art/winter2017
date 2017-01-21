#include<stdio.h>
#define N (100010)
typedef long long LL;
int a[N];
char b[N][2];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%s",a+i,b[i]);
	}
	scanf("%d",a+n);
	LL ans1=a[1];
	for (int i=1;i<n;i++) ans1+=b[i][0]=='+'?a[i+1]:-a[i+1];
	LL temp=ans1;
	LL cur=a[n],tot=0;
	for (int i=n-1;i;i--){
		if (b[i][0]=='-'){
			temp=temp+a[i+1];
			if (temp-cur+tot>ans1) ans1=temp-cur+tot;
			tot+=cur;
			cur=0;
		}
		else {
			temp=temp-a[i+1];
		}
		cur+=a[i];
	}
	printf("%lld\n",ans1);
}
