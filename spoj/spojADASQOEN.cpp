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
int has[26],n,m,dp[2100][2100];
string a,b;
int solve(int i,int j){
    if(i>=n || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){return dp[i][j];}

    if(a[i]==b[j]){
        return dp[i][j]=max(has[(a[i]-'a')]+solve(i+1,j+1),
                   max(solve(i+1,j),solve(i,j+1)));
    }
    return dp[i][j]=max(solve(i+1,j),solve(i,j+1));
}
int main(){
	iin2(n,m);
	LOOP(0,25,i){iin1(has[i]);}
	memset(dp,-1,sizeof(dp));
	cin>>a>>b;
	cout<<solve(0,0);
return 0;}
