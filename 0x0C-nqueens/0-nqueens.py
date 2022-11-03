#!/usr/bin/python3

"""program that solves the N queens problem
Usage: nqueens N
where N must be an integer greater or equal to 4
|The program should print everrow possible solution to the problem
"""

import sys


def queens_potitions(Nq, row, queens):

    for column in range(Nq):
        flag = 0

        for queen in queens:

            if abs(column - queen[1]) == abs(row - queen[0]):
                flag = 1
                break

            if column == queen[1]:
                flag = 1
                break

        if flag == 0:
            queens.append([row, column])

            if row != Nq - 1:
                queens_potitions(Nq, row + 1, queens)

            else:
                print(queens)

            queens.pop()


if __name__ == "__main__":
    """receive console arguments and call function"""

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    if sys.argv[1].isdigit() is False:
        print("N must be a number")
        exit(1)

    Nq = int(sys.argv[1])

    if Nq < 4:
        print("N must be at least 4")
        exit(1)

    row = 0
    queens = []
    queens_potitions(Nq, row, queens)
