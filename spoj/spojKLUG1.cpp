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

int maze[105][105],xadd[8]={-2,-2,-1,-1,1,1,2,2},yadd[8]={-1,1,-2,2,-2,2,-1,1},n,m;

bool isValid(int x,int y){
    return (x>=0 && x<n) && (y>=0 && y<m) && maze[x][y]==0;
}
int main(){
	int sx,sy;
	iin2(n,m);
	LOOP(0,n-1,i){
        LOOP(0,m-1,j){
            iin1(maze[i][j]);
        }
	}
	iin2(sx,sy);
	sx-=1,sy-=1;
	int ans = 0;
	for(int i=0;i<8;i++){
        if(isValid(sx+xadd[i],sy+yadd[i])){
            ans++;
        }
	}
    printf("%d",ans);
return 0;}
