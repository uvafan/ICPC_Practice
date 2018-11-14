#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef set<int> si;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9

int main(){
    int i;
    si primes;
    int p[] = {2,3,5,7,11,13};
    repr(i,0,8){
        primes.insert(p[i]);
    }
    int ca=0;
    while(1){
        ca++;
        int x;
        cin>>x;
        if(!x)
            break;
        vi male(8,0);
        string s = to_string(abs(x));
        if(x>0)
            male[x-1]=1;
        repr(i,0,7){
            cin>>x;
            if(x>0)
                male[x-1]=1;
            s+=to_string(abs(x));
        }
        queue<string> q;
        q.push(s);
        unordered_map<string,int> dist;
        dist[s]=0;
        string t = "12345678";
        while(!q.empty()){
            string u = q.front(); q.pop();
            if(u==t)
                break;
            //d(u);
            int asker, askee, askee1;
            repr(asker,0,8){
                repr(askee1,0,8){
                    askee=askee1;
                    int askerNum = u[asker] - '0';
                    int askeeNum = u[askee] - '0';
                    if(male[askerNum-1]==male[askeeNum-1]||primes.find(askerNum+askeeNum)==primes.end())
                        continue;
                    //d(askerNum);
                    //d(askeeNum);
                    string aremoved = u.substr(0,asker)+u.substr(asker+1,u.size()-asker-1);
                    if(asker<askee)
                        askee--;
                    string vleft = aremoved.substr(0,askee)+u[asker]+aremoved.substr(askee,aremoved.size()-askee);
                    string vright = aremoved.substr(0,askee+1)+u[asker]+aremoved.substr(askee+1,aremoved.size()-askee-1);
                    if(dist.find(vleft)==dist.end()){
                        dist[vleft] = dist[u]+1;
                        q.push(vleft);
                        //d(vleft);
                    }
                    if(dist.find(vright)==dist.end()){
                        dist[vright] = dist[u]+1;
                        q.push(vright);
                        //d(vright);
                    }
                }
            }
        }
        if(dist.find(t)==dist.end()){
            cout<<"Case "<<ca<<": "<<"-1"<<endl;
        }
        else
            cout<<"Case "<<ca<<": "<<dist[t]<<endl;
    }
    return 0;
}
