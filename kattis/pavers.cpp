#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9

iii dp[(int)1e6][2]; //0 is no overflow, 1 is overflow

iii sum(iii a, iii b){
    return iii(ii(a.first.first+b.first.first,a.first.second+b.first.second),ii(a.second.first+b.second.first,a.second.second+b.second.second));
}

iii create(int a,int b, int c, int d){
    return iii(ii(a,b),ii(c,d));
}

iii mult(iii a, int b){
    return create(a.first.first*b,a.first.second*b,a.second.first*b,a.second.second*b);
}

iii solve(int r, int o){
    if(dp[r][o].first.first > -1){
        return dp[r][o];
    }
    if(r==0 && o==0){
        return create(1,0,0,0);
    }
    else if(r<1){
        return iii(ii(0,0),ii(0,0));
    }
    iii ret = create(0,0,0,0);
    iii obo = create(0,1,0,0);
    iii obt = create(0,0,1,0);
    iii tro = create(0,0,0,1);
    if(o==0){
        ret = sum(ret,mult(solve(r,1),2));
        ret = sum(ret,mult(obo,solve(r,1).first.first*2));
        //overcounting
        ret.first.first -= solve(r-1,0).first.first;
        ret.first.second -= solve(r-1,0).first.second*2 + 2;
        ret.second.first -= solve(r-1,0).second.first;
        ret.second.second -= solve(r-1,0).second.second;
        //d(r);d(o);d(ret.first.first);d(ret.first.second);
        ret = sum(ret,solve(r-1,0));
        ret = sum(ret,mult(obt,solve(r-1,0).first.first));
        if(r-1>0){
            ret = sum(ret,mult(solve(r-1,1),2));
            ret = sum(ret,mult(tro,solve(r-1,1).first.first*2));
            ret = sum(ret,solve(r-2,0));
            ret = sum(ret,mult(obt,solve(r-2,0).first.first*2));
        }
    }
    else if(o==1){
        ret = sum(ret,solve(r-1,0));
        ret = sum(ret,mult(obo,solve(r-1,0).first.first));
        //d(r);d(o);d(ret.first.first);d(ret.first.second);
        if(r-1>0){
            ret = sum(ret,solve(r-1,1));
            ret = sum(ret,mult(obt,solve(r-1,1).first.first));
            ret = sum(ret,solve(r-2,0));
            ret = sum(ret,mult(tro,solve(r-2,0).first.first));
        }
    }
    //d(r);d(o);d(ret.first.first);d(ret.first.second);
    return dp[r][o]=ret;
}

int main(){
    int n; cin>>n;
    repr(i,0,(int)1e6)repr(j,0,2)dp[i][j]=iii(ii(-1,-1),ii(-1,-1));
    iii ans = solve(n,0);
    cout<<ans.first.first<<' '<<ans.first.second<<' '<<ans.second.first<<' '<<ans.second.second<<endl;
    return 0;
}
