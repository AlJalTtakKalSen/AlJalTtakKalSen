def solution(n, times):
# 탐색 범위 설정 (최소 시간 ~ 최악 시간)
    start = 1
    end = max(times) * n # 가장 긴 시간이 걸리는 심사관에게 n명이 모두 받는 경우 
    while start <= end:
        mid = (start + end) // 2 # 심사 시간 (범위에서 중간값)
        people = 0 # 모든 심사관들이 mid 시간 동안 심사한 사람의 수 
        for time in times:
            people += mid // time
            if people >= n: # mid 시간 동안 n명 이상 심사를 했다면 반복문 종료 
                break
        if people >= n: # 심사한 사람의 수가 많거나 같으면 시간이 충분 한 것
            answer = mid # 결과값 저장 
            end = mid - 1 # 왼쪽 부분 탐색 
        else: # 심사한 사람의 수가 적으면 시간이 부족한 것
            start = mid + 1 # 오른쪽 부분 탐색 
    return answer