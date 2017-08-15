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

struct Edge{
    int v,cap,rev;
    Edge(int v,int cap,int rev){
        this->v=v;
        this->cap=cap;
        this->rev=rev;
    }
};
vector<Edge*> graph[200];
int MAXX;
int visited[200];
bool isPath(int start,int target,int temp_min){
  //  cout<<start<<" "<<target<<endl;
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
    ios_base::sync_with_stdio(false);
	int tc,flow,u,v,iter=1;
	char a,b;
	cin>>tc;
	map<char,int> track;
	while(tc--){
        cin>>a>>b>>flow;
        if(track.find(a)==track.end()){
            track[a]=iter++;
            u=track[a];
        }else{u=track[a];}

         if(track.find(b)==track.end()){
            track[b]=iter++;
            v=track[b];
        }else{v=track[b];}

        Edge *tmp = new Edge(v,flow,graph[v].size()),*tmp1 = new Edge(u,0,graph[u].size());
        graph[u].pb(tmp);
        graph[v].pb(tmp1);

	}

	//cout<<track['A']<<" "<<track['B']<<" "<<track['C']<<" "<<track['D']<<" "<<track['Z']<<" ";
	int source,sink;
	if(track.find('A')==track.end() || track.find('Z')==track.end()){
        cout<<0;
	}
	else{
        int res = 0;
        while(isPath(track['A'],track['Z'],INT_MAX)){
            res+=MAXX;
            memset(visited,0,sizeof(visited));
        }
        printf("%d",res);
	}


return 0;}
