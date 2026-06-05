""" Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn]. """

class Solution:
    def shuffle(self, nums: list[int], n: int) -> list[int]:
        ans = [0] * (2 * n)

        for x in range(0, n):
            ans[x * 2] = nums[x]
            ans[(x * 2) + 1] = nums[n + x]
            
        return ans