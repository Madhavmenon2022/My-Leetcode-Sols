# Last updated: 6/5/2026, 8:47:21 PM
1class Solution(object):
2    def sortColors(self, nums):
3        """
4        :type nums: List[int]
5        :rtype: void Do not return anything, modify nums in-place instead.
6        """
7        def triPartition(nums, target):
8            i, left, right = 0, 0, len(nums)-1
9            while i <= right:
10                if nums[i] > target:
11                    nums[i], nums[right] = nums[right], nums[i]
12                    right -= 1
13                else:
14                    if nums[i] < target:
15                        nums[left], nums[i] = nums[i], nums[left]
16                        left += 1
17                    i += 1
18
19        triPartition(nums, 1)