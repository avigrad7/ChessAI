#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(Color WhatColor, sf::RenderWindow& window);
public:
	std::vector<sf::Vector2f> possibleMoves(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray) override;
};