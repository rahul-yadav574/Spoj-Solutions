/*
Pretty Kind , Pretty Smart.
*/
#include<stdio.h>
#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
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
map<int,int> assigned;
map<int,int>::iterator it;

int placed[1000010];
int main(){
    int n,q,type,idx;
    iin2(n,q);
    while(q--){
        iin2(type,idx);
        if(type==1 && !placed[idx]){
            assigned[idx]=1;
            placed[idx]=1;
        }else if(type==2){
            if(placed[idx]){
                printf("%d\n",idx);
            }
            else{
                it = assigned.lower_bound(idx);
                if(it==assigned.end()){
                    printf("-1\n");
                }
                else{

                    printf("%d\n",it->first);
                }
            }
        }
    }
return 0;}
