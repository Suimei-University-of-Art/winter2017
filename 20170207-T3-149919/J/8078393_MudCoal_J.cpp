#include<cstdio>
typedef long long LL;
#define N (9)
#define M (280)
int ub,cnt[M],a[M][N],f[M][M],l[N];
LL g[N][M];
void init(int n){
    ub=1<<n;
    for (int i=1;i<ub;i++){
        cnt[i]=0;
        for (int k=1,j=1;j<=i;j<<=1,k++){
            if (j&i){
                a[i][cnt[i]++]=k;
            }
        }
    }
    for (int i=1;i<ub;i++){
        for (int j=1;j<ub;j++){
            if (cnt[i]>=cnt[j]){
                int ok=1;
                for (int k=0;k<cnt[j];k++){
                    if (a[i][k]>a[j][k]){
                        ok=0;
                        break;
                    }
                }
                f[i][j]=ok;
            }
        }
    }
}
int main(){
    int n,k;
    while (~scanf("%d",&k)){
        for (int i=1;i<=k;i++){
            scanf("%d",l+i);
        }
        scanf("%d",&n);
        //printf("%d %d\n",n,k);
        init(n);
        for (int i=1;i<ub;i++){
            if (cnt[i]==k){
                g[1][i]=1;
            }
            else {
                g[1][i]=0;
            }
        }
        //printf("%d %d\n",n,k,l[1]);
        for (int i=2,x;i<=l[1];i++){
            x=1;
            //printf("%d\n",i);
            for (int j=1;j<=k;j++){
                if (l[j]>=i){
                    x=j;
                }
                else {
                    break;
                }
            }
            //printf("%d %d\n",i,x);
            for (int j=1;j<ub;j++){
                g[i][j]=0;
                if (cnt[j]==x){
                    for (int pre=1;pre<ub;pre++){
                        if (f[pre][j]){
                            g[i][j]+=g[i-1][pre];
                        }
                    }
                }
                //printf("%d %d %d\n",i,j,g[i][j]);
            }
        }
        LL ans=0;
        for (int i=1;i<ub;i++){
            ans+=g[l[1]][i];
        }
        printf("%lld\n",ans);
    }
}