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

int arr[100010];
int prefixSum[100010];
int main(){
	int tc,n,total;
	iin1(tc);
	while(tc--){
        iin1(n);
        total=0;
        LOOP(0,n-1,i){
            iin1(arr[i]);
            total+=arr[i];
        }

        if(total&1){
            printf("SAD\n");
            continue;
        }
        memset(prefixSum,0,sizeof(prefixSum));
        prefixSum[0]=arr[n-1];
        LOOP(1,n-1,i){
            prefixSum[i]=prefixSum[i-1]+arr[n-1-i];
        }

        bool sad = false;
        LOOP(1,n,i){
            int left = prefixSum[i-1]-(i*(i-1));
            int right =0;
            for(int j=i;j<n;j++){
                right+=min(i,arr[n-j-1]);
            }
            if(left>right){
                sad=true;
                break;
            }
        }

        if(sad){
            printf("SAD\n");
        }else{
            printf("HAPPY\n");
        }


	}
return 0;}
