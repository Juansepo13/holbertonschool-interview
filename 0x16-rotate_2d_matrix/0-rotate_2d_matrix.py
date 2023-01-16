#!/usr/bin/python3
"""
File that contains the rotate_2d_matrix function
"""


def valid_matrix_size(matrix):
    """
    Function that checks if a matrix is valid
    """
    if (not type(matrix) is list):
        return False

    if (len(matrix) == 0):
        return False

    size = len(matrix)

    for row in matrix:
        if (not type(row) is list):
            return False

        if size != len(row):
            return False

    return True


def rotate_2d_matrix(matrix):
    """
    Function that rotates a 2D matrix 90 degrees clockwise
    """
    if valid_matrix_size(matrix) is False:
        return

    zipped = list(map(lambda x: list(x), zip(*matrix[::-1])))
    for i in range(len(matrix)):
        matrix[i] = zipped[i]
