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
    string s; cin>>s;
    if(s=="1"){
        cout<<1<<endl;
        return 0;
    }
    if(s.size()<7){
        int temp = stoi(s);
        int divisor = 0;

        while(temp!=1){
            divisor++;
            temp = temp/divisor;
            //divisor++;
        }
        cout<<divisor<<endl;
    } else {
        double n = 1;
        int counter = 1;
        //cout<<s.size()<<endl;
        while(floor(n) != s.size()){
            n += log10(counter);
            //cout<<n<<endl;
            counter++;
        }
        cout<<counter-1<<endl;

    }
    return 0;
}
