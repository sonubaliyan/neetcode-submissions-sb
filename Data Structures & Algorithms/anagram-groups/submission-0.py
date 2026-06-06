class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        res = defaultdict(list)

        for word in strs:
            count = [0] * 26

            for ch in word:
                index = ord(ch) - ord('a')
                count[index] += 1   # count = [1,0,1] ... populate the index based on char
            
            res[tuple(count)].append(word)

        return list(res.values())
