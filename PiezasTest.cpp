/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, firstDropX) {
	Piezas board;
	Piece check = board.dropPiece(0);
	ASSERT_EQ(X, check);
}

TEST(PiezasTest, firstDropO) {
	Piezas board;
	board.dropPiece(0);
	Piece check = board.dropPiece(1);
	ASSERT_EQ(O, check);
}

TEST(PiezasTest, secondDropX) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(1);
	Piece check = board.dropPiece(2);
	ASSERT_EQ(X, check);
}

TEST(PiezasTest, secondDropO) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	Piece check = board.dropPiece(1);
	ASSERT_EQ(O, check);
}

TEST(PiezasTest, fullColumn) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	Piece check = board.dropPiece(0);
	ASSERT_EQ(Blank, check);
}

TEST(PiezasTest, OOBtestLeft) {
	Piezas board;
	Piece check = board.dropPiece(-1);
	ASSERT_EQ(Invalid, check);
}

TEST(PiezasTest, OOBtestRight) {
	Piezas board;
	Piece check = board.dropPiece(7);
	ASSERT_EQ(Invalid, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, fillBoardLastO) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.dropPiece(3);
	ASSERT_EQ(O, check);
}

/**
 * 2 [X][X][O][X]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, fillBoardLastX) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(2);
	Piece check = board.dropPiece(3);
	ASSERT_EQ(X, check);
}

/**
 * 2 [X][ ][ ][ ]
 * 1 [O][O][ ][ ]
 * 0 [X][O][ ][ ]
 *    0  1  2  3
 * 
 * X Lose Turn filling column 1
**/
TEST(PiezasTest, LoseTurnX) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(0);
	Piece check = board.dropPiece(1);
	ASSERT_EQ(O, check);
}

/**
 * 2 [X][X][ ][ ]
 * 1 [O][O][ ][ ]
 * 0 [X][O][X][ ]
 *    0  1  2  3
 * 
 * O Lose Turn filling column
**/
TEST(PiezasTest, LoseTurnO) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	Piece check = board.dropPiece(2);
	ASSERT_EQ(X, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPiece00) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(0,0);
	ASSERT_EQ(X, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPiece01) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(0,1);
	ASSERT_EQ(X, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPiece02) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(0,2);
	ASSERT_EQ(O, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPiece03) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(0,3);
	ASSERT_EQ(O, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPiece10) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(1,0);
	ASSERT_EQ(O, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPiece11) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(1,1);
	ASSERT_EQ(O, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPiece12) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(1,2);
	ASSERT_EQ(X, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPiece13) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(1,3);
	ASSERT_EQ(X, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPiece20) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(2,0);
	ASSERT_EQ(X, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPiece21) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(2,1);
	ASSERT_EQ(X, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPiece22) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(2,2);
	ASSERT_EQ(O, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPiece23) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(2,3);
	ASSERT_EQ(O, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPieceOOBrowLeft) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(-2,3);
	ASSERT_EQ(Invalid, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPieceOOBrowRight) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(23,3);
	ASSERT_EQ(Invalid, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPieceOOBcolumnLeft) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(2,-3);
	ASSERT_EQ(Invalid, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, getPieceOOBcolumnRight) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.pieceAt(2,13);
	ASSERT_EQ(Invalid, check);
}

TEST(PiezasTest, resetBoard) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	board.reset();
	Piece check = board.pieceAt(2,3);
	ASSERT_EQ(Blank, check);
}

/**
 * 2 [X][X][O][]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, gameStateIncomplete) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.gameState();
	ASSERT_EQ(Invalid, check);
}

/**
 * 2 [X][X][O][O]
 * 1 [O][O][X][X]
 * 0 [X][X][O][O]
 *    0  1  2  3
**/
TEST(PiezasTest, gameStateTie) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	Piece check = board.gameState();
	ASSERT_EQ(Blank, check);
}

/**
 * 2 [X][X][O][X]
 * 1 [O][O][O][O]
 * 0 [X][O][X][X]
 *    0  1  2  3
**/
TEST(PiezasTest, gameStateOwins) {
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(2);
	Piece check = board.gameState();
	ASSERT_EQ(O, check);
}

/**
 * 2 [O][X][X][X]
 * 1 [X][O][X][O]
 * 0 [X][O][X][O]
 *    0  1  2  3
**/
TEST(PiezasTest, gameStateXwins) {
	Piezas board;
	board.dropPiece(0); //X
	board.dropPiece(1); //O
	board.dropPiece(0); //X
	board.dropPiece(1); //O
	board.dropPiece(2); //X
	board.dropPiece(0); //O
	board.dropPiece(2); //X
	board.dropPiece(3); //O
	board.dropPiece(2); //X
	board.dropPiece(3); //O
	board.dropPiece(1); //X
	board.dropPiece(0); //O
	board.dropPiece(2); //X
	board.dropPiece(2); //O
	board.dropPiece(3); //X
	Piece check = board.gameState();
	ASSERT_EQ(X, check);
}

