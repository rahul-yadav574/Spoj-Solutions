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
#define MOD 1000000007
#define pii pair<int,int>
#define iin1(a) scanf("%d",&a)
#define LOOP(s,t,i) for(int i=s;i<=t;i++)
#define iin2(a,b) scanf("%d%d",&a,&b)
#define iin3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define iin4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define pll pair<ll,ll>
typedef long long ll;

char grid[105][105];
int sx,sy,n,m,visited[105][105],k;

bool isValid(int i,int j){
    return i>=1&&i<=n && j>=1&&j<=m&&grid[i][j]!='*'&&!visited[i][j];
}
bool dfs(int i,int j,int tu){
    if(i==sx && j==sy && tu!=k){
        return tu<=0;
    }

    bool chk = 0;
    if(isValid(i+1,j)){
        visited[i+1][j]=1;
        chk|=dfs(i+1,j,tu-1);
        visited[i+1][j]=0;
    }
    if(isValid(i-1,j)){
        visited[i-1][j]=1;
        chk|=dfs(i-1,j,tu-1);
        visited[i-1][j]=0;
    }
    if(isValid(i,j-1)){
        visited[i][j-1]=1;
        chk|=dfs(i,j-1,tu-1);
        visited[i][j-1]=0;
    }
    if(isValid(i,j+1)){
        visited[i][j+1]=1;
        chk|=dfs(i,j+1,tu-1);
        visited[i][j+1]=0;
    }

    return chk;
}
int main(){
	iin4(n,m,k,sx);
	iin1(sy);
	LOOP(1,n,i){
        LOOP(1,m,j){
            cin>>grid[i][j];
        }
	}
	if(dfs(sx,sy,k)){printf("YES\n");
	}else{printf("NO\n");}
return 0;}
