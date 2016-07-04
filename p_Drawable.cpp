#include "p_Drawable.h"



void p_Drawable::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (circle == nullptr)
		target.draw(m_sprite);
	else
		target.draw(*circle);
}

void p_Drawable::update()
{
}

p_Drawable::p_Drawable(std::string texture)
{
	if (!m_texture.loadFromFile(texture))
		EXIT_FAILURE;
}

p_Drawable::p_Drawable(float radius, sf::Color color)
{
	circle = std::make_unique<sf::CircleShape>(radius);
	circle->setFillColor(color);
}

p_Drawable::p_Drawable() {
	
	//////////////////////////////////////////////////////////////////
	if (!m_texture.loadFromFile("default.png"))
		EXIT_FAILURE;
	m_sprite.setTexture(m_texture);
}

p_Drawable::~p_Drawable()
{
}
