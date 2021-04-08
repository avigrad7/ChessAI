#include"Piece.h"

void Piece::moveUpLeft(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
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
				i = 16;
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
				i = 16;
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

void Piece::moveUpRight(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
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
				i = 16;
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
				i = 16;
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

void Piece::moveDownLeft(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
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
				i = 16;
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
				i = 16;
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

void Piece::moveDownRight(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
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
				i = 16;
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
				i = 16;
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

void Piece::moveLeft(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
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

void Piece::moveRight(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
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

void Piece::moveUp(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
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

void Piece::moveDown(std::vector<sf::Vector2f>& allMoves, std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray)
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

void Piece::checkIfCouldMove(std::vector<sf::Vector2f>& whitePositions, std::vector<sf::Vector2f>& blackPositions, int indexInArray, std::vector<sf::Vector2f>& allMoves, int moveToX, int moveToY)
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