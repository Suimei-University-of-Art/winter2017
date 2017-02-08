#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[101];
int i,j,k,y,m,d,ans,a[13];
int main(){
	a[1]=a[3]=a[5]=a[7]=a[8]=a[10]=a[12]=31;
	a[4]=a[6]=a[9]=a[11]=30;
	while (scanf("%s",s)!=EOF){
		for (y=0,i=0;i<4;i++) y=y*10+s[i]-'0';
		for (i=5,m=0;i<=6;i++) m=m*10+s[i]-'0';
		for (i=8,d=0;i<=9;i++) d=d*10+s[i]-'0';
		ans=11;
		for (i=1700;;i+=100){
			if (i%400==0) continue;
			if (i>y||i==y&&m<=2) break;
			ans++;
		}
		d+=ans;
		if (y%4==0&&y%100!=0||y%400==0) a[2]=29;else a[2]=28;
		while (d>a[m]){
			d-=a[m];
			if (m==12){
				y++;m=1;
				if (y%4==0&&y%100!=0||y%400==0) a[2]=29;else a[2]=28;
			}else m++;
		}
		printf("%d-%02d-%02d\n",y,m,d);
	}
	return 0;
}