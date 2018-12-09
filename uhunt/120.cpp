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
    while(1){
        int i,j,k;
        vi nums;
        while(cin>>j){
            nums.pb(j);
            cout<<j<<' ';
            if(cin.peek()=='\n')
                break;
        }
        if(!nums.size())
            break;
        cout<<endl;
        reverse(nums.begin(),nums.end());
        repr(i,0,nums.size()){
            int maxIndex=-1;
            int max = -INF;
            repr(j,i,nums.size()){
                if(nums[j]>max){
                    max=nums[j];
                    maxIndex=j;
                }
            }
            if(maxIndex==i){
                continue;
            }
            else{
                if(maxIndex<nums.size()-1){
                    reverse(nums.begin()+maxIndex,nums.end());
                    cout<<maxIndex+1<<' ';
                }
                reverse(nums.begin()+i,nums.end());
                cout<<i+1<<' ';
            }
        }
        cout<<0<<endl;
    }
    return 0;
}
