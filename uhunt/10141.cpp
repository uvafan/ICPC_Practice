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
    double p,bp;
    int N,P,i,j,k;
    string a,b,w;
    int ca=0;
    while(cin>>N>>P>>ws&&(N||P)){
        if(ca)cout<<endl;
        ca++;
        while(N--){getline(cin,a);}
        w="";
        j=-1;
        bp=INF*1.0;
        while(P--){
            getline(cin,a);
            cin>>p>>i>>ws;
            if(i>j||(i==j&&p<bp-EPS)){
                j=i;
                bp=p;
                w=a;
            }
            while(i--)getline(cin,a);
        }
        cout<<"RFP #"<<ca<<'\n'<<w<<endl;
    }
    return 0;
}
