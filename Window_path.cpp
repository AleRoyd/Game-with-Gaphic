#include "header.h"

// функция выбора пути
int Window_path(RenderWindow& window, Texture Background, Sprite sprite, Font font, int choise_of_path) {
	string path_one = "Go right";
	string path_two = "Go left";
	string path_three = "Go straight";



	Text text_path_one(path_one, font, 18);
	Text text_path_two(path_two, font, 18);
	Text text_path_three(path_three, font, 18);

	text_path_one.setPosition(600, 270);



	text_path_two.setPosition(600, 300);



	text_path_three.setPosition(600, 330);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				Window_close(window, Background, sprite, font);
			}


			if (IntRect(600, 270, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					choise_of_path = 1;
					return choise_of_path;

				}
			}

			if (IntRect(600, 300, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					choise_of_path = 2;
					return choise_of_path;

				}
			}

			if (IntRect(600, 330, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					choise_of_path = 3;
					return choise_of_path;

				}
			}


			window.clear();
			window.draw(sprite);
			window.draw(text_path_one);
			window.draw(text_path_two);
			window.draw(text_path_three);
			window.display();

		}
	}
	

	
	
}