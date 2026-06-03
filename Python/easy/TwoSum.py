from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        complementos = {}

        for i, x in enumerate(nums):
            complemento = target - x

            if complemento in complementos:
                return [complementos[complemento], i]

            complementos[x] = i