#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 1000;
const std::string WINDOW_TITLE = "Race to the bottom";
const float FPS = 60.f;

const sf::Vector2f START{ WINDOW_WIDTH / 2, WINDOW_HEIGHT - 550 };

const sf::Vector2f textPosition{ WINDOW_WIDTH - 100.f, 50 };
const sf::Vector2f textPosition1{ WINDOW_WIDTH - 150.f, 100 };
const sf::Vector2f textPosition2{ WINDOW_WIDTH - 100.f, 100 };
const sf::Vector2f textPosition3{ WINDOW_WIDTH - 100.f, 150 };
const sf::Vector2f textPosition4{ WINDOW_WIDTH - 150.f, 50 };
const sf::Vector2f textPosition5{ WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
const sf::Vector2f Pos { WINDOW_WIDTH - 100.f, 200 };
const std::string file_Name = "car1.png";