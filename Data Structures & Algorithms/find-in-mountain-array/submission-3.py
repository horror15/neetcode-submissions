class Solution:
    def findInMountainArray(self, target: int, mountainArr: 'MountainArray') -> int:
        
        def search1(i,j):
            while i<=j:
                mid = (i+j)//2
                if mountainArr.get(mid) < target:
                    i = mid+1
                elif mountainArr.get(mid) > target:
                    j = mid-1
                else:
                    return mid
            return -1
        
        def search2(i,j):
            while i<=j:
                mid = (i+j)//2
                if mountainArr.get(mid) < target:
                    j = mid-1
                elif mountainArr.get(mid) > target:
                    i = mid+1
                else:
                    return mid
            return -1

        
        i = 0
        j = mountainArr.length()-1

        while i<=j:
            mid = (i+j)//2
            left = mountainArr.get(mid-1)
            index = mountainArr.get(mid)
            right = mountainArr.get(mid+1)

            if left < index and index > right:
                a = search1(0,mid)
                b = search2(mid, mountainArr.length()-1)
                if a == -1 and b==-1:
                    return -1
                elif a!=-1:
                    return a
                else:
                    return b
            elif left < index:
                 i = mid+1
            else:
                j = mid-1
