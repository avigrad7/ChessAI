#include "AI.h"

AI::AI()
{
	srand((unsigned int)time(NULL));
	game.setAI();
}

void AI::startGame()
{
	game.movePieceAndSetPosition(BLACK, 6, sf::Vector2f(1, 5));
	game.movePieceAndSetPosition(BLACK, 6, sf::Vector2f(1, 5));
	while (!game.isGameEnd() && game.getWindow().isOpen())
	{
		game.startGame();
		if (!game.getIsWhitesTurn() && game.getWindow().isOpen())
		{
			BestMoveAndPiece bestMove = genBestMove();
			if (bestMove.whatPiece == 15)
			{
				if (game.getBlackPositions()[15].x == 5 && bestMove.bestMove.x == 3)
				{
					game.movePieceAndSetPosition(BLACK, 0, sf::Vector2f(4, 1));
				}
				else if (game.getBlackPositions()[15].x == 5 && bestMove.bestMove.x == 7)
				{
					game.movePieceAndSetPosition(BLACK, 1, sf::Vector2f(6, 1));
				}
			}
			else if (bestMove.whatPiece >= 6 && bestMove.whatPiece <= 6 + game.getPawnSize(BLACK))
			{
				std::vector<sf::Vector2f> allMoves = game.genPieceMoves(bestMove.whatPiece - 6, TypeOfPiece::BlackPawn);
				if (game.getBlackPositions()[bestMove.whatPiece].y == 7 && bestMove.bestMove.y == 5)
				{
					game.setEnPisantIndex(bestMove.whatPiece);
				}
				else if (game.getEnPisantIndex() != -1 && (game.getBlackPositions()[bestMove.whatPiece].x == game.getWhitePositions()[game.getEnPisantIndex()].x + 1 || game.getBlackPositions()[bestMove.whatPiece].x == game.getWhitePositions()[game.getEnPisantIndex()].x - 1) && game.getBlackPositions()[bestMove.whatPiece].y == game.getWhitePositions()[game.getEnPisantIndex()].y && bestMove.bestMove.x == allMoves[allMoves.size() - 1].x && bestMove.bestMove.y == allMoves[allMoves.size() - 1].y)
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
	std::vector<Game::PieceAndMoves> allMoves = game.genAllMovesAndTheirPiece(BLACK);
	int randomNum = rand() / ((RAND_MAX + 1u) / allMoves.size());
	BestMoveAndPiece bestMove(allMoves[randomNum].moves[rand() / ((RAND_MAX + 1u) / allMoves[randomNum].moves.size())], allMoves[randomNum].piece);
	return bestMove;
}