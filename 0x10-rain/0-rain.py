#!/usr/bin/python3
"""
0-rain
"""


def rain(walls):
    """
    Calculate how many square units of water will be
    retained after it rains
    """
    if not isinstance(walls, list) or len(walls) <= 2:
        return 0

    tall, taller = 0, len(walls) - 1

    # Find 2 tallest walls.
    for i, wall in enumerate(walls):
        if wall >= walls[tall]:
            taller = tall
            tall = i
        elif wall > taller:
            taller = i

    # Check that there were 2 walls to retain rain.
    if walls[tall] == 0 or walls[taller] == 0:
        return 0

    # Find the left, right position and size of walls
    left = min((tall, taller))
    right = max((tall, taller))
    filler = sum(walls[left + 1: right])

    # Calculate volume
    height = min((walls[tall], walls[taller]))
    width = right - left - 1
    water = (height * width) - filler

    return water + rain(walls[:left + 1]) + rain(walls[right:])
