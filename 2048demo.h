#pragma once

#include <array>

class Demo2048{
    public:
        Demo2048()=default;
        void MoveLeft();
        void MoveRight();
        void MoveUp();
        void MoveDown();
        bool IsGameOver();
        int GetScore() const
            {
                return Score;
            }
        const std::array<std::array<int,4>,4>& Getgrid() const
            {
                return grid;
            };
        void RstGame();
    private:
        void transpose();
        void CreateTile();
        std::array<std::array<int,4>,4> grid;
        int Score;
};