#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

vector<pii> lcs(string a,string b,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){

            if(i==0||j==0){
                dp[i][j]=0;
            }else if (a[i-1]==b[j-1]){
                dp[i][j]= 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
   int index = dp[n][m];
   vector<pii> rec;

   int i = n, j = m;
   while (i > 0 && j > 0){
      if (a[i-1] == b[j-1]){
        rec.push_back(make_pair(i-1,j-1));
        i--; j--; index--;}
      else if (dp[i-1][j] > dp[i][j-1]){i--;}
      else{j--;}
   }

   return rec;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a,b,ans;
    while(cin>>a>>b){
        vector<pii> rec = lcs(a,b,a.length(),b.length());
        int att=0,btt=0;
        ans="";
        for(int i=rec.size()-1;i>=0;i--){

            for(int j=att;j<rec[i].first;j++){
                ans+=a[j];
            }
            for(int j=btt;j<rec[i].second;j++){
                ans+=b[j];
            }
            ans+=a[rec[i].first];
            att=rec[i].first+1,btt=rec[i].second+1;
        }
        for(int i=att;i<a.length();i++){ans+=a[i];}
        for(int i=btt;i<b.length();i++){ans+=b[i];}

        cout<<ans<<endl;


    }

return 0;}
