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
int N,M;

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int s,r,i,j,k;
    cin>>N>>M;
    priority_queue<int> pq;
    vector<priority_queue<int> > people(M,pq);
    set<int> subjects; 
    repr(i,0,N){
        cin>>s>>r;
        people[s-1].push(r);
        subjects.insert(s-1);
    }
    vi sums(M,0);
    int ans=0;
    repr(i,0,1e5){
        int sum=0;
        set<int> nextsubs;
        for(int s: subjects){
            sums[s]+=people[s].top(); people[s].pop();
            sum = max(sum,sum+sums[s]);
            if(sums[s]<=0||people[s].empty()){
                continue;
            }
            nextsubs.insert(s);
        }
        subjects = nextsubs;
        ans = max(sum,ans);
    }
    cout<<ans<<endl;
    return 0;
}
