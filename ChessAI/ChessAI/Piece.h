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
protected:
	Color m_Color;
	sf::RectangleShape m_Graphic;
	bool m_Deleted = false;
public:
	static sf::Texture m_GraphicTexture;
};
