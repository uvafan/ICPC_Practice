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

int N,C;
vi nums,cs;
map<int,int> freq;

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int ret=0;
    int i,j,k;
    cin>>N>>C;
    vi sumcs;
    int cs=0;
    repr(i,0,N){
        cin>>j;
        nums.pb(j);
        if(j==C)cs++;
        sumcs.pb(cs);
    }
    int maxDiff = 0;
    map<int,int> curSum;
    map<int,int> lastO;
    repr(i,0,N){
        if(nums[i]==C)continue;
        if(lastO.find(nums[i])==lastO.end()){
            curSum[nums[i]]=1;
            maxDiff = max(maxDiff,1);
        }
        else{
            int cssinceLast = sumcs[i]-sumcs[lastO[nums[i]]];
            curSum[nums[i]] = max(curSum[nums[i]]+1-cssinceLast,1);
            maxDiff = max(maxDiff,curSum[nums[i]]);
        }
        lastO[nums[i]]=i;
    }
    cout<<cs+maxDiff<<endl;
    return 0;
}
