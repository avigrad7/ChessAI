#pragma once
#include<SFML/Graphics.hpp>
#include<array>
#include<vector>
#include<iostream>

#include"allPieces.h"

class Game
{
public:
	Game();
	~Game();
public:
	/*
	* gets if it is white's turn
	* 
	* @return true if it is white's turn and false if not
	*/
	bool getIsWhitesTurn() { return isWhiteTurn; }
	/*
	* Moves a piece to a new place on the board and sets it's position
	*
	* @param color: the color of piece you are moving
	* @param index: the index where the piece is in positions array
	* @param moveTo: The place you the piece to move (1 -8 , 1 - 8)
	*
	* @return None
	*/
	void movePieceAndSetPosition(Color color, int index, const sf::Vector2f& moveTo);
	/*
	* Gets the window
	*
	* @return A reference to the window
	*/
	const sf::RenderWindow& getWindow() const { return *m_Window; }
	/*
	* Starts the game
	*
	* @return None
	*/
	void startGame();
	/*
	* Generates all possible moves
	*
	* @param color: The color of the pices you want to generate the moves of
	*
	* @return An array of all possible moves
	*/
	std::vector<sf::Vector2f> genAllMoves(const Color& color);
	/*
	* Gets the white positions
	* 
	* @retun The vector for the white positions
	*/
	std::vector<sf::Vector2f> getWhitePositions() { return m_WhitePositions; }
	/*
	* Gets the black positions
	*
	* @retun The vector for the black positions
	*/
	std::vector<sf::Vector2f> getBlackPositions() { return m_BlackPositions; }

	bool isGameEnd();
	void setAI() { isAI = true; }
private:
	/*
	* Moves a piece to a new place on the board
	*
	* @param piece: The piece you want to move
	* @param moveTo: The place you the piece to move (1 -8 , 1 - 8)
	*
	* @return None
	*/
	void movePiece(sf::RectangleShape& piece, const sf::Vector2f& moveTo);
	/*
	* Used in the constroctor to set up all the pieces
	*
	* @return None
	*/
	void setPieces();
	/*
	* Deals with all the events (Clicked, Closed window)
	*
	* @return None
	*/
	void eventHandler(sf::Event& event);
	/*
	* Draws the board
	*
	* @return None
	*/
	void drawBoard();
	/*
	* Draws all the pieces
	*
	* @return None
	*/
	void drawPieces();
	/*
	* Draws all the pieces excluding the piece specified
	*
	* @param whichPiece: The type of piece that is being excluded (White Rook, Black Queen)
	* @param index: The index in the array (if there is an array) to not draw
	*
	* @return None
	*/
	void drawPieces(const TypeOfPiece& whichPiece, const int& index);
	/*
	* Only used in the constuctor to load the texture for all the pieces
	*
	* @return None
	*/
	void loadGraphics();
	/*
	* Deals with what happens when the mouse button is pressed (move a piece, delete a piece, do nothing)
	*
	* @return None
	*/
	void onClickEvent();
	/*
	* Figures out what piece something is
	*
	* @param indexOfPiece: The index in positions array the piece is found at
	* @param color: If the piece is white or black
	*
	* @return The type of piece
	*/
	TypeOfPiece getPieceType(const int& indexOfPiece, const Color& color);
	/*
	* Renders everything
	*
	* @return None
	*/
	void render();
	/*
	* Removes a piece from the board
	*
	* @param color: The color of the piece that you are taking
	* @param position: Position of the piece you are taking with
	*/
	void removePiece(const Color& color, const sf::Vector2f& position);
	/*
	* Checks if a move is valid
	*
	* @param Piece: The type of piece
	* @param MoveToX: The X cordinate you want to move to
	* @param moveToY: the Y cordinate you wantt to move to
	* @param index: The index in the array you want to check the move of
	* @param indexInPositions: The index in the positions where the piece could be found
	*
	* @return True if it a valid move, false otherwise
	*/
	bool isValidMove(const TypeOfPiece& Piece, const int& moveToX, const int& moveToY, const int& index, const int& indexInPositions);
#if _DEBUG
	/*
	* Graphicly shows the valid moves
	*
	* @param allMoves: All the posible moves
	*
	* @return None
	*/
	void drawValidMoves(const std::vector<sf::Vector2f>& allMoves);
#endif
	/*
	* Checks if a castle is possible and then castles if it is
	*
	* @param whatCastle: The type of castle and color of castle that you want to preform
	*
	* @return None
	*/
	void castle(const CastlingOptions& whatCastle);
	/*
	* Determines if a given castle is valid
	*
	* @param whatCastle: The type of castle you are checking
	*
	* @return True if it is a valid castle. Fasle otherwise
	*/
	bool isValidCastle(const CastlingOptions& whatCastle);
	/*
	* Generates the possible moves of a specific piece
	*
	* @param index: The index of the piece in its array
	* @param pieceType: The type of piece it is
	*
	* @return A vector of all the possible moves
	*/
	std::vector<sf::Vector2f> genPieceMoves(const int& index, const TypeOfPiece& pieceType);
	/*
	* Checks if a king is in check
	*
	* @param color: The color king you are checking
	*
	* @return True if it is being checked and false otherwise
	*/
	bool isBeingChecked(const Color& color);
	/*
	* Checks if a specific piece is in the way of a check
	*
	* @param pieceType: The type of piece that you want to check
	* @param index: The index of that piece
	*
	* @return True if it is in the way of a check and fasle otherwise
	*/
	bool isInWayOfCheck(const TypeOfPiece& pieceType, const int& index);
	/*
	* Generates all the moves of a specific color without special moves
	*
	* @parm color: The color of the pieces you want to generate the moves for
	*
	* @return All the possible moves
	*/
	std::vector<sf::Vector2f> genAllBaseLevelMoves(const Color& color);
	/*
	* Figures out what piece is giving check
	*
	* @param color: the color of the piece that is giving check
	*
	* @return the index in positions where that piece could be found or -1 if there are two checks or if it is not in check
	*/
	int whatPieceIsChecking(const Color& color);
	/*
	* Determines if the game is over and if so prints the results
	*
	* @return None
	*/
	void gameEnd();
private:
	sf::RenderWindow* m_Window = new sf::RenderWindow;
	std::vector<Rook> whiteRooks;
	std::vector<Rook> blackRooks;

	std::vector<Knight> whiteKnights;
	std::vector<Knight> blackKnights;

	std::vector<Bishop> whiteBishops;
	std::vector<Bishop> blackBishops;

	std::vector<Pawn> whitePawns;
	std::vector<Pawn> blackPawns;

	std::vector<Queen> whiteQueens;
	std::vector<Queen> blackQueens;

	King* whiteKing;
	King* blackKing;
	sf::Event event;

	std::vector<sf::Vector2f> m_WhitePositions;
	std::vector<sf::Vector2f> m_BlackPositions;

	float m_SizeOfSquare;

	bool isWhiteTurn = true;
	int enPisantIndex = -1;

	bool isAI = false;
};

