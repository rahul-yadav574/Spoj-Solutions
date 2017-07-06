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
#include<stack>
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

int member[100010],level[100010],first[100010],visited[100010],chk,minn,tim,answer[100010];
vector<int> graph[100010];
stack<int> recStack,temp;
void dfs(int start){
    visited[start]=1;
    first[start]=tim;
    level[start]=tim;
    tim++;
    recStack.push(start);
    member[start]=1;
    for(int i=0;i<graph[start].size();i++){
        int next = graph[start][i];

        if(!visited[next]){
            dfs(next);
            first[start]=min(first[start],first[next]);

        }
        else if(member[next]){
            first[start]=min(first[start],level[next]);
        }


    }

    if(first[start]==level[start]){
        chk = recStack.top(),minn=chk;
        while(chk!=start){
            temp.push(chk);
            minn=min(minn,chk);
            member[chk]=0;
            recStack.pop();
            chk=recStack.top();
        }
        minn=min(minn,chk);
        temp.push(chk);
        member[chk]=0;
        recStack.pop();

        while(!temp.empty()){
            answer[temp.top()]=minn;
            temp.pop();
        }
    }
}

int main(){
	int n,m,a,b;
	iin2(n,m);
	tim=1;
	while(m--){
        iin2(a,b);
        graph[a].pb(b);

	}
	LOOP(0,n-1,i){
        if(!visited[i]){
            dfs(i);
        }
	}

	LOOP(0,n-1,i){
        printf("%d\n",answer[i]);
	}

return 0;}
