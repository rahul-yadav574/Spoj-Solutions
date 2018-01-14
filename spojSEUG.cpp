/*
Pretty Kind , Pretty Smart.
*/
#include<stdio.h>
#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
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


int main(){
	int tc,a,b,c,d,n,arr[1010];
	iin1(tc);
	while(tc--){
        iin4(a,b,c,d);
        iin1(n);
        LOOP(0,n-1,i){
            iin1(arr[i]);
        }
        sort(arr,arr+n);
        int res = 0;
        for(int i=n-1;i>=0;i--){
            if(d>c){

                break;
            }

            d+=arr[i];
            res+=1;
        }
         printf("%d\n",res);

	}
return 0;}
