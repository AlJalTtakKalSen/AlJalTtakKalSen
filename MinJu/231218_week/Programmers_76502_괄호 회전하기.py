def solution(s):
    answer = 0
    length = len(s)

    for _ in range(length):
        s = s[1:] + s[0]
        stack = []
        valid = True

        for bracket in s:
            if bracket in '({[':
                stack.append(bracket)
            else:
                if not stack:
                    valid = False
                    break

                current_bracket = stack.pop()

                if bracket == ')' and current_bracket != '(':
                    valid = False
                    break
                elif bracket == '}' and current_bracket != '{':
                    valid = False
                    break
                elif bracket == ']' and current_bracket != '[':
                    valid = False
                    break

        if valid and not stack:
            answer += 1

    return answer