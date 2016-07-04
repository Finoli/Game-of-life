#pragma once

#define MOVE_ONLY(T)                                                           \
  T(T const&) = delete;                                                        \
  T& operator=(T const&) = delete;                                             \
  T(T&&) = default;                                                            \
  T& operator=(T&&) = default;

#include <vector>
#include "Cell.h"
#include "p_Drawable.h"


class Grid
{
public:
	//std::vector<std::vector<Cell>> _predictedGrid;
	std::vector<std::vector<Cell>> _currentGrid;
	//MOVE_ONLY(Grid)

public:
	Grid();
	Grid(int width, int heigth, float cellSize);
	~Grid();
};

