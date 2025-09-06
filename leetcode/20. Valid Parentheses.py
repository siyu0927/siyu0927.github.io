#題目連結:https://leetcode.com/problems/valid-parentheses/description/
#用stack,左括號放進,右括號提出比對
class Solution(object):

    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        mapping = {')': '(', ']': '[', '}': '{'}  # 右括號對應左括號
        stack = []

        for i in s:  #右括號(字典中的前面)
            if i in mapping: #在字典中
                if not stack: #stack是空的話回傳False
                    return False
                a=stack.pop()
                if a!=mapping[i]: #比對是不是字典中對應的
                    return False
            else:  #左括號
                stack.append(i)
        return not stack

#sol=Solution()
#print(sol.isValid("{}}"))
