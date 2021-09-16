#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

int total_paths = 1;
map<char, pair<int, int>> dirs;

bool is_corner(int i, int j) {
    return (i == 0 && j == 0) || (i == 6 && j == 0) || (i == 0 && j == 6)
    || (i == 6 && j == 6);
}
bool is_edge(int i, int j) {
    return i == 0 || i == 6 || j == 0 || j == 6;
}

bool inside(int i, int j) {
    return i >= 0 && i < 7 && j >= 0 && j < 7;
}

// I am not counting correctly.
void solve(vector<vector<bool>> &vis, string path, int i = 0, int r = 0, int c = 0) {
    if(i >= path.length()) return;
    if(path[i] == '?') {
        for(auto dir : dirs) {
            int new_r = dir.second.first + r, new_c = dir.second.second + c;
            if(inside(new_r, new_c) && !vis[new_r][new_c]) {
                ++total_paths;
                // vis[new_r][new_c] = true;
                char tmp = path[i]; 
                path[i] = dir.first;
                solve(vis, path, i, r, c);
                path[i] = tmp; 
            }
        }
    }
    else {
        int new_r = dirs[path[i]].first + r, new_c = dirs[path[i]].second + c;
        if(inside(new_r, new_c) && !vis[new_r][new_c]) {
            vis[new_r][new_c] = true;
            solve(vis, path, i + 1, new_r, new_c);
        }
    }
}
int main() {
    dirs['L'] = make_pair(-1, 0);
    dirs['U'] = make_pair(0, -1);
    dirs['D'] = make_pair(0, 1);
    dirs['R'] = make_pair(1, 0);

    string s;
    cin >> s;
    vector<vector<bool>> vis(7, vector<bool>(7));
    solve(vis, s);
    cout << total_paths << endl;
}