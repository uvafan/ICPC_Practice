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

struct SegTree{
    vi st, A;
    int n;
    int left(int p){return p<<1;}
    int right(int p){return (p<<1)+1;}

    void build(int p, int l, int r){
        if(l==r)st[p]=l;
        else{
            build(left(p),l,(l+r)/2);
            build(right(p),(l+r)/2+1,r);
            int p1=st[left(p)],p2=st[right(p)];
            st[p] = (A[p1]>=A[p2])?p1:p2;
        }
    }

    int rmq(int p,int l,int r,int i,int j){
        if(i>r||j<l) return -1;
        if(l>=i&&r<=j)return st[p];
        int p1=rmq(left(p),l,(l+r)/2,i,j);
        int p2=rmq(right(p),(l+r)/2+1,r,i,j);
        if(p1==-1)return p2; if(p2==-1) return p1;
        return (A[p1]>=A[p2]?p1:p2);
    }

    SegTree(const vi &_A){
        A=_A; n = (int)A.size();
        st.assign(4*n,0);
        build(1,0,n-1);
    }

    int rmq(int i,int j){
        return rmq(1,0,n-1,i,j);
    }

};

int main(){
    int N;
    while(cin>>N&&N){
        vi nums;
        vi seg;
        int Q,i,j,k;
        cin>>Q;
        k=0;
        vi starts;
        vi counts;
        repr(i,0,N){cin>>j;nums.pb(j);
            if(i==0){
                starts.pb(0);
            }
            else if(j!=nums[i-1]){
                k++;
                counts.pb(i-starts[starts.size()-1]);
                starts.pb(i);
            }
            seg.pb(k);
        }
        counts.pb(N-starts[starts.size()-1]);
        SegTree st(counts);
        repr(i,0,Q){
            cin>>j>>k;j--;k--;
            int segLow=seg[j];int segHi = seg[k];
            int ans=-1;
            if(segLow==segHi){
                ans = k-j+1;
            }
            else{
                if(segLow+1<=segHi-1){
                    int idx = st.rmq(segLow+1,segHi-1);
                    ans = counts[idx];
                }
                ans = max(ans,starts[segLow+1]-j);
                ans = max(ans,k-starts[segHi]+1);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
