#題目連結:https://leetcode.com/problems/plus-one/description/
#小於九直接加,等於九先變零後往前檢查
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        for i in range(len(digits)-1,-1,-1):  #最後一個開始,-1結束,步伐-1,
            if digits[i]<9:  #小於9直接加
                digits[i]+=1
                return digits
            else:  #等於9先變0,往前檢查
                digits[i]=0

        return [1]+digits  #都是9,前面補1的list



#測試用
#sol=Solution()
#print(sol.plusOne([9,9,9]))
