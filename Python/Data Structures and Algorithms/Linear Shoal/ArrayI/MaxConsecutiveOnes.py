""" Given a binary array nums, return the maximum number of consecutive 1's in the array. """

class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        greaterConsecutive = 0
        current_sum = 0

        for x in nums:
            if x == 1:
                current_sum += 1
            elif x == 0:
                if greaterConsecutive < current_sum:
                    greaterConsecutive = current_sum 
                
                current_sum = 0

        return max(greaterConsecutive, current_sum)

