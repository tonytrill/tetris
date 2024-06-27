#include "block.h"

Block::Block(){
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
};

void Block::Draw(sf::RenderWindow &window, int offSetX, int offSetY){
    std::vector<Position> tiles = GetCellPositions();
    for(Position item: tiles){
        sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(cellSize-1,cellSize-1));
        rectangle.setPosition(item.column*cellSize+offSetX, item.row*cellSize+offSetY);
        rectangle.setFillColor(colors[id]);
        window.draw(rectangle);
    }
};

void Block::Move(int rows, int columns){
    rowOffset+=rows;
    columnOffset += columns;
};

std::vector<Position> Block::GetCellPositions(){
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for( Position item: tiles){
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}
void Block::Rotate() {
    rotationState++;
    if(rotationState == cells.size()){
        rotationState = 0;
    };
}
void Block::UndoRotate() {
    rotationState --;
    if(rotationState == -1){
        rotationState = cells.size()-1;
    }
};