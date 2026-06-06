class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        # take elem as key and value count as freq
        hashmap = {}

        for num in nums:
            hashmap[num] = hashmap.get(num, 0) + 1

        # sort by frequency (descending)
        sorted_items = sorted(hashmap.items(), key=lambda x: x[1], reverse=True)

        res = []
        for i in range(k):
            res.append(sorted_items[i][0])
        return res

        


            
        