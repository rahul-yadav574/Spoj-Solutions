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

ll binexpo(ll n){
    if(n==0){return 1;}
    if(n&1){return (2*binexpo(n-1))%MOD;}

    ll a = (binexpo(n/2));
    return (a*a)%MOD;

}

pair<ll,ll> nthfib(ll n){

    if(n==0){
        return make_pair(0,1);
    }

    pair<ll,ll> tmp = nthfib(n/2);

    ll a = tmp.first;
    ll b = tmp.second;
    ll c = 2*b-a;
    if(c<0){c+=(MOD-1);}

    c = (a*c)%(MOD-1);
    ll d = ((a*a)%(MOD-1) + (b*b)%(MOD-1))%(MOD-1);

    if(n&1){
        return make_pair(d,c+d);
    }else{
        return make_pair(c,d);
    }

}

int main(){
	int tc;
	ll n;
	iin1(tc);
	while(tc--){
        scanf("%lld",&n);

        //if(n==0){printf("2\n");continue;}
        printf("%lld\n",binexpo(nthfib(n).first));
	}
return 0;}
