# 풍선 터뜨리기

# 원형으로 놓여진 풍선 (1번 왼쪽이 n번)
# 1번 풍선을 터트리고, 풍선 안에 있는 숫자만큼 왼쪽으로 이동
# 터진 풍선 순서 구하기

from collections import deque

n = int(input())
data = deque(enumerate(map(int, input().split()))) # 인덱스, 값 저장

for _ in range(n):
    idx, value = data.popleft()
    print(idx+1, end=' ')

    # 수가 양수이면 오른쪽으로 이동 (deque에서는 왼쪽)
    if value > 0:
        data.rotate(-(value-1)) # 1번은 터트렸으므로 -1
    # 음수이면 왼쪽으로 이동 (deque에서는 오른쪽)
    else:
        data.rotate(-value)

