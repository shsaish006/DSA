# total cost jo hoga wo equal hoga first element off each k subarray ke
#  first subarray hamesha start hoga
# k-1 hamesha chose karenge starting point jo index i se hoga 
#  set iss liye use kar rahe taki pata chal sake cost mein kitan contribute the cost ke
# 0(n log n)
# hardam pick karenge k-1 smallest posiible value



import heapq
from typing import List
class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        k-=1
        l=[]
        r=[]
        used=set()
        # s=nums[0]
        s=0
        ans=float('inf')
        for right in range(1, len(nums)):
            left = right - dist - 1

            if left > 0 and left in used:
                used.remove(left)
                s -= nums[left]

                while r and r[0][1] <= left:
                    heapq.heappop(r)
        # for i in range(1,dist+2):
        #     heapq.heappush(l,-nums[i])
        #     s+=nums[i]
        # while len(l)>k:
        #     x=-heapq.heappop(l)
        #     s-=x 
        #     heapq.heappush(r,x)
        # ans=s
                if r:
                    val, idx = heapq.heappop(r)
                    heapq.heappush(l, (-val, idx))
                    used.add(idx)
                    s += val
            if len(used) < k:
                heapq.heappush(l, (-nums[right], right))
                used.add(right)
                s += nums[right]
            else:
                while l and l[0][1] not in used:
                    heapq.heappop(l)

                if l and nums[right] < -l[0][0]:
                    val, idx = heapq.heapreplace(l, (-nums[right], right))
                    used.remove(idx)
                    used.add(right)
                    s += val + nums[right]
                    heapq.heappush(r, (-val, idx))
                else:
                    heapq.heappush(r, (nums[right], right))
            if left >= 0 and len(used) == k:
                ans = min(ans, s)

        return nums[0] + ans

        # for i in range(dist+2,len(nums)):
        #     rem=nums[i-dist-1]
        #     if l and rem<=-l[0]:
        #         l.remove(-rem)
        #         heapq.heapify(l)
        #         s-=rem 
        #     else:
        #         if rem in r:
        #             r.remove(rem)
        #             heapq.heapify(r)

        #     add=nums[i]
        #     if l and add<-l[0]:
        #         heapq.heappush(l,-add)
        #         s+=add 
        #     else:
        #         heapq.heappush(r,add)
        #     while len(l)<k:
        #         x=heapq.heappop(r)
        #         heapq.heappush(l,-x)
        #         s+=x 
        #     while len(l)>k:
        #         x=-heapq.heappop(l)
        #         s+=x 
        #         heapq.heappush(r,x)
        #     ans=min(ans,s)
        # return ans