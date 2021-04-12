#include "AI.h"

AI::AI()
{
	srand(time(NULL));
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