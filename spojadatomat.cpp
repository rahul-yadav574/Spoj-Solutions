#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define MOD 1000000007
#define BASE 256
typedef long long ll;
ll arr[20000010],MAX,temp[20000010],freq[BASE];
using namespace std;
void cs(ll e){
    memset(freq,0,sizeof(freq));
    for(int i=0;i<MAX;i++){
        freq[(arr[i]>>e)&(BASE-1)]++;
    }
    for(int i=1;i<BASE;i++){
        freq[i]+=freq[i-1];
    }
    for(int i=MAX-1;i>=0;i--){
        temp[freq[(arr[i]>>e)&(BASE-1)]-1]=arr[i];

        freq[(arr[i]>>e)&(BASE-1)]--;
    }
    for(int i=0;i<MAX;i++){
        arr[i]=temp[i];
    }
}
int main(){
    ll tc,n,a,b,x,maxx,tmp,base;
    scanf("%lld",&tc);
    while(tc--){
        scanf("%lld%lld%lld%lld",&n,&a,&b,&x);
        MAX=n;
        arr[0]=x,maxx=x;
        for(ll i=1;i<n;i++){
            arr[i]=((arr[i-1]*a) + b)%MOD;

            maxx=max(arr[i],maxx);
        }
        for(ll i=0;(maxx>>i)>0;i+=8){
            cs(i);
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            ans = (ans + (arr[i]*(i+1)))%MOD;
        }
        printf("%lld\n",ans);
    }
return 0;}
