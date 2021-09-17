class Solution(object):

    def __init__(self):
        self.lo=int(0)
        self.maxLen=int(0)



    def longestPalindrome(self, s):
        print(self.maxLen)
        s_len = len(s)
        if (s_len<2):
            return s
        
        def extendPal(self,s,j,k):
            while (j>=0 and k<len(s)) and s[j]==s[k]:
                j-=1
                k+=1

            if self.maxLen<(k-j-1):
                self.lo = j+1
                self.maxLen = k-j-1

        
        for i in range(s_len-1):
            extendPal(self,s,i,i)
            extendPal(self,s,i,i+1)
        
        return s[self.lo:self.lo+self.maxLen]