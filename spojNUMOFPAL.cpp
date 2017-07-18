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
    int suffix,direct[26],len,coun;
};
char inp[1100];
Node* tree[1100];
int maxx,currNode;
void clearTree(){
    LOOP(0,1050,i){tree[i]=new Node();}
    tree[1]->len=-1,tree[2]->len=0;
    tree[1]->suffix=1,tree[2]->suffix=1;
    tree[1]->coun=0;
    tree[2]->coun=0;
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
        return;
    }

    maxx++;

    tree[temp]->direct[inp[index]-'a']=maxx;
    tree[maxx]->len=tree[temp]->len+2;

    currNode=maxx;
    if(tree[currNode]->len==1){
        tree[currNode]->suffix=2;
        tree[currNode]->coun=1;
        return;
    }
    temp = tree[temp]->suffix;
    templ = tree[temp]->len;

    while(!(index-templ-1>=0 && inp[index]==inp[index-templ-1])){
        temp = tree[temp]->suffix;
        templ=tree[temp]->len;
    }

    tree[currNode]->suffix = tree[temp]->direct[inp[index]-'a'];
    tree[currNode]->coun = 1+ tree[tree[currNode]->suffix]->coun;
    return;

}
int main(){
        int ans =0;
        scanf("%s",inp);
        clearTree();
        LOOP(0,strlen(inp)-1,i){
            add(i);
            ans+=tree[currNode]->coun;
        }
        printf("%d",ans);

return 0;}
