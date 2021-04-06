#include "Knight.h"

Knight::Knight(Color whatColor, sf::RenderWindow& window)
{
	m_Color = whatColor;
	m_Graphic.setSize(sf::Vector2f((float)window.getSize().x / 8, (float)window.getSize().y / 8));
	m_Graphic.setTexture(&m_GraphicTexture);
	auto textureSize = m_GraphicTexture.getSize();
	textureSize.x /= 6;
	textureSize.y /= 2;

	if (m_Color == Color::Black)
	{
		m_Graphic.setTextureRect(sf::IntRect(textureSize.x * 3, textureSize.y, textureSize.x, textureSize.y));
	}
	else
	{
		m_Graphic.setTextureRect(sf::IntRect(textureSize.x * 3, textureSize.y * 0, textureSize.x, textureSize.y));
	}
}
std::vector<sf::Vector2f> Knight::possibleMoves(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
{
	std::vector<sf::Vector2f> allMoves;
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, -1, 2);
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, 1, 2);
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, -1, -2);
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, 1, -2);
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, -2, 1);
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, -2, -1);
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, 2, 1);
	checkIfCouldMove(whitePositions, blackPositions, indexInArray, allMoves, 2, -1);
	return allMoves;
}

void Knight::checkIfCouldMove(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray, std::vector<sf::Vector2f>& allMoves, int moveToX, int moveToY)
{
	int thisX = 0;
	int thisY = 0;
	if (m_Color == WHITE)
	{
		thisX = (int)whitePositions[indexInArray].x;
		thisY = (int)whitePositions[indexInArray].y;
	}
	else
	{
		thisX = (int)blackPositions[indexInArray].x;
		thisY = (int)blackPositions[indexInArray].y;
	}
	bool couldMove = true;
	for (int i = 0; i < (int)whitePositions.size(); i++)
	{
		if (m_Color == WHITE && whitePositions[i].x == thisX + moveToX && whitePositions[i].y == thisY + moveToY || m_Color == BLACK && blackPositions[i].x == thisX + moveToX && blackPositions[i].y == thisY + moveToY)
		{
			couldMove = false;
			i = whitePositions.size();
		}
	}
	if (thisX + moveToX > 8 || thisX + moveToX < 1 || thisY + moveToY > 8 || thisY + moveToY < 1)
	{
		couldMove = false;
	}
	if (couldMove)
	{
		allMoves.push_back(sf::Vector2f((float)thisX + moveToX, (float)thisY + moveToY));
	}
}
