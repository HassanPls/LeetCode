""" You are given two integers num1 and num2 representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:

A digit is a peak if it is strictly greater than both of its immediate neighbors.
A digit is a valley if it is strictly less than both of its immediate neighbors.
The first and last digits of a number cannot be peaks or valleys.
Any number with fewer than 3 digits has a waviness of 0.
Return the total sum of waviness for all numbers in the range [num1, num2]. """

class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        
        total = 0
        for x in range(num1, num2 + 1):
            waviness = 0
            x = str(x)
            for y in range(0, len(x) -2):
                if ((x[y] > x[y+1] and x[y+2] > x[y+1]) or (x[y] < x[y+1] and x[y+2] < x[y+1])):
                    waviness += 1

            total += waviness

        return total