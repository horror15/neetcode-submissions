class MinStack:

    def __init__(self):
        self.lst = []
        self.st = []

    def push(self, val: int) -> None:
        if not self.st or val <= self.st[-1]:
            self.st.append(val)
        self.lst.append(val)

    def pop(self) -> None:
       val =  self.lst.pop()
       if val == self.st[-1]:
            self.st.pop()

    def top(self) -> int:
        return self.lst[-1]

    def getMin(self) -> int:
        if self.st:
            return self.st[-1]
