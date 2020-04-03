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
#define iin2(a,b) scanf("%d%d",&a,&b)
#define iin3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define iin4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define pll pair<ll,ll>
typedef long long ll;

char haystack[100010];

int main(){

	int tc,n,prev,chk;
	char needle[100010];
	iin1(tc);
	while(tc--){
        iin1(n);
        iin1(prev);
        LOOP(1,n-1,i){
            iin1(chk);
            if(chk==prev){
                haystack[i]='E';
            }else if(chk<prev){
                haystack[i]='L';
            }else{
                haystack[i]='G';
            }
            prev=chk;
        }

        scanf("%s",&needle);

        int lps[strlen(needle)],start=1,lp=0,iter=1,danger=1;
        lps[lp]=lp;
        while(start<strlen(needle)){
            if(needle[start]==needle[lp]){
                lps[start++]=++lp;
            }
            else{
                if(lp==0){
                    lps[start++]=lp;
                }
                else{
                    lp=lps[lp-1];
                }
            }
        }

        start=0;
        while(iter<n){
            if(haystack[iter]==needle[start]){
                iter++;
                start++;
            }

            if(start==strlen(needle)){
                danger=0;
                break;
            }
            else if(iter<n && haystack[iter]!=needle[start]){

                if(start==0){
                    iter++;
                }
                else{
                    start=lps[start-1];
                }
            }
        }
        if(danger){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
	}



return 0;}
