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
    cin>>N;
    vi nums;
    int max=-INF; int nextMax=-INF;
    repr(i,0,N){
        cin>>j;
        nums.pb(j);
        sum+=j;
        if(j>max){
            nextMax=max;
            max=j;
        }
        else if(j>nextMax)
            nextMax=j;
    }
    vi ans;
    repr(i,0,N){
        j=nums[i];
        k=sum-j;
        int sumTo=(j==max?nextMax:max);
        if(k-sumTo==sumTo)
            ans.pb(i+1);
    }
    if(!ans.size()){
        cout<<'0'<<endl;
    }
    else{
        cout<<ans.size()<<endl;
        cout<<ans[0];
        repr(i,1,ans.size())
            cout<<' '<<ans[i];
        cout<<endl;
    }
    return 0;
}
