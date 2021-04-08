#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(Color WhatColor, sf::RenderWindow& window);
public:
	std::vector<sf::Vector2f> possibleMoves(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray) override;
	bool hasBeenMoved() { return hasMoved; }
	void moved() { hasMoved = true; }
	bool hasMoved = false;
};

