#include "AI.h"

AI::AI()
{
	srand((unsigned int)time(0));
	resetValues();
	game.setAI();
}

void AI::startGame()
{
	while (!game.isGameEnd() && game.getWindow().isOpen())
	{
		game.startGame();
		resetValues();
		if (!game.getIsWhitesTurn() && game.getWindow().isOpen())
		{
			BestMoveAndPiece bestMove = genBestMove();
			game.movePieceAndSetPosition(BLACK, bestMove.whatPiece, bestMove.bestMove);
		}
	}
}

AI::BestMoveAndPiece AI::genBestMove()
{
	int test = 0;

	std::vector<Game::PieceAndMoves> allMoves = game.genAllMovesAndTheirPiece(BLACK, sizeOfWhitePawns, sizeOfBlackPawns, m_WhitePositions, m_BlackPositions, hasWhiteRooksMoved, hasBlackRooksMoved, hasWhiteKingMoved, hasBlackKingMoved, enPisantIndex);
	std::vector<AI::BestMoveAndPiece> path;
	path.push_back(AI::BestMoveAndPiece(allMoves[0].moves[0], allMoves[0].piece));
	float bestValue = genLayerDeep(path, BLACK, 0, test);
	float value = 0.0f;
	std::vector<AI::BestMoveAndPiece> allPosibleMoves;
	allPosibleMoves.push_back(AI::BestMoveAndPiece(allMoves[0].moves[0], allMoves[0].piece));
	resetValues();
	for (int i = 0; i < (int)allMoves.size(); i++)
	{
		for (int u = 0; u < (int)allMoves[i].moves.size(); u++)
		{
			path.clear();
			path.push_back(AI::BestMoveAndPiece(allMoves[i].moves[u], allMoves[i].piece));
			value = genLayerDeep(path, BLACK, 0, test);
			if (value < bestValue)
			{
				bestValue = value;
				allPosibleMoves.clear();
				allPosibleMoves.push_back(AI::BestMoveAndPiece(allMoves[i].moves[u], allMoves[i].piece));
			}
			else if (value == bestValue)
			{
				allPosibleMoves.push_back(AI::BestMoveAndPiece(allMoves[i].moves[u], allMoves[i].piece));
			}
		}
	}
	/*for (int q = 0; q < (int)allPosibleMoves.size(); q++)
	{
		std::cout << q + 1 << ": move: " << allPosibleMoves[q].bestMove.x << ", " << allPosibleMoves[q].bestMove.y << " | best piece: " << allPosibleMoves[q].whatPiece << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;*/
	return allPosibleMoves[rand() % allPosibleMoves.size()];
}

void AI::resetValues()
{
	m_WhitePositions = game.getWhitePositions();
	m_BlackPositions = game.getBlackPositions();
	sizeOfWhitePawns = game.getSizeWhitePawns();
	sizeOfBlackPawns = game.getSizeBlackPawns();
	hasWhiteRooksMoved[0] = game.hasWhiteRooks0Moved();
	hasWhiteRooksMoved[1] = game.hasWhiteRooks1Moved();
	hasBlackRooksMoved[0] = game.hasBlackRooks0Moved();
	hasBlackRooksMoved[1] = game.hasBlackRooks1Moved();
	hasWhiteKingMoved = game.hasWhiteKingMoved();
	hasBlackKingMoved = game.hasBlackKingMoved();
	enPisantIndex = game.getEnPisantIndex();
}

void AI::moveDownPath(std::vector<AI::BestMoveAndPiece> path)
{
	for (int i = 0; i < (int)path.size(); i++)
	{
		if (i % 2 == 0)
		{
			game.simulateMovingAPiece(BLACK, sizeOfWhitePawns, sizeOfBlackPawns, hasWhiteRooksMoved, hasBlackRooksMoved, hasWhiteKingMoved, hasBlackKingMoved, path[i].whatPiece, path[i].bestMove, m_WhitePositions, m_BlackPositions, enPisantIndex);
		}
		else
		{
			game.simulateMovingAPiece(WHITE, sizeOfWhitePawns, sizeOfBlackPawns, hasWhiteRooksMoved, hasBlackRooksMoved, hasWhiteKingMoved, hasBlackKingMoved, path[i].whatPiece, path[i].bestMove, m_WhitePositions, m_BlackPositions, enPisantIndex);
		}
	}
}

float AI::genPositionValue(std::vector<sf::Vector2f> whitePos, std::vector<sf::Vector2f> blackPos)
{
	float value = 0;
	for (int i = 0; i < 16; i++)
	{
		if (!(whitePos[i].x < 1 || whitePos[i].x > 8))
		{
			if (i == 0 || i == 1)
			{
				value += 5;
			}
			else if (i == 2 || i == 3)
			{
				value += 3;
			}
			else if (i == 4 || i == 5)
			{
				value += 3.1f;
			}
			else if (i > 5 && i < 6 + sizeOfWhitePawns)
			{
				value++;
			}
			else if (i != 15)
			{
				value += 10;
			}
			else
			{
				value += 1000;
				if (game.isCheckMate(BLACK, sizeOfWhitePawns, sizeOfBlackPawns, whitePos, blackPos))
				{
					value += 1000;
				}
				else if (game.isStaleMate(BLACK, sizeOfWhitePawns, sizeOfBlackPawns, whitePos, blackPos))
				{
					value = 0;
				}
			}
		}
		if (!(blackPos[i].x < 1 || blackPos[i].x > 8))
		{
			if (i == 0 || i == 1)
			{
				value -= 5;
			}
			else if (i == 2 || i == 3)
			{
				value -= 3;
			}
			else if (i == 4 || i == 5)
			{
				value -= 3.1f;
			}
			else if (i > 5 && i < 6 + sizeOfBlackPawns)
			{
				value--;
			}
			else if (i != 15)
			{
				value -= 10;
			}
			else
			{
				value -= 1000;
				if (game.isCheckMate(WHITE, sizeOfWhitePawns, sizeOfBlackPawns, whitePos, blackPos))
				{
					value -= 1000;
				}
				else if (game.isStaleMate(WHITE, sizeOfWhitePawns, sizeOfBlackPawns, whitePos, blackPos))
				{
					value = 0;
				}
			}
		}
	}
	return value;
}

float AI::genLayerDeep(std::vector<AI::BestMoveAndPiece>& path, Color color, int count, int& test)
{
	moveDownPath(path);
	std::vector<Game::PieceAndMoves> allMoves;
	if (color == WHITE)
	{
		allMoves = game.genAllMovesAndTheirPiece(BLACK, sizeOfWhitePawns, sizeOfBlackPawns, m_WhitePositions, m_BlackPositions, hasWhiteRooksMoved, hasBlackRooksMoved, hasWhiteKingMoved, hasBlackKingMoved, enPisantIndex);
	}
	else
	{
		allMoves = game.genAllMovesAndTheirPiece(WHITE, sizeOfWhitePawns, sizeOfBlackPawns, m_WhitePositions, m_BlackPositions, hasWhiteRooksMoved, hasBlackRooksMoved, hasWhiteKingMoved, hasBlackKingMoved, enPisantIndex);
	}
	float value = 0.0f;
	float bestValue = -999.1f;
	if (count == 2)
	{
		game.simulateMovingAPiece(color, sizeOfWhitePawns, sizeOfBlackPawns, hasBlackRooksMoved, hasBlackRooksMoved, hasWhiteKingMoved, hasBlackKingMoved, allMoves[0].piece, allMoves[0].moves[0], m_WhitePositions, m_BlackPositions, enPisantIndex);
		bestValue = genPositionValue(m_WhitePositions, m_BlackPositions);
	}
	for (int i = 0; i < (int)allMoves.size(); i++)
	{
		for (int u = 0; u < (int)allMoves[i].moves.size(); u++)
		{
			path.push_back(AI::BestMoveAndPiece(allMoves[i].moves[u], allMoves[i].piece));
			resetValues();
			moveDownPath(path);
			game.simulateMovingAPiece(color, sizeOfWhitePawns, sizeOfBlackPawns, hasBlackRooksMoved, hasBlackRooksMoved, hasWhiteKingMoved, hasBlackKingMoved, allMoves[i].piece, allMoves[i].moves[u], m_WhitePositions, m_BlackPositions, enPisantIndex);
			if (count < 2)
			{
				if (color == WHITE)
				{
					value = genLayerDeep(path, BLACK, (count + 1), test);
					if (bestValue == -999.1f || value > bestValue)
					{
						bestValue = value;
					}
				}
				else
				{
					value = genLayerDeep(path, WHITE, (count + 1), test);
					if (bestValue == -999.1f || value < bestValue)
					{
						bestValue = value;
					}
				}
				
				path.pop_back();
			}
			else
			{
				value = genPositionValue(m_WhitePositions, m_BlackPositions);
				if (color == WHITE && value > bestValue || color == BLACK && value < bestValue)
				{
					bestValue = value;
				}
			}
		}
	}
	return bestValue;
	/*moveDownPath(path);
	std::vector<Game::PieceAndMoves> allMoves = game.genAllMovesAndTheirPiece(color, sizeOfWhitePawns, sizeOfBlackPawns, m_WhitePositions, m_BlackPositions, hasWhiteRooksMoved, hasBlackRooksMoved, hasWhiteKingMoved, hasBlackKingMoved, enPisantIndex);
	float bestValue = genPositionValue(m_WhitePositions, m_BlackPositions);
	float value = 0.0f;
	if ((int)allMoves.size() != 0)
	{
		game.simulateMovingAPiece(color, sizeOfWhitePawns, sizeOfBlackPawns, hasWhiteRooksMoved, hasBlackRooksMoved, hasWhiteKingMoved, hasBlackKingMoved, allMoves[0].piece, allMoves[0].moves[0], m_WhitePositions, m_BlackPositions, enPisantIndex);
		bestValue = genPositionValue(m_WhitePositions, m_BlackPositions);
		resetValues();
		moveDownPath(path);
		for (int i = 0; i < (int)allMoves.size(); i++)
		{
			for (int u = 0; u < (int)allMoves[i].moves.size(); u++)
			{
				game.simulateMovingAPiece(color, sizeOfWhitePawns, sizeOfBlackPawns, hasWhiteRooksMoved, hasBlackRooksMoved, hasWhiteKingMoved, hasBlackKingMoved, allMoves[i].piece, allMoves[i].moves[u], m_WhitePositions, m_BlackPositions, enPisantIndex);
				value = genPositionValue(m_WhitePositions, m_BlackPositions);
				if (value > bestValue)
				{
					bestValue = value;
				}
				resetValues();
				moveDownPath(path);
			}
		}
	}
	return bestValue;*/
}