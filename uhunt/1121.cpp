#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (ll)1e9
#define EPS 1e-9

int main(){
    int N,S;
    while(cin>>N>>S){
        vi nums;
        int i,j,k;
        repr(i,0,N){
            cin>>j;
            nums.pb(j);
        }
        deque<int> dq;
        ll sum=0;
        ll best=INF;
        ll size=0;
        repr(i,0,N){
            dq.pb(nums[i]);
            sum+=nums[i];
            size++;
            while(sum>=S){
                sum-=dq.front();dq.pop_front();
                best = min(best,size);
                size--;
           }
        }
        if(best==INF)
            best=0;
        cout<<best<<endl;
    }
    return 0;
}
