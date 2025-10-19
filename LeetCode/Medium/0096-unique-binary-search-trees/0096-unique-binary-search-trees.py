class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """

        c = 1  # C0
        for k in range(n):
            c = c * 2 * (2 * k + 1) // (k + 2)
        return c
        