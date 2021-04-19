#include "AI.h"

AI::AI()
{
	srand((unsigned int)time(0));
	sizeOfWhitePawns = 8;
	sizeOfBlackPawns = 8;
	m_WhitePositions = game.getWhitePositions();
	m_BlackPositions = game.getBlackPositions();
	game.setAI();
}

void AI::startGame()
{
	while (!game.isGameEnd() && game.getWindow().isOpen())
	{
		game.startGame();
		if (!game.getIsWhitesTurn() && game.getWindow().isOpen())
		{
			BestMoveAndPiece bestMove = genBestMove();
			if (bestMove.whatPiece == 15)
			{
				if (game.isValidCastle(CastlingOptions::bigBlack) && bestMove.bestMove.x == 3)
				{
					game.castle(CastlingOptions::bigBlack, m_WhitePositions, m_BlackPositions);
				}
				else if (game.isValidCastle(CastlingOptions::smallBlack) && bestMove.bestMove.x == 7)
				{
					game.castle(CastlingOptions::smallBlack, m_WhitePositions, m_BlackPositions);
				}
			}
			else if (bestMove.whatPiece >= 6 && bestMove.whatPiece <= 6 + sizeOfBlackPawns)
			{
				if (bestMove.bestMove.y == 8)
				{
					game.promote(BLACK, sizeOfBlackPawns, bestMove.bestMove, bestMove.whatPiece, m_WhitePositions, m_BlackPositions);
				}
				else
				{
					game.EnPisant(BLACK, bestMove.bestMove, m_WhitePositions, m_BlackPositions);
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