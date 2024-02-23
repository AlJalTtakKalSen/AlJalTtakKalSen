# 모의고사

# 가장 많은 정답을 맞힌 사람 구하기
# 각 학생의 찍는 방식 주기를 파악하기

def solution(answers):
    answer = []
    score = [0, 0, 0]
    s1 = [1, 2, 3, 4, 5]
    s2 = [2, 1, 2, 3, 2, 4, 2, 5]
    s3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

    for i in range(len(answers)):  # 정답을 순서대로 돌면서
        if answers[i] == s1[i % 5]:
            score[0] += 1
        if answers[i] == s2[i % 8]:
            score[1] += 1
        if answers[i] == s3[i % 10]:
            score[2] += 1

    for i in range(3):
        if score[i] == max(score):
            answer.append(i + 1)

    return answer