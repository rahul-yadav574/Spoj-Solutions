#include<stdio.h>
using namespace std;
int INI, dp[10000][105],MAX;
bool solve(int mask,int turn){
    if(turn==MAX){return mask>INI;}
    bool a,b,c,d;
    a=b=c=d=false;
    if(dp[mask][turn]!=-1){return dp[mask][turn];}
    int u = mask%10,t=(mask/10)%10,h=(mask/100)%10,th=(mask/1000)%10;
    if(u==9){
        a = solve((th*1000)+(h*100)+(t*10),turn+1);
    }
    else{
        a = solve((th*1000)+(h*100)+(t*10)+(u+1),turn+1);
    }
    if(t==9){
        b = solve((th*1000)+(h*100)+u,turn+1);
    }
    else{
        b =  solve((th*1000)+(h*100)+((t+1)*10)+u,turn+1);
    }
    if(h==9){
        c = solve((th*1000)+(t*10)+u,turn+1);
    }
    else{
        c = solve((th*1000)+((h+1)*100)+(t*10)+u,turn+1);
    }
    if(th==9){
        d = solve((h*100)+(t*10)+u,turn+1);
    }
    else{
        d = solve(((th+1)*1000)+(h*100)+(t*10)+u,turn+1);
    }

    if(turn&1){
        return dp[mask][turn] = a&&b&&c&&d;
    }
    return dp[mask][turn] = a||b||c||d;
}
int main(){
    int tc,n,k;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&k);
        MAX=k;
        for(int i=0;i<10000;i++){
            for(int j=0;j<105;j++){
                dp[i][j]=-1;
            }
        }
        INI=n;
        if(solve(n,0)){printf("Ada\n");}
        else{printf("Vinit\n");}
    }
return 0;}
