#題目連結:https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
#可以一行解決(return haystack.find(needle))就好
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle in haystack:  #在裡面的話
            return haystack.index(needle)  #回傳在第幾個
        else:
            return -1

#測試用
#sol = Solution()
#print(sol.strStr("hello", "ll"))
