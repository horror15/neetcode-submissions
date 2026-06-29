class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        st=[]
        lt = [0]*len(temperatures)
        for i in range(len(temperatures)-1,-1,-1):
            if not st:
                st.append([temperatures[i],i])
            else:
                while st and temperatures[i] >= st[-1][0]:
                    st.pop()
                if st:
                    lt[i] = st[-1][1] - i
                st.append([temperatures[i],i])
        return lt