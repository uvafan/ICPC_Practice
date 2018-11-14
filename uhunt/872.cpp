#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vi> solutions;

void findAllSolutions(vector<vi> adjList, vi indegree, vi solutionSoFar, vi visited){
    if(solutionSoFar.size() == indegree.size()){
        solutions.push_back(solutionSoFar);
        return;
    }
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0 && !visited[i]){
            for(int j=0;j<adjList[i].size();j++){
                indegree[adjList[i][j]]--;
            }
            solutionSoFar.push_back(i);
            visited[i] = 1;
            findAllSolutions(adjList,indegree,solutionSoFar,visited);
            visited[i] = 0;
            solutionSoFar.pop_back();
            for(int j=0;j<adjList[i].size();j++){
                indegree[adjList[i][j]]++;
            }
        }
    }
}

int main(){
    int N,i,j;
    char c;
    cin >> N;
    int count = 0;
    while(N--){
        solutions.clear();
        vi indegree;
        vector<vi> adjList;
        vector<char> chars;
        int req;
        string s;
        unordered_map<char,int> cti;
        i = 0;
        if(count){
            chars.push_back(c);
            cti[c] = 0;
            indegree.push_back(0);
            vi toAdd;
            adjList.push_back(toAdd);
            i++;
        }
        while(cin>>s){
            if(s.size()>1)break;
            c = s[0];
            chars.push_back(c);
            cti[c] = i;
            indegree.push_back(0);
            vi toAdd;
            adjList.push_back(toAdd);
            i++;
        }
        vi visited(indegree.size(),0);
        adjList[cti[s[0]]].push_back(cti[s[2]]);
        indegree[cti[s[2]]]++;
        while(cin>>s){
            if(s.size()==1)break;
            adjList[cti[s[0]]].push_back(cti[s[2]]);
            indegree[cti[s[2]]]++;
        }
        if(s.size()==1)c=s[0];
        vi sol;
        findAllSolutions(adjList,indegree,sol,visited);
        //cout << solutions.size() << endl;
        if(!solutions.size()) cout << "NO" << endl;
        else{
            for(i=0;i<solutions.size();i++){
                for(j=0;j<solutions[i].size();j++){
                    cout << chars[solutions[i][j]];
                    if(j<solutions[i].size()-1) cout << " ";
                }
                cout << endl;
            }
        }
        if(N)cout << endl;
        count++;
    }
    return 0;
}
