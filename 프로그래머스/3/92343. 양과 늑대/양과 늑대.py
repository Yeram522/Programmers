def solution(info, edges):
    answer = 0
    visited = [0] * len(info) # 방문 체크
    
    # 인접 그래프로 변환
    graph = [[] for _ in range(len(info))]
    for u, v in edges:
        graph[u].append(v)  # 단방향으로만 추가
        
    def backtracking(current,sheep, wolf,next_possible):
        # 현재 노드 처리
        if info[current] == 0:
            sheep += 1
        else:
            wolf += 1
    
        # 늑대가 양보다 많으면 종료
        if wolf >= sheep:
            return

        # 최대 양 업데이트
        nonlocal answer
        answer = max(answer, sheep)
        
        next_nodes = next_possible + graph[current]
        
        for next_node in next_nodes:
            next_candidates = [n for n in next_nodes if n != next_node]
            backtracking(next_node, sheep, wolf, next_candidates)
        
    backtracking(0, 0, 0, [])
    
    return answer