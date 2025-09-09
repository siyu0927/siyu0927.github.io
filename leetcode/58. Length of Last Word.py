#題目連結:https://leetcode.com/problems/length-of-last-word/description/
#直接用split(),會用空白切分字串,並去掉多餘空白
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        a=s.split()
        return len(a[-1])  #印出最後一個的長度

#測試用
#sol=Solution()
#print(sol.lengthOfLastWord("hello world  "))
