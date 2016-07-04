#pragma once
#include "Game.h"
#include "SFML\Graphics.hpp"
#include <iostream>
#include "p_Physical.h"
#include <memory>




Game::Game() {
	_gameState = Uninitialized;
	
}

void Game::Start()
{
	if (_gameState != Uninitialized)
		return;
	
	//Create main window
	_mainWindow.create(sf::VideoMode(1280, 720, 32), "Game of Life");

	sf::Vector2u temp;
	temp = _mainWindow.getSize();
	//initialize grids based on window size
	grid1 = std::make_unique<Grid>(temp.x, temp.y, 10.0f);
	grid2 = std::make_unique<Grid>(temp.x, temp.y, 10.0f);

	//Pointers to grids. These are used to tell the update and draw functions
	//which grid to draw and write from
	writeTo = grid1.get();
	readFrom = grid2.get();


	_gameState = Playing;


	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting() {
	if (_gameState == Exiting)
		return true;
	else return false;	
}

void Game::GameLoop() {
	
	sf::Event currentEvent;

	while (_mainWindow.pollEvent(currentEvent))
	{
		switch (_gameState)
		{
			case Playing:
			{
				//clear the window
				_mainWindow.clear();
				//draw the stuff to the window
				Draw();

				//switch the Grid pointers
				switchGrids();

				//currently not using Update()
				Update(currentEvent);

				if (currentEvent.type == sf::Event::Closed)
				{
					_gameState = Exiting;
				}

				//Display the window
				_mainWindow.display();

				break;
			}
		}
	}
}

void Game::Draw()
{
	//Draw and update grids
	for (auto& i : readFrom->_currentGrid)
	{
		for (auto& j : i)
		{
			j.update(readFrom->_currentGrid, writeTo->_currentGrid);
			_mainWindow.draw(j);
		}
	}
}

void Game::Update(sf::Event currentEvent)
{

}

void Game::switchGrids()
{
	//WriteTo gets adress from ReadFrom and vice versa
	Grid* temp = writeTo;
	writeTo = readFrom;
	readFrom = temp;
}

