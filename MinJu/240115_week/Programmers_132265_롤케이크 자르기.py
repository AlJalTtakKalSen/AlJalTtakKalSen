# 롤케이크 자르기

from collections import Counter

# 집합을 두 개 만들어 비교
def solution(topping):
    answer = 0
    dic = Counter(topping)
    print(dic)
    set_dic = set()  # 중복 제거

    # 집합 두 개 만들어 비교
    for i in topping:
        dic[i] -= 1  # 하나 차감
        set_dic.add(i)
        if dic[i] == 0:
            dic.pop(i)  # 0 되면 제거
        if len(dic) == len(set_dic):
            answer += 1

    return answer