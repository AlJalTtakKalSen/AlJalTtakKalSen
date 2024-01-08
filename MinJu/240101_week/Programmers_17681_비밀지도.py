# 비밀지도

# 숫자를 비트 연산 -> #으로 표현
def solution(n, arr1, arr2):
    answer = []
    print(bin(1111))
    for i in range(n): # 각 숫자들을 하나씩 계산
        tmp = bin(arr1[i]|arr2[i]) # or 비트 연산 후 2진법으로
        tmp = tmp[2:].zfill(n) # 앞 2개 자르고 0으로 채움
        tmp = tmp.replace('1', '#').replace('0',' ')
        answer.append(tmp)
    return answer