class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        return str(sorted(list(map(lambda x: int(x), nums)), reverse=True)[k - 1])