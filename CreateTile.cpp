#include <vector>
using std::vector;
using std::pair;
//创建新数字，90%几率为2，10%几率为4
void CreateTile(int grid[4][4]){
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