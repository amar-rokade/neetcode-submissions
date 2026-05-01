class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans = "";
        for (const string& s : strs) {
            ans += to_string(s.length()) + "#" + s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int n = s.length();
        int i = 0;
        vector<string> ans;

        while (i < n) {
            // Read the length digits until '#'
            string lenStr = "";
            while (i < n && s[i] != '#') {
                lenStr += s[i];
                i++;
            }
            i++;  // skip '#'

            int len = stoi(lenStr);

            // Extract exactly 'len' characters as the string
            ans.push_back(s.substr(i, len));
            i += len;
        }

        return ans;
    }
};