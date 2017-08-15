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
#define pii pair<int,int>
#define iin1(a) scanf("%d",&a)
#define LOOP(s,t,i) for(int i=s;i<=t;i++)
#define iin2(a,b) scanf("%d%d",&a,&b)
#define iin3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define iin4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define pll pair<ll,ll>
typedef long long ll;
#define SIZE 1000010
#define MOD 1000000003
ll memo[SIZE],track[SIZE];
void compute(){
    memo[0]=0;
    track[0]=0;
    for(ll i=1;i<SIZE;i++){
        track[i] = (track[i-1]%MOD + (i*i*i)%MOD)%MOD;
        memo[i] = ((memo[i-1])%MOD + track[i]%MOD)%MOD;
    }
}
int main(){
    compute();
	int tc,n;
	iin1(tc);
	while(tc--){
        iin1(n);
        printf("%lld\n",memo[n]%MOD);
	}
return 0;}
