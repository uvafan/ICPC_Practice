#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9

int main(){
    int N,i;
    int ca=0;
    while(cin>>N&&N){
        ca++;
        int ans = 0;
        unordered_map<string,int> dist_s;
        unordered_map<string,int> dist_t;
        string a,s,t;
        for(i=1;i<=N;i++){
            t+=to_string(i);
        }
        for(i=0;i<N;i++){
            cin>>a;
            s+=a;
        }
        dist_t[t]=0;
        dist_s[s]=0;
        if(s==t){
            cout<<"Case "<<ca<<": "<<0<<endl;
            continue;
        }
        queue<string> q;
        q.push(s);
        while(!q.empty()&&!ans){
            string u=q.front(); q.pop();
            int d = dist_s[u];
            int cstart, cend, pspot;
            for(cstart=0;cstart<N;cstart++){
                for(cend=cstart;cend<N;cend++){
                    string cut = u.substr(cstart,cend-cstart+1);
                    string umcut = u.substr(0,cstart)+u.substr(cend+1,u.size()-cend-1);
                    for(pspot=0;pspot<umcut.size()+1;pspot++){
                        string v=umcut.substr(0,pspot)+cut;
                        if(pspot<umcut.size()){
                            v+=umcut.substr(pspot,umcut.size()-pspot);
                        }
                        if(dist_s.find(v)==dist_s.end()){
                            if(v==t){
                                ans=d+1;
                            }
                            dist_s[v]=d+1;
                            if(!d){
                                q.push(v);
                            }
                        }
                    }
                }
            }
        }
        q.push(t);
        while(!q.empty()&&!ans){
            string u=q.front(); q.pop();
            int d = dist_t[u];
            int cstart, cend, pspot;
            for(cstart=0;cstart<N;cstart++){
                for(cend=cstart;cend<N;cend++){
                    string cut = u.substr(cstart,cend-cstart+1);
                    string umcut = u.substr(0,cstart)+u.substr(cend+1,u.size()-cend-1);
                    for(pspot=0;pspot<umcut.size()+1;pspot++){
                        string v=umcut.substr(0,pspot)+cut;
                        if(pspot<umcut.size()){
                            v+=umcut.substr(pspot,umcut.size()-pspot);
                        }
                        if(dist_t.find(v)==dist_t.end()){
                            if(dist_s.find(v)!=dist_s.end()){
                                ans = d+1+dist_s[v];
                            }
                            dist_t[v]=d+1;
                            if(!d){
                                q.push(v);
                            }
                        }
                    }
                }
            }
        }
        if(!ans){
            cout<<"Case "<<ca<<": "<<5<<endl;
        }
        else
            cout<<"Case "<<ca<<": "<<ans<<endl;
    }
    return 0;
}
