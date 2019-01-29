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

class UnionFind {
    private: vi p,rank;
    public:
        UnionFind(int N){
            rank.assign(N,0);
            p.assign(N,0);
            int i;
            repr(i,0,N)p[i]=i;
        }

        int findSet(int i){
            return (p[i]==i) ? i : (p[i] == findSet(p[i]));
        }

        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j){
            if(!isSameSet(i,j)){
                int x = findSet(i), y = findSet(j);
                if(rank[x]>rank[y]){
                    p[y]=x;
                }
                else{
                    p[x]=y;
                    if(rank[x]==rank[y])
                        rank++;
                }
            }
        }
}

int main(){
    int N,M,i,j,k;
    cin>>N>>M;
    UnionFind uf = UnionFind(N);
    while(M--){
        cin>>i;
        if(i==1){
            cin>>j>>k;
            uf.unin(j,k);
        }
        else if(i==2){
            cin>>j>>k;
            uf.move(j,k);
        }
        else{
            cin>>j;
            ii ret = uf.sizesum(j);
            cout<<ret.first<<' '<<ret.second<<endl;
        }
    }
    return 0;
}
