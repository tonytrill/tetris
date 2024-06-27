#include "RoundedRectangleShape.h"
#include <SFML/Graphics.hpp>
#include "game.h"
#include "colors.h"
#include <iostream>



int main (){
    sf::RenderWindow window(sf::VideoMode(500,620), "Tetris");
    window.setFramerateLimit(60);

    sf::Font font;
    sf::Text scoreTitle;
    sf::Text nextText;
    sf::Text gameOverText;
    if (font.loadFromFile("../Font/monogram.ttf"))
    {
        scoreTitle.setFont(font);
        scoreTitle.setString("Score");
        scoreTitle.setPosition(365,15);
        scoreTitle.setCharacterSize(38);
        scoreTitle.setFillColor(sf::Color::White);
        nextText.setFont(font);
        nextText.setString("Next");
        nextText.setPosition(370,175);
        nextText.setCharacterSize(38);
        nextText.setFillColor(sf::Color::White);
        gameOverText.setFont(font);
        gameOverText.setString("GAME OVER");
        gameOverText.setPosition(340,450);
        gameOverText.setCharacterSize(38);
        gameOverText.setFillColor(sf::Color::White);
    }
    sf::RoundedRectangleShape scoreRectangle = sf::RoundedRectangleShape(sf::Vector2f(170, 60), 8,4);
    scoreRectangle.setFillColor(lightBlue);
    scoreRectangle.setPosition(320, 60);
    sf::RoundedRectangleShape nextRectangle = sf::RoundedRectangleShape(sf::Vector2f(170, 180), 8,4);
    nextRectangle.setFillColor(lightBlue);
    nextRectangle.setPosition(320, 220);

    Game game = Game();

    sf::Clock clock;
    while(window.isOpen()){
       
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            game.HandleInput(event);
        }
        window.clear(darkBlue);
        window.draw(scoreTitle);
        window.draw(scoreRectangle);
        sf::Text score;
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        score.setFont(font);
        score.setString(scoreText);
        sf::FloatRect textSize =  score.getLocalBounds();
        score.setPosition(315+(170-textSize.getSize().x)/2, 65);
        score.setCharacterSize(38);
        score.setFillColor(sf::Color::White);
        window.draw(score);
        window.draw(nextText);
        window.draw(nextRectangle);
        
        if(clock.getElapsedTime().asSeconds() >= 0.2)
        {
            game.MoveBlockDown();
            clock.restart();
        }
        if(game.gameOver){
            window.draw(gameOverText);
        }
        game.Draw(window);
        
        window.display();
        
    }

    return 0;
}