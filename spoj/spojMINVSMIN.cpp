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
#define pii pair<int,int>
#define iin1(a) scanf("%d",&a)
#define LOOP(s,t,i) for(int i=s;i<=t;i++)
#define iin2(a,b) scanf("%d%d",&a,&b)
#define iin3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define iin4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define pll pair<ll,ll>
typedef long long ll;
struct State{
    int x,y,time;
    State(int x,int y,int time){
        this->x=x;
        this->y=y;
        this->time=time;
    }
};
char grid[1005][1005];
int visited[1005][1005],MAXX;
bool isValid(int x,int y){
    return  (x>=0 && x<MAXX) &&
    (y>=0 && y<MAXX) &&
    !visited[x][y] &&
    grid[x][y]!='B';
}
int main(){
    ios_base::sync_with_stdio(false);
	int tc,start1x,start1y,start2x,start2y,n,first,second;
	cin>>tc;
	while(tc--){
        cin>>n;
        MAXX=n;
        first=0,second=0;
        LOOP(0,n-1,i){
            LOOP(0,n-1,j){
                cin>>grid[i][j];
                if(grid[i][j]=='X'){
                    start1x=i,start1y=j;
                }
                if(grid[i][j]=='Y'){
                    start2x=i,start2y=j;
                }
            }
        }
        memset(visited,0,sizeof(visited));
        list<State*> que1,que2;
        que1.pb(new State(start1x,start1y,0));
        que2.pb(new State(start2x,start2y,0));
        visited[start1x][start1y]=1;
        visited[start2x][start2y]=1;
        while(true){
            if(!que1.empty() && !que2.empty()){
                State *state1 = que1.front(),*state2 = que2.front();
                que1.pop_front();
                que2.pop_front();
                int x1=state1->x,x2=state2->x,y1=state1->y,y2=state2->y,time1=state1->time,time2=state2->time;
                if(x1==x2 && y1==y2){
                    if(time1==time2){
                        first--,second--;
                        continue;
                    }
                    if(time1>time2){
                        first--;
                        if(isValid(x2+1,y2)){
                            visited[x2+1][y2]=1;
                            second++;
                            que2.pb(new State(x2+1,y2,time2+1));
                        }
                        if(isValid(x2-1,y2)){
                            visited[x2-1][y2]=1;
                            second++;
                            que2.pb(new State(x2-1,y2,time2+1));
                        }
                        if(isValid(x2,y2-1)){
                            visited[x2][y2-1]=1;
                            second++;
                            que2.pb(new State(x2,y2-1,time2+1));
                        }
                        if(isValid(x2,y2+1)){
                            visited[x2][y2+1]=1;
                            second++;
                            que2.pb(new State(x2,y2+1,time2+1));
                        }
                    }
                    else{
                        second--;
                        if(isValid(x1+1,y1)){
                            visited[x1+1][y1]=1;
                            first++;
                            que1.pb(new State(x1+1,y1,time1+1));
                        }
                        if(isValid(x1-1,y1)){
                            visited[x1-1][y1]=1;
                            first++;
                            que1.pb(new State(x1-1,y1,time1+1));
                        }
                        if(isValid(x1,y1-1)){
                            visited[x1][y1-1]=1;
                            first++;
                            que1.pb(new State(x1,y1-1,time1+1));
                        }
                        if(isValid(x1,y1+1)){
                            visited[x1][y1+1]=1;
                            first++;
                            que1.pb(new State(x1,y1+1,time1+1));
                        }
                    }
                    continue;
                }
                if(isValid(x1+1,y1)){
                    first++;
                    que1.pb(new State(x1+1,y1,time1+1));
                }
                if(isValid(x1-1,y1)){
                    first++;
                    que1.pb(new State(x1-1,y1,time1+1));
                }
                if(isValid(x1,y1-1)){
                    first++;
                    que1.pb(new State(x1,y1-1,time1+1));
                }
                if(isValid(x1,y1+1)){
                    first++;
                    que1.pb(new State(x1,y1+1,time1+1));
                }
                if(isValid(x2+1,y2)){
                    second++;
                    que2.pb(new State(x2+1,y2,time2+1));
                }
                if(isValid(x2-1,y2)){
                    second++;
                    que2.pb(new State(x2-1,y2,time2+1));
                }
                if(isValid(x2,y2-1)){
                    second++;
                    que2.pb(new State(x2,y2-1,time2+1));
                }
                if(isValid(x2,y2+1)){
                    second++;
                    que2.pb(new State(x2,y2+1,time2+1));
                }
                if(isValid(x1+1,y1)){
                    visited[x1+1][y1]=1;
                }
                if(isValid(x1-1,y1)){
                    visited[x1-1][y1]=1;
                }
                if(isValid(x1,y1-1)){
                    visited[x1][y1-1]=1;
                }
                if(isValid(x1,y1+1)){
                    visited[x1][y1+1]=1;
                }
                if(isValid(x2+1,y2)){
                    visited[x2+1][y2]=1;
                }
                if(isValid(x2-1,y2)){
                    visited[x2-1][y2]=1;
                }
                if(isValid(x2,y2-1)){
                    visited[x2][y2-1]=1;
                }
                if(isValid(x2,y2+1)){
                    visited[x2][y2+1]=1;
                }
            }
            else if(!que1.empty()){
                State *state = que1.front();
                que1.pop_front();
                int x=state->x,y=state->y,time=state->time;
                if(isValid(x+1,y)){
                    first++;
                    visited[x+1][y]=1;
                    que1.pb(new State(x+1,y,time+1));
                }
                if(isValid(x-1,y)){
                    visited[x-1][y]=1;
                    first++;
                    que1.pb(new State(x-1,y,time+1));
                }
                if(isValid(x,y-1)){
                    visited[x][y-1]=1;
                    first++;
                    que1.pb(new State(x,y-1,time+1));
                }
                if(isValid(x,y+1)){
                    visited[x][y+1]=1;
                    first++;
                    que1.pb(new State(x,y+1,time+1));
                }
            }
            else if(!que2.empty()){
                State *state = que2.front();
                que2.pop_front();
                int x=state->x,y=state->y,time=state->time;
                if(isValid(x+1,y)){
                    second++;
                    visited[x+1][y]=1;
                    que2.pb(new State(x+1,y,time+1));
                }
                if(isValid(x-1,y)){
                    visited[x-1][y]=1;
                    second++;
                    que2.pb(new State(x-1,y,time+1));
                }
                if(isValid(x,y-1)){
                    visited[x][y-1]=1;
                    second++;
                    que2.pb(new State(x,y-1,time+1));
                }
                if(isValid(x,y+1)){
                    visited[x][y+1]=1;
                    second++;
                    que2.pb(new State(x,y+1,time+1));
                }
            }
            else{
                break;
            }
        }
        if(first>second){
            cout<<"Pack 1"<<endl;
        }
        else if(first<second){
            cout<<"Pack 2"<<endl;
        }
        else{
            cout<<"Gru gets to keep all bananas!"<<endl;
        }
	}
return 0;}
