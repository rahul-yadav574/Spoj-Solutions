
//Question Copied from amazon hiring challenge on hacker-earth
#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
long long bs(long long start,long long last,long long a,long long b,long long n,int lastcall,long long chk){
    long long mid = (start+last)/2;
    if(mid%a==0 || mid%b==0){
        long long a1 = mid/a,b1 = mid/b,cmn = mid/(chk),d1=a1+b1-cmn;
        if(d1==n){return mid;}
        else if(d1>n){return bs(start,mid-1,a,b,n,0,chk);}
        return bs(mid+1,last,a,b,n,1,chk);

    }

    else{
        if(lastcall==0){
            return bs(start,last-1,a,b,n,lastcall,chk);
        }else{
            return bs(start+1,last,a,b,n,lastcall,chk);
        }
    }
}

long long solve (long long a, long long b, long long n) {
    long long last = max(a,b)*n,chk = (a*b)/gcd(a,b);
    return bs(min(a,b),last,a,b,n,2,chk);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        long long a;
        cin >> a;
        long long b;
        cin >> b;
        long long n;
        cin >> n;

        long long out_;
        out_ = solve(a, b, n);
        cout << out_;
        cout << "\n";
    }
}
