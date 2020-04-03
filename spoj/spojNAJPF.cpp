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
#define pii pair<int,int>
#define iin1(a) scanf("%d",&a)
#define LOOP(s,t,i) for(int i=s;i<=t;i++)
#define iin2(a,b) scanf("d",&a,&b)
#define iin3(a,b,c) scanf("d%d",&a,&b,&c)
#define iin4(a,b,c,d) scanf("dd",&a,&b,&c,&d)
#define pll pair<ll,ll>
typedef long long ll;



int main(){

	ios::sync_with_stdio(false);
	int tc;
	cin>>tc;
	string haystack,needle;
	 queue<int> que;
	while(tc--){
        cin>>haystack>>needle;

        int lps[needle.length()],start=1,lp=0;
        lps[lp]=lp;

        while(start<needle.length()){

            if(needle[start]==needle[lp]){
                lp++;
                lps[start]=lp;
                start++;
            }

            else{

                if(lp==0){
                    lps[start]=lp;
                    start++;
                }
                else{
                    lp=lps[lp-1];
                }
            }
        }


        int iter=0;
        start=0;
        while(iter<haystack.length()){
            if(haystack[iter]==needle[start]){
                iter++;
                start++;
            }

            if(start==needle.length()){
                que.push(iter-start);
                start=lps[start-1];
            }

            else if(iter<haystack.length() && haystack[iter]!=needle[start]){

                if(start!=0){
                    start=lps[start-1];
                }
                else{
                    iter++;
                }
            }
        }

        if(que.size()==0){cout<<"Not Found"<<endl<<endl;continue;}
        cout<<que.size()<<endl;
        while(!que.empty()){
            cout<<que.front()+1<<" ";
            que.pop();
        }
        cout<<endl<<endl;
	}



return 0;}
