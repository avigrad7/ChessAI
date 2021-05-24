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
	struct PieceAndMoves
	{
		PieceAndMoves(int whatPiece, std::vector<sf::Vector2f> allMoves)
		{
			piece = whatPiece;
			moves = allMoves;
		}
		int piece;
		std::vector<sf::Vector2f> moves;
	};
public:
	/*
	* Checks if the positions is check mate
	* 
	* @param color: The color of the pieces that you want to see if it is check mate of
	* @param howManyWhitePawns: How many white pawns that have not been promoted
	* @param howManyBlackPawns: How many black pawns that have not been promoted
	* @param whitePos: a vector of white positions
	* @param blackPos: a vector of black positions
	* 
	* @return True if it is check mate and false otherwise
	*/
	bool isCheckMate(Color color, int howManyWhitePawns, int howManyBlackPawns, std::vector<sf::Vector2f>& whitePos, std::vector<sf::Vector2f>& blackPos);
	/*
	* Checks if the positions is stale mate
	*
	* @param color: The color of the pieces that you want to see if it is check mate of
	* @param howManyWhitePawns: How many white pawns that have not been promoted
	* @param howManyBlackPawns: How many black pawns that have not been promoted
	* @param whitePos: a vector of white positions
	* @param blackPos: a vector of black positions
	*
	* @return True if it is stale mate and false otherwise
	*/
	bool isStaleMate(Color color, int howManyWhitePawns, int howManyBlackPawns, std::vector<sf::Vector2f>& whitePos, std::vector<sf::Vector2f>& blackPos);
	/*
	* Determines if the white king has moved
	* 
	* @return True if it has moved and false otherwise
	*/
	bool hasWhiteKingMoved() { return whiteKing->hasBeenMoved(); }
	/*
	* Determines if the black king has moved
	*
	* @return True if it has moved and false otherwise
	*/
	bool hasBlackKingMoved() { return blackKing->hasBeenMoved(); }
	/*
	* Determines if the white rook[0] has been moved
	*
	* @return True if it has and false otherwise
	*/
	bool hasWhiteRooks0Moved() { return whiteRooks[0].hasBeenMoved(); }
	/*
	* Determines if the white rook[1] has been moved
	*
	* @return True if it has and false otherwise
	*/
	bool hasWhiteRooks1Moved() { return whiteRooks[1].hasBeenMoved(); }
	/*
	* Determines if the black rook[0] has been moved
	*
	* @return True if it has and false otherwise
	*/
	bool hasBlackRooks0Moved() { return blackRooks[0].hasBeenMoved(); }
	/*
	* Determines if the black rook[1] has been moved
	*
	* @return True if it has and false otherwise
	*/
	bool hasBlackRooks1Moved() { return blackRooks[1].hasBeenMoved(); }
	/*
	* Gets how many white pawns
	* 
	* @return How many white pawns have not been promoted
	*/
	int getSizeWhitePawns() { return whitePawns.size(); }
	/*
	* Gets how many black pawns
	*
	* @return How many black pawns have not been promoted
	*/
	int getSizeBlackPawns() { return blackPawns.size(); }
	/*
	* Generates a vector of moves and what piece could move there
	* 
	* @param color: The color of the pieces that you want to generate the moves of
	* @param howManyWhitePawns: How many white pawns that have not been promoted
	* @param howManyBlackPawns: How many black pawns that have not been promoted
	* @param whitePos: a vector of white positions
	* @param blackPos: a vector of black positions
	* @param whiteRooksHaveMoved: An array of weather or not the white rooks have moved
	* @param blackRooksHaveMoved: An array of weather or not the black rooks have moved
	* @param whiteKingHasMoved: Weather or not the white king has moved
	* @param blackKingHasMoved: Weather or not the black king has moved
	* 
	* @retun An array of moves and their piece
	*/
	std::vector<PieceAndMoves> genAllMovesAndTheirPiece(Color color, int howManyWhitePawns, int howManyBlackPawns, std::vector<sf::Vector2f>& whitePos, std::vector<sf::Vector2f>& blackPos, bool* whiteRooksHaveMoved, bool* blackRooksHaveMoved, bool whiteKingHasMoved, bool blackKingHasMoved);

	/*
	* Gets if it is white's turn
	* 
	* @return True if it is white's turn and false if not
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
	void movePieceAndSetPosition(Color color, int indexInPositions, const sf::Vector2f& moveTo);
	/*
	* Simulates moving a piece to a new place on the board and sets it's position
	*
	* @param color: the color of piece you are moving
	* @param howManyWhitePawns: The amount of white pawns
	* @param howManyBlackPawns: The amount of black pawns
	* @param whiteRookHasMooved: An array of bools of weather or not the white rooks have moved
	* @param blackRookHasMooved: An array of bools of weather or not the black rooks have moved
	* @param whiteKingHasMoved: a bool of weather or not the white king has moved
	* @param blackKingHasMoved: a bool of weather or not the black king has moved
	* @param indexInPositions: the index where the piece is in positions array
	* @param moveTo: The place you the piece to move (1 -8 , 1 - 8)
	* @param whitePos: A vector of white positions
	* @param blackPos: A vector of black positions
	*
	* @return None
	*/
	void simulateMovingAPiece(Color color, int& howManyWhitePawns, int& howManyBlackPawns, bool (&whiteRookHasMoved)[2], bool (&blackRookHasMoved)[2], bool& whiteKingHasMoved, bool& blackKingHasMoved, int indexInPositions, const sf::Vector2f& moveTo, std::vector<sf::Vector2f>& whitePos, std::vector<sf::Vector2f>& blackPos);
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
	/*
	* Returns if the game is over or not
	* 
	* @return True if the game has ended; false otherwise
	*/
	bool isGameEnd();
	/*
	* Tells the game that it is an AI playing
	* 
	* @retun None
	*/
	void setAI() { isAI = true; }
private:
	/*
	* Checks if a king is in check
	*
	* @param color: The color king you are checking
	* @param whitePos: A vector of white positions
	* @param blackPos: A vector of black positions
	* @param howManyWhitePawns: How many white pawns have not been promoted
	* @param howManyBlackPawns: How many black pawns have not been promoted
	*
	* @return True if it is being checked and false otherwise
	*/
	bool isBeingChecked(const Color& color, std::vector<sf::Vector2f>& whitePos, std::vector<sf::Vector2f>& blackPos, int howManyWhitePawns, int howManyBlackPawns);
	/*
	* Generates all possible moves
	*
	* @param color: The color of the pices you want to generate the moves of
	*
	* @return An array of all possible moves
	*/
	std::vector<sf::Vector2f> genAllMoves(const Color& color);
	/*
	* Generates the possible moves of a specific piece
	*
	* @param index: The index of the piece in its array
	* @param pieceType: The type of piece it is
	* @param whitePos: A vector of white positions
	* @param blackPos: A vector of black positions
	* @param howManyWhitePawns: How many white pawns have not been promoted
	* @param howManyBlackPawns: How many black pawns have not been promoted
	* @param whiteRooksHaveMoved: An array of weather or not the white rooks have moved
	* @param blackRooksHaveMoved: An array of weather or not the wblack rooks have moved
	* @param whiteKingHasMoved: Weather or not the white king has moved
	* @param blackKingHasMoved: Weather or not the black king has moved
	* 
	* @return A vector of all the possible moves
	*/
	std::vector<sf::Vector2f> genPieceMoves(const int& index, const TypeOfPiece& pieceType, std::vector<sf::Vector2f>& whitePos, std::vector<sf::Vector2f>& blackPos, int howManyWhitePawns, int howManyBlackPawns, bool* whiteRooksHaveMoved, bool* blackRooksHaveMoved, bool whiteKingHasMoved, bool blackKingHasMoved);
	/*
	* Castles for a specific castle
	*
	* @param whatCastle: The type of castle and color of castle that you want to preform
	*
	* @return None
	*/
	void castle(const CastlingOptions& whatCastle);
	/*
	* Checks if a move is an en pisant and if so takes the piece
	*
	* @param color: The color of the piece you are taking with
	* @param moveTo: Where the piece is moving to
	*
	* @return None
	*/
	void EnPisant(Color color, sf::Vector2f moveTo);
	/*
	* Determines if a given castle is valid
	*
	* @param whatCastle: The type of castle you are checking
	* @param whitePos: A vector of white positions
	* @param blackPos: A vector of black positions
	* @param howManyWhitePawns: The number of unpromoted white pawns
	* @param howManyBlackPawns: The number of unpromoted black pawns
	* @param whiteRooksHaveMoved: An array of weather or not the white rooks have moved
	* @param blackRooksHaveMoved: An array of weather or not the black rooks have moved
	* @param whiteKingHasMoved: Weather or not the white king has moved
	* @param blackKingHasMoved: Weather or not the black king has moved
	*
	* @return True if it is a valid castle. Fasle otherwise
	*/
	bool isValidCastle(const CastlingOptions& whatCastle, std::vector<sf::Vector2f> whitePos, std::vector<sf::Vector2f> blackPos, int howManyWhitePawns, int howManyBlackPawns, bool* whiteRooksHaveMoved, bool* blackRooksHaveMoved, bool whiteKingHasMoved, bool blackKingHasMoved);
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
	* @param event: The event
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
	* Checks if a specific piece is in the way of a check
	*
	* @param pieceType: The type of piece that you want to check
	* @param index: The index of that piece
	* @param whitePos: A vector of white positions
	* @param blackPos: A vector of black positions
	* @param howManyWhitePawns: How many white pawns have not been promoted
	* @param howManyBlackPawns: How many black pawns have not been promoted
	*
	* @return True if it is in the way of a check and fasle otherwise
	*/
	bool isInWayOfCheck(const TypeOfPiece& pieceType, const int& index, std::vector<sf::Vector2f>& whitePos, std::vector<sf::Vector2f>& blackPos, int howManyWhitePawns, int howManyBlackPawns);
	/*
	* Generates all the moves of a specific color without special moves
	*
	* @param color: The color of the pieces you want to generate the moves for
	* @param whitePos: A vector of white positions
	* @param blackPos: A vector of black positions
	* @param howManyWhitePawns: How many white pawns have not been promoted
	* @param howManyBlackPawns: How many black pawns have not been promoted
	*
	* @return All the possible moves
	*/
	std::vector<sf::Vector2f> genAllBaseLevelMoves(const Color& color, std::vector<sf::Vector2f>& whitePos, std::vector<sf::Vector2f>& blackPos, int howManyWhitePawns, int howManyBlackPawns);
	/*
	* Figures out what piece is giving check
	*
	* @param color: the color of the piece that is giving check
	* @param whitePos: A vector of the white positions
	* @param blackPos: A vector of the black positions
	* @param howManyWhitePawns: How many white pawns that have not been promoted
	* @param howManyBlackPawns: How many black pawns that have not been promoted
	*
	* @return the index in positions where that piece could be found or -1 if there are two checks or if it is not in check
	*/
	int whatPieceIsChecking(const Color& color, std::vector<sf::Vector2f>& whitePos, std::vector<sf::Vector2f>& blackPos, int howManyWhitePawns, int howManyBlackPawns);
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

