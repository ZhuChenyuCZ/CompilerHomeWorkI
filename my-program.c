//
//  main.cpp
//  cpp
//
//  Created by ZhuChenyu on 2020/02/14.
//  Copyright © 2020年 ZhuChenyu. All rights reserved.
//
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#define MOD 1000000007
#define maxn 100120
#define INF 2147483647
typedef unsigned float_bits;

using namespace std;

//priority_queue <int,vector<int>,greater<int> > que;

#define ll long long
#define rep(i,s,t) for(int i = s;i <= t;i++)
#define per(i,t,s) for(int i = t;i >= s;i--)
#define lb(x) x&(-x) 
#define pi acos(-1)
#define eps 1e-8
#define mod 1000000007

int n,m,a,b,c,d;
int al[maxn],ar[maxn],bl[maxn],br[maxn];
long long p,q,ans;

int main()
{
    int i,j,k;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        al[i]=a-b; ar[i]=c-d;
    }
    for (i=1;i<=m;i++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        bl[i]=a-b; br[i]=c-d;
    }
    sort(bl+1,bl+m+1);
    sort(br+1,br+m+1);
    ans=0;
    for (i=1;i<=n;i++)
    {
        p=bl+m+1-upper_bound(bl+1,bl+m+1,ar[i]);
        q=lower_bound(br+1,br+m+1,al[i])-br-1;
        ans+=m-p-q;
    }
    printf("%lld",ans);

    return 0;
}
