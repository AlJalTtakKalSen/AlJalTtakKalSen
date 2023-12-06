def solution(distance, rocks, n):
    answer = 0
# 탐색 범위 정하기 (start, end)
    start = 0
    end = distance
    rocks.sort() # 이진 탐색 수행을 위해 정렬
    rocks.append(distance) # 도착지 추가 

    while start <= end:
        mid = (start + end) // 2 # 최소 거리를 구하기 위해 탐색 범위의 중간값
        remove = 0 # 제거할 바위의 수 
        prev = 0   # 이전 위치 바위
        for rock in rocks: 
            if (rock - prev) < mid: # (현재 위치 - 이전 위치) 사이 거리가 중간값보다 작으면
                remove += 1 # 제거할 바위 수에 +1
                if remove > n: # 제거할 바위 수 n을 넘으면 종료 
                    break
            else:
                prev = rock # 거리가 중간값보다 크면 제거할 수 없으므로 prev에 현재 바위 위치
        if remove > n: # n을 넘어가면 왼쪽 부분으로 이동 (n을 초과하면 조건 불만족)
            end = mid - 1
        else: # n보다 작으면 더 큰 mid값 찾기 위해 오른쪽 부분으로 이동 
            answer = mid 
            start = mid + 1
    return answer