#include "Snake.hpp"

Snake::Snake(){
    len = 1;
    snake[0].x = N / 2;
    snake[0].y = M / 2;
}

void Snake::move(int dir,coordonates& food){
    
    for (int i = len; i > 0; i--) {
        snake[i].x = snake[i - 1].x;
        snake[i].y = snake[i - 1].y;
    }
    
    if (dir == 0) snake[0].y += 1;
    if (dir == 1) snake[0].x -= 1;
    if (dir == 2) snake[0].x += 1;
    if (dir == 3) snake[0].y -= 1;
    
    if(food.x == snake[0].x && food.y == snake[0].y){
        len++;
        food.x = rand() % N;
        food.y = rand() % M;
    }
    
    if (snake[0].x > N) snake[0].x = 0;
    if (snake[0].x < 0) snake[0].x = N;
    if (snake[0].y > M) snake[0].y = 0;
    if (snake[0].y<0) snake[0].y=M;
    
    for (int i = 1;i < len ;i++)
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            len = i;
}
