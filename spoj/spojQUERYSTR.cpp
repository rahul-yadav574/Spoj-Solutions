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
#include<algorithm>
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
int len,F[1000100],start,last,tmp,k,idx;
string inp;
void solve(){
    cin>>inp;
    reverse(inp.begin(),inp.end());
    len = inp.length();
    F[0]=len;
    start=last=0;
    LOOP(1,len-1,i){

        if(i>last){
            start=last=i;

            while(last<len && inp[last]==inp[last-start]){
                last++;
            }
            F[i]=last-start;
            last--;
        }
        else{
            tmp = i-start;
            if(F[tmp]<last-i+1){
                F[i]=F[tmp];
            }
            else{
                start=i;

                 while(last<len && inp[last]==inp[last-start]){
                    last++;
                    }
                F[i]=last-start;
                last--;
            }
        }
    }

    iin1(k);
    while(k--){
        iin1(idx);
        printf("%d\n",F[len-idx]);
    }
}

int main(){
	int tc;
	iin1(tc);
	while(tc--){
        solve();
	}
return 0;}
