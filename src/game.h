#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game{
    public:
        Game();
        void Draw(sf::RenderWindow &window);
        void HandleInput(const sf::Event &event);
        void MoveBlockDown();
        bool gameOver;
        int score;

    private:
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void MoveBlockLeft();
        void MoveBlockRight();
        bool IsBlockOutside();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        void Reset();
        void UpdateScore(int linesCleared, int moveDownPoints);
        Grid grid;
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;

};