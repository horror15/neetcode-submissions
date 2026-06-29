class TimeMap:

    def __init__(self):
        self.mp = defaultdict(list)


    def set(self, key: str, value: str, timestamp: int) -> None:
        self.mp[key].append([timestamp, value])

    def get(self, key: str, timestamp: int) -> str:

            if not self.mp[key]:
                return ""

            i,j=0, len(self.mp[key])-1
            while i<=j:
                mid = (i+j)//2
                if self.mp[key][mid][0] > timestamp:
                    j = mid-1
                elif self.mp[key][mid][0] < timestamp:
                    i = mid+1
                else:
                    #print(mid)
                    return self.mp[key][mid][1]
            if j < 0:
                return ""
            else:
                return self.mp[key][j][1]