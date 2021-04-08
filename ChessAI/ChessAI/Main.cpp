#include"AI.h"

sf::Texture Piece::m_GraphicTexture;

int main()
{
	// put as main loop for the AI
	Game gameTest;
	gameTest.setAI();
	while (!gameTest.isGameEnd() && gameTest.getWindow().isOpen())
	{
		gameTest.startGame();
		gameTest.movePieceAndSetPosition(BLACK, 0, sf::Vector2f(4, 4));
	}
}