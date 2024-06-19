def isValidSudoku(board: list) -> bool:
    rows = [set() for i in range(9)]
    cols = [set() for i in range(9)]
    boxs = [[set() for i in range(3)] for j in range(3)]
    for i in range(9):
        for j in range(9):
            if board[i][j] == " . ": continue
            if board[i][j] not in rows[i]:
                rows[i].add(board[i][j])
            else: return False
            
            if board[i][j] not in boxs[i//3][j//3]:
                boxs[i//3][j//3].add(board[i][j])
            else: return False
                
            if board[i][j] not in cols[j]:
                cols[j].add(board[i][j])
            else: return False
    return True

if __name__ == "__main__":
    board = [
                [" 5 ", " 3 ", " . ", " . ", " 7 ", " . ", " . ", " . ", " . "],
                [" 6 ", " . ", " . ", " 1 ", " 9 ", " 5 ", " . ", " . ", " . "],
                [" . ", " 9 ", " 8 ", " . ", " . ", " . ", " . ", " 6 ", " . "],
                [" 8 ", " . ", " . ", " . ", " 6 ", " . ", " . ", " . ", " 3 "],
                [" 4 ", " . ", " . ", " 8 ", " . ", " 3 ", " . ", " . ", " 1 "],
                [" 7 ", " . ", " . ", " . ", " 2 ", " . ", " . ", " . ", " 6 "],
                [" . ", " 6 ", " . ", " . ", " . ", " . ", " 2 ", " 8 ", " . "],
                [" . ", " . ", " . ", " 4 ", " 1 ", " 9 ", " . ", " . ", " 5 "],
                [" . ", " . ", " . ", " . ", " 8 ", " . ", " . ", " 7 ", " 9 "]
            ]

    print(isValidSudoku(board=board))

