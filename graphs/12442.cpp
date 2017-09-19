#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int dfs(int u, int reach);
int loopStart;
int toStore;
vi visited;
vi check;
vi dfs_num;
vi reach;
vi adj_list;

int main(){
    int k,N;
    cin >> N;
    for(int ca = 1; ca <= N; ca++){
        dfs_num.clear();
        reach.clear();
        adj_list.clear();
        check.clear();
        cin >> k;
        int i = 0;
        for(i; i < k; i++){
            reach.push_back(0);
            dfs_num.push_back(0);
            adj_list.push_back(0);
            check.push_back(1);
        }
        for(i=0;i<k;i++){
            int f,t;
            cin >> f >> t;
            adj_list[f-1] = t-1;
        }
        for(i=0;i<k;i++){
            if(!check[i])
                continue;
            loopStart = 0;
            toStore = 0;
            reach[i] = dfs(i,0);
            for(int in = 0; in < visited.size(); in++){
                int j = visited[in];
                check[j] = 0;
                if(loopStart && toStore && dfs_num[j]>=loopStart)
                    reach[j] = toStore;
                dfs_num[j] = 0;
            }
            visited.clear();
        }
        int max = reach[0];
        int ret = 1;
        for(i=0;i<k;i++){
            //cout << "reach of " << (i+1) << " is " << reach[i] << endl;
            if(reach[i]>max){
                max = reach[i];
                ret = i+1;
            }
        }
        cout << "Case " << ca << ": " << ret << endl;
    }
    return 0;
}

int dfs(int u, int reachSoFar){
    //cout << "dfs " << u << endl;
    if(dfs_num[u]){
        toStore = reachSoFar - dfs_num[u] + 1;
        loopStart = dfs_num[u];
        return reachSoFar;
    }
    if(reach[u])
        return reach[u] + reachSoFar;
    dfs_num[u] = reachSoFar + 1;
    visited.push_back(u);
    return dfs(adj_list[u],reachSoFar+1);
}
