class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else [] 

def clone_graph(node):
    if not node:
        return
    visited = set()
    def bfs():
        pass

if __name__ == "__main__":
    adjList = [[2,4],[1,3],[2,4],[1,3]]
    nodes = {}
    
    print(clone_graph(nodes[1]))