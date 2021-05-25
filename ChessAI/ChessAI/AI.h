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
	void resetValues();
	float genPositionValue(std::vector<sf::Vector2f> whitePos, std::vector<sf::Vector2f> blackPos);
	float genLayerDeep(std::vector<AI::BestMoveAndPiece> path, Color color);
	void moveDownPath(std::vector<AI::BestMoveAndPiece> path);
private:
	Game game;
	std::vector<sf::Vector2f> m_WhitePositions;
	std::vector<sf::Vector2f> m_BlackPositions;
	int sizeOfWhitePawns;
	int sizeOfBlackPawns;
	bool hasWhiteRooksMoved[2];
	bool hasBlackRooksMoved[2];
	bool hasWhiteKingMoved;
	bool hasBlackKingMoved;
	int enPisantIndex;
};

