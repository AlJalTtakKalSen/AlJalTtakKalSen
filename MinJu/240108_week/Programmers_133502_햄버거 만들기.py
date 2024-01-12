# 빵-야채-고기-빵
def solution(ingredient):
    answer = 0
    stack = []
    for i in ingredient:
        stack.append(i) # 스택에 재료 추가
        if stack[-4:] == [1, 2, 3, 1]: # 스택에 쌓인 순서가 일치하면
            answer += 1
            for _ in range(4):
                stack.pop() # 만든 재료는 제거
    return answer