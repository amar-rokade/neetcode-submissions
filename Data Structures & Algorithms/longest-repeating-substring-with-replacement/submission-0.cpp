class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
    int start = 0, max_freq = 0, global_max = 0;

    for (int end = 0; end < s.length(); end++) {
        // Update frequency and the "High Water Mark"
        max_freq = max(max_freq, ++count[s[end] - 'A']);

        // If invalid, just shift the whole window (don't shrink it)
        if ((end - start + 1) - max_freq > k) {
            count[s[start] - 'A']--;
            start++;
        }

        // The window size (end - start + 1) only ever increases 
        // when we find a better max_freq.
        global_max = max(global_max, end - start + 1);
    }
    return global_max;
    }
};
