#include <SFML/Graphics.hpp>

#include "../include/consts.h"
#include "../include/Snake.hpp"

int main(int argc, char *argv[])
{    
	sf::RenderWindow app(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake Game!");
	sf::Texture tex_tile, tex_block, tex_apple;
    
	tex_tile.loadFromFile("../images/white.png");
	tex_block.loadFromFile("../images/red.png");
	tex_apple.loadFromFile("../images/green.png");
    
	sf::Sprite tile(tex_tile), block(tex_block), apple(tex_apple);
	sf::Clock clock;
    
	sf::Event e;
    
	int dir = -1;
	float timer = 0, delay = 0.1;
	Snake s;
	sf::Vector2<int> food(10, 10);
	
	while (app.isOpen()) {
		timer += clock.getElapsedTime().asSeconds();
		clock.restart();
        
		while (app.pollEvent(e)) {
			if (e.type == e.Closed)
				app.close();
			
			if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Escape))
				app.close();
			
			if (e.type == sf::Event::KeyPressed)
				switch (e.key.code) {
					case sf::Keyboard::A:
					case sf::Keyboard::Left:
						dir = LEFT;
						break;
					
					case sf::Keyboard::D:
					case sf::Keyboard::Right:
						dir = RIGHT;
						break;
					
					case sf::Keyboard::W:
					case sf::Keyboard::Up:
						dir = UP;
						break;
						
					case sf::Keyboard::S:
					case sf::Keyboard::Down:
						dir = DOWN;
						break;
						
					default: break;
				}
		}
            
        
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++){
				tile.setPosition(SIZE * i, SIZE * j);
				app.draw(tile);
			}
		
		if(timer > delay){
			timer = 0;
			s.move(dir, food);
		}
		
		for (int i = 0; i < s.len; i++) {
			block.setPosition(s.snake[i].x * SIZE, s.snake[i].y * SIZE);
			app.draw(block);
		}
		
		apple.setPosition(SIZE * food.x, SIZE * food.y);
		app.draw(apple);
		
		app.display();
		app.clear();
		
	}
    
	return 0;
}
