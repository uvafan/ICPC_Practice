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

vi freqs;

int bSearch(int t,int lo){
    if(freqs[lo]>=t)
        return lo;
    int hi=freqs.size()-1;
    while(lo<hi){
        int mid = (lo+hi)/2;
        if(freqs[mid]<t){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    return lo;
}
int N,M;
/*
int dp[1000][200000];

int solve(int i, int ma){
    if(i>=M)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans = -INF;
    int k;
    repr(k,i+1,M){
        
    }
    return dp[i][j] = ans;
}*/


int calc(int k){
    int i=0;
    int ans=0;
    while(true){
        i = lower_bound(freqs.begin()+i,freqs.end(),k)-freqs.begin();
        if(i==freqs.size())
            break;
        ans += k;
        k*=2;
        i+=1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int sum=0;
    int i,j,k;
    cin>>N;
    map<int,int> freq;
    repr(i,0,N){
        cin>>j;
        freq[j]++;
    }
    for(auto el: freq){
        freqs.pb(el.second);
    } 
    sort(freqs.begin(),freqs.end());
    M=freqs.size();
    int ans=-INF;
    repr(k,1,freqs[M-1]+1){
        ans = max(ans,calc(k));
    }
    cout<<ans<<endl;
    return 0;
}
