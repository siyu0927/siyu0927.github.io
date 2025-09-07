#題目連結:https://leetcode.com/problems/search-insert-position/description/
#big-O(n),可以優化到O(log n)
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        for i in range(len(nums)): #遍歷
            if nums[i] >= target:  #如果大於或等於直接輸出
                return i

        return len(nums)  #都比她小的話輸出最後一個

#優化版(二分搜尋法)
# class Solution(object):
#     def searchInsert(self, nums, target):
#         """
#         :type nums: List[int]
#         :type target: int
#         :rtype: int
#         """
#         left=0
#         right=len(nums)-1
#         while left<=right:
#             mid=(left+right)//2
#             if nums[mid]==target:  #正中
#                 return mid
#             elif nums[mid] <target:  #目標在右半
#                 left=mid+1  #調左上限
#             else:
#                 right=mid-1  #目標在左半,調右上限
#         return left  


#測試用
#sol=Solution()
#print (sol.searchInsert([1,3,5,6],5))
