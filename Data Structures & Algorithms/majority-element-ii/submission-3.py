class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        num1=num2=-1
        count1=count2=0

        for num in nums:
            if num1==num:
                count1 += 1
            elif num2==num:
                count2 += 1
            elif count1 == 0:
                count1 = 1
                num1 = num
            elif count2 == 0:
                count2 = 1
                num2 = num
            else:
                count1 -= 1
                count2 -= 1
        output = []
        count1=count2=0
        for num in nums:
            if num1 == num:
                count1 += 1
            if num2 == num:
                count2 += 1
        if count1 > n // 3:
            output.append(num1)

        if count2 > n // 3:
            output.append(num2)

        return output
