#include <SFML/Graphics.hpp>
#include "Snake.hpp"

const int N = 30,M = 20,size = 16,WIDTH = size * N,HEIGHT = size * M;

int main(){
    
    sf::RenderWindow app(sf::VideoMode(WIDTH,HEIGHT),"Snake Game!");
    sf::Texture t1,t2,t3;
    
    t1.loadFromFile("images/white.png");
    t2.loadFromFile("images/red.png");
    t3.loadFromFile("images/green.png");
    
    sf::Sprite s1(t1),s2(t2),s3(t3);
    sf::Clock clock;
    
    int dir{-1},ismoving{0};
    float timer{0},delay{0.1};
    Snake s;
    coordonates food;
    
    food.x = food.y = 10;
    
    while (app.isOpen()) {
        
        timer += clock.getElapsedTime().asSeconds();
        clock.restart();
        
        sf::Event e;
        
        while (app.pollEvent(e))
            if(e.type == e.Closed)
                app.close();
        
        for(int i = 0;i < N;i++)
            for(int j = 0;j < M;j++){
                s1.setPosition(size * i,size * j);
                app.draw(s1);
            }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){dir = 1;ismoving = true;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){dir = 2;ismoving = true;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){dir = 3;ismoving = true;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){{dir = 0;ismoving = true;}}
        
        if(timer > delay){
            timer = 0;
            s.move(dir, food);
        }
        
        for (int i = 0; i < s.len; i++) {
            s2.setPosition(s.snake[i].x * size,s.snake[i].y * size);
            app.draw(s2);
        }
        
        s3.setPosition(size * food.x, size * food.y);
        app.draw(s3);
        
        app.display();
        app.clear();
        
    }
    
    return 0;
}
