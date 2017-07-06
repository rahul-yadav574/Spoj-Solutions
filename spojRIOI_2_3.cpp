#include<stdio.h>
#include<list>
#include<string>
#include<iostream>
#include<string.h>
using namespace std;

int pow(int n){
    if(n==0){return 1;}
    return 2*pow(n-1);
}
struct State{
    int x,y,vis,cell;
    string mask;
    State(int x,int y,int vis,int cell,string mask){
        this->x=x;
        this->y=y;
        this->cell=cell;
        this->vis=vis;
        this->mask=mask;
    }
};
int arr[55][55],visited[55][55][1025];

bool isValid(int i,int j,int n){
    return (i>=0&&i<n)  && (j>=0&&j<n);
}
int main(){
    int tc,sx,sy,ex,ey,n,MINN;
    string mask;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        mask="0000000000";
        MINN=500;
        memset(visited,0,sizeof(visited));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        list<State*> que;
        que.push_back(new State(sx,sy,0,0,"0000000000"));

        while(!que.empty()){
            State *state = que.front();
            que.pop_front();

            int tx = state->x,ty=state->y,tvis=state->vis,tcell=state->cell;

            string tmask=state->mask;

            if(tmask[arr[tx][ty]]=='0'){
                tcell+=pow(arr[tx][ty]);
                tmask[arr[tx][ty]]='1';
                tvis++;
            }
            visited[tx][ty][tcell]=1;
            if(tx==ex && ty==ey){
                MINN = min(MINN,tvis);
            }
            else{
                if(isValid(tx+1,ty,n) && !visited[tx+1][ty][tcell] && tvis<MINN){
                    que.push_back(new State(tx+1,ty,tvis,tcell,tmask));
                    visited[tx+1][ty][tcell]=1;
                }
                if(isValid(tx-1,ty,n) && !visited[tx-1][ty][tcell]&& tvis<MINN){
                    que.push_back(new State(tx-1,ty,tvis,tcell,tmask));
                    visited[tx-1][ty][tcell]=1;
                }
                if(isValid(tx,ty+1,n) && !visited[tx][ty+1][tcell]&& tvis<MINN){
                    que.push_back(new State(tx,ty+1,tvis,tcell,tmask));
                    visited[tx][ty+1][tcell]=1;
                }
                if(isValid(tx,ty-1,n) && !visited[tx][ty-1][tcell]&& tvis<MINN){
                    que.push_back(new State(tx,ty-1,tvis,tcell,tmask));
                    visited[tx][ty-1][tcell]=1;
                }
            }

        }

        printf("%d\n",MINN);
    }


return 0;}
