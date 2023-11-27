def solution(n, lost, reserve):
    reserve_set = set(reserve)
    lost_set = set(lost)

    for i in reserve_set.copy():
        if i in lost_set:
            reserve_set.remove(i)
            lost_set.remove(i)

    for i in reserve_set:
        if i - 1 in lost_set:
            lost_set.remove(i - 1)
        elif i + 1 in lost_set:
            lost_set.remove(i + 1)

    answer = n - len(lost_set)

    return answer