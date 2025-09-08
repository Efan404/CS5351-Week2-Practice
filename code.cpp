#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];

// 初始化棋盘，每个格子填入数字1-9
void initBoard() {
    char num = '1';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = num++;
        }
    }
}

// 打印当前棋盘状态
void printBoard() {
    cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << " " << board[i][j] << " ";
            if (j < SIZE - 1) cout << "|";
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "-----------\n";
    }
    cout << "\n";
}

// 检查当前棋局是否有一方获胜
bool checkWin() {
    // 检查所有行
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    
    // 检查所有列
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }
    
    // 检查两条对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    
    return false;
}

// 检查棋局是否平局（棋盘已满且无人获胜）
bool checkDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // 如果还有格子是数字，说明还可以落子，不是平局
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                return false;
            }
        }
    }
    // 所有格子都已被占满且未获胜，则是平局
    return true;
}

int main() {
    int currentPlayer = 1; // 1 代表玩家1（X），2 代表玩家2（O）
    int choice;
    char mark; // 当前玩家的棋子符号
    bool gameOver = false;
    
    initBoard();
    
    cout << "井字棋游戏开始！\n";
    cout << "玩家1 (X) - 玩家2 (O)\n\n";
    
    do {
        printBoard();
        currentPlayer = (currentPlayer % 2) ? 1 : 2;
        mark = (currentPlayer == 1) ? 'X' : 'O';
        
        cout << "玩家 " << currentPlayer << " (" << mark << "), 请输入数字(1-9)下棋: ";
        cin >> choice;
        
        int row = (choice - 1) / SIZE;
        int col = (choice - 1) % SIZE;
        
        if (choice >= 1 && choice <= 9 && board[row][col] >= '1' && board[row][col] <= '9') {
            board[row][col] = mark;
            currentPlayer++;
        } else {
            cout << "无效的移动，请重新选择！\n";
            continue;
        }
        
        if (checkWin()) {
            printBoard();
            cout << "\n==> 玩家 " << ((mark == 'X') ? 1 : 2) << " (" << mark << ") 获胜！\n";
            gameOver = true;
        } else if (checkDraw()) {
            printBoard();
            cout << "\n==> 游戏平局！\n";
            gameOver = true;
        }
        
    } while (!gameOver);
    
    return 0;
}
