class Solution(object):
    def lengthOfLongestSubstring(self, s):
        if len(s)==0: return 0
        h_map = dict()
        maxLen = 0
        i = 0
        j = 0
        for i in range(len(s)):
            if s[i] in h_map:
                j = max(j,h_map[s[i]]+1)

            h_map[s[i]] = i
            maxLen = max(maxLen, i-j+1)

        return maxLen
