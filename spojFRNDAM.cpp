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
#define MAXX 1000010
ll sieve[MAXX];
void precompute(){

    sieve[0]=0;

    LOOP(1,MAXX-1,i){
        for(int j=2*i;j<MAXX-1;j+=i){
            sieve[j]+=i;
        }
    }
}

int main(){
	int tc,a,b;
	iin1(tc);
	precompute();
	while(tc--){
        iin2(a,b);

        if(sieve[a]==b && sieve[b]==a){
            printf("Friendship is ideal\n");
        }else{
            printf("Friendship is not ideal\n");
        }
	}
return 0;}
