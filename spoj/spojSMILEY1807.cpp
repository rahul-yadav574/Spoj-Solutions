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

string seq;
int dp[1000010][20];
int solve(int idx,int mask){
    if(idx==seq.length()){
        if(mask==15){
            return 0;
        }
        return INT_MIN;
    }

    if(dp[idx][mask]!=-1){return dp[idx][mask];}

    if(mask==0){
        if(seq[idx]=='1'){
            return dp[idx][mask]=max(1+solve(idx+1,1),solve(idx+1,0));
        }
        return dp[idx][mask]=solve(idx+1,0);
    }

    if(mask==1){
        if(seq[idx]=='1'){
            return dp[idx][mask]=max(1+solve(idx+1,1),solve(idx+1,1));
        }

        if(seq[idx]=='8'){
            return dp[idx][mask]=max(1+solve(idx+1,3),solve(idx+1,1));
        }
        return dp[idx][mask]=solve(idx+1,1);
    }

    if(mask==3){
        if(seq[idx]=='8'){
            return dp[idx][mask]=max(1+solve(idx+1,3),solve(idx+1,3));
        }

        if(seq[idx]=='0'){
            return dp[idx][mask]=max(1+solve(idx+1,7),solve(idx+1,3));
        }
         return solve(idx+1,3);
    }

    if(mask==7){

        if(seq[idx]=='0'){
            return dp[idx][mask]=max(1+solve(idx+1,7),solve(idx+1,7));
        }

        if(seq[idx]=='7'){
            return dp[idx][mask]=max(1+solve(idx+1,15),solve(idx+1,7));
        }
         return solve(idx+1,7);
    }

    if(mask==15){
        if(seq[idx]=='7'){
            return dp[idx][mask]=1+solve(idx+1,15);
        }
        return dp[idx][mask]=solve(idx+1,15);
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin>>seq;
    memset(dp,-1,sizeof(dp));
    int ans = solve(0,0);
    if(ans<=0){
        cout<<0;
    }else{
        cout<<ans;
    }
return 0;}
