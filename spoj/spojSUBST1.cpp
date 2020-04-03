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
#define iin4(a,b,c,d) scanf("%d%d%d",&a,&b,&c,&d)
#define pll pair<ll,ll>
typedef long long ll;
#define SIZE 500100
struct State{
    int len,suffix;
    map<char,int> direct;
};
char inp[SIZE];
State sa[2*SIZE];
int last,states, dp[2*SIZE];
void ini(){
    LOOP(0,SIZE,i){sa[i].direct.clear();dp[i]=0;}
    last=0,states=1;
    sa[0].len=0;
    sa[0].suffix=-1;
}

void add(char c){
    int curr  = states++,tmp=last;
    last=curr;

    sa[tmp].direct[c]=curr;
    sa[curr].len = 1+sa[tmp].len;
    tmp=sa[tmp].suffix;

    while(1){
        if(tmp==-1 || sa[tmp].direct[c]){break;}
        sa[tmp].direct[c]=curr;
        tmp=sa[tmp].suffix;

    }

    if(tmp==-1){
        sa[curr].suffix = 0;
        return;
    }

    int tmp1 = sa[tmp].direct[c];

    if(sa[tmp].len+1 == sa[tmp1].len){
        sa[curr].suffix=tmp1;
        return;
    }

    int clone = states++;
    sa[clone].len = 1+sa[tmp].len;
    sa[clone].direct = sa[tmp1].direct;
    sa[clone].suffix = sa[tmp1].suffix;

    while(1){
        if(tmp==-1 || sa[tmp].direct[c]!=tmp1){break;}
        sa[tmp].direct[c]=clone;
        tmp=sa[tmp].suffix;
    }

    sa[tmp1].suffix = sa[curr].suffix = clone;
}

int dfs(int start){
    if(dp[start]){return dp[start];}
    map<char,int>::iterator it;
    for(it = sa[start].direct.begin();it!=sa[start].direct.end();++it){
        dp[start]+=1+dfs(it->second);
    }

    return dp[start];
}
int main(){
	int tc,idx;
	char c;
	iin1(tc);
	getchar();
	while(tc--){
        ini();
        while((c = getchar())!='\n'){
            add(c);
        }
        printf("%d\n",dfs(0));

	}
return 0;}
