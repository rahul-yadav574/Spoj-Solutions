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

int arr[300020],idx,n,MAXX=0;

void dfs(int prev){
   // cout<<arr[idx]<<" "<<prev<<endl;
    if(n==1 || (arr[idx]==prev && idx!=0)){
        return;
    }
    int degree,temp=idx;
    if(idx==0){degree=-1;}
    else{degree=0;}

    while(idx<(2*n-1)){
        degree++;
        idx++;
        dfs(arr[temp]);


        if(arr[idx]==arr[temp]){
            break;
        }

    }
    //cout<<arr[temp]<<" "<<degree<<endl;
    MAXX = max(MAXX,degree);

}
int main(){
	int tc;
	iin1(tc);
	while(tc--){
        iin1(n);
        LOOP(0,(2*n)-1,i){
            iin1(arr[i]);
        }
        idx=0;
        MAXX=0;
        dfs(arr[0]);
        printf("%d\n",MAXX);
	}
return 0;}
