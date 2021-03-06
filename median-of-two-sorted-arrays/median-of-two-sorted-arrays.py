class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        def median(A, B):
            m, n = len(A), len(B)

            # swap if A is larger. alwasy make A the smaller array
            if m > n:
                A, B, m, n = B, A, n, m
            if n == 0:
                raise ValueError


            imin, imax, half_len = 0, m, (m + n + 1) / 2

            # Basic binary search. Search the middle point.
            while imin <= imax:
                # Search the middle point
                i = (imin + imax) / 2
                j = half_len - i
                if i < m and B[j-1] > A[i]:
                    # i is too small, must increase it
                    # set the new lower boundary
                    imin = i + 1
                elif i > 0 and A[i-1] > B[j]:
                    # i is too big, must decrease it
                    # set the new higher boudary
                    imax = i - 1
                else:
                    # i is perfect

                    # edge cases
                    if i == 0: max_of_left = B[j-1]
                    elif j == 0: max_of_left = A[i-1]
                    else: max_of_left = max(A[i-1], B[j-1])

                    # Odd number 
                    if (m + n) % 2 == 1:
                        return max_of_left

                    # Even number case. 
                    if i == m: min_of_right = B[j]
                    elif j == n: min_of_right = A[i]
                    else: min_of_right = min(A[i], B[j])

                    return (max_of_left + min_of_right) / 2.0

        return median(nums1,nums2)