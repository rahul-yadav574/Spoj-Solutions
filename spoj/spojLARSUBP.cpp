/*
Pretty Kind , Pretty Smart.
*/
#include<stdio.h>
#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<map>
#include<list>
#include<climits>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define pii pair<int,int>
#define iin1(a) scanf("%d",&a)
#define LOOP(s,t,i) for(int i=s;i<=t;i++)
#define iin2(a,b) scanf("%d%d",&a,&b)
#define iin3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define iin4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define pll pair<ll,ll>
typedef long long ll;
int dp[10010][20];
char num[10010];
int MAXX;
int solve(int idx,int prev){
    //cout<<"yah"<<endl;
    if(idx==MAXX){return 0;}
    if(prev!=-1){
        if(dp[idx][prev]!=-1){return dp[idx][prev]%MOD;}
    }
    if(num[idx]-'0' >prev){
        return dp[idx][prev]=(1+solve(idx+1,num[idx]-'0')%MOD+solve(idx+1,prev)%MOD)%MOD;
    }
    return dp[idx][prev]=solve(idx+1,prev);
}

int main(){
	int tc,cas=1;
	iin1(tc);
	while(tc--){
        scanf("%s",num);
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        MAXX = strlen(num);
        printf("Case %d: %d\n",cas++,solve(0,-1));
	}
return 0;}
