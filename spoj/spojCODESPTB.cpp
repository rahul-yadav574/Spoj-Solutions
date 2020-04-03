/*
Pretty Kind , Pretty Smart.
*/
#include<stdio.h>
#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
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
int arr[100100],BIT[1000010],MAXX;

void update(int idx){
    while(idx<=MAXX){
        BIT[idx]+=1;
        idx+=idx&-idx;
    }
}
int query(int idx){
    int res=0;
    while(idx>0){
        res+=BIT[idx];
        idx-=idx&-idx;
    }
    return res;
}

int main(){
	int tc,n;
	iin1(tc);
	while(tc--){
        iin1(n);
        memset(BIT,0,sizeof(BIT));
        MAXX=0;
        LOOP(0,n-1,i){
            iin1(arr[i]);
            MAXX = max(MAXX,arr[i]);
        }

        int ans=0;
        for(int i=n-1;i>=0;i--){
            ans+=query(arr[i]-1);
            update(arr[i]);
        }
        printf("%d\n",ans);
	}
return 0;}
