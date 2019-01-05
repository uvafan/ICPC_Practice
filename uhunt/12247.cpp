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
    int a,b,c,d,e;
    while(cin>>a>>b>>c>>d>>e&&a){
        vi cess = {a,b,c};
        vi ince = {d,e};
        sort(cess.begin(),cess.end());
        sort(ince.begin(),ince.end());
        set<int> s = {a,b,c,d,e};
        int ans;
        int ret=-1;
        repr(ans,1,53){
            if(s.find(ans)!=s.end())
                continue;
            vi n=ince;
            n.pb(ans);
            sort(n.begin(),n.end());
            if(n[0]>cess[1]||n[1]>cess[2]){
                ret=ans;
                break;
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}
