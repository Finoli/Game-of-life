#include "Grid.h"
#include "Cell.h"



Grid::Grid()
{

}

//Constructor
Grid::Grid(int width, int heigth, float cellSize)
{
	int hori_cells =	(width / cellSize)/2;
	int verti_cells = (heigth / cellSize)/2;

	sf::Vector2f vec = { 0.0f,0.0f };
	
	for (int i = 0; i < verti_cells; i++)
	{
		vec.y = i * cellSize * 2;
		_currentGrid.push_back(std::vector<Cell>());
		for (int j = 0; j < hori_cells; j++)
		{
			vec.x = j * cellSize * 2;
			_currentGrid[i].push_back(Cell(cellSize, sf::Color(50,50,50,255)));
			_currentGrid[i][j].move(vec);
			_currentGrid[i][j].index.col = i;
			_currentGrid[i][j].index.row = j;



		}
	}
}


Grid::~Grid()
{
}
