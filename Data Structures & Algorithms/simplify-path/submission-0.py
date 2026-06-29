class Solution:
    def simplifyPath(self, path: str) -> str:
        path = path.split('/')
        stack = []
        for string in path:
            if string == "..":
                if stack:
                    stack.pop()
            elif string != "." and string != "":
                stack.append(string)

        return "/" + "/".join(stack)
             