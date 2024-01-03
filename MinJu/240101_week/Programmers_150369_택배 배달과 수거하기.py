# 택배 배달과 수거하기

# 트럭에 재활용 상자 최대 cap개 올릴 수 있음
# 각 집에 배달/수거 최소 거리로 이동

# 가장 먼 곳부터 이동하기

def solution(cap, n, deliveries, pickups):
    answer = 0 # 최소 거리
    truck = [0, 0] # 배달 상자 ,수거 상자
    # 가장 먼 곳부터 이동하기
    for i in range(n-1, -1, -1):
        truck[0] += deliveries[i]
        truck[1] += pickups[i]
        # 상자를 모두 채울 때까지 이동
        while truck[0] > 0 or truck[1] > 0:
            # 상자가 남아있을 경우 cap 수만큼 내림
            truck [0] -= cap
            truck [1] -= cap
            answer += (i+1) * 2 # 다시 지점으로 돌아오므로 *2
    return answer
