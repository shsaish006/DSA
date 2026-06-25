class Solution:
    def countMajoritySubarrays(self,a: List[int],b: int) -> int:
        sai=a
        c=0
        # s=[0]*(n+1)
        n=len(a)
        for idx in range(n):
            # cnt=0
            # mp={}
            # for temp in range(idx,n):
            #     mp[a[temp]]= mp.get(a[temp],0)+1
            #     cnt=temp-idx+1
            d=0
            for temp in range(idx,n):
                if a[temp]==b:
                    d+=1
            # for d in a:
            #     s.append(s[-1] + ( 1 if d ==b else -1))
                if d*2> temp-idx+1:
                    c+=1
        return c
        