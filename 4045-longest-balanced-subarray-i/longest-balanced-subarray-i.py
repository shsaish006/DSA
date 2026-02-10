class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        sai=nums
        # temp={}
        # idx1=0
        # val=0
        # curr={(0,0):-1}
        n=len(sai)
        curr=0
        for i in range(n):
            temp1,temp2=set(),set()
            # for idx2,i in enumerate(sai):
            #     if i%2==0:
            #         cnt[i]=1
            #     else:
            #         temp[i]=1
            for j in range(i,n):
                if sai[j]%2==0:
                    temp1.add(sai[j])
                else:
                    temp2.add(sai[j])
                # diff=len(cnt)-len(temp)
                # if diff in curr:
                #     val=max(val,idx2-curr[diff])
            # else:
            #     curr[diff]=idx2
                if len(temp1)==len(temp2):
                    curr=max(curr,j-i+1)
        return curr
        