#include "MarkerDisplay.h"

MarkerDisplay::MarkerDisplay(BoardArray& board)
	: board(board)
{
	x_Texture.loadFromFile("Assets/X.png");
	o_Texture.loadFromFile("Assets/O.png");
}
