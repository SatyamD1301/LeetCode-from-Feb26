class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node dp[20][11][11][20];
    bool vis[20][11][11][20];

    Node dfs(int pos, int last2, int last1, int len, bool tight) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][last2][last1][len]) {
            return dp[pos][last2][last1][len];
        }

        int limit = tight ? (s[pos] - '0') : 9;

        long long totalCnt = 0;
        long long totalWav = 0;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (len == 0 && d == 0) {
                Node nxt = dfs(pos + 1, 10, 10, 0, ntight);
                totalCnt += nxt.cnt;
                totalWav += nxt.wav;
                continue;
            }

            int add = 0;

            if (len >= 2) {
                if ((last1 > last2 && last1 > d) ||
                    (last1 < last2 && last1 < d)) {
                    add = 1;
                }
            }

            int nlast2, nlast1;

            if (len == 0) {
                nlast2 = 10;
                nlast1 = d;
            } else if (len == 1) {
                nlast2 = last1;
                nlast1 = d;
            } else {
                nlast2 = last1;
                nlast1 = d;
            }

            Node nxt = dfs(pos + 1, nlast2, nlast1, len + 1, ntight);

            totalCnt += nxt.cnt;
            totalWav += nxt.wav + nxt.cnt * add;
        }

        Node res = {totalCnt, totalWav};

        if (!tight) {
            vis[pos][last2][last1][len] = true;
            dp[pos][last2][last1][len] = res;
        }

        return res;
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, 0, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};