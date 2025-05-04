def solution(info, edges):
    answer = 0
    
    # 1. 이진 트리를 인접 그래프로 변경
    graph = [[] for _ in range(len(info))]
    visited = [False for _ in range(len(info))]
    for edge in edges:
        graph[edge[0]].append(edge[1])
        
    def DFS(curr, sheep, wolf, valid_vertexes):
        nonlocal answer
        # 종료 조건
        if sheep <= wolf:
            return
        
        # 양 업데이트
        answer = max(sheep, answer)
        valid_vertexes += graph[curr] 
        for vertex in valid_vertexes:
            new_vertexes = [item for item in valid_vertexes if item != vertex]
            if visited[vertex]: 
                DFS(vertex, sheep, wolf, new_vertexes)
                continue
                
            if info[vertex] == 0:
                DFS(vertex, sheep+1, wolf, new_vertexes)
            elif info[vertex] == 1:
                DFS(vertex, sheep, wolf+1, new_vertexes)
                
        return
    
    DFS(0,1,0,[])
            
        
        
        
    return answer