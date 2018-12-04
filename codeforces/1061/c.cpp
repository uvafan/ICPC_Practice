#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<int,int,custom_hash> m;

int MOD = INF+7;
vi nums;
int N;
int K=500;
/*
int solve(int i, int j){
    if(i==N-1&&nums[i]%j==0)
        return 1;
    if(i==N)
        return 0;
    if(j<K&&dp[i][j]!=-1)
        return dp[i][j];
    int ans=solve(i+1,j);
    if(nums[i]%j==0)
        ans += 1+solve(i+1,j+1);
    ans = ans%MOD;
    if(j<K)
        dp[i][j]=ans;
    return ans;
}*/

set<int> getFactors(int i){
    int j;
    set<int> ret;
    ret.insert(-i);
    for(int j=sqrt(i);j>0;j--){
        if(i%j==0){
            ret.insert(-j);
            ret.insert(-(i/j));
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>N;
    int i,j,k;
    vi nums;
    repr(i,0,N){
        cin>>j;nums.pb(j);
    }
    vi dp(1000001,0);
    dp[0]=1;
    repr(i,0,N){ 
        for(int f: getFactors(nums[i])){ 
            int n=-f;
            dp[n]+=dp[n-1];
            dp[n]%=MOD;
            //d(i);d(e.first+1);d(nm[e.first+1]);d(e.second);d(m[e.first+1]);
        }
    }
    int ret=0;
    repr(i,1,1000001){
        ret+=dp[i];
        ret%=MOD;
    }
    cout<<ret<<endl;
    return 0;
}
