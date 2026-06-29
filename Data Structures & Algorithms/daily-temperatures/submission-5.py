class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        st=[]
        lt = [0]*len(temperatures)
        for i in range(len(temperatures)-1,-1,-1):
            if not st:
                st.append(i)
            else:
                while st and temperatures[i] >= temperatures[st[-1]]:
                    st.pop()
                if st:
                    lt[i] = st[-1] - i
                st.append(i)
        return lt