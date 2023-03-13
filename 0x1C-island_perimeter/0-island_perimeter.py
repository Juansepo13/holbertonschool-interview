#!/usr/bin/python3
"""
Function that returns the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """
    grid is a list of list of integers:
     0 represents water
     1 represents land
     Each cell is square, with a side length of 1
     Cells are connected horizontally/vertically (not diagonally).
     grid is rectangular, with its width and height not exceeding 100
    The grid is completely surrounded by water
    There is only one island (or nothing).
    The island doesn’t have “lakes” (water inside that isn’t connected
    to the water surrounding the island).
    """
    count = 0
    row = len(grid)
    col = len(grid[0]) if row else 0

    for i in range(len(grid)):
        for j in range(len(grid[i])):

            idx = [(i - 1, j), (i, j - 1), (i, j + 1), (i + 1, j)]
            check = [1 if k[0] in range(row) and k[1] in range(col) else 0
                     for k in idx]

            if grid[i][j]:
                count += sum([1 if not r or not grid[k[0]][k[1]] else 0
                              for r, k in zip(check, idx)])

    return (count)
