#題目連結:https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#題目要求要原地修改,用兩個指標,一個記更新到哪.一個做比較
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:  #防空的例外
            return 0

        i=0
        for j in range(1,len(nums)): #j從第一個開始比
            if nums[j]!=nums[i]:  #每個作對比,不一樣的改i+1位子
                i=i+1
                nums[i]=nums[j]

        return i+1  #因為從0開始,所以+1

#測試用
#sol = Solution()
#nums = [1,1,2]
#k = sol.removeDuplicates(nums)
#print(k, nums[:k])          # 2 [1, 2]
