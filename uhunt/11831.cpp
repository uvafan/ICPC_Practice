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

int main(){
    //0=..1=*,2=#
    //orientation: N->0,E->1,S->2,W->3
    vector<vi> g;
    ii loc;
    int rows, cols, moves, cups, orientation;
    string row;
    char c;
    while(1){
        cups = 0;
        g.clear();
        scanf("%d %d %d",&rows,&cols,&moves);
        if(rows == 0 && cols == 0 && moves == 0)
            break;
        for(int i = 0; i < rows; i++){
            vi toAdd;
            cin >> row;
            //cout << "row = " << row << endl;
            for(int j = 0; j < cols; j++){
                c = row[j];    
                if(c=='.')
                    toAdd.push_back(0);
                else if(c=='*')
                    toAdd.push_back(1);
                else if(c=='#')
                    toAdd.push_back(2);
                else{
                    loc.first = i;
                    loc.second = j; 
                    toAdd.push_back(0);
                    if(c=='N')
                        orientation = 0;
                    else if(c=='L')
                        orientation = 1;
                    else if(c=='S')
                        orientation = 2;
                    else
                        orientation = 3;
                }
            }
            g.push_back(toAdd);
        }
        /*for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g[0].size(); j++){
                cout << g[i][j];
            }
            cout << endl;
        }*/
        string m;
        cin >> m;
        for(int i = 0; i < moves; i++){
            //printf("loc = %d,%d\n",loc.first,loc.second);
            char move = m[i];
            if(move=='F'){
                ii moveTo = loc;
                switch(orientation){
                    case 0:moveTo.first--; break;
                    case 1:moveTo.second++; break;
                    case 2:moveTo.first++; break;
                    case 3:moveTo.second--; break;
                }
                if(moveTo.first >= g.size() || moveTo.first < 0
                        || moveTo.second >= g[0].size() || moveTo.second < 0
                        || g[moveTo.first][moveTo.second] == 2)
                    continue;
                loc = moveTo;
                //cout << "moving to " << g[loc.first][loc.second] << endl;
                if(g[loc.first][loc.second] == 1){
                    cups++;
                    g[loc.first][loc.second] = 0;
                }
            }
            else if(move == 'D'){
                orientation = (orientation+1) % 4;
            }
            else{
                orientation--;
                if(orientation<0)
                    orientation = 3;
            }
        }
        cout << cups << endl;
    }
}   
