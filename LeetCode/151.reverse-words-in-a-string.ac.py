# python3
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(str(i) for i in s.split()[::-1])