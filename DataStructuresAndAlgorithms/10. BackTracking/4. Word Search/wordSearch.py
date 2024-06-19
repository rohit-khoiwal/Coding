def exist(board, word: str) -> bool:
    visited = set()
    def dfs(i, j, k):
        if i*10 + j in visited:
            return False
        visited.add(i*10 + j)
        if k == len(word):
            return True
        left = [i, j-1]
        right = [i, j+1]
        up = [i-1, j]
        down = [i+1, j]
        #up
        if i > 0 and board[up[0]][up[1]] == word[k]:
            if dfs(i-1, j, k+1): return True
        #down
        if i < len(board) - 1 and board[down[0]][down[1]] == word[k]:
            if dfs(i+1, j, k+1): return True
        # left
        if j > 0 and board[left[0]][left[1]] == word[k]:
            print(word[k], i, j)
            if dfs(i, j-1, k+1): return True
        # right
        if j < len(board[0]) - 1 and board[right[0]][right[1]] == word[k]:
            if dfs(i, j+1, k+1): return True
        visited.remove(i*10 + j)
        return False

    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == word[0]:
                if dfs(i, j, 1): return True
    return False
if __name__ == '__main__':
    board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]] 
    word = "ABCCED"
    # board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    # word = "SEE"
    # board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    # word = "ABCB"
    # # board = [["C","A","A"],["A","A","A"],["B","C","D"]]
    # word = "AAB"

    print(exist(board, word))