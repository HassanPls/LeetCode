""" You are given a 0-indexed integer array nums of size n.

Define two arrays leftSum and rightSum where:

leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|. """

# First try
""" class Solution:
    def leftRightDifference(self, nums: list[int]) -> list[int]:
        if len(nums) <= 1: return [0]

        n = len(nums)

        leftSum = [0] * n
        rightSum = [0] * n

        for i,x in enumerate(leftSum):
            if (i + 1 >= n): break
            leftSum[i + 1] = leftSum[i] + nums[i]

        for i,x in enumerate(rightSum):
            if ((n - 1 - i) == 0): break
            rightSum[n - 2 - i] = rightSum[n - 1 - i] + nums[n - 1 - i]

        ans = [0] * (n)

        for i,x in enumerate(leftSum):
            ans[i] = max(leftSum[i] - rightSum[i], -(leftSum[i] - rightSum[i]))

        return ans """

# Second try
class Solution:
    def leftRightDifference(self, nums: list[int]) -> list[int]:
        if len(nums) <= 1: return [0]

        n = len(nums)
        ans = [0] * (n)

        leftSum = 0
        for x in range(n):
            ans[x] = leftSum
            leftSum += nums[x]

        rightSum = 0
        for x in range(n - 1, -1, -1):
            ans[x] = abs(ans[x] - rightSum)
            rightSum += nums[x]

        return ans