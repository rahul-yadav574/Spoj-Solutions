#include<stdio.h>
#include<string.h>
typedef long long ll;
using namespace std;
int choice[25][25],n;
ll dp[1048900];
ll solve(int idx,int *mask,int val){
    if(idx==0){
        return 1;
    }
    if(dp[val]!=-1){return dp[val];}
    ll ans = 0;
    for(int j=1;j<=n;j++){
        if(choice[idx][j] && !mask[j]){
            mask[j]=1;
            ans +=solve(idx-1,mask,val+(1<<(j-1)));
            mask[j]=0;
        }
    }
    return dp[val]=ans;
}
int main(){
    int tc,mask[22];
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&choice[i][j]);
            }
        }
        memset(mask,0,sizeof(mask));
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve(n,mask,0));
    }
return 0;}
