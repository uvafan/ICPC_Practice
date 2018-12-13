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
    int h,u,d,f,i,j,k;
    while(1){
        cin>>h>>u>>d>>f;
        if(!h)
            break;
        double step=u;
        double loc=0;
        double ff = f/100.0;
        int day=0;
        while(1){
            day++;
            loc+=step;
            if(loc-h>EPS){
                cout<<"success on day "<<day<<endl;
                break;
            }
            loc-=d;
            if(loc<-EPS){
                cout<<"failure on day "<<day<<endl;
                break;
            }
            step-=ff*u;
            step=max(step,0.0);
        }
    }
    return 0;
}
