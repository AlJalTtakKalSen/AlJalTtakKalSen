# 모음 사전
# 알파벳 모음을 사용하여 만들 수 있는 길이 5 이하의 단어가 있는 사전
# 단어가 사전에서 몇 번째인지 구하기
from itertools import product


def solution(word):
    answer = 0
    vowel = ['A', 'E', 'I', 'O', 'U']
    words = []

    # 중복 순열로 단어 구하기
    for i in range(1, 6):  # 길이 1부터 5까지
        for j in product(vowel, repeat=i):
            words.append(''.join(list(j)))
    words.sort()
    answer = words.index(word) + 1
    return answer