#pragma once
#include"Game.h"
#include<time.h>

class AI
{
public:
	struct BestMoveAndPiece
	{
		sf::Vector2f bestMove;
		int whatPiece;
		BestMoveAndPiece(sf::Vector2f setBestMove, int setPiece)
		{
			bestMove = setBestMove;
			whatPiece = setPiece;
		}
	};
public:
	AI();
public:
	void startGame();
private:
	BestMoveAndPiece genBestMove();
	
private:
	Game game;
};

