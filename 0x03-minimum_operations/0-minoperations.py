#!/usr/bin/python3
"""
    calculates the fewest number of operations needed
"""


def min_divider(n):
    """ Method that determines the min divider of n int """
    for i in range(2, n+1):
        if n % i == 0:
            return i


def minOperations(n):
    """ Method that determines the fewest number of operations """
    if not isinstance(n, int):
        return 0
    res = 0
    while n > 1:
        res += min_divider(n)
        n = int(n / min_divider(n))
    return res
