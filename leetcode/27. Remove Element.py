#題目連結:https://leetcode.com/problems/remove-element/description/
#用覆蓋的寫法(不然會造成索引錯誤)
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        if not nums: #防例外
            return 0
        i=0
        for j in range(len(nums)):
            if nums[j] != val:  #不是val的數字
                nums[i] = nums[j]  #往前面放
                i=i+1 #指標後移

        return i
  
#測試用   
# sol=Solution()
# nums=[1,2,3,4,5,6,7]
# k=sol.removeElement( nums, 1)
# print(k,nums[:k])
