#include<cstdio>
#include<algorithm>
using namespace std;
#define N (910)
int s[N],f[N][N],a[N],b[N],lst[N];
int main(){
    int v,e;
    while (~scanf("%d%d",&v,&e)){
        for (int i=1;i<=v;i++){
            scanf("%d",s+i);
            for (int j=1;j<=v;j++){
                f[i][j]=0;
            }
        }
        for (int i=1;i<=e;i++){
            scanf("%d%d",a+i,b+i);
            f[a[i]][b[i]]=f[b[i]][a[i]]=1;
        }
        int ans=0;
        for (int i=1,cl,se;i<=e;i++){
            cl=0,se=s[a[i]]+s[b[i]];
            for (int j=1;j<=v;j++){
                if (j!=a[i]&&j!=b[i]&&f[j][a[i]]&&f[j][b[i]]){
                    ans=max(se+s[j],ans);
                    lst[cl++]=j;
                }
            }
            for (int j=0;j<cl;j++){
                for (int k=j+1;k<cl;k++){
                    if (f[lst[j]][lst[k]]){
                        ans=max(s[lst[j]]+s[lst[k]]+se,ans);
                    }
                }
            }
            ans=max(ans,se);
        }
        printf("%d\n",ans);
    }
}