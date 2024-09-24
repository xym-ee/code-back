from collections import deque

# 定义上下左右四个方向
directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def bfs(maze, N, max_radiation):
    """
    使用 BFS 检查是否存在一条路径，使得经过的格子的辐射值都不超过 max_radiation
    """
    # 如果起点或终点的辐射值超过 max_radiation，直接返回 False
    if maze[0][0] > max_radiation or maze[N-1][N-1] > max_radiation:
        return False
    
    # BFS 队列
    queue = deque([(0, 0)])
    # 访问标记
    visited = [[False] * N for _ in range(N)]
    visited[0][0] = True
    
    while queue:
        x, y = queue.popleft()
        
        # 如果到达右下角，返回 True
        if x == N-1 and y == N-1:
            return True
        
        # 遍历四个方向
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            # 判断是否在边界内，并且没有访问过，且辐射值不超过 max_radiation
            if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny] and maze[nx][ny] <= max_radiation:
                visited[nx][ny] = True
                queue.append((nx, ny))
    
    return False

def min_radiation(maze, N, K):
    # 二分查找的初始范围
    low = max(maze[0][0], maze[N-1][N-1])
    high = max(max(row) for row in maze)
    
    while low < high:
        mid = (low + high) // 2
        # 使用 BFS 检查是否可以在辐射值不超过 mid 的情况下从起点到终点
        if bfs(maze, N, mid):
            high = mid  # 如果可以，尝试更小的辐射值
        else:
            low = mid + 1  # 否则增加辐射值
            
    return low

# 输入读取
N = int(input())
K = int(input())
maze = [list(map(int, input().split())) for _ in range(N)]

# 输出结果
print(min_radiation(maze, N, K))
