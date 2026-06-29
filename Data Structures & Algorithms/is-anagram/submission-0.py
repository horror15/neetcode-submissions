class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        anagram_1 = {}
        anagram_2 = {}
        for char in s:
            if char in anagram_1:
                anagram_1[char] = anagram_1[char] + 1
            else:
                anagram_1[char] = 0
        for char in t:
            if char in anagram_2:
                anagram_2[char] = anagram_2[char] + 1
            else:
                anagram_2[char] = 0
        return anagram_1 == anagram_2