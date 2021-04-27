#include "AI.h"

AI::AI()
{
	srand((unsigned int)time(0));
	sizeOfWhitePawns = 8;
	sizeOfBlackPawns = 8;
	m_WhitePositions = game.getWhitePositions();
	m_BlackPositions = game.getBlackPositions();
	for (int i = 0; i < 2; i++)
	{
		hasWhiteRooksMoved[i] = false;
		hasBlackRooksMoved[i] = false;
	}
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
			if (bestMove.whatPiece == 15)
			{
				if (game.isValidCastle(CastlingOptions::bigBlack, m_WhitePositions, m_BlackPositions) && bestMove.bestMove.x == 3)
				{
					game.castle(CastlingOptions::bigBlack);
				}
				else if (game.isValidCastle(CastlingOptions::smallBlack, m_WhitePositions, m_BlackPositions) && bestMove.bestMove.x == 7)
				{
					game.castle(CastlingOptions::smallBlack);
				}
			}
			game.movePieceAndSetPosition(BLACK, bestMove.whatPiece, bestMove.bestMove);
		}
	}
}

AI::BestMoveAndPiece AI::genBestMove()
{
	std::vector<Game::PieceAndMoves> allMoves = game.genAllMovesAndTheirPiece(BLACK, sizeOfBlackPawns, m_WhitePositions, m_BlackPositions);
	int randomNum = rand() / ((RAND_MAX + 1u) / allMoves.size());
	BestMoveAndPiece bestMove(allMoves[randomNum].moves[rand() / ((RAND_MAX + 1u) / allMoves[randomNum].moves.size())], allMoves[randomNum].piece);
	return bestMove;
}

void AI::resetValues()
{
	m_WhitePositions = game.getWhitePositions();
	m_BlackPositions = game.getBlackPositions();
	sizeOfWhitePawns = game.getSizeWhitePawns();
	sizeOfBlackPawns = game.getSizeBlackPawns();
}

float AI::genPositionValue(std::vector<sf::Vector2f> whitePos, std::vector<sf::Vector2f> blackPos)
{
	float value = 0;
	for (int i = 0; i < 15; i++)
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
				value += 3.1;
			}
			else if (i > 5 && i < 6 + sizeOfWhitePawns)
			{
				value++;
			}
			else
			{
				value += 10;
			}
		}
		else if (!(blackPos[i].x < 1 || blackPos[i].x > 8))
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
				value -= 3.1;
			}
			else if (i > 5 && i < 6 + sizeOfBlackPawns)
			{
				value--;
			}
			else
			{
				value -= 10;
			}
		}
	}
	return value;
}