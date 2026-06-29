class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        
        for char in s:
            if char == "]":
                string = ""
                num = ""
                while stack and stack[-1] != "[":
                    string = stack.pop() + string
                stack.pop()
                while stack and stack[-1].isdigit():
                    num = stack.pop() + num
                string = int(num)*string
                stack.append(string)
            else:
                stack.append(char)
        return  "".join(stack)