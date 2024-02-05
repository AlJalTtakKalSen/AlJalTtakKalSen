# 균형잡힌 세상

while True:
    word = input()
    if word == '.':
        break # 종료조건
    stack = []

    for i in word:
        if i in '([':
            stack.append(i) # 여는 소/대괄호이면 스택에 추가
        elif i == ']':
            if stack and stack[-1] == '[':
                stack.pop() # 스택 끝에 여는 대괄호가 있다면 짝지어지므로 제거
            else:
                stack.append(i)
                break
        elif i == ')':
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                stack.append(i)
                break
    if stack: # 스택에 남아있으면 균형잡히지 않은 문자열
        print('no')
    else:
        print('yes')
