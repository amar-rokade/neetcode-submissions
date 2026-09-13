class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> need(26, 0), window(26, 0);

        // Count characters in s1 and in the first window of s2.
        for (int i = 0; i < s1.size(); i++) {
            need[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        // Count how many letters currently match.
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (need[i] == window[i]) matches++;
        }

        // Slide the window across s2.
        int left = 0;
        for (int right = s1.size(); right < s2.size(); right++) {
            if (matches == 26) return true;

            // Add s2[right].
            int idx = s2[right] - 'a';
            window[idx]++;
            if (window[idx] == need[idx]) matches++;
            else if (window[idx] == need[idx] + 1) matches--;

            // Remove s2[left].
            idx = s2[left] - 'a';
            window[idx]--;
            if (window[idx] == need[idx]) matches++;
            else if (window[idx] == need[idx] - 1) matches--;

            left++;
        }

        return matches == 26;
    }
};