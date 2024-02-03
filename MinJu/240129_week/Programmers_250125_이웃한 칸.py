def solution(board, h, w):
    count = 0  # 같은 색으로 색칠된 칸의 개수를 저장할 변수
    n = len(board)  # 보드의 길이
    d = [(1, 0), (-1, 0), (0, 1), (0, -1)]  # 상하좌우

    for dh, dw in d:
        h_check, w_check = h + dh, w + dw  # 각 방향별 탐색
        if 0 <= h_check < n and 0 <= w_check < n:  # 범위 내이고
            if board[h][w] == board[h_check][w_check]:  # 색이 같다면
                count += 1  # 카운트
    return count



