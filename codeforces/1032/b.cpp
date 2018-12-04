#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<int,int,custom_hash> m;

void p(string s, int a,int r, int c){
    cout<<r<<' '<<c<<endl;
    int i,j;
    repr(i,0,r){
        int rowsLeft = r-i;
        int astsInRow = a/rowsLeft;
        string o = "";
        repr(j,0,astsInRow)
            o+='*';
        o+=s.substr(0,c-astsInRow);
        cout<<o<<endl;
        a-=astsInRow;
        s = s.substr(c-astsInRow);
    }
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    string s;
    cin>>s;
    int L=s.size();
    int i,j,k;
    repr(i,1,6){
        repr(j,0,i*20-L+1){
            if((L+j)%i==0&&(L+j)/i<21){
                p(s,j,i,(L+j)/i);
                return 0;
            }
        }
    }
}
