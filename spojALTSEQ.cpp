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

int arr[5010],MAXX,dp[5010][5010];
bool canPlaced(int a,int b){
    return (a>0&&b<0&&a<-b)||(a<0&&b>0&&-a<b);
}
int  solve(int idx,int prev){
    if(idx==MAXX+1){return 0;}
    if(dp[idx][prev]!=-1){return dp[idx][prev];}

    if(prev!=0){
        if(canPlaced(arr[prev],arr[idx])){
            return dp[idx][prev]=max(solve(idx+1,prev),1+solve(idx+1,idx));
        }
        return dp[idx][prev]=solve(idx+1,prev);
    }
    return dp[idx][prev]=max(1+solve(idx+1,idx),solve(idx+1,prev));


}
int main(){
	int n;
	iin1(n);
	MAXX=n;
	LOOP(1,n,i){
        iin1(arr[i]);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d",solve(1,0));
return 0;}
