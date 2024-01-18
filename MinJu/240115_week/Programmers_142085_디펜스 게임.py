# 디펜스 게임

from heapq import heappop, heappush
def solution(n, k, enemy):
    answer, cnt = 0, 0 # 라운드 수, 적의 전체 수
    heap = []

    for e in enemy:
        heappush(heap, -e)  # 최대힙 음수형식으로 저장
        cnt += e  # 적의 전체 수 갱신
        if cnt > n:  # 보유 병사보다 적의 전체수가 많으면
            if k == 0: break  # k도 없으면 종료
            cnt += heappop(heap)  # 적이 가장 많은 라운드 차감
            k -= 1  # 무적권 수 -1
        answer += 1
    return answer