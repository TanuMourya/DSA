class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int sr, sc;
        vector<pair<int,int>> litter;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if(classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();
        int full = (1 << k) - 1;

        vector<vector<int>> id(n, vector<int>(m, -1));

        for(int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }

        vector<vector<vector<vector<bool>>>> vis(
            n,
            vector<vector<vector<bool>>>(
                m,
                vector<vector<bool>>(energy + 1, vector<bool>(1 << k, false))
            )
        );

        queue<array<int,5>> q;

        q.push({sr, sc, energy, 0, 0});
        vis[sr][sc][energy][0] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            int r = cur[0];
            int c = cur[1];
            int e = cur[2];
            int mask = cur[3];
            int dist = cur[4];

            if(mask == full)
                return dist;

            for(int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                if(classroom[nr][nc] == 'X')
                    continue;

                if(e == 0)
                    continue;

                int ne = e - 1;
                int nmask = mask;

                if(classroom[nr][nc] == 'L') {
                    nmask |= (1 << id[nr][nc]);
                }

                if(classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                if(!vis[nr][nc][ne][nmask]) {
                    vis[nr][nc][ne][nmask] = true;
                    q.push({nr, nc, ne, nmask, dist + 1});
                }
            }
        }

        return -1;
    }
};