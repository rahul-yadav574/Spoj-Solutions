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
#include<algorithm>
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

int ti[800],first[800],parent[800],visited[800];

vector<int> graph[800];
vector<pii> output;

bool Comp(pii a,pii b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}
void dfs(int start,int tim){

    visited[start]=1;
    ti[start]=tim;
    first[start]=tim;

    for(int i=0;i<graph[start].size();i++){

        if(!visited[graph[start][i]]){
            parent[graph[start][i]]=start;
            dfs(graph[start][i],tim+1);
            first[start]=min(first[start],first[graph[start][i]]);

            if(first[graph[start][i]]>ti[start]){
                output.push_back(mp(min(start,graph[start][i]),max(start,graph[start][i])));
            }
        }
        else if(graph[start][i]!=parent[start]){
            first[start]=min(first[start],ti[graph[start][i]]);
        }

    }
}

void ini(int n){

    for(int i=0;i<=n;i++){
        ti[i]=-1;
        first[i]=-1;
        parent[i]=-1;
        visited[i]=0;
        graph[i].clear();
    }
}
int main(){
	int tc,a,b,m,n,cas=1;
	iin1(tc);
	while(tc--){
        iin2(n,m);
        output.clear();
        ini(n);
        while(m--){
            iin2(a,b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(1,1);
         printf("Caso #%d\n",cas++);
        if(output.size()==0){
            printf("Sin bloqueos\n");
        }
        else{
            printf("%d\n",output.size());
            sort(output.begin(),output.end(),Comp);

            for(int i=0;i<output.size();i++){
                printf("%d %d\n",output[i].first,output[i].second);
            }
        }


	}


return 0;}
