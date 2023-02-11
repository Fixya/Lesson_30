#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

struct RoadLayer
{
	sf::Texture texture;
	sf::Sprite sprite;
};

struct all_text
{
	sf::Text  text[4];
	int hp = 3, point = 0;
	sf::Font font;

};

void initRoadL(RoadLayer& layer, sf::Vector2f pos, std::string fileName)
{
	layer.texture.loadFromFile(fileName);
	layer.sprite.setTexture(layer.texture);
	layer.sprite.setPosition(pos);
}

void textInit(all_text& text, all_text& font)
{
	font.font.loadFromFile("ds-digib.ttf");
	for (int i = 0; i < 4; i++)
	{
		text.text[i].setFont(font.font);
		text.text[i].setCharacterSize(30);
	}
		text.text[0].setPosition(textPosition);
		text.text[1].setPosition(textPosition1);
		text.text[2].setPosition(textPosition2);
		text.text[3].setPosition(textPosition3);
}

void PText1(all_text& text, std::int16_t tim, all_text& hp, all_text& point)
{
	text.text[0].setString(std::to_string(tim));
	text.text[1].setString("Hp");
	text.text[2].setString(std::to_string(hp.hp));
	text.text[3].setString(std::to_string(point.point));
}