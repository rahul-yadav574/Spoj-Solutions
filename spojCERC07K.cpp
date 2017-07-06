/*
Pretty Kind , Pretty Smart.
*/
#include<stdio.h>
#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<list>
#include<climits>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define MAX 99999999
#define pii pair<int,int>
#define iin1(a) scanf("%d",&a)
#define LOOP(s,t,i) for(int i=s;i<=t;i++)
#define iin2(a,b) scanf("%d%d",&a,&b)
#define iin3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define iin4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define pll pair<ll,ll>
typedef long long ll;

struct State{
    int i,j,mask,steps;
    State(int i,int j,int mask,int steps){
        this->i=i;
        this->j=j;
        this->mask=mask;
        this->steps=steps;
    }
};
char grid[105][105];
int visited[105][105][16],n,m;

bool isValid(int i,int j,int mask){


    /*
        Blue is 1
        Yellow is 2
        Red is 3
        Green is 4
    */
    if(i>=0 && i<n && j>=0&& j<m && !visited[i][j][mask]){
         if(grid[i][j]=='X'){return true;}
        char ch  = grid[i][j];
        if(ch=='#'){return false;}
        if(ch=='.' ||ch=='*'|| ch=='b' || ch=='g' || ch=='y' || ch=='r'){return true;}

        if(ch=='B'){
            return mask&1;
        }
        if(ch=='Y'){
            return mask&2;
        }
        if(ch=='G'){
            return mask&8;
        }
        if(ch=='R'){
            return mask&4;
        }


    }
    return false;
}
int main(){
	int sx,sy;
	iin2(n,m);
	while(n!=0 && m!=0){
        memset(visited,0,sizeof(visited));
        LOOP(0,n-1,i){
            LOOP(0,m-1,j){
                cin>>grid[i][j];
                if(grid[i][j]=='*'){
                    sx=i;sy=j;
                }
            }
        }

    /*
        Blue is 1
        Yellow is 2
        Red is 3
        Green is 4
    */

        list<State*> que;
        que.push_back(new State(sx,sy,0,0));
       // cout<<sx<<" "<<sy<<endl;
        visited[sx][sy][0]=1;
        int ans = MAX;
        while(!que.empty()){
            State *state = que.front();
            que.pop_front();

            int tx=state->i,ty=state->j,mask=state->mask,steps=state->steps;
           // cout<<tx<<"  "<<ty<<" "<<mask<<endl;
            if(grid[tx][ty]=='b'){


                if(!(mask&1)){
                     mask+=1;
                }

            }
            else if(grid[tx][ty]=='y'){
               if(!(mask&2)){
                     mask+=2;
                }
            }
            else if(grid[tx][ty]=='r'){
              if(!(mask&4)){
                     mask+=4;
                }
            }
            else if(grid[tx][ty]=='g'){
               if(!(mask&8)){
                     mask+=8;
                }
            }


            if(grid[tx][ty]=='X'){
                ans=min(ans,steps);
            }
            else{

                if(isValid(tx+1,ty,mask)){
                    visited[tx+1][ty][mask]=1;
                    que.pb(new State(tx+1,ty,mask,steps+1));
                }

                if(isValid(tx-1,ty,mask)){
                     visited[tx-1][ty][mask]=1;
                    que.pb(new State(tx-1,ty,mask,steps+1));
                }

                if(isValid(tx,ty+1,mask)){
                     visited[tx][ty+1][mask]=1;
                    que.pb(new State(tx,ty+1,mask,steps+1));
                }

                if(isValid(tx,ty-1,mask)){
                    visited[tx][ty-1][mask]=1;
                    que.pb(new State(tx,ty-1,mask,steps+1));
                }
            }

        }
        if(ans==MAX){
            printf("The poor student is trapped!\n");
        }
        else{
            printf("Escape possible in %d steps.\n",ans);
        }
        iin2(n,m);
	}



return 0;}
