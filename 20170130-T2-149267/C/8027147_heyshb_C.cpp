#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int N,M;
int cnt,size[200010],maxe[200010],fa[200010],top[200010],p[200010];
int anc[200010][21];
int ufa[200010];
int find(int x){return ufa[x]==x?x:ufa[x]=find(ufa[x]);}

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)
	{
		top[i] = i;
		ufa[i] = i;
		p[i] = i;
		size[i] = 1;
	}
	int cnt = N;
	memset(fa,0,sizeof(fa));
	for (int i=1;i<=M;i++)
	{
		int L,R;
		scanf("%d%d",&L,&R);
		if (find(L) == find(R)) continue;
		//printf("connect %d %d\n",L,R);
		int p1 = p[find(L)], p2 = p[find(R)];
		ufa[find(L)] = find(R);
		cnt++;
		size[cnt] = size[p1] + size[p2];
		maxe[cnt] = i;
		fa[p1] = fa[p2] = cnt;
		//printf("GAO %d %d--->%d\n",p1,p2,cnt);
		p[find(L)] = cnt;
	}
	//for (int i=1;i<=cnt;i++)printf("%d:%d %d %d\n",i,fa[i],size[i],maxe[i]);
	for (int i=cnt;i>=1;i--)
	{
		anc[i][0] = fa[i];
		for (int j=1;j<=20;j++)
			anc[i][j] = anc[anc[i][j-1]][j-1];
	}
	maxe[0] = 100000000;
	/*
	for (int i=1;i<=cnt;i++)
	{
		for (int j=0;j<=2;j++)printf("%d ",anc[i][j]);
		puts("!");
	}*/
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int X,Y,Z,L,R,res,X0,Y0;
		scanf("%d%d%d",&X0,&Y0,&Z);
		L = 0, R = M;
		while(L<R-1)
		{
			int mid = (L+R)>>1,res;
			X = X0;
			Y = Y0;
			for (int j=20;j>=0;j--)
			{
				
				if (maxe[anc[X][j]]<=mid) 
				{
					
					//printf("Jump X %d %d->%d\n",j,X,anc[X][j]);
					X = anc[X][j];
				}
			}
			for (int j=20;j>=0;j--)
			{
				if (maxe[anc[Y][j]]<=mid) 
				{
					
					//printf("Jump Y %d %d->%d\n",j,Y,anc[Y][j]);
					Y = anc[Y][j];
				}
			}	
			
			if (X==Y) res = size[X];
			else res = size[X]+size[Y];
			
			//printf("%d %d %d %d\n",mid,X,Y,res);
			if (res >= Z)
				R = mid;
			else
				L = mid;
		}
		printf("%d\n",R);
	}
}