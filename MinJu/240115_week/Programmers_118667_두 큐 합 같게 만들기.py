# 두 큐 합 같게 만들기

from collections import deque


def solution(queue1, queue2):
    answer = 0
    q1 = deque(queue1)
    q2 = deque(queue2)
    sum1 = sum(queue1)
    sum2 = sum(queue2)

    # 두 큐 합이 홀 수일 경우 같아질 수 없음
    if (sum1 + sum2) % 2 != 0:
        return -1
    while True:
        if answer == 4 * len(queue1):
            return -1
        if sum1 > sum2:  # 1번 큐가 더 크면
            tmp = q1.popleft()
            q2.append(tmp)  # q2에 추가
            # 합 갱신
            sum1 -= tmp
            sum2 += tmp
        elif sum1 < sum2:
            tmp = q2.popleft()
            q1.append(tmp)
            sum1 += tmp
            sum2 -= tmp
        else:
            return answer
        answer += 1
    return answer