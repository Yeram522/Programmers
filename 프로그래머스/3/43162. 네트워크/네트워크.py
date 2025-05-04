def solution(n, computers):
    answer = 0
    visited = set()
    
    def dfs(com):
        if com in visited:
            return
        
        visited.add(com)
        
        for other in range(n):
            if other == com : continue
            if computers[com][other] == 1 or computers[other][com] == 1:
                dfs(other)
                
    for i in range(n):
        if i not in visited:
            dfs(i)
            answer += 1
    return answer