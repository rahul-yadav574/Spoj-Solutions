/*
Pretty Kind , Pretty Smart.
*/
#include<stdio.h>
#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<list>
#include<climits>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define MAX 99999999
#define MOD 1000000007
#define pii pair<int,int>
#define iin1(a) scanf("%d",&a)
#define LOOP(s,t,i) for(int i=s;i<=t;i++)
#define iin2(a,b) scanf("d",&a,&b)
#define iin3(a,b,c) scanf("d%d",&a,&b,&c)
#define iin4(a,b,c,d) scanf("dd",&a,&b,&c,&d)
#define pll pair<ll,ll>
typedef long long ll;
int arr[20],cost[20];
int dp[1<<17][200],n;

int solve(int mask,int last,int iter){

    if(iter==n){return 0;}
    if(dp[mask][last]!=-1){return dp[mask][last];}
    dp[mask][last]=MAX;
    for(int i=0;i<n;i++){
        if(!(mask&(1<<i))){
                dp[mask][last] = min(dp[mask][last],(abs(arr[i]-arr[last])*cost[iter])+solve(mask+(1<<i),i,iter+1));
        }
    }
    return dp[mask][last];
}
int main(){
	int tc;
	iin1(tc);
	while(tc--){
        iin1(n);
        memset(dp,-1,sizeof(dp));
        LOOP(0,n-1,i){iin1(arr[i]);}
        LOOP(0,n-1,i){iin1(cost[i]);}
        cost[0]=0;

        printf("%d\n",solve(0,0,0));
	}
return 0;}
