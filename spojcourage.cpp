#include<stdio.h>
#include<utility>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pii pair<ll,ll>
int arr[100010];
pii Tree[4*100010];


void build(ll idx,ll start,ll last){
    if(start==last){
        Tree[idx] = mp(arr[start],arr[start]);
        return;
    }
    int mid = (start+last)/2;
    build(2*idx+1,start,mid);
    build(2*idx+2,mid+1,last);
    Tree[idx].first = Tree[2*idx+1].first+Tree[2*idx+2].first;
    Tree[idx].second = min(Tree[2*idx+1].second,Tree[2*idx+2].second);
}

void update(ll idx,ll start,ll last,ll target,ll val){
    if(start==last && start==target){
        arr[start]+=val;
        Tree[idx] = mp(arr[start],arr[start]);
        return;
    }

    int mid = (start+last)/2;
    if(target<=mid && target>=start){
        update(2*idx+1,start,mid,target,val);
    }
    else{
        update(2*idx+2,mid+1,last,target,val);
    }

    Tree[idx].first = Tree[2*idx+1].first+Tree[2*idx+2].first;
    Tree[idx].second = min(Tree[2*idx+1].second,Tree[2*idx+2].second);

}
pii query(ll idx,ll start,ll last,ll left,ll right){
    if(start>=left && last<=right){return Tree[idx];}
    if(last<left || start>right){return mp(0,INT_MAX);}
    int mid = (start+last)/2;
    pii le = query(2*idx+1,start,mid,left,right);
    pii re = query(2*idx+2,mid+1,last,left,right);
    return mp(le.first+re.first,min(le.second,re.second));
}
int main(){
    ll n,q,l,r;
    char type[10];
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    build(0,0,n-1);
    scanf("%lld",&q);
    while(q--){
        scanf("%s%lld%lld",&type,&l,&r);
        if(type[0]=='G'){
            update(0,0,n-1,r,l);
        }
        else if(type[0]=='E'){
            update(0,0,n-1,r,-l);
        }
        else if(type[0]=='C'){
            pii ans = query(0,0,n-1,l,r);
            printf("%lld\n",ans.first-ans.second);
        }
    }

return 0;}
