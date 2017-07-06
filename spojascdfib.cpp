#include<stdio.h>
#include<queue>
#define  MOD 100000
int arr[1100100];
using namespace std;
int main(){
    arr[1]=0;
    arr[2]=1;
    for(int i=3;i<1100100;i++){
        arr[i]=(arr[i-1]+arr[i-2])%MOD;
    }
    int tc,l,r,cas=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&l,&r);
        priority_queue<int,vector<int>,greater<int> > que;
        for(int i=l;i<=l+r;i++){
            que.push(arr[i]);
        }
        int i=0;
        printf("Case %d: ",cas++);
        while(i<100 && !que.empty()){
            printf("%d ",que.top());
            que.pop();
            i++;
        }
        printf("\n");
    }

return 0;}
