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

struct Node{
    int len,suffix,direct[26],cnt;

};
char inp[30100];
Node* tree[30100];
int curr,maxx,ans=0,k;

void add(int index){
    int tmp = curr,tmpl=tree[tmp]->len;
    while(!(index-tmpl-1>=0 && inp[index]==inp[index-tmpl-1])){
        tmp = tree[tmp]->suffix;
        tmpl = tree[tmp]->len;
    }


    if(tree[tmp]->direct[inp[index]-'a']){
        curr=tree[tmp]->direct[inp[index]-'a'];
        return;
    }

    maxx++;
    tree[tmp]->direct[inp[index]-'a']=maxx;
    curr=maxx;
    tree[curr]=new Node();
    tree[curr]->len = tree[tmp]->len+2;

    if(tree[curr]->len==1){
        tree[curr]->suffix=2;
        return;
    }
    tmp = tree[tmp]->suffix;
    tmpl=tree[tmp]->len;
    while(!(index-tmpl-1>=0 && inp[index]==inp[index-tmpl-1])){
        tmp = tree[tmp]->suffix;
        tmpl = tree[tmp]->len;
    }
    tree[curr]->suffix = tree[tmp]->direct[inp[index]-'a'];

}


int main(){
    char c;
    int ln=0;
	iin1(k);
	getchar();
	tree[1]=new Node(),tree[2]=new Node();
	tree[1]->len=-1,tree[2]->len=0;
	tree[1]->suffix=1,tree[2]->suffix=1;
	curr=1,maxx=2;

	while (( c = getchar()) != '\n'){
        inp[ln] = c;
        add(ln);
        tree[curr]->cnt++;
        ln++;
	}
	for(int i=maxx;i>1;i--){
        tree[tree[i]->suffix]->cnt +=tree[i]->cnt;
        if(tree[i]->len==k){
            ans+= tree[i]->cnt;
	    }
	}

	printf("%d",ans);

return 0;}
