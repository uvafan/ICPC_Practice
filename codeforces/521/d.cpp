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

int main(){
    int sum=0;
    int N,i,j,k;
    cin>>N>>k;
    vi nums;
    unordered_map<int,int> freq;
    repr(i,0,N){
        cin>>j;
        nums.pb(j);
        if(freq.find(j)==freq.end())
            freq[j]=0;
        freq[j]++;
    }
    int lo=0;int hi=N;
    int copies;
    while(lo<hi){
        copies=(lo+hi)/2+1;
        int canCut=0;
        for(auto el: freq){
            canCut+=(el.second/copies);
            if(canCut>=k)
                break;
        }
        if(canCut<k){
            hi = copies-1;
        }
        else{
            lo=copies;
        }
    }
    copies=lo;
    vi ans;
    for(auto el: freq){
        repr(i,0,el.second/copies){
            ans.pb(el.first);
        }
    }
    cout<<ans[0];
    repr(i,1,k){
        cout<<' '<<ans[i];
    }
    cout<<endl;
    return 0;
}
