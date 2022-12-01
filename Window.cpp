#include "header.h"
void OknoIgri() { // функция создания окна для битвы, передается функция локации, в которой происходят все сражения, создаются графические объекты
	//создаются объекты структур которые передаются в функции создания персонажа и в функцию локации
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Game");


	sf::Texture Background;
	sf::Sprite sprite;
	sf::Font font;

	Class person;
	Agr MONSTER = {"nach", 0, 0, 0, 0};

	Background.loadFromFile(("G:\\Progects\\Game\\Game\\Background.jpg"));
	if (!Background.loadFromFile(("G:\\Progects\\Game\\Game\\Background.jpg")))
		cout << "image is not open";

	
	font.loadFromFile("Inconsolata[wdth,wght].ttf");
	
	person = Personag(window, Background, sprite, font);
	pyt1(person, MONSTER, window, Background, sprite, font);


}

