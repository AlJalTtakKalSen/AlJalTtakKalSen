# 124 나라의 숫자

# 자연수만 존재 + 1, 2, 4로 표현
def solution(n):
    answer = ''
    # 1, 4, 7, 10 ,,,, 은 일의 자리 1
    # 3의 배수 제외 3진법
    # 3의 배수이면 n//3 -1
    while n:
        if n % 3 != 0: # 3의 배수가 아니라면
            answer += str(n%3)
            n = n//3
        else:
            answer += "4"
            n = n//3 -1
    return answer[::-1] # 역순