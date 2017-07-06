#include<iostream>
#include<climits>
#include<list>
#include<utility>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
char grid[1010][1010];
int minndis[1010][1010];

bool isValid(int i,int j,int r,int c){
    return (i>=0 && i<r) && (j>=0 && j<c);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc,r,c;
    cin>>tc;
    while(tc--){
        cin>>r>>c;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>grid[i][j];
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                minndis[i][j]=INT_MAX;
            }
        }
        minndis[0][0]=0;

        list<pii> que;
        que.push_back(mp(0,0));

        while(!que.empty()){

            pii chk = que.front();
            que.pop_front();
            int tx = chk.first,ty=chk.second;

            if(isValid(tx+1,ty,r,c)&&grid[tx+1][ty]==grid[tx][ty] && minndis[tx+1][ty]>minndis[tx][ty]){
                minndis[tx+1][ty]=minndis[tx][ty];
                que.push_front(mp(tx+1,ty));
            }
            else if(isValid(tx+1,ty,r,c)&&grid[tx+1][ty]!=grid[tx][ty] && minndis[tx+1][ty]>minndis[tx][ty]+1){
                minndis[tx+1][ty]=minndis[tx][ty]+1;
                que.push_back(mp(tx+1,ty));
            }

            if(isValid(tx-1,ty,r,c)&&grid[tx-1][ty]==grid[tx][ty] && minndis[tx-1][ty]>minndis[tx][ty]){
                minndis[tx-1][ty]=minndis[tx][ty];
                que.push_front(mp(tx-1,ty));
            }
            else if(isValid(tx-1,ty,r,c)&&grid[tx-1][ty]!=grid[tx][ty] && minndis[tx-1][ty]>minndis[tx][ty]+1){
                minndis[tx-1][ty]=minndis[tx][ty]+1;
                que.push_back(mp(tx-1,ty));
            }

             if(isValid(tx,ty+1,r,c)&&grid[tx][ty+1]==grid[tx][ty] && minndis[tx][ty+1]>minndis[tx][ty]){
                minndis[tx][ty+1]=minndis[tx][ty];
                que.push_front(mp(tx,ty+1));
            }
            else if(isValid(tx,ty+1,r,c)&&grid[tx][ty+1]!=grid[tx][ty] && minndis[tx][ty+1]>minndis[tx][ty]+1){
                minndis[tx][ty+1]=minndis[tx][ty]+1;
                que.push_back(mp(tx,ty+1));
            }

            if(isValid(tx,ty-1,r,c)&&grid[tx][ty-1]==grid[tx][ty] && minndis[tx][ty-1]>minndis[tx][ty]){
                minndis[tx][ty-1]=minndis[tx][ty];
                que.push_front(mp(tx,ty-1));
            }
            else if(isValid(tx,ty-1,r,c)&&grid[tx][ty-1]!=grid[tx][ty] && minndis[tx][ty-1]>minndis[tx][ty]+1){
                minndis[tx][ty-1]=minndis[tx][ty]+1;
                que.push_back(mp(tx,ty-1));
            }
        }
        cout<<minndis[r-1][c-1]<<endl;
    }
return 0;}
