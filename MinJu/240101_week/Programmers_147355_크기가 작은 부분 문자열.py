# 크기가 작은 부분 문자열

# t에서 p와 길이 같은 부분 문자열 중 p가 나타내는 수보다 작거나 같은 것이 나오는 횟수 구하기

def solution(t, p):
    answer = 0

    # 부분 문자열과 p를 int형으로 변환하여 비교
    for i in range(len(t)-len(p) + 1):
        if int(t[i:i+len(p)]) <= int(p):
            answer += 1
    return answer