#!/usr/bin/python3
"""
making_change
"""


def makeChange(coins, total):
    """
    Making change method
    """
    if total <= 0:
        return 0
    if coins == []:
        return -1
    coins.sort(reverse=True)
    len_coins = len(coins)
    i = 0
    counter = 1
    sub_total = coins[i]

    while True:
        if sub_total > total:
            counter -= 1
            sub_total -= coins[i]
            i += 1
            if i >= len_coins:
                return makeChange(coins[1:], total)
        if sub_total == total:
            return counter
        sub_total += coins[i]
        counter += 1
