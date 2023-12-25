from collections import Counter

def solution(weights):
    answer = 0
    counter = Counter(weights)

    for weight, count in counter.items():
        answer += count * (count - 1) // 2

        two_weight = weight * 2
        three_weight = weight * 3 / 2
        four_weight = weight * 4 / 3

        answer += count * counter[two_weight]
        answer += count * counter[three_weight]
        answer += count * counter[four_weight]

    return answer