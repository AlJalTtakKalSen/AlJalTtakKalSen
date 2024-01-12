# 조건을 만족하는 부분 수열의 시작/마지막 인덱스 구하기
# 기존 수열의 부분 수열
# 부분 수열 합은 k
# 합이 k인 수열이 여러 개이면 길이가 짧은 수열
# 길이가 짧은 수열도 여러 개이면 시작 인덱스가 작은 수열 구하기

def solution(sequence, k):
    answer = []
    start = 0
    end = -1
    sum = 0

    while True:
        if sum < k:
            end += 1
            if end == len(sequence):
                break
            sum += sequence[end]
        else:
            if sum == k:
                answer.append((start, end))
            sum -= sequence[start]
            start += 1

    # 길이가 짧은 것, 시작 인덱스가 작은 것 순 정렬
    answer.sort(key=lambda x: (x[1] - x[0], x[0]))
    return answer[0]