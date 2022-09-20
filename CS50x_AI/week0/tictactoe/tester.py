import tictactoe as ttt
import math, copy

X = "X"
O = "O"
EMPTY = None

def initial_state():
    """
    Returns starting state of the board.
    """
    return [[X, O, X],
            [O, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]

board = initial_state()
print(ttt.minimax(board))
