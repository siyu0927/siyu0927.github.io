#題目連結:https://leetcode.com/problems/merge-two-sorted-lists/description/
#linked-list合併,使用假開頭跟tail移動
class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        fake=ListNode(-1)  #建立假的起點node
        tail=fake  #尾巴設定

        while list1 and list2:  #兩個一起比
            if list1.val<list2.val:
                tail.next=list1  #list1給尾巴指
                list1=list1.next  #list1往前
            else:
                tail.next=list2  #list2給尾巴指
                list2=list2.next  #list2往前
            tail=tail.next  #尾巴往前指

        if list1:  #剩下的直接接上
            tail.next=list1
        if list2:
            tail.next=list2

        return fake.next


#測試用
# list1 = [1,2,4]
list1 = ListNode(1, ListNode(2, ListNode(4)))
# list2 = [1,3,4]
list2 = ListNode(1, ListNode(3, ListNode(4)))

sol = Solution()
merged = sol.mergeTwoLists(list1, list2)

while merged:
    print(merged.val, end=" -> ")
    merged = merged.next
