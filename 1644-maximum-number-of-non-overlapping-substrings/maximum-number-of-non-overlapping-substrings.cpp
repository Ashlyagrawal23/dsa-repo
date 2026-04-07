class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        
        vector<int> first(26, n), last(26, -1);
        
        // Find first and last occurrence of each character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        // Build graph
        vector<vector<int>> g(26), rg(26);
        vector<int> exists(26, 0);
        
        for (int c = 0; c < 26; c++) {
            if (last[c] != -1) exists[c] = 1;
        }

        for (int c = 0; c < 26; c++) {
            if (!exists[c]) continue;
            
            for (int i = first[c]; i <= last[c]; i++) {
                int d = s[i] - 'a';
                if (d != c) {
                    g[c].push_back(d);
                    rg[d].push_back(c);
                }
            }
        }

        // Remove duplicate edges
        for (int i = 0; i < 26; i++) {
            sort(g[i].begin(), g[i].end());
            g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
            sort(rg[i].begin(), rg[i].end());
            rg[i].erase(unique(rg[i].begin(), rg[i].end()), rg[i].end());
        }

        // Kosaraju - 1st DFS
        vector<int> vis(26, 0), order;
        function<void(int)> dfs1 = [&](int u) {
            vis[u] = 1;
            for (int v : g[u]) {
                if (!vis[v]) dfs1(v);
            }
            order.push_back(u);
        };

        for (int i = 0; i < 26; i++) {
            if (exists[i] && !vis[i]) dfs1(i);
        }

        // Kosaraju - 2nd DFS
        vector<int> comp(26, -1);
        vector<vector<int>> comps;
        function<void(int, int)> dfs2 = [&](int u, int cid) {
            comp[u] = cid;
            comps[cid].push_back(u);
            for (int v : rg[u]) {
                if (comp[v] == -1) dfs2(v, cid);
            }
        };

        reverse(order.begin(), order.end());
        int cid = 0;
        for (int u : order) {
            if (comp[u] == -1) {
                comps.push_back({});
                dfs2(u, cid++);
            }
        }

        // SCC DAG outdegree
        vector<int> outdeg(cid, 0);
        for (int u = 0; u < 26; u++) {
            if (!exists[u]) continue;
            for (int v : g[u]) {
                if (comp[u] != comp[v]) {
                    outdeg[comp[u]]++;
                }
            }
        }

        // Build answer from SCCs with 0 out-degree
        vector<pair<int, int>> intervals;
        for (int i = 0; i < cid; i++) {
            if (outdeg[i] == 0) {
                int l = n, r = -1;
                for (int c : comps[i]) {
                    l = min(l, first[c]);
                    r = max(r, last[c]);
                }
                intervals.push_back({r, l});
            }
        }

        // Sort by ending index for non-overlapping selection
        sort(intervals.begin(), intervals.end());

        vector<string> ans;
        int prevEnd = -1;
        for (auto &[r, l] : intervals) {
            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};