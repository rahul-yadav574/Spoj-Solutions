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

vector<int> graph[10005];
int visited[10005],parent[10005],ti[10005],first[10005],points[10005];
void ini(int n){

    for(int i=1;i<=n;i++){
        points[i]=0;
        graph[i].clear();
        visited[i]=0;
        parent[i]=-1;
        ti[i]=-1;
        first[i]=-1;
    }
}

int ans,tim;
int dfs(int u){

    visited[u]=1;
    ti[u]=first[u]=++tim;
    int child=0;
    for(int i=0;i<graph[u].size();i++){
        int v = graph[u][i];

        if(!visited[v]){
            parent[v]=u;
            child+=1;
            dfs(v);

            first[u]=min(first[u],first[v]);

            if(parent[u]==-1 && child>1 &&!points[u]){
                ans+=1;
                points[u]=1;

            }
            if(parent[u]!=-1 && first[v]>=ti[u] &&!points[u]){
                ans+=1;
                points[u]=1;
            }
        }
        else if (v!=parent[u]){
            first[u]=min(first[u],ti[v]);
        }
    }

}
int main(){

	int n,m,a,b;
	iin2(n,m);
	while(n!=0 && m!=0){
        ini(n);
        ans=0;
        while(m--){
            iin2(a,b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
        dfs(1);
        printf("%d\n",ans);
        iin2(n,m);
	}



return 0;}
