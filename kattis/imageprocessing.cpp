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
    int h,w,n,m,i,j,k,l;
    cin>>h>>w>>n>>m;
    vector<vi> img(h,vi(w,0));
    vector<vi> kernel(n,vi(m,0));
    repr(i,0,h){
        repr(j,0,w){
            cin>>img[i][j];
        }
    }
    repr(i,0,n){
        repr(j,0,m){
            cin>>kernel[n-i-1][m-j-1];
        }
    }
    vector<vi> ans(h-n+1,vi(w-m+1,0));
    repr(i,0,h-n+1){
        repr(j,0,w-m+1){
            int sum=0;
            repr(k,0,n){
                repr(l,0,m){
                    sum += kernel[k][l]*img[i+k][j+l];
                }
            }
            ans[i][j] = sum;
        }   
    }
    repr(i,0,h-n+1){
        repr(j,0,w-m+1){
            if(j)cout<<' ';
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}
