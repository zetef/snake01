#include "../include/Snake.hpp"

Snake::Snake(){
	len = 1;
	snake[HEAD].x = N / 2;
	snake[HEAD].y = M / 2;
	srand(time(NULL));
}

void Snake::move(int dir, sf::Vector2<int>& food){
	for (int i = len; i > HEAD; i--) {
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}
	
	if (dir == 0) snake[HEAD].y += 1;
	if (dir == 1) snake[HEAD].x -= 1;
	if (dir == 2) snake[HEAD].x += 1;
	if (dir == 3) snake[HEAD].y -= 1;
	
	if(food.x == snake[HEAD].x && food.y == snake[HEAD].y){
		len++;
		food.x = rand() % N;
		food.y = rand() % M;
	}
	
	if (snake[HEAD].x > N) snake[HEAD].x = 0;
	if (snake[HEAD].x < 0) snake[HEAD].x = N;
	if (snake[HEAD].y > M) snake[HEAD].y = 0;
	if (snake[HEAD].y < 0) snake[HEAD].y = M;
	
	for (int i = HEAD + 1; i < len; i++)
		if (snake[HEAD].x == snake[i].x && snake[HEAD].y == snake[i].y)
			len = i;
}
