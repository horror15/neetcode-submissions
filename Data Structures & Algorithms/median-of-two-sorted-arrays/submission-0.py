class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        l = 0
        r = len(nums1)
        n = len(nums1)
        m = len(nums2)
        total = n+m
        while l<=r:
            partition_x = (l+r)//2
            partition_y = (n+m+1)//2 - partition_x

            if partition_x >0:
                Aleft = nums1[partition_x-1] 
            else:
                Aleft = float("-infinity")

            if partition_x < len(nums1):
                Aright = nums1[partition_x]
            else:
                Aright = float("infinity")

            if partition_y >0:
                Bleft = nums2[partition_y-1] 
            else:
                Bleft = float("-infinity")

            if partition_y < len(nums2):
                Bright = nums2[partition_y] 
            else:
                Bright = float("infinity")
            
            if Aleft <= Bright and Bleft <= Aright:
                if total%2:
                    return max(Aleft,Bleft)
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
            elif Aleft > Bright:
                r = partition_x-1
            else:
                l = partition_x+1








