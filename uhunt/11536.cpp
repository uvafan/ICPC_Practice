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
    int T; cin>>T;
    int ca=0;
    while(T--){
        ca++;
        vi nums;
        int i,j,k,N,M,K;
        cin>>N>>M>>K;
        nums.pb(1);nums.pb(2);nums.pb(3);
        repr(i,3,N){
            nums.pb((nums[i-3]+nums[i-2]+nums[i-1])%M+1);
        }
        repr(i,0,N)
            nums[i]--;
        deque<int> dq;
        int count = 0;
        vi freq(K,0);
        int best=INF;
        int size=0;
        for(int num: nums){
            dq.pb(num);
            if(num<K){
                freq[num]++;
                if(freq[num]==1)
                    count++;
            }
            size++;
            while(count==K){
                int rem=dq.front();dq.pop_front();
                best = min(best,size);
                size--;
                if(rem<K){
                    freq[rem]--;
                    if(!freq[rem])
                        count--;
                }
           }
        }
        if(best<INF)
            cout<<"Case "<<ca<<": "<<best<<endl;
        else
            cout<<"Case "<<ca<<": sequence nai"<<endl;
    }
    return 0;
}
