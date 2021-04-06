#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(Color WhatColor, sf::RenderWindow& window);
public:
	std::vector<sf::Vector2f> possibleMoves(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray) override;
private:
	/*
	* Checks all the moves to the top left of the Bishop
	*
	* @param allMoves: Vector of all moves
	* @param whitePositions: Vector of the positions of the white pieces
	* @param blackPositions: Vector of the positions of the black pieces
	* @param indexInArray: The index in the position array
	*
	* @return None
	*/
	void moveUpLeft(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray);
	/*
	* Checks all the moves to the top right of the Bishop
	*
	* @param allMoves: Vector of all moves
	* @param whitePositions: Vector of the positions of the white pieces
	* @param blackPositions: Vector of the positions of the black pieces
	* @param indexInArray: The index in the position array
	*
	* @return None
	*/
	void moveUpRight(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray);
	/*
	* Checks all the moves to the bottom left of the Bishop
	*
	* @param allMoves: Vector of all moves
	* @param whitePositions: Vector of the positions of the white pieces
	* @param blackPositions: Vector of the positions of the black pieces
	* @param indexInArray: The index in the position array
	*
	* @return None
	*/
	void moveDownLeft(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray);
	/*
	* Checks all the moves to the bottom right of the Bishop
	*
	* @param allMoves: Vector of all moves
	* @param whitePositions: Vector of the positions of the white pieces
	* @param blackPositions: Vector of the positions of the black pieces
	* @param indexInArray: The index in the position array
	*
	* @return None
	*/
	void moveDownRight(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray);
	/*
	* Checks all the moves to the left of the Rook
	*
	* @param allMoves: Vector of all moves
	* @param whitePositions: Vector of the positions of the white pieces
	* @param blackPositions: Vector of the positions of the black pieces
	* @param indexInArray: The index in the position array
	*
	* @return None
	*/
	void moveLeft(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray);
	/*
	* Checks all the moves to the Right of the Rook
	*
	* @param allMoves: Vector of all moves
	* @param whitePositions: Vector of the positions of the white pieces
	* @param blackPositions: Vector of the positions of the black pieces
	* @param indexInArray: The index in the position array
	*
	* @return None
	*/
	void moveRight(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray);
	/*
	* Checks all the moves Above the Rook
	*
	* @param allMoves: Vector of all moves
	* @param whitePositions: Vector of the positions of the white pieces
	* @param blackPositions: Vector of the positions of the black pieces
	* @param indexInArray: The index in the position array
	*
	* @return None
	*/
	void moveUp(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray);
	/*
	* Checks all the moves below the Rook
	*
	* @param allMoves: Vector of all moves
	* @param whitePositions: Vector of the positions of the white pieces
	* @param blackPositions: Vector of the positions of the black pieces
	* @param indexInArray: The index in the position array
	*
	* @return None
	*/
	void moveDown(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray);
};