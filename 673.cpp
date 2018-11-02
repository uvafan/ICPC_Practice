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
    int N;
    cin>>N;
    while(N--){
        vector<char> s;
        string line;
        cin>>line;
        string out = "Yes";
        for(char c: line){
            if(c=='('||c=='[')
                s.pb(c);
            else if(c==']'){
                if(!s.size()||s[s.size()-1]!='['){
                    out="No";
                    break;
                }
                s.pop_back();
            }
            else if(c==')'){
                if(!s.size()||s[s.size()-1]!='('){
                    out="No";
                    break;
                }
                s.pop_back();
            }
        }
        if(s.size())
            out="No";
        cout<<out<<endl;
    }
    return 0;
}
