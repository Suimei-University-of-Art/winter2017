#include<cstdio>
#define N (2010)
#define M (4000010)
typedef int arr[N<<1];
arr ax,ay,az,nxt,v,be,w,cnt,lca,d,pree;
int a[N][N],dis[N][N],vst[N],de[N][N],n;
void adde(int x, int y, int z, int id){
    ax[id]=x;
    ay[id]=y;
    az[id]=z;
    nxt[id<<=1]=be[x];
    v[id]=y;
    w[id]=z;
    be[x]=id;
    nxt[id|=1]=be[y];
    v[id]=x;
    w[id]=z;
    be[y]=id;
}
void dfs(int fa, int now){
    vst[now]=1;
    for (int j=be[now];j;j=nxt[j]){
        if (!vst[v[j]]){
            d[v[j]]=d[now]+w[j];
            dfs(now,v[j]);
        }
    }
    for (int i=1;i<=n;i++){
        if (vst[i]){
            dis[i][now]=dis[now][i]=d[i]+d[now]-(d[lca[i]]<<1);
        }
    }
    for (int i=1;i<=cnt[now];i++){
        lca[de[fa][++cnt[fa]]=de[now][i]]=fa;
    }
}
int main(){
    int fst=1;
    while (~scanf("%d",&n)){
        if (!fst) printf("\n");
        fst=0;
        for (int i=1;i<=n;i++){
            be[i]=vst[i]=0;
            lca[i]=de[i][cnt[i]=1]=i;
            d[i]=M;
        }
        for (int i=1,id=1;i<=n;i++){
            for (int j=1;j<=n;j++,id++){
                scanf("%d",a[i]+j);
            }
        }
        d[1]=0;
        int ed=0;
        for (int i=1;i<=n;i++){
            int p=0;
            for (int j=1;j<=n;j++){
                if (!vst[j]&&(!p||d[j]<d[p])){
                    p=j;
                }
            }
            vst[p]=1;
            if (p!=1){
               // printf("%d %d %d\n",pree[p],p,d[p]);
                adde(pree[p],p,d[p],++ed);
            }
            for (int j=1;j<=n;j++){
                if (!vst[j]&&a[p][j]<d[j]){
                    d[j]=a[p][j];
                    pree[j]=p;
                }
            }
        }
        for (int i=1;i<=n;i++){
            vst[i]=0;
        }
        int fd=0;
        cnt[0]=d[1]=0;
        dfs(0,1);
        /*for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                printf("%d%c",dis[i][j]," \n"[j==n]);
            }
        }*/
        int mm=1000001,px=0,py;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                if (a[i][j]<dis[i][j]&&a[i][j]<mm){
                    mm=a[i][j];
                    px=i,py=j;
                }
            }
        }
        if (px){
            adde(px,py,mm,n);
        }
        else {
            adde(1,2,1000000,n);
        }
        for (int i=1;i<=n;i++){
            printf("%d %d %d\n",ax[i],ay[i],az[i]);
        }
    }
}