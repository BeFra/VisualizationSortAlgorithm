#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "draw.hpp"

void draw(vector<int> &to_sort);

sf::VertexArray quad(sf::Quads,4);
sf::RenderWindow window(sf::VideoMode(600,800), "FSML works");

void draw(vector<int> &to_sort) {
	window.clear();
	for(int i = 0; i<to_sort.size(); i++) {
		int length = 30 * to_sort[i];
		quad[0].position = sf::Vector2f(((double)(i*10)+10.0),10);
		quad[1].position = sf::Vector2f(((i*10)+10.0),length);
		quad[2].position = sf::Vector2f(((i*10)+20.0),length);
		quad[3].position = sf::Vector2f(((i*10)+20.0),10);
		window.draw(quad);
	}
	window.display();
	sleep(1);
}
