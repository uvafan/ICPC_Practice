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

unordered_map<char,char> rev = 
{{'A','A'},{'E','3'},{'H','H'},{'I','I'},{'J','L'},{'L','J'},{'M','M'},{'O','O'},{'S','2'},{'T','T'},{'U','U'},{'V','V'},{'W','W'},{'X','X'},{'Y','Y'},{'Z','5'},{'1','1'},{'2','S'},{'3','E'},{'5','Z'},{'8','8'}};

int main(){
    string s;
    while(cin>>s){
        bool pal=true;
        bool mir=true;
        int l = 0;
        int h = s.size()-1;
        while(l<=h){
            if(s[l]!=s[h])
                pal=false;
            if(rev.find(s[l])==rev.end()||rev.find(s[h])==rev.end()||rev[s[l]]!=s[h]||rev[s[h]]!=s[l])
                mir=false;
            l++;
            h--;
        }
        if(!mir&&!pal)
            cout<<s<<" -- is not a palindrome.\n\n";
        else if(!mir&&pal)
            cout<<s<<" -- is a regular palindrome.\n\n";
        else if(mir&&!pal)
            cout<<s<<" -- is a mirrored string.\n\n";
        else
            cout<<s<<" -- is a mirrored palindrome.\n\n";
    }
    return 0;
}
