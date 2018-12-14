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
    int N,i,j,k;
    while(cin>>N){
        vi nums;
        repr(i,0,N){
            cin>>j;nums.pb(j);
        }
        int ans=0;
        repr(i,0,N){
            repr(j,1,N){
                if(nums[j]<nums[j-1]){
                    k=nums[j];
                    nums[j]=nums[j-1];
                    nums[j-1]=k;
                    ans++;
                }
            }
        }
        cout<<"Minimum exchange operations : "<<ans<<endl;
    }
    return 0;
}
