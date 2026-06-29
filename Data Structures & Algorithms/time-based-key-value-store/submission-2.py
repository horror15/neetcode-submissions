class TimeMap:

    def __init__(self):
        self.mp = defaultdict(list)


    def set(self, key: str, value: str, timestamp: int) -> None:
        self.mp[key].append([timestamp, value])

    def get(self, key: str, timestamp: int) -> str:
            res = ""

            i,j=0, len(self.mp[key])-1
            while i<=j:
                mid = (i+j)//2
                if self.mp[key][mid][0] <= timestamp:
                    res = self.mp[key][mid][1]
                    i = mid+1
                else:
                    j = mid-1
            return res