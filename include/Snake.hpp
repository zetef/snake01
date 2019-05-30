#pragma once

#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "consts.h"

class Snake{
	public:
		Snake();
		void move(int dir, sf::Vector2<int>& food);

		int len;
		sf::Vector2<int> snake[100];
};
