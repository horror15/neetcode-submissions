class FreqStack:

    def __init__(self):
        self.elements = defaultdict(int)
        self.freq = defaultdict(list)
        self.count = 0

    def push(self, val: int) -> None:
        self.elements[val]+=1
        self.freq[self.elements[val]].append(val)
        if self.elements[val] > self.count:
            self.count = self.elements[val]

    def pop(self) -> int:
        val = self.freq[self.count].pop()
        self.elements[val]-=1
        if not self.freq[self.count]:
            self.count-=1
        return val


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()