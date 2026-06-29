class Solution:
    def calPoints(self, operations: List[str]) -> int:
        lst = []
        for val in operations:
            if val == "+":
                #a = operations[-1] + operations[-2]
                lst.append(lst[-1] + lst[-2])
            elif val == "C":
                lst.pop()
            elif val == "D":
                #a = 2*operations[-1]
                lst.append(2*lst[-1])
            else:
                lst.append(int(val))
        return sum(lst)
