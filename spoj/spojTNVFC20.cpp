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
map<ll,ll> ma;

int main(){
	ll n,k,id;
    scanf("%lld %lld",&n,&k);
	while(n--){
        scanf("%lld",&id);
        ma[id]++;
	}

	map<ll,ll>::iterator it;

	for(it=ma.begin();it!=ma.end();++it){
        if(it->second%k){
            printf("%lld\n",it->first);
            break;
        }
	}

return 0;}
