#題目連結:https://leetcode.com/problems/longest-common-prefix/description/
#把第一個當prefix去比,不對就刪一位
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:  #輸入空的防例外
            return ""
        else:
            prefix = strs[0]

        for i in strs[1:]:  #從第一個開始比
            while not i.startswith(prefix):  #判斷一樣嗎
                prefix = prefix[:-1]  #刪一位
                if not prefix:   #找不到一樣的防例外
                    return ""
        return prefix
sol=Solution()  #測試用
print(sol.longestCommonPrefix(["abrrec","awbc","abcg"]))  #測試用
