#題目網址 https://leetcode.com/problems/two-sum/description/
#暴力解,bigO(n^2)
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)): #用len防止超出
            for j in range(i + 1,len(nums)): #從i+1保證不重複使用
                if nums[j] + nums[i] == target:
                    return [i,j]  #回傳值要是陣列
        return []  #預防找不到

#sol=Solution()  測試用
#print(sol.twoSum([2,7,11,15],9))
