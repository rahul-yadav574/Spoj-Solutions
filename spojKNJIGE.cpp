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
#define iin2(a,b) scanf("d",&a,&b)
#define iin3(a,b,c) scanf("d%d",&a,&b,&c)
#define iin4(a,b,c,d) scanf("dd",&a,&b,&c,&d)
#define pll pair<ll,ll>
typedef long long ll;


int has[300010];
int main(){

	int tc,chk,last,iter;
	iin1(tc);
	last=tc,iter=0;
	LOOP(0,tc-1,i){
        iin1(chk);
        has[chk]=i;
	}

	while(1){
        if(has[last]>has[last-1]){
            iter++;
            last--;
        }
        else{break;}

	}

    printf("%d",tc-iter-1);


return 0;}
