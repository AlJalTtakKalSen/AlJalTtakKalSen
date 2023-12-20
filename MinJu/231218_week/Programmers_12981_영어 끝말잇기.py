def solution(n, words):
    length = len(words)
    
    for i in range(1, length):
        if words[i - 1][-1] != words[i][0]:
            return [i % n + 1, i // n + 1]
        elif words[i] in words[:i]:
            return [i % n + 1, i // n + 1]
        elif len(words[i]) == 1:
            return [i % n + 1, i // n + 1]
        
    return [0, 0]