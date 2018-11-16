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

vector<vi> dp;

int calc(int k,int i){
    if(k>freqs[M-1]||i>=M){
        return 0;
    }
    if(dp[k][i]!=-1)
        return dp[k][i];
    int f = bSearch(k,i);
    int ans = k+calc(k*2,f+1);
    return dp[k][i] = ans;
}

int main(){
    int sum=0;
    int i,j,k;
    cin>>N;
    vi nums;
    unordered_map<int,int> freq;
    repr(i,0,N){
        cin>>j;
        nums.pb(j);
        if(freq.find(j)==freq.end())
            freq[j]=0;
        freq[j]++;
    }
    set<int> f;
    for(auto el: freq){
        freqs.pb(el.second);
    } 
    sort(freqs.begin(),freqs.end());
    M=freqs.size();
    dp.assign(freqs[M-1]+1,vi(M,-1));
    int ans=-INF;
    repr(k,1,freqs[M-1]+1){
        ans = max(ans,calc(k,0));
    }
    cout<<ans<<endl;
    return 0;
}
