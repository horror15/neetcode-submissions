class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        i,j=0,len(arr)-1
        out=[]
        ans=0
        while i<=j:
            mid = (i+j)//2
            if arr[mid] < x:
                ans = mid
                i = mid+1
            else:
                j=mid-1
        i=ans
        j=i+1
        while k>0 and i>=0 and j<len(arr):
            if abs(arr[i]-x) > abs(arr[j]-x):
                out.append(arr[j])
                j+=1
            else:
                out.append(arr[i])
                i-=1
            k-=1
        while k>0 and i>=0:
            out.append(arr[i])
            i-=1
            k-=1
        while k>0 and j<len(arr):
            out.append(arr[j])
            j+=1
            k-=1
        out.sort()
        return out


