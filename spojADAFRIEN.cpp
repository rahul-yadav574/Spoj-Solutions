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

map<string,ll> values;
priority_queue<ll> que;
int main(){
	string s;
	ll val;
	int n,k;
	iin2(n,k);
	while(n--){
        cin>>s>>val;
        if(values.find(s)==values.end()){
            values[s]=val;
        }else{
            values[s]+=val;
        }
	}

	map<string,ll>::iterator it;

	for(it=values.begin();it!=values.end();it++){
        que.push(it->second);
	}

	ll ans = 0 ;

	while(k>0 && que.size()>0){
        ans += que.top();
        que.pop();
        k--;
	}
	cout<<ans;


return 0;}
