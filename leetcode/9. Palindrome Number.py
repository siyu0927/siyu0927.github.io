#題目:https://leetcode.com/problems/palindrome-number/description/
#轉成字串,用比對的
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x = str(x)  #轉字串
        if x == x[::-1]: #前後比對
            return True
        else:
            return False

#sol=Solution()  測試用
#print(sol.isPalindrome(121))
