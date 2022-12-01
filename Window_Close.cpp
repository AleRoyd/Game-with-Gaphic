#include "header.h"
// функция которая спрашивает пользователя, хочет ли он закрыть окно или нет
bool Window_close(RenderWindow& window, Texture Background, Sprite sprite, Font font) {
	Text text_exit("Do you want to exit the game?", font, 18);
	Text text_exit_yes("Yes", font, 18);
	Text text_exit_no("No", font, 18);
	text_exit.setPosition(500, 250);
	text_exit_yes.setPosition(500, 280);
	text_exit_no.setPosition(500, 310);
	
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (IntRect(500, 280, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					return false;
				}
			}
			if (IntRect(500, 310, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					return true;
				}
			}
			if (event.type == Event::Closed) {
				window.close();
				exit;

			}
			window.clear();
			window.draw(text_exit);
			window.draw(text_exit_yes);
			window.draw(text_exit_no);
			window.display();
		}
		
	}
	window.close();
}