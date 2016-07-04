#pragma once
#include "p_Drawable.h"
#include "indexes.h"
#define MOVE_ONLY(T)                                                           \
  T(T const&) = delete;                                                        \
  T& operator=(T const&) = delete;                                             \
  T(T&&) = default;                                                            \
  T& operator=(T&&) = default;

class Cell :
	public p_Drawable
{
private:
	Indexes index;

	bool isAlive;
	int liveNeigbours;


public:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	friend class Grid;
	MOVE_ONLY(Cell)

	Cell();
	Cell(float radius, sf::Color color);
	~Cell();
	void update(std::vector<std::vector<Cell>> & read_grid, std::vector<std::vector<Cell>> &write_grid);
	void move(sf::Vector2f vector);
	int checkNeighbours(std::vector<std::vector<Cell>>& read_grid, std::vector<std::vector<Cell>> & write_grid);

};

