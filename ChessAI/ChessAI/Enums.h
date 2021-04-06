#pragma once
enum class TypeOfPiece
{
	WhiteRook = 0,
	BlackRook,
	WhiteBishop,
	BlackBishop,
	WhiteKnight,
	BlackKnight,
	WhitePawn,
	BlackPawn,
	WhiteQueen,
	BlackQueen,
	WhiteKing,
	BlackKing,
	none
};

enum class Color
{
	White = 0,
	Black
};

enum class CastlingOptions
{
	bigWhite = 0,
	smallWhite,
	bigBlack,
	smallBlack
};
