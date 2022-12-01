#!/usr/bin/python3
"""
Module contains function for solving
prompted problem. Problem found in documentation.
"""


def pop_ends(walls):
    """
    Pops zeros from the ends of the list.
    """

    if len(walls) == 0:
        return walls

    while walls[-1] == 0:
        walls.pop(-1)

    while walls[0] == 0:
        walls.pop(0)

    return walls


def rain(walls):
    """
    Problem Prompt:
    Given a list of non-negative integers representing
    the heights of walls with unit width 1, as if viewing
    the cross-section of a relief map, calculate how many
    square units of water will be retained after it rains.

    Args:
        walls: List of integers representing wall heights.

    Return:
        Integer indicating total amount of rainwater retained.
    """

    walls = pop_ends(walls)

    if len(walls) == 0:
        return 0

    tot, cnt = 0, 0
    left = walls[0]

    for x, wall in enumerate(walls[1:]):
        if wall == 0:
            cnt += 1
        else:
            height = min(left, wall)
            tot += (cnt * height)
            left = wall
            cnt = 0

    return tot
