from collections import deque

def solution(priorities, location):
    q = deque(priorities)
    answer = 0
    
    while q:
        m = max(q)
        l = q.popleft()
        location -= 1 
        if l != m:
            q.append(l)
            if location < 0:
                location = len(q) -1
        else:
            answer += 1
            if location < 0:
                break
            
    return answer