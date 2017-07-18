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
struct Node{
    int suffix,direct[26],len;
};
char inp[3200];
Node* tree[3200];
pii ans;
int maxx,currNode;
void clearTree(){
    LOOP(0,3100,i){tree[i]=new Node();}
    tree[1]->len=-1,tree[2]->len=0;
    tree[1]->suffix=1,tree[2]->suffix=1;
    ans = mp(0,0);
    currNode = 1;
    maxx=2;
}
void add(int index){

    int temp = currNode,templ = tree[currNode]->len;
    while(!(index-templ-1>=0 && inp[index]==inp[index-templ-1])){
        temp = tree[temp]->suffix;
        templ=tree[temp]->len;
    }

    if(tree[temp]->direct[inp[index]-'a']){
        currNode = tree[temp]->direct[inp[index]-'a'];

    if(tree[currNode]->len==ans.first){
        ans.second++;
    }else if(tree[currNode]->len>ans.first){
        ans = mp(tree[currNode]->len,1);
    }
        return;
    }

    maxx++;

    tree[temp]->direct[inp[index]-'a']=maxx;
    tree[maxx]->len=tree[temp]->len+2;

    if(tree[maxx]->len==ans.first){
        ans.second++;
    }else if(tree[maxx]->len>ans.first){
        ans = mp(tree[maxx]->len,1);
    }

    currNode=maxx;
    if(tree[currNode]->len==1){
        tree[currNode]->suffix=2;
        return;
    }
    temp = tree[temp]->suffix;
    templ = tree[temp]->len;

    while(!(index-templ-1>=0 && inp[index]==inp[index-templ-1])){
        temp = tree[temp]->suffix;
        templ=tree[temp]->len;
    }

    tree[currNode]->suffix = tree[temp]->direct[inp[index]-'a'];
    return;

}
int main(){
	int tc;
	iin1(tc);
	while(tc--){
        scanf("%s",inp);
        clearTree();
        LOOP(0,strlen(inp)-1,i){
            add(i);
        }
        printf("%d %d\n",ans.first,ans.second);
	}
return 0;}
