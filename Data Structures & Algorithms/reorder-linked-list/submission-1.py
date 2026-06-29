# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        def reverse(head):
            if not head or not head.next:
                return head
            new_head = reverse(head.next)
            head.next.next = head
            head.next = None
            return new_head
        ptr1,ptr2=head,head.next
        while ptr2 and ptr2.next:
            ptr1 = ptr1.next
            ptr2 = ptr2.next.next
        new_head = reverse(ptr1.next)
        ptr1.next = None

        first = head
        second = new_head

        while first and second:
            ptr_1 = first
            first = first.next
            ptr_1.next = second
            ptr_2 = second
            second = second.next
            ptr_2.next = first
            


