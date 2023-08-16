#include <vector>
#include <cmath>
#include <queue>
#include <iostream>
#include <set>

using namespace std;


class Solution {
public:
    int n;
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        vector<vector<bool>>visited(n, vector<bool>(n, false));
        queue<pair<int, int>> thieves;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    pair<int, int> p = {i,j};
                    thieves.push(p);
                    visited[i][j] = true;
                }
            }
        }


        int d = 0;
        while(!thieves.empty()){
            int size = thieves.size();
            while (size--){
                pair curr = thieves.front();
                thieves.pop();

                grid[curr.first][curr.second] = d;

                vector<pair<int,int>> adj;
                if(curr.first >= 1){
                    adj.emplace_back(curr.first-1, curr.second);
                }
                if(curr.second >= 1){
                    adj.emplace_back(curr.first, curr.second-1);
                }
                if(curr.first < n-1){
                    adj.emplace_back(curr.first+1, curr.second);
                }
                if(curr.second < n-1){
                    adj.emplace_back(curr.first, curr.second + 1);
                }

                for(pair p:adj){
                    if(!visited[p.first][p.second]) {
                        visited[p.first][p.second] = true;
                        thieves.push(p);
                    }
                }
            }
            d++;
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        priority_queue<pair<int, pair<int,int>>> pq;
        pair start = make_pair(0,0);
        pair end = make_pair(n-1, n-1);
        pq.emplace(grid[0][0]*2*n + dist(start, end), start);
        set<pair<int,int>> searched;


        while(!pq.empty()){
            int cost = pq.top().first;
            pair curr = pq.top().second;
            pq.pop();
            if(curr == end){
                return cost/(2*n);
            }
            if(!(searched.insert(curr)).second){
                continue;
            }
            vector<pair<int,int>> adj;
            if(curr.first >= 1){
                adj.emplace_back(curr.first-1, curr.second);
            }
            if(curr.second >= 1){
                adj.emplace_back(curr.first, curr.second-1);
            }
            if(curr.first < n-1){
                adj.emplace_back(curr.first+1, curr.second);
            }
            if(curr.second < n-1){
                adj.emplace_back(curr.first, curr.second + 1);
            }
            for(pair<int,int> p:adj){
                pq.emplace(min(cost, grid[p.first][p.second]*2*n + dist(p, end)), p);
            }
        }
        return -1;
    }

    int dist(pair<int, int> p1, pair <int, int> p2){
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    }
};

int main(){
    /*vector<vector<int>> grid = {{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0},
                                {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                                {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
                                */
    vector<vector<int>> grid = {{1,0,0}, {0,0,0}, {0,0,1}};
    Solution s;

    cout << s.maximumSafenessFactor(grid) << endl;
}
