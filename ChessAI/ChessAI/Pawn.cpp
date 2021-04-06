#include "Pawn.h"

Pawn::Pawn(Color whatColor, sf::RenderWindow& window)
{
	m_Color = whatColor;
	m_Graphic.setSize(sf::Vector2f((float)window.getSize().x / 8, (float)window.getSize().y / 8));
	m_Graphic.setTexture(&m_GraphicTexture);
	auto textureSize = m_GraphicTexture.getSize();
	textureSize.x /= 6;
	textureSize.y /= 2;

	if (m_Color == Color::Black)
	{
		m_Graphic.setTextureRect(sf::IntRect(textureSize.x * 5, textureSize.y, textureSize.x, textureSize.y));
	}
	else
	{
		m_Graphic.setTextureRect(sf::IntRect(textureSize.x * 5, textureSize.y * 0, textureSize.x, textureSize.y));
	}
}
std::vector<sf::Vector2f> Pawn::possibleMoves(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
{
	std::vector<sf::Vector2f> allMoves;
	moveUp(whitePositions, blackPositions, indexInArray, allMoves);
	takePiece(whitePositions, blackPositions, indexInArray, allMoves);
	return allMoves;
}

void Pawn::moveUp(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray, std::vector<sf::Vector2f>& allMoves)
{
	int thisX = 0;
	int thisY = 0;
	bool checked = false;
	int colorForAdding = 0;
	if (m_Color == WHITE)
	{
		thisX = (int)whitePositions[indexInArray].x;
		thisY = (int)whitePositions[indexInArray].y;
		colorForAdding = -1;
	}
	else
	{
		thisX = (int)blackPositions[indexInArray].x;
		thisY = (int)blackPositions[indexInArray].y;
		colorForAdding = 1;
	}
	for (int i = 0; i < 16; i++)
	{
		if (whitePositions[i].x == thisX && whitePositions[i].y == thisY + colorForAdding || blackPositions[i].x == thisX && blackPositions[i].y == thisY + colorForAdding)
		{
			checked = true;
			i = 16;
		}
	}
	if (m_Color == WHITE)
	{
		if (!checked && thisY == 7)
		{
			colorForAdding = -2;
			for (int i = 0; i < 16; i++)
			{
				if (whitePositions[i].x == thisX && whitePositions[i].y == thisY + colorForAdding || blackPositions[i].x == thisX && blackPositions[i].y == thisY + colorForAdding)
				{
					checked = true;
					allMoves.push_back(sf::Vector2f((float)thisX, (float)thisY - 1));
					i = 16;
				}
			}
			if (!checked)
			{
				allMoves.push_back(sf::Vector2f((float)thisX, (float)thisY + colorForAdding));
				colorForAdding = -1;
			}
		}
	}
	if (m_Color == BLACK)
	{
		if (!checked && thisY == 2)
		{
			colorForAdding = 2;
			for (int i = 0; i < 16; i++)
			{
				if (whitePositions[i].x == thisX && whitePositions[i].y == thisY + colorForAdding || blackPositions[i].x == thisX && blackPositions[i].y == thisY + colorForAdding)
				{
					checked = true;
					allMoves.push_back(sf::Vector2f((float)thisX, (float)thisY + 1));
					i = 16;
				}
			}
			if (!checked)
			{
				allMoves.push_back(sf::Vector2f((float)thisX, (float)thisY + colorForAdding));
				colorForAdding = 1;
			}
		}
	}
	if (!checked)
	{
		allMoves.push_back(sf::Vector2f((float)thisX, (float)thisY + colorForAdding));
	}
}

void Pawn::takePiece(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray, std::vector<sf::Vector2f>& allMoves)
{
	int thisX = 0;
	int thisY = 0;
	int colorForAdding = 0;
	if (m_Color == WHITE)
	{
		thisX = (int)whitePositions[indexInArray].x;
		thisY = (int)whitePositions[indexInArray].y;
		colorForAdding = -1;
	}
	else
	{
		thisX = (int)blackPositions[indexInArray].x;
		thisY = (int)blackPositions[indexInArray].y;
		colorForAdding = 1;
	}
	for (int i = 0; i < 16; i++)
	{
		if (m_Color == WHITE)
		{
			if (blackPositions[i].x == thisX + 1 && blackPositions[i].y == thisY + colorForAdding)
			{
				allMoves.push_back(sf::Vector2f((float)thisX + 1, (float)thisY + colorForAdding));
			}
			else if (blackPositions[i].x == thisX - 1 && blackPositions[i].y == thisY + colorForAdding)
			{
				allMoves.push_back(sf::Vector2f((float)thisX - 1, (float)thisY + colorForAdding));
			}
		}
		else
		{
			if (whitePositions[i].x == thisX + 1 && whitePositions[i].y == thisY + colorForAdding)
			{
				allMoves.push_back(sf::Vector2f((float)thisX + 1, (float)thisY + colorForAdding));
			}
			else if (whitePositions[i].x == thisX - 1 && whitePositions[i].y == thisY + colorForAdding)
			{
				allMoves.push_back(sf::Vector2f((float)thisX - 1, (float)thisY + colorForAdding));
			}
		}
	}
}