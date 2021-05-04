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
	std::vector<Game::PieceAndMoves> allMoves = game.genAllMovesAndTheirPiece(BLACK, sizeOfWhitePawns, sizeOfBlackPawns, m_WhitePositions, m_BlackPositions, hasWhiteRooksMoved, hasBlackRooksMoved, hasWhiteKingMoved, hasBlackKingMoved);
	AI::BestMoveAndPiece bestMove(allMoves[0].moves[0], allMoves[0].piece);
	game.simulateMovingAPiece(BLACK, sizeOfWhitePawns, sizeOfBlackPawns, hasWhiteRooksMoved, hasBlackRooksMoved, hasWhiteKingMoved, hasBlackKingMoved, allMoves[0].piece, allMoves[0].moves[0], m_WhitePositions, m_BlackPositions);
	float bestValue = genPositionValue(m_WhitePositions, m_BlackPositions);
	std::vector<AI::BestMoveAndPiece> allPossibleBestMoves;
	resetValues();
	for (int i = 0; i < (int)allMoves.size(); i++)
	{
		for(int u = 0; u < (int)allMoves[i].moves.size(); u++)
		{
			game.simulateMovingAPiece(BLACK, sizeOfWhitePawns, sizeOfBlackPawns, hasWhiteRooksMoved, hasBlackRooksMoved, hasWhiteKingMoved, hasBlackKingMoved, allMoves[i].piece, allMoves[i].moves[u], m_WhitePositions, m_BlackPositions);
			if (bestValue > genPositionValue(m_WhitePositions, m_BlackPositions))
			{
				bestValue = genPositionValue(m_WhitePositions, m_BlackPositions);
				bestMove.bestMove = allMoves[i].moves[u];
				bestMove.whatPiece = allMoves[i].piece;
				allPossibleBestMoves.clear();
			}
			else if (bestValue == genPositionValue(m_WhitePositions, m_BlackPositions))
			{
				allPossibleBestMoves.push_back(AI::BestMoveAndPiece(allMoves[i].moves[u], allMoves[i].piece));
			}
			resetValues();
		}
	}
	if (allPossibleBestMoves.size() > 0)
	{
		int randomNum = rand() % allPossibleBestMoves.size();
		bestMove = allPossibleBestMoves[randomNum];
	}
	return bestMove;
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
				value += 3.1f;
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
			else
			{
				value -= 10;
			}
		}
	}
	return value;
}