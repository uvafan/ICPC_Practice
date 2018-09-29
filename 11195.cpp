#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define pb push_back
#define INF 1e9

int ans;
int N,i,j,OK;
vi bad;

void backtrack(int rw, int ld, int rd, int col){
    if(rw==OK) {ans++; return; }
    int pos = OK & (~(rw | ld | rd | bad[col]));
    while(pos){
        int p = pos&-pos;
        pos-=p;
        backtrack(rw|p,(ld|p)<<1,(rd|p)>>1,col+1);
    }
}

int main(){
    int ca=0;
    while(cin>>N&&N){
        ca++;
        ans=0;
        bad.assign(N,0);
        OK = (1<<N)-1;
        for(i=0;i<N;i++){
            string line;
            cin>>line;
            for(j=0;j<N;j++){
                if(line[j]=='*'){
                    bad[j] += 1<<i;
                }
            }
        }
        backtrack(0,0,0,0);
        cout<<"Case "<<ca<<": "<<ans<<endl;
    }
    return 0;
}
