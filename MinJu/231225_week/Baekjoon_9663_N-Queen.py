n = int(input())
row = [0] * n
answer = 0

# 유효한 배치인지 확인 (서로 공격 X)
def is_valid(x):
    for i in range(x):
        # 같은 열에 있는지 또는 대각선 상에 있는지 확인
        if row[x] == row[i] or abs(row[x] - row[i]) == x - i:
            return False
    return True

# N*N 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수
def solution(x):
    global answer
    if x == n:
        answer += 1
    else:
        for i in range(n):
            row[x] = i
            if is_valid(x):
                solution(x+1)

solution(0)
print(answer)
