def solution(n, results):
    answer = 0
    board = [[0]*n for _ in range(n)]
    
    for a,b in results:
        board[a-1][b-1] = 1 # a가 이기면 1
        board[b-1][a-1] = -1 # a가 지면 -1 초기화 
    
    # board 순회 
    # i가 k에 이기고, k가 j에 이기면, i는 j에게 이김 
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if i == j or board[i][j] in [1,-1]:
                    continue
                if board[i][k] == board[k][j] == 1:
                    board[i][j] = 1
                    board[j][i] = board[k][i] = board[j][k] = -1
    for row in board:
        if row.count(0) == 1: # 각 노드에 0이 하나일 때만 answer에 +1 (승패 결정 완료)
            answer += 1
    return answer