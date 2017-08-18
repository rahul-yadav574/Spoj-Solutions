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

int arr[205];
int dp[205][205][205],MAXX;

int max3(int a,int b,int c){
    return max(a,max(b,c));
}
int solve(int idx,int white,int black){
    if(idx==MAXX+1){
        return 0;
    }

    if(dp[idx][white][black]!=-1){return dp[idx][white][black];}

    if(white!=0 && black!=0){
        if(arr[idx]>arr[black] && arr[idx]<arr[white]){
            return dp[idx][white][black]=max3(1+solve(idx+1,idx,black),1+solve(idx+1,white,idx),solve(idx+1,white,black));
        }
        if(arr[idx]>arr[black]){
            return dp[idx][white][black]=max(1+solve(idx+1,white,idx),solve(idx+1,white,black));
        }
        if(arr[idx]<arr[white]){
            return dp[idx][white][black]=max(1+solve(idx+1,idx,black),solve(idx+1,white,black));
        }
        return dp[idx][white][black]=solve(idx+1,white,black);
    }
    if(black!=0){
        if(arr[idx]>arr[black]){
            return dp[idx][white][black]=max3(1+solve(idx+1,white,idx),1+solve(idx+1,idx,black),solve(idx+1,white,black));
        }
        return dp[idx][white][black]=max(1+solve(idx+1,idx,black),solve(idx+1,white,black));

    }
    if(white!=0){
        if(arr[idx]<arr[white]){
            return dp[idx][white][black]= max3(solve(idx+1,white,black),1+solve(idx+1,idx,black),1+solve(idx+1,white,idx));
        }
        return dp[idx][white][black]=max(solve(idx+1,white,black),1+solve(idx+1,white,idx));
    }

    return dp[idx][white][black]=max3(1+solve(idx+1,idx,black),1+solve(idx+1,white,idx),solve(idx+1,white,black));
}
int main(){
    ios_base::sync_with_stdio(false);
	int n;
	iin1(n);
	while(n!=-1){
        MAXX=n;
        LOOP(1,n,i){
            iin1(arr[i]);
        }
        memset(dp,-1,sizeof(dp));
        cout<<MAXX-solve(1,0,0)<<endl;
        iin1(n);
	}
return 0;}
