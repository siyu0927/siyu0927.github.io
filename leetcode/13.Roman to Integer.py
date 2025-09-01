#題目連結:https://leetcode.com/problems/roman-to-integer/
#用字典比對,從前往後,小於後面的就減法,其他加法
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = 0
        for i in range(len(s)):
            if i + 1 < len(s) and value[s[i]] < value[s[i + 1]]: #限制長度,比下一個小就減法
                ans = ans - value[s[i]]
            else:
                ans = ans + value[s[i]]
        return ans
value = {    #字典
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

sol=Solution()  #測試用
print(sol.romanToInt("MCMXCIV"))  #測試用
