#pragma once
#include "SFML\Graphics.hpp"
#include "p_Physical.h"
#include "Grid.h"
#include <memory>

enum GameState {
		Uninitialized,
		ShowingSplash,
		Paused,
		ShowingMenu,
		Playing,
		Exiting
	};



class Game {

public:
	Game();
	void Start();
private:
	sf::Clock clock;
	GameState _gameState;
	sf::RenderWindow _mainWindow;

		
	bool IsExiting();
	void GameLoop();
	void Draw();
	void Update(sf::Event currentEvent);
	void switchGrids();
	
	//Entities
	std::vector<p_Physical> rigidbody;
	std::vector<Cell> circles;
	std::unique_ptr<Grid> grid1;
	std::unique_ptr<Grid> grid2;
	Grid* writeTo;
	Grid* readFrom;
	std::unique_ptr<Cell> cell;
};

