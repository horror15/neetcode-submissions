class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for i in range(len(tokens)):
            if tokens[i] == "+":
                st.append(st.pop() + st.pop())
            elif tokens[i] == "-":
                a,b = st.pop(), st.pop()
                st.append(b-a)
            elif tokens[i] == "*":
                st.append(st.pop() * st.pop())
            elif tokens[i] == "/":
                a,b = st.pop(), st.pop()
                st.append(int(float(b) / a))
            else:
                st.append(int(tokens[i]))
        print(st)
        return st[-1]