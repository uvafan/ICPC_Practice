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
    int N,i,j,k;
    cin>>N;
    while(N--){
        string s;
        cin>>s;
        int sum=0;
        for(int i = s.size()-2;i>-1;i-=2){
            int n = (int(s[i])-'0')*2;
            int add = (n>9?n-9:n);
            sum+=add;
        }
        for(int i=s.size()-1;i>-1;i-=2){
            sum+=(int(s[i])-'0');
        }
        if(sum%10){
            cout<<"FAIL"<<endl;
        }
        else
            cout<<"PASS"<<endl;
    }
    return 0;
}
