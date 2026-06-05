""" You are given two integers num1 and num2 representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:

A digit is a peak if it is strictly greater than both of its immediate neighbors.
A digit is a valley if it is strictly less than both of its immediate neighbors.
The first and last digits of a number cannot be peaks or valleys.
Any number with fewer than 3 digits has a waviness of 0.
Return the total sum of waviness for all numbers in the range [num1, num2]. """

class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        
        def solve(num: int) -> int:
            if num < 100:
                return 0
            
            s = str(num)
            n = len(s)

            memo = {}

            def dfs(pos: int, prev: int, curr: int, isLimit: bool, isLeading: bool):
                if pos == n:
                    return 1, 0

                if not isLimit and not isLeading and (pos, prev, curr) in memo:
                    return memo[(pos, prev, curr)]

                cnt = 0
                waviness = 0
                up = int(s[pos]) if isLimit else 9

                for digit in range(up + 1):
                    newLeading = isLeading and (digit == 0)
                    newPrev = curr
                    newCurr = -1 if newLeading else digit
                    
                    subCnt, subSum = dfs(
                        pos + 1,
                        newPrev,
                        newCurr,
                        isLimit and (digit == up),
                        newLeading
                    )
                    
                    if not newLeading and prev >= 0 and curr >= 0:
                        if (prev < curr and curr > digit) or (prev > curr and curr < digit):
                            waviness += subCnt

                    cnt += subCnt
                    waviness += subSum

                if not isLimit and not isLeading:
                    memo[(pos, prev, curr)] = (cnt, waviness)

                return cnt, waviness

            _, totalSum = dfs(0, -1, -1, True, True)
            return totalSum

        return solve(num2) - solve(num1 - 1)