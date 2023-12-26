from collections import Counter

def solution(k, tangerine):
    answer = 0
    tangerine_count = Counter(tangerine)
    sorted_tangerine = sorted(tangerine_count.items(), key=lambda x: x[1], reverse=True)

    for _, count in sorted_tangerine:
        if k <= 0:
            return answer
        k -= count
        answer += 1

    return answer