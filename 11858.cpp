#include <bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> ii;
typedef vector<ii> vii;
typedef vector<long long> vi;

#define repr(i,l,r) for(long long i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (long long)1e9
#define EPS 1e-9

pair<vi,long long> inv(vi nums){
    if(nums.size()==1)
        return make_pair(nums,0);
    vi left(nums.begin(),nums.begin()+nums.size()/2);
    vi right(nums.begin()+nums.size()/2,nums.end());
    pair<vi,long long> l = inv(left);
    pair<vi,long long> r = inv(right);
    vi larr=l.first, rarr=r.first;
    long long inversions = l.second+r.second;
    vi ret;
    long long lp=0;
    long long rp=0;
    while(lp<larr.size()&&rp<rarr.size()){
        if(larr[lp]<=rarr[rp]){
            ret.pb(larr[lp]);
            lp++;
        }
        else{
            ret.pb(rarr[rp]);
            rp++;
            inversions+=(larr.size()-lp);
        }
    }
    while(lp<larr.size()){
        ret.pb(larr[lp]);
        lp++;
    }
    while(rp<rarr.size()){
        ret.pb(rarr[rp]);
        rp++;
    }
    return make_pair(ret,inversions);
}

int main(){
    long long N,i,j,k;
    while(cin>>N){
        vi nums;
        repr(i,0,N){
            cin>>j;
            nums.pb(j);
        }
        cout<<inv(nums).second<<endl;
    }
    return 0;
}
