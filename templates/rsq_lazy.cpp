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
    vi st, A, lazy;
    int n;
    int left(int p){return p<<1;}
    int right(int p){return (p<<1)+1;}

    void build(int p, int l, int r){
        if(l==r)st[p]=A[l];
        else{
            build(left(p),l,(l+r)/2);
            build(right(p),(l+r)/2+1,r);
            st[p]=st[left(p)]+st[right(p)];
        }
    }

    void change(int p,int l,int r, int ttd){
        if(!ttd)return;
        switch(ttd){
            case 1: st[p]=0; break;
            case 2: st[p]=r-l+1; break;
            case 3: st[p]=r-l+1-st[p]; break;
        }
        int le=left(p);int ri=right(p);
        if(ri<4*n){
            lazy[le] = ttd<3?ttd:3-lazy[le];
            lazy[ri] = ttd<3?ttd:3-lazy[ri];
        }
    }

    void prop(int p,int l, int r){
        if(!lazy[p])return;
        change(p,l,r,lazy[p]);
        lazy[p]=0;
    }

    int rsq(int p,int l,int r,int i,int j){
        if(i>r||j<l) return 0;
        if(l<=i&&r>=j){if(lazy[p]==1)return 0;if(lazy[p]==2)return j-i+1;}
        prop(p,l,r);
        if(l>=i&&r<=j){return st[p];}
        int a=rsq(left(p),l,(l+r)/2,i,j);
        int b=rsq(right(p),(l+r)/2+1,r,i,j);
        return a+b;
    }

    int update(int p,int l,int r,int i,int j,int ttd){
        prop(p,l,r);
        if(i>r||j<l) return st[p];
        if(l>=i&&r<=j){change(p,l,r,ttd);return st[p];}
        int a=update(left(p),l,(l+r)/2,i,j,ttd);
        int b=update(right(p),(l+r)/2+1,r,i,j,ttd);
        return st[p]=a+b;
    }

    SegTree(const vi &_A){
        A=_A; n = (int)A.size();
        st.assign(4*n,0);
        lazy.assign(4*n,0); //0 dn, 1 clear, 2 set, 3 flip
        build(1,0,n-1);
    }

    int rsq(int i,int j){
        return rsq(1,0,n-1,i,j);
    }

    void update(int i, int j, int ttd){
        //ttd: 1 clear, 2 set, 3 flip
        int a=update(1,0,n-1,i,j,ttd);
    }

};

int main(){
    int T;
    cin>>T;
    int cas=1;
    while(T--){
        cout<<"Case "<<cas<<":"<<endl;
        cas++;
        vi nums;
        string s,l;
        int M,P,j,k;
        cin>>M;
        s="";
        while(M--){
            cin>>P>>l;
            while(P--){
                s+=l;
            }
        }
        //d(s);
        for(char c: s){
            nums.pb(int(c)-'0');
        }
        SegTree st(nums);
        int Q;
        cin>>Q;
        int ca=1;
        char c;
        while(Q--){
            cin>>c>>j>>k;
            if(c=='F'){
                st.update(j,k,2);
            }
            if(c=='E'){
                st.update(j,k,1);
            }
            if(c=='I'){
                st.update(j,k,3);
            }
            if(c=='S'){
                cout<<"Q"<<ca<<": "<<st.rsq(j,k)<<endl;
                ca++;
            }
        }
    }
    return 0;
}
