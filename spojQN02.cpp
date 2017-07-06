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

int dsu[100010],siz[100010];

int root(int a){
    while(a!=dsu[a]){
        a=dsu[a];
        dsu[a]=dsu[dsu[a]];
    }
    return a;
}
int dsufind(int a,int b){
    return root(a)==root(b);
}
void dsujoin(int a,int b){
    int r_a=root(a),r_b=root(b);

    if(siz[r_a]>siz[r_b]){
        dsu[r_b]=dsu[r_a];
        siz[r_a]+=siz[r_b];
    }
    else{
        dsu[r_a]=dsu[r_b];
        siz[r_b]+=siz[r_a];
    }

}
int main(){
	int n,k,a,b,q;
	iin2(n,k);
	LOOP(1,n,i){dsu[i]=i;siz[i]=i;}
	while(k--){
        iin2(a,b);
        dsujoin(a,b);
	}
	iin1(q);
	while(q--){
        iin2(a,b);
        if(dsufind(a,b)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
	}

return 0;}
