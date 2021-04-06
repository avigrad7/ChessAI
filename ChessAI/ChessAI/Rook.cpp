#include "Rook.h"

Rook::Rook(Color whatColor, sf::RenderWindow& window)
{
	m_Color = whatColor;
	m_Graphic.setSize(sf::Vector2f((float)window.getSize().x / 8, (float)window.getSize().y / 8));
	m_Graphic.setTexture(&m_GraphicTexture);
	auto textureSize = m_GraphicTexture.getSize();
	textureSize.x /= 6;
	textureSize.y /= 2;

	if (m_Color == Color::Black)
	{
		m_Graphic.setTextureRect(sf::IntRect(textureSize.x * 4, textureSize.y, textureSize.x, textureSize.y));
	}
	else
	{
		m_Graphic.setTextureRect(sf::IntRect(textureSize.x * 4, textureSize.y * 0, textureSize.x, textureSize.y));
	}
}
std::vector<sf::Vector2f> Rook::possibleMoves(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
{
	std::vector<sf::Vector2f> allMoves;
	moveLeft(allMoves, whitePositions, blackPositions, indexInArray);
	moveRight(allMoves, whitePositions, blackPositions, indexInArray);
	moveUp(allMoves, whitePositions, blackPositions, indexInArray);
	moveDown(allMoves, whitePositions, blackPositions, indexInArray);
	return allMoves;
}

void Rook::moveLeft(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
{
	int thisX = 0;
	int thisY = 0;
	int checkPosition = 0;
	bool hasBeenChecked = false;
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
	checkPosition = thisX;
	while (checkPosition > 0)
	{
		checkPosition--;
		for (int i = 0; i < 16; i++)
		{
			if (whitePositions[i].y == thisY && whitePositions[i].x == checkPosition && whitePositions[i].x != thisX)
			{
				hasBeenChecked = true;
				if (m_Color == WHITE)
				{
					if (checkPosition + 1 != thisX)
					{
						while (checkPosition < thisX - 1)
						{
							allMoves.push_back(sf::Vector2f((float)checkPosition + 1, (float)thisY));
							checkPosition++;
						}
					}
				}
				else
				{
					while (checkPosition < thisX)
					{
						allMoves.push_back(sf::Vector2f((float)checkPosition, (float)thisY));
						checkPosition++;
					}
				}
				checkPosition = 0;
				i = 16;
			}
			else if (blackPositions[i].y == thisY && blackPositions[i].x == checkPosition && blackPositions[i].x != thisX)
			{
				hasBeenChecked = true;
				if (m_Color == BLACK)
				{
					if (checkPosition + 1 != thisX)
					{
						while (checkPosition < thisX - 1)
						{
							allMoves.push_back(sf::Vector2f((float)checkPosition + 1, (float)thisY));
							checkPosition++;
						}
					}
				}
				else
				{
					while (checkPosition < thisX)
					{
						allMoves.push_back(sf::Vector2f((float)checkPosition, (float)thisY));
						checkPosition++;
					}
				}
				checkPosition = 0;
				i = 16;
			}
		}
	}
	if (!hasBeenChecked)
	{
		checkPosition = thisX - 1;
		while (checkPosition > 0)
		{
			allMoves.push_back(sf::Vector2f((float)checkPosition, (float)thisY));
			checkPosition--;
		}
	}
}

void Rook::moveRight(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
{
	int thisX = 0;
	int thisY = 0;
	int checkPosition = 0;
	bool hasBeenChecked = false;
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
	checkPosition = thisX;
	while (checkPosition < 9)
	{
		checkPosition++;
		for (int i = 0; i < 16; i++)
		{
			if (whitePositions[i].y == thisY && whitePositions[i].x == checkPosition && whitePositions[i].x != thisX)
			{
				hasBeenChecked = true;
				if (m_Color == WHITE)
				{
					if (checkPosition - 1 != thisX)
					{
						while (checkPosition > thisX + 1)
						{
							allMoves.push_back(sf::Vector2f((float)checkPosition - 1, (float)thisY));
							checkPosition--;
						}
					}
				}
				else
				{
					while (checkPosition > thisX)
					{
						allMoves.push_back(sf::Vector2f((float)checkPosition, (float)thisY));
						checkPosition--;
					}
				}
				checkPosition = 9;
				i = 16;
			}
			else if (blackPositions[i].y == thisY && blackPositions[i].x == checkPosition && blackPositions[i].x != thisX)
			{
				hasBeenChecked = true;
				if (m_Color == BLACK)
				{
					if (checkPosition - 1 != thisX)
					{
						while (checkPosition > thisX + 1)
						{
							allMoves.push_back(sf::Vector2f((float)checkPosition - 1, (float)thisY));
							checkPosition--;
						}
					}
				}
				else
				{
					while (checkPosition > thisX)
					{
						allMoves.push_back(sf::Vector2f((float)checkPosition, (float)thisY));
						checkPosition--;
					}
				}
				checkPosition = 9;
				i = 16;
			}
		}
	}
	if (!hasBeenChecked)
	{
		checkPosition = thisX + 1;
		while (checkPosition < 9)
		{
			allMoves.push_back(sf::Vector2f((float)checkPosition, (float)thisY));
			checkPosition++;
		}
	}
}

void Rook::moveUp(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
{
	int thisX = 0;
	int thisY = 0;
	int checkPosition = 0;
	bool hasBeenChecked = false;
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
	checkPosition = thisY;
	while (checkPosition > 0)
	{
		checkPosition--;
		for (int i = 0; i < 16; i++)
		{
			if (whitePositions[i].x == thisX && whitePositions[i].y == checkPosition && whitePositions[i].y != thisY)
			{
				hasBeenChecked = true;
				if (m_Color == WHITE)
				{
					if (checkPosition + 1 != thisY)
					{
						while (checkPosition < thisY - 1)
						{
							allMoves.push_back(sf::Vector2f((float)thisX, (float)checkPosition + 1));
							checkPosition++;
						}
					}
				}
				else
				{
					while (checkPosition < thisY)
					{
						allMoves.push_back(sf::Vector2f((float)thisX, (float)checkPosition));
						checkPosition++;
					}
				}
				checkPosition = 0;
				i = 16;
			}
			else if (blackPositions[i].x == thisX && blackPositions[i].y == checkPosition && blackPositions[i].y != thisY)
			{
				hasBeenChecked = true;
				if (m_Color == BLACK)
				{
					if (checkPosition + 1 != thisY)
					{
						while (checkPosition < thisY - 1)
						{
							allMoves.push_back(sf::Vector2f((float)thisX, (float)checkPosition + 1));
							checkPosition++;
						}
					}
				}
				else
				{
					while (checkPosition < thisY)
					{
						allMoves.push_back(sf::Vector2f((float)thisX, (float)checkPosition));
						checkPosition++;
					}
				}
				checkPosition = 0;
				i = 16;
			}
		}
	}
	if (!hasBeenChecked)
	{
		checkPosition = thisY - 1;
		while (checkPosition > 0)
		{
			allMoves.push_back(sf::Vector2f((float)thisX, (float)checkPosition));
			checkPosition--;
		}
	}
}

void Rook::moveDown(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
{
	int thisX = 0;
	int thisY = 0;
	int checkPosition = 0;
	bool hasBeenChecked = false;
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
	checkPosition = thisY;
	while (checkPosition < 9)
	{
		checkPosition++;
		for (int i = 0; i < 16; i++)
		{
			if (whitePositions[i].x == thisX && whitePositions[i].y == checkPosition && whitePositions[i].y != thisY)
			{
				hasBeenChecked = true;
				if (m_Color == WHITE)
				{
					if (checkPosition - 1 != thisY)
					{
						while (checkPosition > thisY + 1)
						{
							allMoves.push_back(sf::Vector2f((float)thisX, (float)checkPosition - 1));
							checkPosition--;
						}
					}
				}
				else
				{
					while (checkPosition > thisY)
					{
						allMoves.push_back(sf::Vector2f((float)thisX, (float)checkPosition));
						checkPosition--;
					}
				}
				checkPosition = 9;
				i = 16;
			}
			else if (blackPositions[i].x == thisX && blackPositions[i].y == checkPosition && blackPositions[i].y != thisY)
			{
				hasBeenChecked = true;
				if (m_Color == BLACK)
				{
					if (checkPosition - 1 != thisY)
					{
						while (checkPosition > thisY + 1)
						{
							allMoves.push_back(sf::Vector2f((float)thisX, (float)checkPosition - 1));
							checkPosition--;
						}
					}
				}
				else
				{
					while (checkPosition > thisY)
					{
						allMoves.push_back(sf::Vector2f((float)thisX, (float)checkPosition));
						checkPosition--;
					}
				}
				checkPosition = 9;
				i = 16;
			}
		}
	}
	if (!hasBeenChecked)
	{
		checkPosition = thisY + 1;
		while (checkPosition < 9)
		{
			allMoves.push_back(sf::Vector2f((float)thisX, (float)checkPosition));
			checkPosition++;
		}
	}
}