#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include "C:\Users\elle_\OneDrive\Dokument\Visual Studio 2015\SFML-2.3.2\include\SFML\Graphics\Drawable.hpp"

#define MOVE_ONLY(T)                                                           \
  T(T const&) = delete;                                                        \
  T& operator=(T const&) = delete;                                             \
  T(T&&) = default;                                                            \
  T& operator=(T&&) = default;


class p_Drawable :
	public sf::Drawable
{
protected:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	std::unique_ptr<sf::CircleShape> circle;
public:

	MOVE_ONLY(p_Drawable)
	
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update();
	p_Drawable(std::string texture);
	p_Drawable(float radius, sf::Color color);

	p_Drawable();
	~p_Drawable();
};

