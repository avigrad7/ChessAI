#pragma once
#include "Piece.h"
class Pawn : public Piece
{
public:
	Pawn(Color WhatColor, sf::RenderWindow& window);
public:
	std::vector<sf::Vector2f> possibleMoves(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray) override;
private:
	/*
	* Checks if the pawn could move up
	*
	* @param whitePositions: All the white pieces' positions
	* @param blackPositions: All the black pieces' positions
	* @param indexInArray: The index in the positions array that the piece could be found
	* @param allMoves: An array of all the possible moves
	*
	* @return None
	*/
	void moveUp(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray, std::vector<sf::Vector2f>& allMoves);
	/*
	* Checks if the pawn could take another piece
	*
	* @param whitePositions: All the white pieces' positions
	* @param blackPositions: All the black pieces' positions
	* @param indexInArray: The index in the positions array that the piece could be found
	* @param allMoves: An array of all the possible moves
	*
	* @return None
	*/
	void takePiece(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray, std::vector<sf::Vector2f>& allMoves);
};

