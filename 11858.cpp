#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9

pair<vi,int> inv(vi nums){
    if(nums.size()==1)
        return make_pair(nums,0);
    vi left(nums.begin(),nums.begin()+nums.size()/2);
    vi right(nums.begin()+nums.size()/2,nums.end());
    pair<vi,int> l = inv(left);
    pair<vi,int> r = inv(right);
    vi larr=l.first, rarr=r.first;
    int inversions = l.second+r.second;
    vi ret;
    int lp=0;
    int rp=0;
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
    int N,i,j,k;
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
