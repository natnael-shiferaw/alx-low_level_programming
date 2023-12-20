#!/usr/bin/python3
"""Defines a function to calculate the perimeter of an island."""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island represented by the grid.

    Args:
        grid (list): A list of lists of integers representing an island.
                     0 denotes water, and 1 denotes land.

    Returns:
        This function returns the perimeter of the island defined in the grid.
    """
    # Step 1: Find the dimensions of the grid (width and height).
    # Step 2: Iterate through the grid to count the number of land nodes and
    #        shared edges.
    # Step 3: Calculate and return the perimeter using the formula:
    #         perimeter = (number of land nodes * 4) - (number of shared edges * 2)
    # In this case the time Complexity would be big 'o' of 'n' square(O(n^2))
    size = 0
    edges = 0
    height = len(grid)
    width = len(grid[0])

    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                size += 1
                if (j > 0 and grid[i][j - 1] == 1):
                    edges += 1
                if (i > 0 and grid[i - 1][j] == 1):
                    edges += 1
    return size * 4 - edges * 2
