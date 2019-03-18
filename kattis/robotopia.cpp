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
    int n; cin>>n;
    while(n--){
        int l1, a1, l2, a2, lt, at;
        cin>>l1>>a1>>l2>>a2>>lt>>at;

        int one=0;
        int two=0;
        int solutions=0;
        for(int i=1; (l1*i<lt) && (a1*i<at) && solutions<2; i++){

            if((lt-(i*l1))%l2 != 0) continue;


            if((at-(i*a1))%a2 != 0) continue;
            int temptwo = (lt-(i*l1))/l2;
            int temp = (at-(i*a1))/a2;
            if(temptwo==temp&&temp){
                solutions++;
                one=i;two=temp;
            }
        }
        
        if(solutions==1){
            cout<<one<<' '<<two<<endl;
        }
        else{
            cout<<'?'<<endl;
        }
    }
    return 0;
}
