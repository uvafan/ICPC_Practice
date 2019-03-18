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

vector<string> t = {"@","8","(","|)","3","#","6","[-]","|","_|","|<","1","[]\\/[]","[]\\[]","0","|D","(,)","|Z","$","']['","|_|","\\/","\\/\\/","}{","`/","2"};

int main(){
    string line;
    getline(cin,line);
    string ret;
    int i,j,k;
    for(char c: line){
        int asc = int(c);
        if(asc>64&&asc<91){
            ret+=t[asc-65];
        }
        else if(asc>96&&asc<123){
            ret+=t[asc-97];
        }
        else{
            ret += c;
        }
    }
    cout<<ret<<endl;
    return 0;
}
