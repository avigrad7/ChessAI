#include "Game.h"

Game::Game()
{
	m_Window->create(sf::VideoMode(984, 984), "Chess", sf::Style::Close);
	drawBoard();
	loadGraphics();
	setPieces();
}

Game::~Game()
{
	delete whiteKing;
	delete blackKing;
}

void Game::startGame()
{
	while (m_Window->isOpen() && !(isAI && !isWhiteTurn))
	{
		render();
	}
}
void Game::setPieces()
{
	whiteRooks.reserve(2);
	blackRooks.reserve(2);
	whiteKnights.reserve(2);
	blackKnights.reserve(2);
	whiteBishops.reserve(2);
	blackBishops.reserve(2);
	whitePawns.reserve(8);
	blackPawns.reserve(8);

	for (int i = 0; i < 2; i++)
	{
		whiteRooks.emplace_back(Rook(WHITE, *m_Window));
		blackRooks.emplace_back(Rook(BLACK, *m_Window));
		whiteKnights.emplace_back(Knight(WHITE, *m_Window));
		blackKnights.emplace_back(Knight(BLACK, *m_Window));
		whiteBishops.emplace_back(Bishop(WHITE, *m_Window));
		blackBishops.emplace_back(Bishop(BLACK, *m_Window));
	}

	for (int i = 0; i < 8; i++)
	{
		whitePawns.emplace_back(Pawn(WHITE, *m_Window));
		blackPawns.emplace_back(Pawn(BLACK, *m_Window));
	}

	whiteQueens.emplace_back(Queen(WHITE, *m_Window));
	blackQueens.emplace_back(Queen(BLACK, *m_Window));

	whiteKing = new King(WHITE, *m_Window);
	blackKing = new King(BLACK, *m_Window);

	for (int i = 0; i < 8; i++)
	{
		movePiece(whitePawns[i].getPiece(), sf::Vector2f((float)i + 1, 7));
		movePiece(blackPawns[i].getPiece(), sf::Vector2f((float)i + 1, 2));
	}
	movePiece(whiteRooks[0].getPiece(), sf::Vector2f(1, 8));
	movePiece(whiteRooks[1].getPiece(), sf::Vector2f(8, 8));
	movePiece(blackRooks[0].getPiece(), sf::Vector2f(1, 1));
	movePiece(blackRooks[1].getPiece(), sf::Vector2f(8, 1));
	movePiece(whiteKnights[0].getPiece(), sf::Vector2f(2, 8));
	movePiece(whiteKnights[1].getPiece(), sf::Vector2f(7, 8));
	movePiece(blackKnights[0].getPiece(), sf::Vector2f(2, 1));
	movePiece(blackKnights[1].getPiece(), sf::Vector2f(7, 1));
	movePiece(whiteBishops[0].getPiece(), sf::Vector2f(3, 8));
	movePiece(whiteBishops[1].getPiece(), sf::Vector2f(6, 8));
	movePiece(blackBishops[0].getPiece(), sf::Vector2f(3, 1));
	movePiece(blackBishops[1].getPiece(), sf::Vector2f(6, 1));
	movePiece(whiteQueens[0].getPiece(), sf::Vector2f(4, 8));
	movePiece(blackQueens[0].getPiece(), sf::Vector2f(4, 1));
	movePiece(whiteKing->getPiece(), sf::Vector2f(5, 8));
	movePiece(blackKing->getPiece(), sf::Vector2f(5, 1));

	for (int i = 0; i < 2; i++)
	{
		m_WhitePositions.emplace_back(sf::Vector2f((whiteRooks[i].getPiece().getPosition().x + m_SizeOfSquare) / m_SizeOfSquare, (whiteRooks[i].getPiece().getPosition().y + m_SizeOfSquare) / m_SizeOfSquare));
		m_BlackPositions.emplace_back(sf::Vector2f((blackRooks[i].getPiece().getPosition().x + m_SizeOfSquare) / m_SizeOfSquare, (blackRooks[i].getPiece().getPosition().y + m_SizeOfSquare) / m_SizeOfSquare));

	}
	for (int i = 0; i < 2; i++)
	{
		m_WhitePositions.emplace_back(sf::Vector2f((whiteKnights[i].getPiece().getPosition().x + m_SizeOfSquare) / m_SizeOfSquare, (whiteKnights[i].getPiece().getPosition().y + m_SizeOfSquare) / m_SizeOfSquare));
		m_BlackPositions.emplace_back(sf::Vector2f((blackKnights[i].getPiece().getPosition().x + m_SizeOfSquare) / m_SizeOfSquare, (blackKnights[i].getPiece().getPosition().y + m_SizeOfSquare) / m_SizeOfSquare));

	}
	for (int i = 0; i < 2; i++)
	{
		m_WhitePositions.emplace_back(sf::Vector2f((whiteBishops[i].getPiece().getPosition().x + m_SizeOfSquare) / m_SizeOfSquare, (whiteBishops[i].getPiece().getPosition().y + m_SizeOfSquare) / m_SizeOfSquare));
		m_BlackPositions.emplace_back(sf::Vector2f((blackBishops[i].getPiece().getPosition().x + m_SizeOfSquare) / m_SizeOfSquare, (blackBishops[i].getPiece().getPosition().y + m_SizeOfSquare) / m_SizeOfSquare));

	}
	for (int i = 0; i < 8; i++)
	{
		m_WhitePositions.emplace_back(sf::Vector2f((whitePawns[i].getPiece().getPosition().x + m_SizeOfSquare) / m_SizeOfSquare, (whitePawns[i].getPiece().getPosition().y + m_SizeOfSquare) / m_SizeOfSquare));
		m_BlackPositions.emplace_back(sf::Vector2f((blackPawns[i].getPiece().getPosition().x + m_SizeOfSquare) / m_SizeOfSquare, (blackPawns[i].getPiece().getPosition().y + m_SizeOfSquare) / m_SizeOfSquare));
	}
	m_WhitePositions.emplace_back(sf::Vector2f((whiteQueens[0].getPiece().getPosition().x + m_SizeOfSquare) / m_SizeOfSquare, (whiteQueens[0].getPiece().getPosition().y + m_SizeOfSquare) / m_SizeOfSquare));
	m_BlackPositions.emplace_back(sf::Vector2f((blackQueens[0].getPiece().getPosition().x + m_SizeOfSquare) / m_SizeOfSquare, (blackQueens[0].getPiece().getPosition().y + m_SizeOfSquare) / m_SizeOfSquare));
	m_WhitePositions.emplace_back(sf::Vector2f((whiteKing->getPiece().getPosition().x + m_SizeOfSquare) / m_SizeOfSquare, (whiteKing->getPiece().getPosition().y + m_SizeOfSquare) / m_SizeOfSquare));
	m_BlackPositions.emplace_back(sf::Vector2f((blackKing->getPiece().getPosition().x + m_SizeOfSquare) / m_SizeOfSquare, (blackKing->getPiece().getPosition().y + m_SizeOfSquare) / m_SizeOfSquare));
}

void Game::drawPieces()
{
	for (int i = 0; i < 2; i++)
	{
		m_Window->draw(whiteRooks[i].getPiece());
		m_Window->draw(blackRooks[i].getPiece());
		m_Window->draw(whiteKnights[i].getPiece());
		m_Window->draw(blackKnights[i].getPiece());
		m_Window->draw(whiteBishops[i].getPiece());
		m_Window->draw(blackBishops[i].getPiece());
	}
	for (int i = 0; i < (int)whitePawns.size(); i++)
	{
		m_Window->draw(whitePawns[i].getPiece());
	}
	for (int i = 0; i < (int)blackPawns.size(); i++)
	{
		m_Window->draw(blackPawns[i].getPiece());
	}
	for (int i = 0; i < (int)whiteQueens.size(); i++)
	{
		m_Window->draw(whiteQueens[i].getPiece());
	}
	for (int i = 0; i < (int)blackQueens.size(); i++)
	{
		m_Window->draw(blackQueens[i].getPiece());
	}
	m_Window->draw(whiteKing->getPiece());
	m_Window->draw(blackKing->getPiece());
}
void Game::drawPieces(const TypeOfPiece& whichPiece, const int& index)
{
	for (int i = 0; i < 2; i++)
	{
		if (whichPiece != TypeOfPiece::WhiteRook)
		{
			m_Window->draw(whiteRooks[i].getPiece());
		}
		else
		{
			if (index == 0)
			{
				m_Window->draw(whiteRooks[1].getPiece());
			}
			else
			{
				m_Window->draw(whiteRooks[0].getPiece());
			}
		}
		if (whichPiece != TypeOfPiece::BlackRook)
		{
			m_Window->draw(blackRooks[i].getPiece());
		}
		else
		{
			if (index == 0)
			{
				m_Window->draw(blackRooks[1].getPiece());
			}
			else
			{
				m_Window->draw(blackRooks[0].getPiece());
			}
		}
		if (whichPiece != TypeOfPiece::WhiteKnight)
		{
			m_Window->draw(whiteKnights[i].getPiece());
		}
		else
		{
			if (index == 0)
			{
				m_Window->draw(whiteKnights[1].getPiece());
			}
			else
			{
				m_Window->draw(whiteKnights[0].getPiece());
			}
		}
		if (whichPiece != TypeOfPiece::BlackKnight)
		{
			m_Window->draw(blackKnights[i].getPiece());
		}
		else
		{
			if (index == 0)
			{
				m_Window->draw(blackKnights[1].getPiece());
			}
			else
			{
				m_Window->draw(blackKnights[0].getPiece());
			}
		}
		if (whichPiece != TypeOfPiece::WhiteBishop)
		{
			m_Window->draw(whiteBishops[i].getPiece());
		}
		else
		{
			if (index == 0)
			{
				m_Window->draw(whiteBishops[1].getPiece());
			}
			else
			{
				m_Window->draw(whiteBishops[0].getPiece());
			}
		}
		if (whichPiece != TypeOfPiece::BlackBishop)
		{
			m_Window->draw(blackBishops[i].getPiece());
		}
		else
		{
			if (index == 0)
			{
				m_Window->draw(blackBishops[1].getPiece());
			}
			else
			{
				m_Window->draw(blackBishops[0].getPiece());
			}
		}
	}

	for (int i = 0; i < (int)whitePawns.size(); i++)
	{
		if (whichPiece != TypeOfPiece::WhitePawn)
		{
			m_Window->draw(whitePawns[i].getPiece());
		}
		else if (index != i)
		{
			m_Window->draw(whitePawns[i].getPiece());
		}
	}
	for (int i = 0; i < (int)blackPawns.size(); i++)
	{
		if (whichPiece != TypeOfPiece::BlackPawn)
		{
			m_Window->draw(blackPawns[i].getPiece());
		}
		else if (index != i)
		{
			m_Window->draw(blackPawns[i].getPiece());
		}
	}
	for (int i = 0; i < (int)whiteQueens.size(); i++)
	{
		if (whichPiece != TypeOfPiece::WhiteQueen)
		{
			m_Window->draw(whiteQueens[i].getPiece());
		}
		else if (index != i)
		{
			m_Window->draw(whiteQueens[i].getPiece());
		}
	}
	for (int i = 0; i < (int)blackQueens.size(); i++)
	{
		if (whichPiece != TypeOfPiece::BlackQueen)
		{
			m_Window->draw(blackQueens[i].getPiece());
		}
		else if (index != i)
		{
			m_Window->draw(blackQueens[i].getPiece());
		}
	}
	if (whichPiece != TypeOfPiece::WhiteKing)
	{
		m_Window->draw(whiteKing->getPiece());
	}
	if (whichPiece != TypeOfPiece::BlackKing)
	{
		m_Window->draw(blackKing->getPiece());
	}
}

void Game::movePiece(sf::RectangleShape& piece, const sf::Vector2f& moveTo)
{
	piece.setPosition((moveTo.x - 1) * m_SizeOfSquare, (moveTo.y - 1) * m_SizeOfSquare);
}

void Game::movePieceAndSetPosition(Color color, int index, const sf::Vector2f& moveTo)
{
	TypeOfPiece pieceType = getPieceType(index, color);
	switch (pieceType)
	{
	case TypeOfPiece::WhiteRook:
		whiteRooks[index].getPiece().setPosition((moveTo.x - 1) * m_SizeOfSquare, (moveTo.y - 1) * m_SizeOfSquare);
		m_WhitePositions[index] = moveTo;
		break;
	case TypeOfPiece::BlackRook:
		blackRooks[index].getPiece().setPosition((moveTo.x - 1) * m_SizeOfSquare, (moveTo.y - 1) * m_SizeOfSquare);
		m_BlackPositions[index] = moveTo;
		break;
	case TypeOfPiece::WhiteBishop:
		whiteBishops[index - 2].getPiece().setPosition((moveTo.x - 1) * m_SizeOfSquare, (moveTo.y - 1) * m_SizeOfSquare);
		m_WhitePositions[index - 2] = moveTo;
		break;
	case TypeOfPiece::BlackBishop:
		blackBishops[index - 2].getPiece().setPosition((moveTo.x - 1) * m_SizeOfSquare, (moveTo.y - 1) * m_SizeOfSquare);
		m_BlackPositions[index - 2] = moveTo;
		break;
	case TypeOfPiece::WhiteKnight:
		whiteKnights[index - 4].getPiece().setPosition((moveTo.x - 1) * m_SizeOfSquare, (moveTo.y - 1) * m_SizeOfSquare);
		m_WhitePositions[index - 4] = moveTo;
		break;
	case TypeOfPiece::BlackKnight:
		blackKnights[index - 4].getPiece().setPosition((moveTo.x - 1) * m_SizeOfSquare, (moveTo.y - 1) * m_SizeOfSquare);
		m_BlackPositions[index - 4] = moveTo;
		break;
	case TypeOfPiece::WhitePawn:
		whitePawns[index - 6].getPiece().setPosition((moveTo.x - 1) * m_SizeOfSquare, (moveTo.y - 1) * m_SizeOfSquare);
		m_WhitePositions[index - 6] = moveTo;
		break;
	case TypeOfPiece::BlackPawn:
		blackPawns[index - 6].getPiece().setPosition((moveTo.x - 1) * m_SizeOfSquare, (moveTo.y - 1) * m_SizeOfSquare);
		m_BlackPositions[index - 6] = moveTo;
		break;
	case TypeOfPiece::WhiteQueen:
		whiteQueens[index - (14 + (1 - whiteQueens.size()))].getPiece().setPosition((moveTo.x - 1) * m_SizeOfSquare, (moveTo.y - 1) * m_SizeOfSquare);
		m_WhitePositions[index - (14 + (1 - whiteQueens.size()))] = moveTo;
		break;
	case TypeOfPiece::BlackQueen:
		blackQueens[index - (14 + (1 - blackQueens.size()))].getPiece().setPosition((moveTo.x - 1) * m_SizeOfSquare, (moveTo.y - 1) * m_SizeOfSquare);
		m_BlackPositions[index - (14 + (1 - blackQueens.size()))] = moveTo;
		break;
	case TypeOfPiece::WhiteKing:
		whiteKing->getPiece().setPosition((moveTo.x - 1) * m_SizeOfSquare, (moveTo.y - 1) * m_SizeOfSquare);
		m_WhitePositions[15] = moveTo;
		break;
	case TypeOfPiece::BlackKing:
		blackKing->getPiece().setPosition((moveTo.x - 1) * m_SizeOfSquare, (moveTo.y - 1) * m_SizeOfSquare);
		m_BlackPositions[15] = moveTo;
		break;
	}
	if (isWhiteTurn)
	{
		isWhiteTurn = false;
	}
	else
	{
		isWhiteTurn = true;
	}
}

void Game::castle(const CastlingOptions& whatCastle)
{
	switch (whatCastle)
	{
	case CastlingOptions::bigWhite:
		movePiece(whiteRooks[0].getPiece(), sf::Vector2f(4, 8));
		whiteRooks[0].moved();
		movePiece(whiteKing->getPiece(), sf::Vector2f(3, 8));
		whiteKing->moved();
		m_WhitePositions[0] = sf::Vector2f(4, 8);
		m_WhitePositions[15] = sf::Vector2f(3, 8);
		break;
	case CastlingOptions::smallWhite:
		movePiece(whiteRooks[1].getPiece(), sf::Vector2f(6, 8));
		whiteRooks[1].moved();
		movePiece(whiteKing->getPiece(), sf::Vector2f(7, 8));
		whiteKing->moved();
		m_WhitePositions[1] = sf::Vector2f(6, 8);
		m_WhitePositions[15] = sf::Vector2f(7, 8);
		break;
	case CastlingOptions::bigBlack:
		movePiece(blackRooks[0].getPiece(), sf::Vector2f(4, 1));
		blackRooks[0].moved();
		movePiece(blackKing->getPiece(), sf::Vector2f(3, 1));
		blackKing->moved();
		m_BlackPositions[0] = sf::Vector2f(4, 1);
		m_BlackPositions[15] = sf::Vector2f(3, 1);
		break;
	case CastlingOptions::smallBlack:
		movePiece(blackRooks[1].getPiece(), sf::Vector2f(6, 1));
		blackRooks[1].moved();
		movePiece(blackKing->getPiece(), sf::Vector2f(7, 1));
		blackKing->moved();
		m_BlackPositions[1] = sf::Vector2f(6, 1);
		m_BlackPositions[15] = sf::Vector2f(7, 1);
		break;
	}
}

bool Game::isValidCastle(const CastlingOptions& whatCastle)
{

	for (int i = 0; i < 16; i++)
	{
		switch (whatCastle)
		{
		case CastlingOptions::bigWhite:
			if (isBeingChecked(WHITE))
			{
				return false;
			}
			if ((m_WhitePositions[i].y == 1 && (m_WhitePositions[i].x == 2 || m_WhitePositions[i].x == 3 || m_WhitePositions[i].x == 4)) || (m_BlackPositions[i].y == 1 && (m_BlackPositions[i].x == 2 || m_BlackPositions[i].x == 3 || m_BlackPositions[i].x == 4)) || whiteKing->hasBeenMoved() || whiteRooks[0].hasBeenMoved() || whiteRooks[0].isDeleted())
			{
				return false;
			}

			break;
		case CastlingOptions::smallWhite:
			if (isBeingChecked(WHITE))
			{
				return false;
			}
			if ((m_WhitePositions[i].y == 1 && (m_WhitePositions[i].x == 7 || m_WhitePositions[i].x == 6)) || (m_BlackPositions[i].y == 1 && (m_BlackPositions[i].x == 7 || m_BlackPositions[i].x == 6)) || whiteKing->hasBeenMoved() || whiteRooks[1].hasBeenMoved() || whiteRooks[1].isDeleted())
			{
				return false;
			}
			break;
		case CastlingOptions::bigBlack:
			if (isBeingChecked(BLACK))
			{
				return false;
			}
			if ((m_BlackPositions[i].y == 1 && (m_BlackPositions[i].x == 2 || m_BlackPositions[i].x == 3 || m_BlackPositions[i].x == 4)) || (m_WhitePositions[i].y == 1 && (m_WhitePositions[i].x == 2 || m_WhitePositions[i].x == 3 || m_WhitePositions[i].x == 4)) || blackKing->hasBeenMoved() || blackRooks[0].hasBeenMoved() || blackRooks[0].isDeleted())
			{
				return false;
			}
			break;
		case CastlingOptions::smallBlack:
			if (isBeingChecked(BLACK))
			{
				return false;
			}
			if ((m_BlackPositions[i].y == 1 && (m_BlackPositions[i].x == 7 || m_BlackPositions[i].x == 6)) || (m_WhitePositions[i].y == 1 && (m_WhitePositions[i].x == 7 || m_WhitePositions[i].x == 6)) || blackKing->hasBeenMoved() || blackRooks[1].hasBeenMoved() || blackRooks[1].isDeleted())
			{
				return false;
			}
			break;
		}
	}
	return true;
}

void Game::render()
{
	eventHandler(event);
	m_Window->clear();
	drawBoard();
	drawPieces();
	m_Window->display();
}

void Game::onClickEvent()
{
	if (!(isAI && !isWhiteTurn))
	{
		bool isOnPiece = false;
		int index = 0;
		int indexInPositions = 0;
		sf::Vector2i mousePosition;
		mousePosition.x = (int)(sf::Mouse::getPosition(*m_Window).x + m_SizeOfSquare) / (int)m_SizeOfSquare;
		mousePosition.y = (int)(sf::Mouse::getPosition(*m_Window).y + m_SizeOfSquare) / (int)m_SizeOfSquare;
		TypeOfPiece whatPiece = TypeOfPiece::WhiteRook;
		for (unsigned int i = 0; i < 16; i++)
		{
			index = i;
			indexInPositions = i;
			if (m_WhitePositions[i].x == mousePosition.x && m_WhitePositions[i].y == mousePosition.y)
			{
				whatPiece = getPieceType(i, WHITE);
				i = 16;
				isOnPiece = true;
			}
			else if (m_BlackPositions[i].x == mousePosition.x && m_BlackPositions[i].y == mousePosition.y)
			{
				whatPiece = getPieceType(i, BLACK);
				i = 16;
				isOnPiece = true;
			}
		}
		std::vector<sf::Vector2f> allMoves;
		if (isOnPiece)
		{
			sf::RectangleShape copyOfPiece;
			copyOfPiece.setSize(sf::Vector2f(m_SizeOfSquare, m_SizeOfSquare));
			copyOfPiece.setTexture(&Piece::m_GraphicTexture);
			copyOfPiece.setPosition(sf::Vector2f((float)sf::Mouse::getPosition(*m_Window).x, (float)sf::Mouse::getPosition(*m_Window).y));
			auto textureSize = Piece::m_GraphicTexture.getSize();
			textureSize.x /= 6;
			textureSize.y /= 2;
			copyOfPiece.setTextureRect(sf::IntRect(textureSize.x * 4, textureSize.y * 0, textureSize.x, textureSize.y));
			bool couldBeEnPisant = false;
			switch (whatPiece)
			{
			case TypeOfPiece::WhiteRook:
				allMoves = genPieceMoves(index, TypeOfPiece::WhiteRook);
				copyOfPiece.setTextureRect(sf::IntRect(textureSize.x * 4, textureSize.y * 0, textureSize.x, textureSize.y));
				whiteRooks[index].moved();
				break;
			case TypeOfPiece::BlackRook:
				allMoves = genPieceMoves(index, TypeOfPiece::BlackRook);
				copyOfPiece.setTextureRect(sf::IntRect(textureSize.x * 4, textureSize.y, textureSize.x, textureSize.y));
				blackRooks[index].moved();
				break;
			case TypeOfPiece::WhiteKnight:
				copyOfPiece.setTextureRect(sf::IntRect(textureSize.x * 3, textureSize.y * 0, textureSize.x, textureSize.y));
				index -= 2;
				allMoves = genPieceMoves(index, TypeOfPiece::WhiteKnight);
				break;
			case TypeOfPiece::BlackKnight:
				copyOfPiece.setTextureRect(sf::IntRect(textureSize.x * 3, textureSize.y, textureSize.x, textureSize.y));
				index -= 2;
				allMoves = genPieceMoves(index, TypeOfPiece::BlackKnight);
				break;
			case TypeOfPiece::WhiteBishop:
				copyOfPiece.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 0, textureSize.x, textureSize.y));
				index -= 4;
				allMoves = genPieceMoves(index, TypeOfPiece::WhiteBishop);
				break;
			case TypeOfPiece::BlackBishop:
				copyOfPiece.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y, textureSize.x, textureSize.y));
				index -= 4;
				allMoves = genPieceMoves(index, TypeOfPiece::BlackBishop);
				break;
			case TypeOfPiece::WhitePawn:
				copyOfPiece.setTextureRect(sf::IntRect(textureSize.x * 5, textureSize.y * 0, textureSize.x, textureSize.y));
				index -= 6;
				allMoves = genPieceMoves(index, TypeOfPiece::WhitePawn);
				break;
			case TypeOfPiece::BlackPawn:
				copyOfPiece.setTextureRect(sf::IntRect(textureSize.x * 5, textureSize.y, textureSize.x, textureSize.y));
				index -= 6;
				allMoves = genPieceMoves(index, TypeOfPiece::BlackPawn);
				break;
			case TypeOfPiece::WhiteQueen:
				index -= 14 + (1 - whiteQueens.size());
				copyOfPiece.setTextureRect(sf::IntRect(textureSize.x, textureSize.y * 0, textureSize.x, textureSize.y));
				allMoves = genPieceMoves(index, TypeOfPiece::WhiteQueen);
				break;
			case TypeOfPiece::BlackQueen:
				index -= 14 + (1 - blackQueens.size());
				copyOfPiece.setTextureRect(sf::IntRect(textureSize.x, textureSize.y, textureSize.x, textureSize.y));
				allMoves = genPieceMoves(index, TypeOfPiece::BlackQueen);
				break;
			case TypeOfPiece::WhiteKing:
				copyOfPiece.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));
				allMoves = genPieceMoves(index, TypeOfPiece::WhiteKing);
				break;
			case TypeOfPiece::BlackKing:
				copyOfPiece.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y, textureSize.x, textureSize.y));
				allMoves = genPieceMoves(index, TypeOfPiece::BlackKing);
				break;
			}
			copyOfPiece.setOrigin(copyOfPiece.getSize().x / 2, copyOfPiece.getSize().y / 2);
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				copyOfPiece.setPosition(sf::Vector2f((float)sf::Mouse::getPosition(*m_Window).x, (float)sf::Mouse::getPosition(*m_Window).y));
				m_Window->clear();
				drawBoard();
				drawPieces(whatPiece, index);
#if _DEBUG
				drawValidMoves(allMoves);
#endif
				m_Window->draw(copyOfPiece);
				m_Window->display();
			}
			int copyOfPieceX = (int)(copyOfPiece.getPosition().x + m_SizeOfSquare) / (int)m_SizeOfSquare;
			int copyOfPieceY = (int)(copyOfPiece.getPosition().y + m_SizeOfSquare) / (int)m_SizeOfSquare;
			if (isValidMove(whatPiece, copyOfPieceX, copyOfPieceY, index, indexInPositions))
			{
				switch (whatPiece)
				{
				case TypeOfPiece::WhiteRook:
					movePiece(whiteRooks[index].getPiece(), sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY));
					whiteRooks[index].moved();
					m_WhitePositions[indexInPositions].x = (float)copyOfPieceX;
					m_WhitePositions[indexInPositions].y = (float)copyOfPieceY;
					whiteRooks[index].moved();
					break;
				case TypeOfPiece::BlackRook:
					movePiece(blackRooks[index].getPiece(), sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY));
					blackRooks[index].moved();
					m_BlackPositions[indexInPositions].x = (float)copyOfPieceX;
					m_BlackPositions[indexInPositions].y = (float)copyOfPieceY;
					break;
				case TypeOfPiece::WhiteBishop:
					movePiece(whiteBishops[index].getPiece(), sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY));
					m_WhitePositions[indexInPositions].x = (float)copyOfPieceX;
					m_WhitePositions[indexInPositions].y = (float)copyOfPieceY;
					blackRooks[index].moved();
					break;
				case TypeOfPiece::BlackBishop:
					movePiece(blackBishops[index].getPiece(), sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY));
					m_BlackPositions[indexInPositions].x = (float)copyOfPieceX;
					m_BlackPositions[indexInPositions].y = (float)copyOfPieceY;
					break;
				case TypeOfPiece::WhiteKnight:
					movePiece(whiteKnights[index].getPiece(), sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY));
					m_WhitePositions[indexInPositions].x = (float)copyOfPieceX;
					m_WhitePositions[indexInPositions].y = (float)copyOfPieceY;
					break;
				case TypeOfPiece::BlackKnight:
					movePiece(blackKnights[index].getPiece(), sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY));
					m_BlackPositions[indexInPositions].x = (float)copyOfPieceX;
					m_BlackPositions[indexInPositions].y = (float)copyOfPieceY;
					break;
				case TypeOfPiece::WhitePawn:
					if (m_WhitePositions[indexInPositions].y == 7 && copyOfPieceY == 5)
					{
						enPisantIndex = indexInPositions;
						couldBeEnPisant = true;
					}
					if (enPisantIndex != -1 && (m_WhitePositions[indexInPositions].x == m_BlackPositions[enPisantIndex].x + 1 || m_WhitePositions[indexInPositions].x == m_BlackPositions[enPisantIndex].x - 1) && m_WhitePositions[indexInPositions].y == m_BlackPositions[enPisantIndex].y && copyOfPieceX == allMoves[allMoves.size() - 1].x && copyOfPieceY == allMoves[allMoves.size() - 1].y)
					{
						blackPawns[enPisantIndex - 6].deletePiece(m_BlackPositions, enPisantIndex);
					}
					movePiece(whitePawns[index].getPiece(), sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY));
					m_WhitePositions[indexInPositions].x = (float)copyOfPieceX;
					m_WhitePositions[indexInPositions].y = (float)copyOfPieceY;
					if (m_WhitePositions[indexInPositions].y == 1)
					{
						removePiece(BLACK, sf::Vector2f(m_WhitePositions[indexInPositions].x, m_WhitePositions[indexInPositions].y));
						whitePawns[index].deletePiece(m_WhitePositions, indexInPositions);
						for (int i = indexInPositions; i < 16 - (int)whiteQueens.size(); i++)
						{
							m_WhitePositions[i] = m_WhitePositions[i + 1];
						}
						whitePawns.erase(whitePawns.begin() + index);
						m_WhitePositions[14] = sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY);
						whiteQueens.emplace_back(Queen(WHITE, *m_Window));
						movePiece(whiteQueens[whiteQueens.size() - 1].getPiece(), sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY));
					}
					break;
				case TypeOfPiece::BlackPawn:
					if (m_BlackPositions[indexInPositions].y == 2 && copyOfPieceY == 4)
					{
						enPisantIndex = indexInPositions;
						couldBeEnPisant = true;
					}
					if (enPisantIndex != -1 && (m_BlackPositions[indexInPositions].x == m_WhitePositions[enPisantIndex].x + 1 || m_BlackPositions[indexInPositions].x == m_WhitePositions[enPisantIndex].x - 1) && m_BlackPositions[indexInPositions].y == m_WhitePositions[enPisantIndex].y && copyOfPieceX == allMoves[allMoves.size() - 1].x && copyOfPieceY == allMoves[allMoves.size() - 1].y)
					{
						whitePawns[enPisantIndex - 6].deletePiece(m_WhitePositions, enPisantIndex);
					}
					movePiece(blackPawns[index].getPiece(), sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY));
					m_BlackPositions[indexInPositions].x = (float)copyOfPieceX;
					m_BlackPositions[indexInPositions].y = (float)copyOfPieceY;
					if (m_BlackPositions[indexInPositions].y == 8)
					{
						removePiece(WHITE, sf::Vector2f(m_BlackPositions[indexInPositions].x, m_BlackPositions[indexInPositions].y));
						blackPawns[index].deletePiece(m_BlackPositions, indexInPositions);
						for (int i = indexInPositions; i < 16 - (int)blackQueens.size(); i++)
						{
							m_BlackPositions[i] = m_BlackPositions[i + 1];
						}
						blackPawns.erase(blackPawns.begin() + index);
						m_BlackPositions[14] = sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY);
						blackQueens.emplace_back(Queen(BLACK, *m_Window));
						movePiece(blackQueens[blackQueens.size() - 1].getPiece(), sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY));
					}
					break;
				case TypeOfPiece::WhiteQueen:
					movePiece(whiteQueens[index].getPiece(), sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY));
					m_WhitePositions[indexInPositions].x = (float)copyOfPieceX;
					m_WhitePositions[indexInPositions].y = (float)copyOfPieceY;
					break;
				case TypeOfPiece::BlackQueen:
					movePiece(blackQueens[index].getPiece(), sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY));
					m_BlackPositions[indexInPositions].x = (float)copyOfPieceX;
					m_BlackPositions[indexInPositions].y = (float)copyOfPieceY;
					break;
				case TypeOfPiece::WhiteKing:
					if (copyOfPieceX == 3 && !whiteKing->hasBeenMoved())
					{
						castle(CastlingOptions::bigWhite);
					}
					else if (copyOfPieceX == 7 && !whiteKing->hasBeenMoved())
					{
						castle(CastlingOptions::smallWhite);
					}
					else
					{
						movePiece(whiteKing->getPiece(), sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY));
						m_WhitePositions[indexInPositions].x = (float)copyOfPieceX;
						m_WhitePositions[indexInPositions].y = (float)copyOfPieceY;
						whiteKing->moved();
					}
					break;
				case TypeOfPiece::BlackKing:
					if (copyOfPieceX == 3 && !blackKing->hasBeenMoved())
					{
						castle(CastlingOptions::bigBlack);
					}
					else if (copyOfPieceX == 7 && !blackKing->hasBeenMoved())
					{
						castle(CastlingOptions::smallBlack);
					}
					else
					{
						movePiece(blackKing->getPiece(), sf::Vector2f((float)copyOfPieceX, (float)copyOfPieceY));
						m_BlackPositions[indexInPositions].x = (float)copyOfPieceX;
						m_BlackPositions[indexInPositions].y = (float)copyOfPieceY;
						blackKing->moved();
					}
					break;
				}
				if (isWhiteTurn)
				{
					removePiece(BLACK, sf::Vector2f(m_WhitePositions[indexInPositions].x, m_WhitePositions[indexInPositions].y));
					isWhiteTurn = false;
				}
				else
				{
					removePiece(WHITE, sf::Vector2f(m_BlackPositions[indexInPositions].x, m_BlackPositions[indexInPositions].y));
					isWhiteTurn = true;
				}
				gameEnd();
				if (!couldBeEnPisant)
				{
					enPisantIndex = -1;
				}
			}
		}
	}
}

std::vector<sf::Vector2f> Game::genAllMoves(const Color& color)
{
	std::vector<sf::Vector2f> allMoves;
	std::vector<std::vector<sf::Vector2f>> temp;
	for (int i = 0; i < 2; i++)
	{
		if (color == WHITE)
		{
			temp.push_back(genPieceMoves(i, TypeOfPiece::WhiteRook));
			temp.push_back(genPieceMoves(i, TypeOfPiece::WhiteKnight));
			temp.push_back(genPieceMoves(i, TypeOfPiece::WhiteBishop));
		}
		else
		{
			temp.push_back(genPieceMoves(i, TypeOfPiece::BlackRook));
			temp.push_back(genPieceMoves(i, TypeOfPiece::BlackKnight));
			temp.push_back(genPieceMoves(i, TypeOfPiece::BlackBishop));
		}
	}
	if (color == WHITE)
	{
		for (int i = 0; i < (int)whitePawns.size(); i++)
		{
			temp.push_back(genPieceMoves(i, TypeOfPiece::WhitePawn));
		}
		temp.push_back(genPieceMoves(0, TypeOfPiece::WhiteQueen));
		temp.push_back(genPieceMoves(0, TypeOfPiece::WhiteKing));
	}
	else
	{
		for (int i = 0; i < (int)blackPawns.size(); i++)
		{
			temp.push_back(genPieceMoves(i, TypeOfPiece::BlackPawn));
		}
		temp.push_back(genPieceMoves(0, TypeOfPiece::BlackQueen));
		temp.push_back(genPieceMoves(0, TypeOfPiece::BlackKing));
	}

	for (int i = 0; i < (int)temp.size(); i++)
	{
		for (int u = 0; u < (int)temp[i].size(); u++)
		{
			allMoves.push_back(temp[i][u]);
		}
	}
	return allMoves;
}

std::vector<sf::Vector2f> Game::genAllBaseLevelMoves(const Color& color)
{
	std::vector<sf::Vector2f> allMoves;
	std::vector<std::vector<sf::Vector2f>> temp;
	if (color == WHITE)
	{
		for (int i = 0; i < 2; i++)
		{
			if (!whiteRooks[i].isDeleted())
			{
				temp.push_back(whiteRooks[i].possibleMoves(m_WhitePositions, m_BlackPositions, i));
			}
			if (!whiteKnights[i].isDeleted())
			{
				temp.push_back(whiteKnights[i].possibleMoves(m_WhitePositions, m_BlackPositions, i + 2));
			}
			if (!whiteBishops[i].isDeleted())
			{
				temp.push_back(whiteBishops[i].possibleMoves(m_WhitePositions, m_BlackPositions, i + 4));
			}
		}
		for (int i = 0; i < (int)whitePawns.size(); i++)
		{
			if (!whitePawns[i].isDeleted())
			{
				temp.push_back(whitePawns[i].possibleMoves(m_WhitePositions, m_BlackPositions, i + 6));
			}
		}
		for (int i = 0; i < (int)whiteQueens.size(); i++)
		{
			if (!whiteQueens[i].isDeleted())
			{
				temp.push_back(whiteQueens[i].possibleMoves(m_WhitePositions, m_BlackPositions, 15 - whiteQueens.size() + i));
			}
		}
		if (!whiteKing->isDeleted())
		{
			temp.push_back(whiteKing->possibleMoves(m_WhitePositions, m_BlackPositions, 15));
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			if (!blackRooks[i].isDeleted())
			{
				temp.push_back(blackRooks[i].possibleMoves(m_WhitePositions, m_BlackPositions, i));
			}
			if (!blackKnights[i].isDeleted())
			{
				temp.push_back(blackKnights[i].possibleMoves(m_WhitePositions, m_BlackPositions, i + 2));
			}
			if (!blackBishops[i].isDeleted())
			{
				temp.push_back(blackBishops[i].possibleMoves(m_WhitePositions, m_BlackPositions, i + 4));
			}
		}
		for (int i = 0; i < (int)blackPawns.size(); i++)
		{
			if (!blackPawns[i].isDeleted())
			{
				temp.push_back(blackPawns[i].possibleMoves(m_WhitePositions, m_BlackPositions, i + 6));
			}
		}
		for (int i = 0; i < (int)blackQueens.size(); i++)
		{
			if (!blackQueens[i].isDeleted())
			{
				temp.push_back(blackQueens[i].possibleMoves(m_WhitePositions, m_BlackPositions, 15 - blackQueens.size() + i));
			}
		}
		if (!blackKing->isDeleted())
		{
			temp.push_back(blackKing->possibleMoves(m_WhitePositions, m_BlackPositions, 15));
		}
	}
	for (int i = 0; i < (int)temp.size(); i++)
	{
		for (int u = 0; u < (int)temp[i].size(); u++)
		{
			allMoves.push_back(temp[i][u]);
		}
	}
	return allMoves;
}

std::vector<sf::Vector2f> Game::genPieceMoves(const int& index, const TypeOfPiece& pieceType)
{
	std::vector<sf::Vector2f> allMoves;
	bool check = false;
	bool checkingTakePiece = false;
	sf::Vector2f currentPos;
	sf::Vector2f tookPiecePos;
	int indexOfTookPiece = -1;
	if (pieceType != TypeOfPiece::WhiteKing && pieceType != TypeOfPiece::BlackKing)
	{
		check = isInWayOfCheck(pieceType, index);
	}
	switch (pieceType)
	{
	case TypeOfPiece::WhiteRook:
		if (!whiteRooks[index].isDeleted())
		{
			allMoves = whiteRooks[index].possibleMoves(m_WhitePositions, m_BlackPositions, index);
		}
		break;
	case TypeOfPiece::BlackRook:
		if (!blackRooks[index].isDeleted())
		{
			allMoves = blackRooks[index].possibleMoves(m_WhitePositions, m_BlackPositions, index);
		}
		break;
	case TypeOfPiece::WhiteBishop:
		if (!whiteBishops[index].isDeleted())
		{
			allMoves = whiteBishops[index].possibleMoves(m_WhitePositions, m_BlackPositions, index + 4);
		}
		break;
	case TypeOfPiece::BlackBishop:
		if (!blackBishops[index].isDeleted())
		{
			allMoves = blackBishops[index].possibleMoves(m_WhitePositions, m_BlackPositions, index + 4);
		}
		break;
	case TypeOfPiece::WhiteKnight:
		if (!whiteKnights[index].isDeleted())
		{
			allMoves = whiteKnights[index].possibleMoves(m_WhitePositions, m_BlackPositions, index + 2);
		}
		break;
	case TypeOfPiece::BlackKnight:
		if (!blackKnights[index].isDeleted())
		{
			allMoves = blackKnights[index].possibleMoves(m_WhitePositions, m_BlackPositions, index + 2);
		}
		break;
	case TypeOfPiece::WhitePawn:
		if (!whitePawns[index].isDeleted())
		{
			allMoves = whitePawns[index].possibleMoves(m_WhitePositions, m_BlackPositions, index + 6);
			if (enPisantIndex != -1 && (m_WhitePositions[index + 6].x == m_BlackPositions[enPisantIndex].x + 1 || m_WhitePositions[index + 6].x == m_BlackPositions[enPisantIndex].x - 1) && m_WhitePositions[index + 6].y == m_BlackPositions[enPisantIndex].y)
			{
				allMoves.push_back(sf::Vector2f(m_BlackPositions[enPisantIndex].x, m_BlackPositions[enPisantIndex].y - 1));
			}
		}
		break;
	case TypeOfPiece::BlackPawn:
		if (!blackPawns[index].isDeleted())
		{
			allMoves = blackPawns[index].possibleMoves(m_WhitePositions, m_BlackPositions, index + 6);
			if (enPisantIndex != -1 && (m_BlackPositions[index + 6].x == m_WhitePositions[enPisantIndex].x + 1 || m_BlackPositions[index + 6].x == m_WhitePositions[enPisantIndex].x - 1) && m_BlackPositions[index + 6].y == m_WhitePositions[enPisantIndex].y)
			{
				allMoves.push_back(sf::Vector2f(m_WhitePositions[enPisantIndex].x, m_WhitePositions[enPisantIndex].y + 1));
			}
		}
		break;
	case TypeOfPiece::WhiteQueen:
		if (!whiteQueens[index].isDeleted())
		{
			allMoves = whiteQueens[index].possibleMoves(m_WhitePositions, m_BlackPositions, 15 - whiteQueens.size() + index);
		}
		break;
	case TypeOfPiece::BlackQueen:
		if (!blackQueens[index].isDeleted())
		{
			allMoves = blackQueens[index].possibleMoves(m_WhitePositions, m_BlackPositions, 15 - blackQueens.size() + index);
		}
		break;
	case TypeOfPiece::WhiteKing:
		if (!whiteKing->isDeleted())
		{
			allMoves = whiteKing->possibleMoves(m_WhitePositions, m_BlackPositions, 15);
			if (isValidCastle(CastlingOptions::bigWhite))
			{
				allMoves.push_back(sf::Vector2f(3, 8));
			}
			if (isValidCastle(CastlingOptions::smallWhite))
			{
				allMoves.push_back(sf::Vector2f(7, 8));
			}
			currentPos = m_WhitePositions[15];
			for (int i = 0; i < (int)allMoves.size(); i++)
			{
				for (int u = 0; u < 16; u++)
				{
					if (allMoves[i] == m_BlackPositions[u])
					{
						tookPiecePos = m_BlackPositions[u];
						m_BlackPositions[u] = sf::Vector2f(1000, 1000);
						checkingTakePiece = true;
						indexOfTookPiece = u;
						u = 16;
					}
				}
				m_WhitePositions[15] = allMoves[i];
				if (isBeingChecked(WHITE))
				{
					m_WhitePositions[15] = currentPos;
					allMoves.erase(allMoves.begin() + i);
					i--;
				}
				else
				{
					m_WhitePositions[15] = currentPos;
				}
				if (checkingTakePiece)
				{
					checkingTakePiece = false;
					m_BlackPositions[indexOfTookPiece] = tookPiecePos;
				}
			}
		}
		break;
	case TypeOfPiece::BlackKing:
		if (!blackKing->isDeleted())
		{
			allMoves = blackKing->possibleMoves(m_WhitePositions, m_BlackPositions, 15);
			if (isValidCastle(CastlingOptions::bigBlack))
			{
				allMoves.push_back(sf::Vector2f(3, 1));
			}
			if (isValidCastle(CastlingOptions::smallBlack))
			{
				allMoves.push_back(sf::Vector2f(7, 1));
			}
			currentPos = m_BlackPositions[15];
			for (int i = 0; i < (int)allMoves.size(); i++)
			{
				for (int u = 0; u < 16; u++)
				{
					if (allMoves[i] == m_WhitePositions[u])
					{
						tookPiecePos = m_WhitePositions[u];
						m_WhitePositions[u] = sf::Vector2f(1000, 1000);
						checkingTakePiece = true;
						indexOfTookPiece = u;
						u = 16;
					}
				}
				m_BlackPositions[15] = allMoves[i];
				if (isBeingChecked(BLACK))
				{
					m_BlackPositions[15] = currentPos;
					allMoves.erase(allMoves.begin() + i);
					i--;
				}
				else
				{
					m_BlackPositions[15] = currentPos;
				}
				if (checkingTakePiece)
				{
					checkingTakePiece = false;
					m_WhitePositions[indexOfTookPiece] = tookPiecePos;
				}
			}
		}
		break;
	case TypeOfPiece::none:
		break;
	}
	if (check || isBeingChecked(BLACK) && !isWhiteTurn || isBeingChecked(WHITE) && isWhiteTurn)
	{
		int whereIsPiece;
		sf::Vector2f currentPosOfPiece;
		for (int i = 0; i < (int)allMoves.size(); i++)
		{
			switch (pieceType)
			{
			case TypeOfPiece::WhiteRook:
				currentPosOfPiece = m_WhitePositions[index];
				m_WhitePositions[index] = sf::Vector2f(1000, 1000);
				whereIsPiece = whatPieceIsChecking(BLACK);
				m_WhitePositions[index] = currentPosOfPiece;
				if (!(whereIsPiece != -1 && m_BlackPositions[whereIsPiece] == allMoves[i]))
				{
					currentPos = m_WhitePositions[index];
					m_WhitePositions[index] = allMoves[i];
					if (isBeingChecked(WHITE))
					{
						m_WhitePositions[index] = currentPos;
						allMoves.erase(allMoves.begin() + i);
						i--;
					}
					m_WhitePositions[index] = currentPos;
				}
				break;
			case TypeOfPiece::BlackRook:
				currentPosOfPiece = m_BlackPositions[index];
				m_BlackPositions[index] = sf::Vector2f(1000, 1000);
				whereIsPiece = whatPieceIsChecking(WHITE);
				m_BlackPositions[index] = currentPosOfPiece;
				if (!(whereIsPiece != -1 && m_WhitePositions[whereIsPiece] == allMoves[i]))
				{
					currentPos = m_BlackPositions[index];
					m_BlackPositions[index] = allMoves[i];
					if (isBeingChecked(BLACK))
					{
						m_BlackPositions[index] = currentPos;
						allMoves.erase(allMoves.begin() + i);
						i--;
					}
					m_BlackPositions[index] = currentPos;
				}
				break;
			case TypeOfPiece::WhiteBishop:
				currentPosOfPiece = m_WhitePositions[index + 4];
				m_WhitePositions[index + 4] = sf::Vector2f(1000, 1000);
				whereIsPiece = whatPieceIsChecking(BLACK);
				m_WhitePositions[index + 4] = currentPosOfPiece;
				if (!(whereIsPiece != -1 && m_BlackPositions[whereIsPiece] == allMoves[i]))
				{
					currentPos = m_WhitePositions[index + 4];
					m_WhitePositions[index + 4] = allMoves[i];
					if (isBeingChecked(WHITE))
					{
						m_WhitePositions[index + 4] = currentPos;
						allMoves.erase(allMoves.begin() + i);
						i--;
					}
					m_WhitePositions[index + 4] = currentPos;
				}
				break;
			case TypeOfPiece::BlackBishop:
				currentPosOfPiece = m_BlackPositions[index + 4];
				m_BlackPositions[index + 4] = sf::Vector2f(1000, 1000);
				whereIsPiece = whatPieceIsChecking(WHITE);
				m_BlackPositions[index + 4] = currentPosOfPiece;
				if (!(whereIsPiece != -1 && m_WhitePositions[whereIsPiece] == allMoves[i]))
				{
					currentPos = m_BlackPositions[index + 4];
					m_BlackPositions[index + 4] = allMoves[i];
					if (isBeingChecked(BLACK))
					{
						m_BlackPositions[index + 4] = currentPos;
						allMoves.erase(allMoves.begin() + i);
						i--;
					}
					m_BlackPositions[index + 4] = currentPos;
				}
				break;
			case TypeOfPiece::WhiteKnight:
				currentPosOfPiece = m_WhitePositions[index + 2];
				m_WhitePositions[index + 2] = sf::Vector2f(1000, 1000);
				whereIsPiece = whatPieceIsChecking(BLACK);
				m_WhitePositions[index + 2] = currentPosOfPiece;
				if (!(whereIsPiece != -1 && m_BlackPositions[whereIsPiece] == allMoves[i]))
				{
					currentPos = m_WhitePositions[index + 2];
					m_WhitePositions[index + 2] = allMoves[i];
					if (isBeingChecked(WHITE))
					{
						m_WhitePositions[index + 2] = currentPos;
						allMoves.erase(allMoves.begin() + i);
						i--;
					}
					m_WhitePositions[index + 2] = currentPos;
				}
				break;
			case TypeOfPiece::BlackKnight:
				currentPosOfPiece = m_BlackPositions[index + 2];
				m_BlackPositions[index + 2] = sf::Vector2f(1000, 1000);
				whereIsPiece = whatPieceIsChecking(WHITE);
				m_BlackPositions[index + 2] = currentPosOfPiece;
				if (!(whereIsPiece != -1 && m_WhitePositions[whereIsPiece] == allMoves[i]))
				{
					currentPos = m_BlackPositions[index + 2];
					m_BlackPositions[index + 2] = allMoves[i];
					if (isBeingChecked(BLACK))
					{
						m_BlackPositions[index + 2] = currentPos;
						allMoves.erase(allMoves.begin() + i);
						i--;
					}
					m_BlackPositions[index + 2] = currentPos;
				}
				break;
			case TypeOfPiece::WhitePawn:
				currentPosOfPiece = m_WhitePositions[index + 6];
				m_WhitePositions[index + 6] = sf::Vector2f(1000, 1000);
				whereIsPiece = whatPieceIsChecking(BLACK);
				m_WhitePositions[index + 6] = currentPosOfPiece;
				if (!(whereIsPiece != -1 && m_BlackPositions[whereIsPiece] == allMoves[i]))
				{
					currentPos = m_WhitePositions[index + 6];
					m_WhitePositions[index + 6] = allMoves[i];
					if (isBeingChecked(WHITE))
					{
						m_WhitePositions[index + 6] = currentPos;
						allMoves.erase(allMoves.begin() + i);
						i--;
					}
					m_WhitePositions[index + 6] = currentPos;
				}
				break;
			case TypeOfPiece::BlackPawn:
				currentPosOfPiece = m_BlackPositions[index + 6];
				m_BlackPositions[index + 6] = sf::Vector2f(1000, 1000);
				whereIsPiece = whatPieceIsChecking(WHITE);
				m_BlackPositions[index + 6] = currentPosOfPiece;
				if (!(whereIsPiece != -1 && m_WhitePositions[whereIsPiece] == allMoves[i]))
					currentPos = m_BlackPositions[index + 6];
				m_BlackPositions[index + 6] = allMoves[i];
				if (isBeingChecked(BLACK))
				{
					m_BlackPositions[index + 6] = currentPos;
					allMoves.erase(allMoves.begin() + i);
					i--;
				}
				m_BlackPositions[index + 6] = currentPos;
				break;
			case TypeOfPiece::WhiteQueen:
				currentPosOfPiece = m_WhitePositions[15 - whiteQueens.size() + index];
				m_WhitePositions[15 - whiteQueens.size() + index] = sf::Vector2f(1000, 1000);
				whereIsPiece = whatPieceIsChecking(BLACK);
				m_WhitePositions[15 - whiteQueens.size() + index] = currentPosOfPiece;
				if (!(whereIsPiece != -1 && m_BlackPositions[whereIsPiece] == allMoves[i]))
				{
					currentPos = m_WhitePositions[15 - whiteQueens.size() + index];
					m_WhitePositions[15 - whiteQueens.size() + index] = allMoves[i];
					if (isBeingChecked(WHITE))
					{
						m_WhitePositions[15 - whiteQueens.size() + index] = currentPos;
						allMoves.erase(allMoves.begin() + i);
						i--;
					}
					m_WhitePositions[15 - whiteQueens.size() + index] = currentPos;
				}
				break;
			case TypeOfPiece::BlackQueen:
				currentPosOfPiece = m_BlackPositions[15 - blackQueens.size() + index];
				m_BlackPositions[15 - blackQueens.size() + index] = sf::Vector2f(1000, 1000);
				whereIsPiece = whatPieceIsChecking(WHITE);
				m_BlackPositions[15 - blackQueens.size() + index] = currentPosOfPiece;
				if (!(whereIsPiece != -1 && m_WhitePositions[whereIsPiece] == allMoves[i]))
				{
					currentPos = m_BlackPositions[15 - blackQueens.size() + index];
					m_BlackPositions[15 - blackQueens.size() + index] = allMoves[i];
					if (isBeingChecked(BLACK))
					{
						m_BlackPositions[15 - blackQueens.size() + index] = currentPos;
						allMoves.erase(allMoves.begin() + i);
						i--;
					}
					m_BlackPositions[15 - blackQueens.size() + index] = currentPos;
				}
				break;
			default:
				break;
			}
		}
	}
	return allMoves;
}

bool Game::isBeingChecked(const Color& color)
{
	std::vector<sf::Vector2f> allMoves;
	int kingX = 0;
	int kingY = 0;
	if (color == WHITE)
	{
		kingX = (int)m_WhitePositions[15].x;
		kingY = (int)m_WhitePositions[15].y;
	}
	else
	{
		kingX = (int)m_BlackPositions[15].x;
		kingY = (int)m_BlackPositions[15].y;
	}
	if (color == WHITE)
	{
		allMoves = genAllBaseLevelMoves(BLACK);
	}
	else
	{
		allMoves = genAllBaseLevelMoves(WHITE);
	}
	for (int i = 0; i < (int)allMoves.size(); i++)
	{
		if (allMoves[i].x == kingX && allMoves[i].y == kingY)
		{
			return true;
		}
	}
	return false;
}

bool Game::isInWayOfCheck(const TypeOfPiece& pieceType, const int& index)
{
	switch (pieceType)
	{
	case TypeOfPiece::WhiteRook:
		if (!isBeingChecked(WHITE))
		{
			sf::Vector2f curentPos = m_WhitePositions[index];
			m_WhitePositions[index] = sf::Vector2f(1000, 1000);
			if (isBeingChecked(WHITE))
			{
				m_WhitePositions[index] = curentPos;
				return true;
			}
			m_WhitePositions[index] = curentPos;
		}
		break;
	case TypeOfPiece::BlackRook:
		if (!isBeingChecked(BLACK))
		{
			sf::Vector2f curentPos = m_BlackPositions[index];
			m_BlackPositions[index] = sf::Vector2f(1000, 1000);
			if (isBeingChecked(BLACK))
			{
				m_BlackPositions[index] = curentPos;
				return true;
			}
			m_BlackPositions[index] = curentPos;
		}
		break;
	case TypeOfPiece::WhiteBishop:
		if (!isBeingChecked(WHITE))
		{
			sf::Vector2f curentPos = m_WhitePositions[index + 4];
			m_WhitePositions[index + 4] = sf::Vector2f(1000, 1000);
			if (isBeingChecked(WHITE))
			{
				m_WhitePositions[index + 4] = curentPos;
				return true;
			}
			m_WhitePositions[index + 4] = curentPos;
		}
		break;
	case TypeOfPiece::BlackBishop:
		if (!isBeingChecked(BLACK))
		{
			sf::Vector2f curentPos = m_BlackPositions[index + 4];
			m_BlackPositions[index + 4] = sf::Vector2f(1000, 1000);
			if (isBeingChecked(BLACK))
			{
				m_BlackPositions[index + 4] = curentPos;
				return true;
			}
			m_BlackPositions[index + 4] = curentPos;
		}
		break;
	case TypeOfPiece::WhiteKnight:
		if (!isBeingChecked(WHITE))
		{
			sf::Vector2f curentPos = m_WhitePositions[index + 2];
			m_WhitePositions[index + 2] = sf::Vector2f(1000, 1000);
			if (isBeingChecked(WHITE))
			{
				m_WhitePositions[index + 2] = curentPos;
				return true;
			}
			m_WhitePositions[index + 2] = curentPos;
		}
		break;
	case TypeOfPiece::BlackKnight:
		if (!isBeingChecked(BLACK))
		{
			sf::Vector2f curentPos = m_BlackPositions[index + 2];
			m_BlackPositions[index + 2] = sf::Vector2f(1000, 1000);
			if (isBeingChecked(BLACK))
			{
				m_BlackPositions[index + 2] = curentPos;
				return true;
			}
			m_BlackPositions[index + 2] = curentPos;
		}
		break;
	case TypeOfPiece::WhitePawn:
		if (!isBeingChecked(WHITE))
		{
			sf::Vector2f curentPos = m_WhitePositions[index + 6];
			m_WhitePositions[index + 6] = sf::Vector2f(1000, 1000);
			if (isBeingChecked(WHITE))
			{
				m_WhitePositions[index + 6] = curentPos;
				return true;
			}
			m_WhitePositions[index + 6] = curentPos;
		}
		break;
	case TypeOfPiece::BlackPawn:
		if (!isBeingChecked(BLACK))
		{
			sf::Vector2f curentPos = m_BlackPositions[index + 6];
			m_BlackPositions[index + 6] = sf::Vector2f(1000, 1000);
			if (isBeingChecked(BLACK))
			{
				m_BlackPositions[index + 6] = curentPos;
				return true;
			}
			m_BlackPositions[index + 6] = curentPos;
		}
		break;
	case TypeOfPiece::WhiteQueen:
		if (!isBeingChecked(WHITE))
		{
			sf::Vector2f curentPos = m_WhitePositions[15 - whiteQueens.size() + index];
			m_WhitePositions[15 - whiteQueens.size() + index] = sf::Vector2f(1000, 1000);
			if (isBeingChecked(WHITE))
			{
				m_WhitePositions[15 - whiteQueens.size() + index] = curentPos;
				return true;
			}
			m_WhitePositions[15 - whiteQueens.size() + index] = curentPos;
		}
		break;
	case TypeOfPiece::BlackQueen:
		if (!isBeingChecked(BLACK))
		{
			sf::Vector2f curentPos = m_BlackPositions[15 - blackQueens.size() + index];
			m_BlackPositions[15 - blackQueens.size() + index] = sf::Vector2f(1000, 1000);
			if (isBeingChecked(BLACK))
			{
				m_BlackPositions[15 - blackQueens.size() + index] = curentPos;
				return true;
			}
			m_BlackPositions[15 - blackQueens.size() + index] = curentPos;
		}
		break;
	}
	return false;
}

int Game::whatPieceIsChecking(const Color& color)
{
	bool foundPiece = false;
	sf::Vector2f pieceFoundPos;
	sf::Vector2f currentPos;
	for (int i = 0; i < 16; i++)
	{
		if (color == WHITE)
		{
			currentPos = m_WhitePositions[i];
			m_WhitePositions[i] = sf::Vector2f(1000, 1000);
			if (!isBeingChecked(BLACK))
			{
				if (foundPiece)
				{
					m_WhitePositions[i] = currentPos;
					return -1;
				}
				pieceFoundPos = currentPos;
				foundPiece = true;
			}
			m_WhitePositions[i] = currentPos;
		}
		else
		{
			currentPos = m_BlackPositions[i];
			m_BlackPositions[i] = sf::Vector2f(1000, 1000);
			if (!isBeingChecked(WHITE))
			{
				if (foundPiece)
				{
					m_BlackPositions[i] = currentPos;
					return -1;
				}
				pieceFoundPos = currentPos;
				foundPiece = true;
			}
			m_BlackPositions[i] = currentPos;
		}
	}
	if (foundPiece)
	{
		for (int i = 0; i < 16; i++)
		{
			if (color == WHITE)
			{
				if (m_WhitePositions[i] == pieceFoundPos)
				{
					return i;
				}
			}
			else
			{
				if (m_BlackPositions[i] == pieceFoundPos)
				{
					return i;
				}
			}
		}

	}
	return -1;
}

void Game::loadGraphics()
{
	Piece::m_GraphicTexture.loadFromFile("../Textures/ChessPieces.png");
}

void Game::drawBoard()
{
	std::array<sf::RectangleShape, 2> board;
	int yPos = 0;
	int xPos = 0;

	board[0].setFillColor(sf::Color(252, 204, 116));
	board[0].setSize(sf::Vector2f((float)m_Window->getSize().x / 8, (float)m_Window->getSize().y / 8));

	board[1].setFillColor(sf::Color(28, 27, 239));
	board[1].setSize(sf::Vector2f((float)m_Window->getSize().x / 8, (float)m_Window->getSize().y / 8));

	m_SizeOfSquare = board[0].getSize().x;

	for (unsigned int i = 0; i < 64; i++)
	{
		if (xPos == 8)
		{
			yPos++;
			xPos = 0;
		}
		board[0].setPosition(sf::Vector2f(xPos * board[0].getSize().x, yPos * board[0].getSize().y));
		board[1].setPosition(sf::Vector2f(xPos * board[0].getSize().x, yPos * board[0].getSize().y));
		if (yPos % 2 == 0)
		{
			if (xPos % 2 == 0)
			{
				m_Window->draw(board[0]);
			}
			else
			{
				m_Window->draw(board[1]);
			}
		}
		else
		{
			if (xPos % 2 == 0)
			{
				m_Window->draw(board[1]);
			}
			else
			{
				m_Window->draw(board[0]);
			}
		}
		xPos++;
	}
}
#if _DEBUG
void Game::drawValidMoves(const std::vector<sf::Vector2f>& allMoves)
{
	sf::CircleShape spot;
	spot.setRadius(m_SizeOfSquare / 2.01f);
	spot.setFillColor(sf::Color(255, 255, 255, 125));
	for (int i = 0; i < (int)allMoves.size(); i++)
	{
		spot.setPosition(sf::Vector2f((allMoves[i].x - 1) * m_SizeOfSquare, (allMoves[i].y - 1) * m_SizeOfSquare));
		m_Window->draw(spot);
	}
}
#endif
void Game::removePiece(const Color& color, const sf::Vector2f& position)
{
	int I_Index = 0;
	TypeOfPiece pieceType = TypeOfPiece::none;
	for (int i = 0; i < 16; i++)
	{
		I_Index = i;
		if (color == BLACK)
		{
			if (m_BlackPositions[i] == position)
			{
				pieceType = getPieceType(i, BLACK);
				i = 16;
			}
		}
		else
		{
			if (m_WhitePositions[i] == position)
			{
				pieceType = getPieceType(i, WHITE);
				i = 16;
			}
		}
	}
	switch (pieceType)
	{
	case TypeOfPiece::WhiteRook:
		whiteRooks[I_Index].deletePiece(m_WhitePositions, I_Index);
		break;
	case TypeOfPiece::BlackRook:
		blackRooks[I_Index].deletePiece(m_BlackPositions, I_Index);
		break;
	case TypeOfPiece::WhiteBishop:
		whiteBishops[I_Index - 4].deletePiece(m_WhitePositions, I_Index);
		break;
	case TypeOfPiece::BlackBishop:
		blackBishops[I_Index - 4].deletePiece(m_BlackPositions, I_Index);
		break;
	case TypeOfPiece::WhiteKnight:
		whiteKnights[I_Index - 2].deletePiece(m_WhitePositions, I_Index);
		break;
	case TypeOfPiece::BlackKnight:
		blackKnights[I_Index - 2].deletePiece(m_BlackPositions, I_Index);
		break;
	case TypeOfPiece::WhitePawn:
		whitePawns[I_Index - 6].deletePiece(m_WhitePositions, I_Index);
		break;
	case TypeOfPiece::BlackPawn:
		blackPawns[I_Index - 6].deletePiece(m_BlackPositions, I_Index);
		break;
	case TypeOfPiece::WhiteQueen:
		whiteQueens[I_Index - (14 + (1 - (int)whiteQueens.size()))].deletePiece(m_WhitePositions, I_Index);
		break;
	case TypeOfPiece::BlackQueen:
		blackQueens[I_Index - (14 + (1 - (int)blackQueens.size()))].deletePiece(m_BlackPositions, I_Index);
		break;
	case TypeOfPiece::WhiteKing:
		whiteKing->deletePiece(m_WhitePositions, I_Index);
		break;
	case TypeOfPiece::BlackKing:
		blackKing->deletePiece(m_BlackPositions, I_Index);
		break;
	case TypeOfPiece::none:
		break;
	}
}

TypeOfPiece Game::getPieceType(const int& indexOfPiece, const Color& color)
{
	if (indexOfPiece == 0 || indexOfPiece == 1)
	{
		if (color == WHITE)
		{
			return TypeOfPiece::WhiteRook;
		}
		else
		{
			return TypeOfPiece::BlackRook;
		}
	}
	else if (indexOfPiece == 2 || indexOfPiece == 3)
	{
		if (color == WHITE)
		{
			return TypeOfPiece::WhiteKnight;
		}
		else
		{
			return TypeOfPiece::BlackKnight;
		}
	}
	else if (indexOfPiece == 4 || indexOfPiece == 5)
	{
		if (color == WHITE)
		{
			return TypeOfPiece::WhiteBishop;
		}
		else
		{
			return TypeOfPiece::BlackBishop;
		}
	}
	else if (indexOfPiece == 15)
	{
		if (color == WHITE)
		{
			return TypeOfPiece::WhiteKing;
		}
		else
		{
			return TypeOfPiece::BlackKing;
		}
	}
	if (color == WHITE)
	{
		if (indexOfPiece >= 6 && indexOfPiece <= 6 + (8 - (int)whiteQueens.size()))
		{
			return TypeOfPiece::WhitePawn;
		}
		else
		{
			return TypeOfPiece::WhiteQueen;
		}
	}
	else
	{
		if (indexOfPiece >= 6 && indexOfPiece <= 6 + (8 - (int)blackQueens.size()))
		{
			return TypeOfPiece::BlackPawn;
		}
		else
		{
			return TypeOfPiece::BlackQueen;
		}
	}

}

bool Game::isValidMove(const TypeOfPiece& Piece, const int& moveToX, const int& moveToY, const int& index, const int& indexInPositions)
{
	std::vector<sf::Vector2f> allMoves;
	switch (Piece)
	{
	case TypeOfPiece::WhiteRook:
		if (isWhiteTurn)
		{
			allMoves = genPieceMoves(index, TypeOfPiece::WhiteRook);
		}
		break;
	case TypeOfPiece::BlackRook:
		if (!isWhiteTurn)
		{
			allMoves = genPieceMoves(index, TypeOfPiece::BlackRook);
		}
		break;
	case TypeOfPiece::WhiteBishop:
		if (isWhiteTurn)
		{
			allMoves = genPieceMoves(index, TypeOfPiece::WhiteBishop);
		}
		break;
	case TypeOfPiece::BlackBishop:
		if (!isWhiteTurn)
		{
			allMoves = genPieceMoves(index, TypeOfPiece::BlackBishop);
		}
		break;
	case TypeOfPiece::WhiteKnight:
		if (isWhiteTurn)
		{
			allMoves = genPieceMoves(index, TypeOfPiece::WhiteKnight);
		}
		break;
	case TypeOfPiece::BlackKnight:
		if (!isWhiteTurn)
		{
			allMoves = genPieceMoves(index, TypeOfPiece::BlackKnight);
		}
		break;
	case TypeOfPiece::WhitePawn:
		if (isWhiteTurn)
		{
			allMoves = genPieceMoves(index, TypeOfPiece::WhitePawn);
		}
		break;
	case TypeOfPiece::BlackPawn:
		if (!isWhiteTurn)
		{
			allMoves = genPieceMoves(index, TypeOfPiece::BlackPawn);
		}
		break;
	case TypeOfPiece::WhiteQueen:
		if (isWhiteTurn)
		{
			allMoves = genPieceMoves(index, TypeOfPiece::WhiteQueen);
		}
		break;
	case TypeOfPiece::BlackQueen:
		if (!isWhiteTurn)
		{
			allMoves = genPieceMoves(index, TypeOfPiece::BlackQueen);
		}
		break;
	case TypeOfPiece::WhiteKing:
		if (isWhiteTurn)
		{
			allMoves = genPieceMoves(index, TypeOfPiece::WhiteKing);
		}
		break;
	case TypeOfPiece::BlackKing:
		if (!isWhiteTurn)
		{
			allMoves = genPieceMoves(index, TypeOfPiece::BlackKing);

		}
		break;
	}
	for (int i = 0; i < (int)allMoves.size(); i++)
	{
		if (moveToX == allMoves[i].x && moveToY == allMoves[i].y)
		{
			return true;
		}
	}
	return false;
}

void Game::gameEnd()
{
	std::vector<sf::Vector2f> allMoves;
	if (isWhiteTurn)
	{
		allMoves = genAllMoves(WHITE);
	}
	else
	{
		allMoves = genAllMoves(BLACK);
	}
	if (allMoves.size() == 0)
	{
		if (isWhiteTurn)
		{
			if (isBeingChecked(WHITE))
			{
				std::cout << "Black Wins!!!\n";
			}
			else
			{
				std::cout << "Tie!!!\n";
			}
		}
		else
		{
			if (isBeingChecked(BLACK))
			{
				std::cout << "White Wins!!!\n";
			}
			else
			{
				std::cout << "Tie!!!\n";
			}
		}
		m_Window->clear();
		drawBoard();
		drawPieces();
		m_Window->display();
		std::cin.get();
		m_Window->close();
	}
}

bool Game::isGameEnd()
{
	std::vector<sf::Vector2f> allMoves;
	if (isWhiteTurn)
	{
		allMoves = genAllMoves(WHITE);
	}
	else
	{
		allMoves = genAllMoves(BLACK);
	}
	if (allMoves.size() == 0)
	{
		m_Window->clear();
		drawBoard();
		drawPieces();
		m_Window->display();
		std::cin.get();
		m_Window->close();
		return true;
	}
	else
	{
		return false;
	}
}

void Game::eventHandler(sf::Event& event)
{
	while (m_Window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_Window->close();
			break;
		case sf::Event::MouseButtonPressed:
			onClickEvent();
		}
	}
}
