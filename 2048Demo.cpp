#include <algorithm>
#include <vector>
#include "2048demo.h"
#include "ProcessRow.cpp"

using std::reverse;
using std::vector;
using std::pair;

//判定游戏是否结束
bool Demo2048::IsGameOver(){
    // 检查空位
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) return false;
        }
    }
    // 检查相邻是否可合并
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((j < 3 && grid[i][j] == grid[i][j + 1]) ||
                (i < 3 && grid[i][j] == grid[i + 1][j])) {
                return false;
            }
        }
    }
    return true;
}

//左移的逻辑
void Demo2048::MoveLeft(){
    for(int i=0;i<4;i++)
        ProcessRow(grid[i].data(),Score);
    CreateTile(); //每次移动后创建新数字
}
//右移的逻辑，反转数组后左移再反转
void Demo2048::MoveRight(){
    for(int i=0;i<4;i++){
        reverse(grid[i].data(),grid[i].data()+4);
        ProcessRow(grid[i].data(),Score);
        reverse(grid[i].data(),grid[i].data()+4);
    }
    CreateTile(); 
}
//上移，下移对应需转置矩阵，以下为转置函数
void Demo2048::transpose(){
    std::array<std::array<int,4>,4> temp;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            temp[i][j]=grid[j][i];
    }
    grid=temp;

}
//上移，下移的逻辑
void Demo2048::MoveUp(){
        transpose();
        MoveLeft();
        transpose();
}

void Demo2048::MoveDown(){
        transpose();
        MoveRight();
        transpose();
}


void Demo2048::RstGame(){
    grid={};
    Score=0;
    CreateTile();
}
//创建新数字，90%几率为2，10%几率为4
void Demo2048::CreateTile(){
    vector <pair<int, int>> empty;
    for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (grid[i][j] == 0) empty.push_back({i, j});
            }
        }
    if (!empty.empty()) {
            auto pos = empty[rand() % empty.size()];
            grid[pos.first][pos.second] = (rand() % 10 < 9) ? 2 : 4;
        }
}