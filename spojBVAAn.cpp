#include<iostream>
#include<algorithm>
#include<climits>
#include<string.h>
int dp[105][105][105],MAX;
#define MINN -9999999
using namespace std;
string a,b;
int lcs(int n,int m,int k){
    if(n==0 || m==0){if(k==MAX){return 0;}
        return  MINN;}
    if(dp[n][m][k]!=-1){return dp[n][m][k];}
    if(a[n-1]==b[m-1]){
       return dp[n][m][k] = max(a[n-1]+lcs(n-1,m-1,k+1),lcs(n-1,m-1,k));}
    return dp[n][m][k] = max(lcs(n-1,m,k),lcs(n,m-1,k));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc,n;
    cin>>tc;
    while(tc--){
        memset(dp,-1,sizeof(dp));
        cin>>a>>b>>n;
        MAX=n;
        int ans = lcs(a.length(),b.length(),0);
        if(ans>0){cout<<ans<<endl;}
        else{cout<<0<<endl;}
    }
return 0;}
