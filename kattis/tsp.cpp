#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<double,double> dd;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9

int N;

int getDist(dd a, dd b){
    return int(hypot(b.first-a.first,b.second-a.second));
}

int main(){
    vector<dd> points;
    int i,j,k;
    double a,b;
    cin>>N;
    repr(i,0,N){
        cin>>a>>b;
        points.pb(dd(a,b));
    }
    vi used(N,0);
    used[0]=1;
    cout<<0<<endl;
    repr(i,1,N){
        int lastIndex = used[used.size()-1];
        int minIndex=-1;
        int minDist = INF;
        repr(j,0,N){
            if(used[j]){
                continue;
            }
            int dist = getDist(points[lastIndex],points[j]);
            if(dist<minDist){
                minDist=dist;
                minIndex=j;
            }
        }
        lastIndex=minIndex;
        used[lastIndex]=1;
        cout<<lastIndex<<endl;
    }
    return 0;
}
