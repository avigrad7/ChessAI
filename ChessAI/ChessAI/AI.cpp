#include "AI.h"

AI::AI()
{
	srand((unsigned int)time(0));
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
				if (m_BlackPositions[15].x == 5 && bestMove.bestMove.x == 3)
				{
					game.castle(CastlingOptions::bigBlack, m_WhitePositions, m_BlackPositions);
				}
				else if (m_BlackPositions[15].x == 5 && bestMove.bestMove.x == 7)
				{
					game.castle(CastlingOptions::smallBlack, m_WhitePositions, m_BlackPositions);
				}
			}
			else if (bestMove.whatPiece >= 6 && bestMove.whatPiece <= 6 + game.getPawnSize(BLACK))
			{
				std::vector<sf::Vector2f> allMoves = game.genPieceMoves(bestMove.whatPiece - 6, TypeOfPiece::BlackPawn, m_WhitePositions, m_BlackPositions);
				if (m_BlackPositions[bestMove.whatPiece].y == 7 && bestMove.bestMove.y == 5)
				{
					game.setEnPisantIndex(bestMove.whatPiece);
				}
				else if (game.getEnPisantIndex() != -1 && (m_BlackPositions[bestMove.whatPiece].x == m_WhitePositions[game.getEnPisantIndex()].x + 1 || m_BlackPositions[bestMove.whatPiece].x == m_WhitePositions[game.getEnPisantIndex()].x - 1) && m_BlackPositions[bestMove.whatPiece].y == m_WhitePositions[game.getEnPisantIndex()].y && bestMove.bestMove.x == allMoves[allMoves.size() - 1].x && bestMove.bestMove.y == allMoves[allMoves.size() - 1].y)
				{
					game.deletePiece(TypeOfPiece::WhitePawn, game.getEnPisantIndex());
				}
			}
			game.movePieceAndSetPosition(BLACK, bestMove.whatPiece, bestMove.bestMove);
		}
	}
}

AI::BestMoveAndPiece AI::genBestMove()
{
	std::vector<Game::PieceAndMoves> allMoves = game.genAllMovesAndTheirPiece(BLACK, m_WhitePositions, m_BlackPositions);
	int randomNum = rand() / ((RAND_MAX + 1u) / allMoves.size());
	BestMoveAndPiece bestMove(allMoves[randomNum].moves[rand() / ((RAND_MAX + 1u) / allMoves[randomNum].moves.size())], allMoves[randomNum].piece);
	return bestMove;
}