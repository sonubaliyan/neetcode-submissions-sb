class Solution:

    def encode(self, strs: List[str]) -> str:
        
        # abc fkgk
        # 3#abc4#fkgk
        res = ""
        for word in strs:
            length = len(word)
            res += str(length) + '#' + word

        return res



    def decode(self, s: str) -> List[str]:
        
        res = []
        i = 0

        while i < len(s):
            j = s.find("#", i)

            length = int(s[i : j])

            word = s[j+1 : j + 1 + length]

            res.append(word)

            i = j + 1 + length
        
        return res
