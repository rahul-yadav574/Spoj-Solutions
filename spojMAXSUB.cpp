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
#define MOD 1000000009
#define pii pair<int,int>
#define iin1(a) scanf("%d",&a)
#define LOOP(s,t,i) for(int i=s;i<=t;i++)
#define iin2(a,b) scanf("%d%d",&a,&b)
#define iin3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define iin4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define pll pair<ll,ll>
typedef long long ll;

ll cal(ll n){
    ll base = 2,ans=1;

    while(n>0){
        if(n&1){
            ans=(ans*base)%MOD;
        }

        base=(base*base)%MOD;
        n/=2;
    }

    return ans%MOD;
}


int main(){
	ll tc,n,chk,neg,zer,pos,sum,maxx;
	cin>>tc;
	while(tc--){
        cin>>n;
        neg=0,zer=0,pos=0,sum=0,maxx=INT_MIN;
        LOOP(0,n-1,i){
           cin>>chk;
            if(chk>0){
                sum+=chk;
                pos++;
            }
            else if(chk==0){
                zer++;
            }
            else{
                if(chk>maxx){
                    neg=1;
                    maxx=chk;
                }
                else if (chk==maxx){
                    neg++;
                }
            }
        }

        if(pos!=0){
            printf("%lld %lld\n",sum,cal(zer)%MOD);
        }else{
            if(zer!=0){
                printf("0 %lld\n",cal(zer)%MOD-1);
            }
            else{
                printf("%lld %lld\n",maxx,neg);
            }
        }

	}
return 0;}

