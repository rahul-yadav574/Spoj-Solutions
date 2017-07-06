#include<bits/stdc++.h>

int memo[9][9],money[9];
using namespace std;

int solve(int idx,string chosen){
    if(idx==9){return 0;}
    bool ch = 0;
    for(int i=1;i<9;i++){
        if(chosen[i]=='1' && (memo[i][idx] || memo[idx][i])){ch=1;}
    }
    if(ch){return solve(idx+1,chosen);}
    else{
        chosen[idx]='1';
        int chk1 = money[idx]+solve(idx+1,chosen);
        chosen[idx]='0';
        int chk2 = solve(idx+1,chosen);

        return max(chk1,chk2);
    }
}
int main(){
    int n,l,r;
    for(int i=1;i<9;i++){scanf("%d",&money[i]);}
    scanf("%d",&n);
    while(n--){scanf("%d%d",&l,&r);memo[l][r]=1;memo[r][l]=1;}
    string chosen="000000000";
    printf("%d",solve(1,chosen));

return 0;}
