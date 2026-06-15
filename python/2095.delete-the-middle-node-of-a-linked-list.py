# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from math import ceil, floor


class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None

        count = 1
        node = head.next
        while node is not None:
            node = node.next
            count += 1

        mid = count // 2

        prev = ListNode(0, head)
        for _ in range(mid):
            prev = prev.next

        prev.next = prev.next.next

        return head
