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
    cin>>N>>ws;
    int ca=0;
    while(N--){
        ca++;
        vector<string> pile;
        int i,j,k;
        string s;
        for(i=0;i<52;i++){
            cin>>s;
            pile.pb(s);
        }
        vector<string> hand;
        repr(i,0,25){
            hand.push_back(pile[pile.size()-1]);
            pile.pop_back();
        }
        int y=0;
        int x;
        repr(i,0,3){
            string c = pile[pile.size()-1];
            pile.pop_back();
            if(!isdigit(c[0]))
                x=10;
            else
                x=int(c[0])-'0';
            y+=x;
            repr(j,0,10-x)
                pile.pop_back();
        }
        for(i=24;i>-1;i--){
            pile.pb(hand[i]);
        }
        cout<<"Case "<<ca<<": "<<pile[y-1]<<"\n";
    }
    return 0;
}
