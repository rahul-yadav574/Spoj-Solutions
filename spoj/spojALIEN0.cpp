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
int n,q,numbers[100005],start,last,base,precomputed[6][100005],prefix_sum[6][100005],power_mem[6][];

int get_highest_power(int number,int k){
    int power = 0;

    while(number % k == 0){
        number/=k;
        power+=1;
    }

    return power;


}

void precompute(){
    memset(precomputed,0,sizeof(precomputed));

  
    LOOP(1,n,i){
        precomputed[2][i] = get_highest_power(numbers[i],2);
        prefix_sum[2][i] = i == 0 ? precomputed[2][i] : precomputed[2][i] + prefix_sum[2][i-1];

        precomputed[3][i] = get_highest_power(numbers[i],3);
        prefix_sum[3][i] = i == 0 ? precomputed[3][i] : precomputed[3][i] + prefix_sum[3][i-1];

        precomputed[5][i] = get_highest_power(numbers[i],5);
        prefix_sum[5][i] = i == 0 ? precomputed[5][i] : precomputed[5][i] + prefix_sum[5][i-1];
    }

}

int main(){

    iin2(n,q);
    LOOP(1,n,idx){iin1(numbers[idx]);}
    int answer = 0;

    precompute();
    LOOP(0,q-1,qidx){
        iin3(start,last,base);
        if(base == 6){
            answer = min(prefix_sum[2][last] - prefix_sum[2][start-1],prefix_sum[3][last] - prefix_sum[3][start-1]);
        }else if (base == 4){
            answer = (prefix_sum[2][last] - prefix_sum[2][start-1])/2;
        }else{
            answer = prefix_sum[base][last] - prefix_sum[base][start-1];
        }

        cout<<answer<<endl;
        
    }


return 0;}
