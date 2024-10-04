from typing import List
# from heapq import heapify,heappop
import heapq


class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        q = [-x for x in nums]
        heapq.heapify(q)
        ans = 0
        for _ in range(k):
            x = heapq.heappop(q)
            ans += -x
            heapq.heappush(q, -((-x + 2) // 3))
        return ans
