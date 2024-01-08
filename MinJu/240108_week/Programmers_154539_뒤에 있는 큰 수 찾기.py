# 뒤에 있는 큰 수 찾기

# 뒷 큰 수 : 자신보다 뒤에 있는 숫자 중 자신보다 크면서 가장 가까이 있는 수
# 모든 원소에 대한 뒷 큰수 구하기
def solution(numbers):
    answer = [-1] * len(numbers)  # -1로 세팅 (뒷 큰 수 존재 X)
    stack = []

    for i in range(len(numbers)):
        # 스택의 마지막 인덱스와 비교 -> pop -> 뒷 큰 수가 없는 인덱스가 남도록
        while stack and numbers[stack[-1]] < numbers[i]:
            answer[stack.pop()] = numbers[i]
        stack.append(i)
    return answer