#include "Bishop.h"
Bishop::Bishop(Color whatColor, sf::RenderWindow& window)
{
	m_Color = whatColor;
	m_Graphic.setSize(sf::Vector2f((float)window.getSize().x / 8, (float)window.getSize().y / 8));
	m_Graphic.setTexture(&m_GraphicTexture);
	auto textureSize = m_GraphicTexture.getSize();
	textureSize.x /= 6;
	textureSize.y /= 2;

	if (m_Color == Color::Black)
	{
		m_Graphic.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y, textureSize.x, textureSize.y));
	}
	else
	{
		m_Graphic.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 0, textureSize.x, textureSize.y));
	}
}

std::vector<sf::Vector2f> Bishop::possibleMoves(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
{
	std::vector<sf::Vector2f> allMoves;
	moveUpLeft(allMoves, whitePositions, blackPositions, indexInArray);
	moveUpRight(allMoves, whitePositions, blackPositions, indexInArray);
	moveDownLeft(allMoves, whitePositions, blackPositions, indexInArray);
	moveDownRight(allMoves, whitePositions, blackPositions, indexInArray);
	return allMoves;
}

void Bishop::moveUpLeft(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
{
	int thisX = 0;
	int thisY = 0;
	int checkPositionX = 0;
	int checkPositionY = 0;
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
	checkPositionX = thisX;
	checkPositionY = thisY;
	while (checkPositionX > 0 && checkPositionY > 0)
	{
		checkPositionX--;
		checkPositionY--;
		for (int i = 0; i < 16; i++)
		{
			if (whitePositions[i].x == checkPositionX && whitePositions[i].y == checkPositionY)
			{
				hasBeenChecked = true;
				if (m_Color == WHITE)
				{
					if (checkPositionX + 1 != thisX)
					{
						while (checkPositionX < thisX - 1)
						{
							allMoves.push_back(sf::Vector2f((float)checkPositionX + 1, (float)checkPositionY + 1));
							checkPositionX++;
							checkPositionY++;
						}
					}
				}
				else
				{
					while (checkPositionX < thisX)
					{
						allMoves.push_back(sf::Vector2f((float)checkPositionX, (float)checkPositionY));
						checkPositionX++;
						checkPositionY++;
					}
				}
				checkPositionX = 0;
				checkPositionY = 0;
			}
			else if (blackPositions[i].x == checkPositionX && blackPositions[i].y == checkPositionY)
			{
				hasBeenChecked = true;
				if (m_Color == BLACK)
				{
					while (checkPositionX < thisX - 1)
					{
						allMoves.push_back(sf::Vector2f((float)checkPositionX + 1, (float)checkPositionY + 1));
						checkPositionX++;
						checkPositionY++;
					}
				}
				else
				{
					while (checkPositionX < thisX)
					{
						allMoves.push_back(sf::Vector2f((float)checkPositionX, (float)checkPositionY));
						checkPositionX++;
						checkPositionY++;
					}
				}
				checkPositionX = 0;
				checkPositionY = 0;
			}
		}
	}
	if (!hasBeenChecked)
	{
		checkPositionX = thisX - 1;
		checkPositionY = thisY - 1;
		while (checkPositionX > 0 && checkPositionY > 0)
		{
			allMoves.push_back(sf::Vector2f((float)checkPositionX, (float)checkPositionY));
			checkPositionX--;
			checkPositionY--;
		}
	}
}

void Bishop::moveUpRight(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
{
	int thisX = 0;
	int thisY = 0;
	int checkPositionX = 0;
	int checkPositionY = 0;
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
	checkPositionX = thisX;
	checkPositionY = thisY;
	while (checkPositionX < 9 && checkPositionY > 0)
	{
		checkPositionX++;
		checkPositionY--;
		for (int i = 0; i < 16; i++)
		{
			if (whitePositions[i].x == checkPositionX && whitePositions[i].y == checkPositionY)
			{
				hasBeenChecked = true;
				if (m_Color == WHITE)
				{
					if (checkPositionX - 1 != thisX)
					{
						while (checkPositionX > thisX + 1)
						{
							allMoves.push_back(sf::Vector2f((float)checkPositionX - 1, (float)checkPositionY + 1));
							checkPositionX--;
							checkPositionY++;
						}
					}
				}
				else
				{
					while (checkPositionX > thisX)
					{
						allMoves.push_back(sf::Vector2f((float)checkPositionX, (float)checkPositionY));
						checkPositionX--;
						checkPositionY++;
					}
				}
				checkPositionX = 9;
				checkPositionY = 0;
			}
			else if (blackPositions[i].x == checkPositionX && blackPositions[i].y == checkPositionY)
			{
				hasBeenChecked = true;
				if (m_Color == BLACK)
				{
					while (checkPositionX > thisX + 1)
					{
						allMoves.push_back(sf::Vector2f((float)checkPositionX - 1, (float)checkPositionY + 1));
						checkPositionX--;
						checkPositionY++;
					}
				}
				else
				{
					while (checkPositionX > thisX)
					{
						allMoves.push_back(sf::Vector2f((float)checkPositionX, (float)checkPositionY));
						checkPositionX--;
						checkPositionY++;
					}
				}
				checkPositionX = 9;
				checkPositionY = 0;
			}
		}
	}
	if (!hasBeenChecked)
	{
		checkPositionX = thisX + 1;
		checkPositionY = thisY - 1;
		while (checkPositionX < 9 && checkPositionY > 0)
		{
			allMoves.push_back(sf::Vector2f((float)checkPositionX, (float)checkPositionY));
			checkPositionX++;
			checkPositionY--;
		}
	}
}

void Bishop::moveDownLeft(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
{
	int thisX = 0;
	int thisY = 0;
	int checkPositionX = 0;
	int checkPositionY = 0;
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
	checkPositionX = thisX;
	checkPositionY = thisY;
	while (checkPositionX > 0 && checkPositionY < 9)
	{
		checkPositionX--;
		checkPositionY++;
		for (int i = 0; i < 16; i++)
		{
			if (whitePositions[i].x == checkPositionX && whitePositions[i].y == checkPositionY)
			{
				hasBeenChecked = true;
				if (m_Color == WHITE)
				{
					if (checkPositionX + 1 != thisX)
					{
						while (checkPositionX < thisX - 1)
						{
							allMoves.push_back(sf::Vector2f((float)checkPositionX + 1, (float)checkPositionY - 1));
							checkPositionX++;
							checkPositionY--;
						}
					}
				}
				else
				{
					while (checkPositionX < thisX)
					{
						allMoves.push_back(sf::Vector2f((float)checkPositionX, (float)checkPositionY));
						checkPositionX++;
						checkPositionY--;
					}
				}
				checkPositionX = 0;
				checkPositionY = 9;
			}
			else if (blackPositions[i].x == checkPositionX && blackPositions[i].y == checkPositionY)
			{
				hasBeenChecked = true;
				if (m_Color == BLACK)
				{
					while (checkPositionX < thisX - 1)
					{
						allMoves.push_back(sf::Vector2f((float)checkPositionX + 1, (float)checkPositionY - 1));
						checkPositionX++;
						checkPositionY--;
					}
				}
				else
				{
					while (checkPositionX < thisX)
					{
						allMoves.push_back(sf::Vector2f((float)checkPositionX, (float)checkPositionY));
						checkPositionX++;
						checkPositionY--;
					}
				}
				checkPositionX = 0;
				checkPositionY = 9;
			}
		}
	}
	if (!hasBeenChecked)
	{
		checkPositionX = thisX - 1;
		checkPositionY = thisY + 1;
		while (checkPositionX > 0 && checkPositionY < 9)
		{
			allMoves.push_back(sf::Vector2f((float)checkPositionX, (float)checkPositionY));
			checkPositionX--;
			checkPositionY++;
		}
	}
}

void Bishop::moveDownRight(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
{
	int thisX = 0;
	int thisY = 0;
	int checkPositionX = 0;
	int checkPositionY = 0;
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
	checkPositionX = thisX;
	checkPositionY = thisY;
	while (checkPositionX < 9 && checkPositionY < 9)
	{
		checkPositionX++;
		checkPositionY++;
		for (int i = 0; i < 16; i++)
		{
			if (whitePositions[i].x == checkPositionX && whitePositions[i].y == checkPositionY)
			{
				hasBeenChecked = true;
				if (m_Color == WHITE)
				{
					if (checkPositionX - 1 != thisX)
					{
						while (checkPositionX > thisX + 1)
						{
							allMoves.push_back(sf::Vector2f((float)checkPositionX - 1, (float)checkPositionY - 1));
							checkPositionX--;
							checkPositionY--;
						}
					}
				}
				else
				{
					while (checkPositionX > thisX)
					{
						allMoves.push_back(sf::Vector2f((float)checkPositionX, (float)checkPositionY));
						checkPositionX--;
						checkPositionY--;
					}
				}
				checkPositionX = 9;
				checkPositionY = 9;
			}
			else if (blackPositions[i].x == checkPositionX && blackPositions[i].y == checkPositionY)
			{
				hasBeenChecked = true;
				if (m_Color == BLACK)
				{
					while (checkPositionX > thisX + 1)
					{
						allMoves.push_back(sf::Vector2f((float)checkPositionX - 1, (float)checkPositionY - 1));
						checkPositionX--;
						checkPositionY--;
					}
				}
				else
				{
					while (checkPositionX > thisX)
					{
						allMoves.push_back(sf::Vector2f((float)checkPositionX, (float)checkPositionY));
						checkPositionX--;
						checkPositionY--;
					}
				}
				checkPositionX = 9;
				checkPositionY = 9;
			}
		}
	}
	if (!hasBeenChecked)
	{
		checkPositionX = thisX + 1;
		checkPositionY = thisY + 1;
		while (checkPositionX < 9 && checkPositionY < 9)
		{
			allMoves.push_back(sf::Vector2f((float)checkPositionX, (float)checkPositionY));
			checkPositionX++;
			checkPositionY++;
		}
	}
}