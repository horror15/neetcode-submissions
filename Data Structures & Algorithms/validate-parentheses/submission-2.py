class Solution:
    def isValid(self, s: str) -> bool:
        lst = []
        mp = {")":"(", "}":"{","]":"["}
        for string in s:
            if string in "({[":
                lst.append(string)
            else:
                if lst and mp[string] == lst[-1]:
                    lst.pop()
                else:
                    return False
        if lst:
            return False
        else:
            return True
