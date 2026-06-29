class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        st = []
        j = 0

        for i in range(j, len(asteroids)):
            if asteroids[i] > 0 or not st or st[-1] < 0:
                st.append(asteroids[i])
            else:
                while st:
                    a = st[-1]
                    if a > abs(asteroids[i]):
                        break
                    elif a < abs(asteroids[i]):
                        st.pop()
                        if not st or st[-1] < 0:
                            st.append(asteroids[i])
                            break
                    else:
                        st.pop()
                        break
                
        return st
