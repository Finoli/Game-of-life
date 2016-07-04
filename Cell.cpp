#include "Cell.h"
#include "SFML\Graphics.hpp"
#include "indexes.h"
#include <iostream>
#include <vector>


//Get the indexes in the grid that a given cell should check (Checking number of neighbours that are alive)
//Poorly optimized function
std::vector<Indexes> GetIndexes(int row, int column, int gridHeigth, int gridWidth) {
	std::vector<Indexes> indexes;
	Indexes index;
	index.col = column;
	index.row = row;
	if ((row > -1 && row < gridHeigth) && (column > -1 && column < gridWidth))
	{
		
		index.row--;
		index.col--;
		indexes.push_back(index);
		index.col++;
		indexes.push_back(index);
		index.col++;
		indexes.push_back(index);

		index.row++;
		index.col -= 2;
		indexes.push_back(index);
		index.col += 2;
		indexes.push_back(index);

		index.row++;
		index.col -= 2;
		indexes.push_back(index);
		index.col++;
		indexes.push_back(index);
		index.col++;
		indexes.push_back(index);
	}

	//for (int i = 0; i < gridHeigth; i++)
	//{
	//	if (indexes[i].row < 0 || indexes[i].row > gridHeigth ||
	//		indexes[i].col < 0 || indexes[i].col > gridWidth)
	//	{
	//		indexes.erase(indexes.begin()+i);
	//	}
	//	else i++;
	//}
	int i = 0;
	while (i != indexes.size())
	{
		if ((indexes[i].row + row < 0 || indexes[i].col + column < 0) || (indexes[i].row + row >= gridHeigth || indexes[i].col + column >= gridWidth))
		{
			indexes.erase(indexes.begin() + i);
		}
		else i++;
	}


	return indexes;


}

//Constructor
Cell::Cell(float radius, sf::Color color) : p_Drawable(radius, color)
{
	
}

//draw function
void Cell::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*circle);
}

Cell::Cell()
{
}
Cell::~Cell()
{
}

//Update the cell
void Cell::update(std::vector<std::vector<Cell>> & read_grid,std::vector<std::vector<Cell>> & write_grid)
{
	checkNeighbours(read_grid, write_grid);
}

//move function, used during grid creation
void Cell::move(sf::Vector2f vector)
{
	this->circle->move(vector);
}

//get and check indexes, kill or revive cell depending on number of live neighbours
int Cell::checkNeighbours(std::vector<std::vector<Cell>>& read_grid, std::vector<std::vector<Cell>> & write_grid)
{
	int m_row = index.row;
	int m_col = index.col;
	liveNeigbours = 0;
	std::vector<Indexes> indexes = GetIndexes(m_row, m_col, read_grid.size(), read_grid[0].size());


	
	for (auto& i : indexes)
	{
		
		if (read_grid[i.row][i.col].isAlive)
		{
			liveNeigbours++;
		}
	}

	if (liveNeigbours > 3)
	{
		write_grid[m_col][m_row].isAlive = false;
		write_grid[m_col][m_row].circle->setFillColor(sf::Color::Black);
	}

	else if (liveNeigbours == 3 || liveNeigbours == 2)
	{
		write_grid[m_col][m_row].isAlive = true;
		write_grid[m_col][m_row].circle->setFillColor(sf::Color::Yellow);
	}

	else if (liveNeigbours < 2)
	{
		write_grid[m_col][m_row].isAlive = false;
		write_grid[m_col][m_row].circle->setFillColor(sf::Color::Black);
	}

	else
	{
		write_grid[m_col][m_row].isAlive = read_grid[m_col][m_row].isAlive;
	}
	return liveNeigbours;
}

 