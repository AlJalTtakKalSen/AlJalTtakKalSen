# 의상

# 서로 다른 옷의 조합 수
# 일부 겹치는 것은 허용

def solution(clothes):
    answer = 1
    # 딕셔너리 {종류: 이름}
    d = {}
    for name, kind in clothes:
        if kind in d.keys():
            d[kind] += [name]
        else:
            d[kind] = [name]
    print(d)
    # 경우의 수 구하기 (n+1)(m+1)
    for _, value in d.items():
        answer *= (len(value) + 1)
    answer -= 1  # 아무것도 안입는 경우 제외

    return answer
