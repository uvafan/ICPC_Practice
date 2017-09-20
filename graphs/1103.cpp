#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <set>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};
vector<vii> grid;

vi hexToBinary(char c){
    vi v (4,0);
    //cout << "v size = " << v.size() << endl;
    switch(c){
        case '0': return v;
        case '1': v[3]=1; return v;
        case '2': v[2]=1; return v;
        case '3': v[2]=1;v[3]=1; return v;
        case '4': v[1]=1; return v;
        case '5': v[1]=1;v[3]=1; return v;
        case '6': v[1]=1;v[2]=1; return v;
        case '7': v[1]=1;v[2]=1;v[3]=1; return v;
        case '8': v[0]=1; return v;
        case '9': v[0]=1;v[3]=1; return v;
        case 'a': v[0]=1;v[2]=1; return v;
        case 'b': v[0]=1;v[2]=1;v[3]=1; return v;
        case 'c': v[0]=1;v[1]=1; return v;
        case 'd': v[0]=1;v[1]=1;v[3]=1; return v;
        case 'e': v[0]=1;v[1]=1;v[2]=1; return v;
        case 'f': v.assign(4,1); return v;
    }
    return v;
}

void floodfillwhite(int r, int c, int region){
    if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size()) return;
    if(grid[r][c].first || grid[r][c].second) return;
    //cout << "r = " << r << " c = " << c << endl;
    grid[r][c].second = region;
    for(int i=0;i<8;i++) floodfillwhite(r+dr[i],c+dc[i],region);
}

set<int> floodfillblack(int r, int c, int region, set<int> borders){
    if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size()) return borders;
    if(!grid[r][c].first){
        borders.insert(grid[r][c].second);
        return borders;
    }
    else if(grid[r][c].second){
        return borders;
    }
    grid[r][c].second = region;
    for(int i=0;i<8;i++) borders = floodfillblack(r+dr[i],c+dc[i],region,borders);
    return borders;
}

void printRegions(){
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            cout << grid[i][j].second;
        }
        cout << endl;
    }
}

int main(){
    int H,W,i,j;
    string line;
    int ca = 1;
    while(1){
        cin >> H >> W;
        if(!H && !W)
            break;
        grid.clear();
        //cout << "b0" << endl;
        while(H--){
            cin >> line;
            vii toAdd;
            for(i=0;i<line.size();i++){
                vi bin = hexToBinary(line[i]);
                for(j=0;j<4;j++){
                    //cout << bin[j];
                    toAdd.push_back(make_pair(bin[j],0));
                }
            }
            //cout << endl;
            grid.push_back(toAdd);
        }
        //cout << "b1" << endl;
        //fill white spaces - first fill edges with region 1 then go from there
        for(i=0;i<grid.size();i++){
            if(!(grid[i][0].first || grid[i][0].second)){
                floodfillwhite(i,0,1);
            }
            if(!(grid[i][grid[0].size()-1].first || grid[i][grid[0].size()-1].second))
                floodfillwhite(i,grid[0].size()-1,1);
        }
        for(j=0;j<grid[0].size();j++){
            if(!(grid[0][j].first || grid[0][j].second))
                floodfillwhite(0,j,1);
            if(!(grid[grid.size()-1][j].first || grid[grid.size()-1][j].second))
                floodfillwhite(grid.size()-1,j,1);
        }
        int regions = 1;
        for(i=0;i<grid.size();i++){
            for(j=0;j<grid[0].size();j++){
                if(!(grid[i][j].first || grid[i][j].second)){
                    regions++;
                    floodfillwhite(i,j,regions);
                }
            }
        }
        //cout << "b2";
        vi ret (6,0);
        //count black space types
        for(i=0;i<grid.size();i++){
            for(j=0;j<grid[0].size();j++){
                if(grid[i][j].first && !grid[i][j].second){
                    set<int> borders;
                    regions++;
                    borders = floodfillblack(i,j,regions,borders);
                    ret[borders.size()-1]++;
                }
            }
        }
        string s (ret[1],'A');
        s.append(ret[5], 'D');
        s.append(ret[3], 'J');
        s.append(ret[2], 'K');
        s.append(ret[4], 'S');
        s.append(ret[0], 'W');
        cout << "Case " << ca << ": " << s << endl;
        ca++;
    }
    return 0;
}



