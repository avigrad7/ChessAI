#pragma once
#include<SFML/Graphics.hpp>
#include"Enums.h"

#define BLACK Color::Black
#define WHITE Color::White

class Piece
{
public:
	/*
	* Gets the piece
	*
	* @return A reference to the piece
	*/
	sf::RectangleShape& getPiece() { return m_Graphic; }
	/*
	* Gets the color of the piece
	*
	* @return The color of the piece
	*/
	const int getColor() const { return (int)m_Color; }
	/*
	* Checks if the piece is deleted
	*
	* @return If the piece is deleted
	*/
	bool isDeleted() const { return m_Deleted; }
	/*
	* Deletes the Piece
	*
	* @param positions: A vector of positions to remove the piece from (set it to -1000, -1000)
	* @param index: Where in the vector to remove the piece
	*
	* @return None
	*/
	void deletePiece(std::vector<sf::Vector2f>& positions, int index)
	{
		m_Deleted = true;
		m_Graphic.setPosition(sf::Vector2f(-1000, -1000));
		positions[index] = sf::Vector2f(-1000, -1000);
	}
protected:
	Piece() : m_Color(Color::White) {}
protected:
	/*
	* Figures out all possible moves
	*
	* @param whitePositions: Vector of all the positions of the white pieces
	* @param blackPositions: Vector pf all the positions of the black pieces
	* @param indexInArray: PositionIn the Vector where "this" piece could be found
	*
	* @return Vector of possible moves
	*/
	virtual std::vector<sf::Vector2f> possibleMoves(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray) = 0;
	/*
	* Checks all the moves to the top left of the Piece
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
	* Checks all the moves to the top right of the Piece
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
	* Checks all the moves to the bottom left of the Piece
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
	* Checks all the moves to the bottom right of the Piece
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
	* Checks all the moves to the left of the Piece
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
	* Checks all the moves to the Right of the Piece
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
	* Checks all the moves Above the Piece
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
	* Checks all the moves below the Piece
	*
	* @param allMoves: Vector of all moves
	* @param whitePositions: Vector of the positions of the white pieces
	* @param blackPositions: Vector of the positions of the black pieces
	* @param indexInArray: The index in the position array
	*
	* @return None
	*/
	void moveDown(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray);
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
protected:
	Color m_Color;
	sf::RectangleShape m_Graphic;
	bool m_Deleted = false;
public:
	static sf::Texture m_GraphicTexture;
};
