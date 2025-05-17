def solution(k, dungeons):
    answer = 0
    visited = [False for _ in range(len(dungeons))]
    
    def backtrack(tired, count):
        nonlocal answer
        
        answer = max(count, answer)
        for i, dungeon in enumerate(dungeons):
            if not visited[i] and tired >= dungeon[0]:     
                visited[i] = True
                backtrack(tired - dungeon[1], count + 1)
                visited[i] = False
                
    backtrack(k, 0)

    return answer