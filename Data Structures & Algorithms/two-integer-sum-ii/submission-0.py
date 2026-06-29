class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i,j=0,len(numbers)-1
        output = []
        while(i<j):
            sum = numbers[i] + numbers[j]
            if sum > target:
                j-=1
            elif sum < target:
                i+=1
            else:
                output.append(i+1)
                output.append(j+1)
                break
        return output
