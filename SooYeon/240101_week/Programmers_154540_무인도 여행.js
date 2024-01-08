function solution(maps) {
    const answer = [];
    
    let n = maps.length;
    let m = maps[0].length;
    
    let dy = [-1, 0, 1, 0];
    let dx = [0, 1, 0, -1];
    
    let visited = Array.from(Array(n),() => new Array(m).fill(false));
    
    const dfs = (y, x) => {
        visited[y][x] = true;
        let foodSum = Number(maps[y][x]);
        
        for(let i = 0; i < 4; i++){
            let ny = y + dy[i];
            let nx = x + dx[i];
            
            if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;
            if(maps[ny][nx] === 'X' || visited[ny][nx]) continue;
            
            foodSum += dfs(ny,nx);
        }
        
        return foodSum;
    }
    
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if(maps[i][j] !== 'X' && !visited[i][j]){
                answer.push(dfs(i, j));
            }
        }
    }
    if(answer.length === 0){
        return [-1];
    } 
    else {
        answer.sort((a, b) => a - b); // 오름차순 정렬
        return answer; 
    }

}
