class Solution {
public:
    vector<string> result;

    bool isValid(string part) {
        // Leading zero check
        if (part.size() > 1 && part[0] == '0')
            return false;

        int num = stoi(part);

        return num >= 0 && num <= 255;
    }

    void backtrack(string s, int start, vector<string>& path) {
        // If 4 parts are formed
        if (path.size() == 4) {
            // Use all characters
            if (start == s.size()) {
                string ip = path[0] + "." + path[1] + "." +
                            path[2] + "." + path[3];
                result.push_back(ip);
            }
            return;
        }

        // Try length 1 to 3
        for (int len = 1; len <= 3; len++) {
            if (start + len > s.size())
                break;

            string part = s.substr(start, len);

            if (isValid(part)) {
                path.push_back(part);
                backtrack(s, start + len, path);
                path.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> path;

        backtrack(s, 0, path);

        return result;
    }
};