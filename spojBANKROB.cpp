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
#define INF 100000
typedef long long ll;

struct Edge{
    int v,cap,rev;
    Edge(int v,int cap,int rev){
        this->v=v;
        this->cap=cap;
        this->rev=rev;
    }
};
vector<Edge*> graph[3000];
int MAXX;
int visited[3000];
bool isPath(int start,int target,int temp_min){

    if(start==target){
        MAXX=temp_min;
        return true;
    }
    visited[start]=1;
    for(int i=0;i<graph[start].size();i++){

        if(!visited[graph[start][i]->v] && graph[start][i]->cap>0){
            if(isPath(graph[start][i]->v,target,min(temp_min,graph[start][i]->cap))){
                graph[start][i]->cap-=MAXX;
                graph[graph[start][i]->v][graph[start][i]->rev]->cap+=MAXX;

                return true;
            }
        }
    }
    return false;
}

int main(){
	int n,m,start,target,a,b;
	iin2(n,m);
	iin2(start,target);
	for(int i=1;i<=2*n;i+=2){
        Edge *tmp = new Edge(i+1,1,graph[i+1].size()),*tmp1 = new Edge(i,1,graph[i].size());
        graph[i].pb(tmp);
        graph[i+1].pb(tmp1);
	}
	while(m--){
        iin2(a,b);
        Edge *tmp = new Edge(2*b-1,INF,graph[2*b-1].size()),*tmp1 = new Edge(2*a,0,graph[2*a].size());
        Edge *temp = new Edge(2*a-1,INF,graph[2*a-1].size()),*temp1 = new Edge(2*b,0,graph[2*b].size());
        graph[2*a].pb(tmp);
        graph[2*b-1].pb(tmp1);
        graph[2*b].pb(temp);
        graph[2*a-1].pb(temp1);
	}

	int res=0;

	while(isPath(2*start,2*target-1,INT_MAX)){
        res+=MAXX;
        memset(visited,0,sizeof(visited));
	}
	printf("%d",res);

	cin.ignore();
return 0;}
