#include "King.h"

King::King(Color whatColor, sf::RenderWindow& window)
{
	m_Color = whatColor;
	m_Graphic.setSize(sf::Vector2f((float)window.getSize().x / 8, (float)window.getSize().y / 8));
	m_Graphic.setTexture(&m_GraphicTexture);
	auto textureSize = m_GraphicTexture.getSize();
	textureSize.x /= 6;
	textureSize.y /= 2;

	if (m_Color == Color::Black)
	{
		m_Graphic.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y, textureSize.x, textureSize.y));
	}
	else
	{
		m_Graphic.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));
	}
}
std::vector<sf::Vector2f> King::possibleMoves(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
{
	std::vector<sf::Vector2f> allMoves;
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, 0, 1);
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, 0, -1);
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, 1, 0);
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, -1, 0);
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, -1, 1);
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, 1, 1);
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, -1, -1);
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, 1, -1);
	return allMoves;
}