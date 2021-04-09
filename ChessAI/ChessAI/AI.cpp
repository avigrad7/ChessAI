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
	std::vector<sf::Vector2f> testing = game.genAllMoves(BLACK);
	BestMoveAndPiece test(testing[rand() / ((RAND_MAX + 1u) / testing.size())], rand() / ((RAND_MAX + 1u) / 16));
	return test;
}