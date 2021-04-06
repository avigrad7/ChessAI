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
private:
	/*
	* Checks if the Knight could move to a specified place
	*
	* @param whitePositions: The positions of all the white Pieces
	* @param blackPositions: The positions of all the black Pieces
	* @param indexInArray: The index in the position arrays that the piece could be found
	* @param allMoves: Vector of all possible moves
	* @param thisX: the X cordinate of the location you want to move relitive to the Knight
	* @param thisY: the Y cordinate of the location you want to move relitive to the Knight
	*
	* @return None
	*/
	void checkIfCouldMove(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray, std::vector<sf::Vector2f>& allMoves, int moveToX, int moveToY);
private:
	bool hasMoved = false;
};

