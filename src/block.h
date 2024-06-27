#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block {
    public:
        Block();
        void Draw(sf::RenderWindow &window, int offsetX, int offsetY);
        void Move(int rows, int columns);
        std::vector<Position> GetCellPositions();
        void Rotate();
        void UndoRotate();
        int id;
        std::map<int,std::vector<Position>> cells;
    private:
        int cellSize;
        int rotationState;
        std::vector<sf::Color> colors;
        int rowOffset;
        int columnOffset;
};