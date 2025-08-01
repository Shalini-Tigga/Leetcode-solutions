class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        stack = []
        idx = 0
        for i in range(len(word)):
            if(word[i] != ch):
                stack.append(word[i])
            else:
                stack.append(ch)
                idx = i
                break
        if idx == 0:
            return word
        s = ""  
        while stack:
            s += stack.pop()
        s += word[idx +1:]
        return s
        
        
