class DataStream:
    def __init__(s,a,b):
        s.a,s.b=a,b
        s.c=0

    # def __init__(self, value: int, k: int):
        

    # def consec(self, num: int) -> bool:
    def consec(s,d):
        s.c=0 if d!= s.a else s.c+1
        return s.c>=s.b
        


# Your DataStream object will be instantiated and called as such:
# obj = DataStream(value, k)
# param_1 = obj.consec(num)