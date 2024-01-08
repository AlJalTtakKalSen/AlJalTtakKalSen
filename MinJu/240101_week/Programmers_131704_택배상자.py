# 택배상자

def solution(order):
    answer = 0
    arr = []  # 보조 컨베이어 벨트
    i = 1
    while i != len(order) + 1:
        # 보조 컨베이어에 물건을 옮김
        arr.append(i)

        # 성분 제거
        while arr and arr[-1] == order[answer]:
            answer += 1
            arr.pop()
        i += 1
    return answer