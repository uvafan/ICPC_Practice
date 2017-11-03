#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int a,b,i,j,k,NC,NE,NM;
    int coun = 0;
    while(1){
        coun++;
        cin>>NC;
        if(!NC)break;
        vector<vi> adjMat(400,vi(400,0));
        map<string,int> m;
        vector<string> events;
        string s,lastS;
        while(NC--){
            cin>>NE;
            lastS="";
            while(NE--){
                cin>>s;
                if(m.find(s)==m.end()){
                    events.push_back(s);
                    m[s] = events.size()-1;
                }
                if(lastS.size()){
                    adjMat[m[lastS]][m[s]]=1;
                }
                lastS = s;
            }
        }
        cin>>NM;
        while(NM--){
            cin>>lastS>>s;
            adjMat[m[lastS]][m[s]]=1;
        }
        for(k=0;k<events.size();k++)
            for(i=0;i<events.size();i++)
                for(j=0;j<events.size();j++)
                    adjMat[i][j] |= (adjMat[i][k]&adjMat[k][j]);
        int count = 0;
        vi top(4,-1);
        for(i=0;i<events.size();i++){
            for(j=i+1;j<events.size();j++){
                if(!(adjMat[i][j]||adjMat[j][i])){
                    count++;
                    if(top[0]==-1){
                        top[0]=i;
                        top[1]=j;
                    }
                    else if(top[2]==-1){
                        top[2]=i;
                        top[3]=j;
                    }
                }
            }
        }
        cout<<"Case "<<coun<<", ";
        if(!count)cout<<"no ";
        else cout<<count<<" ";
        cout<<"concurrent events";
        if(!count)cout<<".";
        else cout<<":";
        cout<<endl;
        if(count){
            cout<<"("<<events[top[0]]<<","<<events[top[1]]<<")";
            if(count>1) cout<<" ("<<events[top[2]]<<","<<events[top[3]]<<")";
            cout<<" "<<endl;
        }
    }
    return 0;
}
