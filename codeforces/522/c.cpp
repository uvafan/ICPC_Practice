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

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    vi nums;
    vi ans;
    int N,i,j;
    cin>>N;
    repr(i,0,N){
        cin>>j;
        nums.pb(j);
    }
    int inc=1;
    int dec=5;
    repr(i,1,N){
        if(nums[i]==nums[i-1]){
            if(inc>1){
                ans.pb(inc);
                dec=(inc==5?4:5);
                inc=1;
            }
            else if(dec<5){
                ans.pb(dec);
                inc=(dec==1?2:1);dec=5;
            }
            else{
                if(ans.size()&&ans[ans.size()-1]==4)
                    ans.pb(3);
                else
                    ans.pb(4);
            }
        }
        else if(nums[i]>nums[i-1]){
            ans.pb(inc);dec=5;inc++;
            if(inc==6){
                cout<<-1<<endl; return 0;
            }
        }
        else{
            ans.pb(dec);inc=1;dec--;
            if(dec==0){
                cout<<-1<<endl; return 0;
            }
        }
    }
    if(nums[N-1]==nums[N-2]){
        ans.pb((ans[N-2]+1)%5+1);
    }
    else if(nums[N-1]>nums[N-2]){
        if(inc==6){
            cout<<-1<<endl; return 0;
        }
        ans.pb(inc);
    }
    else{
        if(dec==0){
            cout<<-1<<endl; return 0;
        }
        ans.pb(dec);
    }
    for(int n: ans){
        cout<<n<<" ";
    }
    cout<<endl;
    return 0;
}
