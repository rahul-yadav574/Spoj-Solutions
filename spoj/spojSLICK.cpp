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
#define i_o ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define pii pair<int,int>
#define iin1(a) scanf("%d",&a)
#define LOOP(s,t,i) for(int i=s;i<=t;i++)
#define iin2(a,b) scanf("%d%d",&a,&b)
#define iin3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define iin4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define pll pair<ll,ll>
typedef long long ll;

int grid[255][255],visited[255][255],n,m;
map<int,int> output;

bool valid(int i,int j){ return i>=0 && i<n && j>=0 && j<m && visited[i][j]==0 && grid[i][j]==1;}
int dfs(int i,int j){
   visited[i][j]=1;

   int ans = 1;

   if(valid(i+1,j)){
    ans+=dfs(i+1,j);
   }
   if(valid(i-1,j)){
    ans+=dfs(i-1,j);
   }
   if(valid(i,j-1)){
    ans+=dfs(i,j-1);
   }
   if(valid(i,j+1)){
    ans+=dfs(i,j+1);
   }
   return ans;
}
int main(){
	int total,chk;
	iin2(n,m);
	while(n!=0 && m!=0){
        memset(visited,0,sizeof(visited));
        output.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }
        }

        total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(!visited[i][j] && grid[i][j]==1){
                    chk=dfs(i,j);
                    total+=1;
                    output[chk]+=1;
               }
            }
        }

        printf("%d\n",total);
        map<int,int>::iterator it;
        for(it=output.begin();it!=output.end();it++){
            printf("%d %d\n",it->first,it->second);
        }

        iin2(n,m);

	}



return 0;}
