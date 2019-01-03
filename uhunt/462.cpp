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
    string line;
    while(getline(cin,line)){
        map<char,int> suitCounts; 
        map<char,int> stopped;
        int points=0;
        vector<string> cards;
        int i,j,k;
        for(i=0;i<39;i+=3){
            cards.pb(line.substr(i,2));
        }
        for(string s: cards){
            suitCounts[s[1]]++;
        }
        map<char,int> priority = {{'S',4},{'H',3},{'D',2},{'C',1}};
        for(string s: cards){
            if(s[0]=='A'){
                points+=4;
                stopped[s[1]]=1;
            }
            else if(s[0]=='K'){
                points+=3;
                if(suitCounts[s[1]]==1)
                    points-=1;
                else
                    stopped[s[1]]=1;
            }
            else if(s[0]=='Q'){
                points+=2;
                if(suitCounts[s[1]]<=2)
                    points-=1;
                else
                    stopped[s[1]]=1;
            }
            else if(s[0]=='J'){
                points+=1;
                if(suitCounts[s[1]]<=3)
                    points-=1;
            }
        }
        int priorPoints = points;
        char maxSuit = '-';
        int count = 0;
        int pri = 0;
        int stop = 0;
        for(auto el: priority){
            if(suitCounts[el.first]<=1)
                points+=2;
            else if(suitCounts[el.first]==2)
                points+=1;
            if(suitCounts[el.first]>count||suitCounts[el.first]==count&&el.second>pri){
                maxSuit=el.first;
                pri=el.second;
                count=suitCounts[el.first];
            }
            stop+=stopped[el.first];
        }
        if(points<14)
            cout<<"PASS\n";
        else if(priorPoints>=16&&stop==4)
            cout<<"BID NO-TRUMP\n";
        else
            cout<<"BID "<<maxSuit<<"\n";
    }
    return 0;
}
