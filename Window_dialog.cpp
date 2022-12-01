#include "header.h"
// не реализованная функция отображения диалога персонажа. передается строка, которая отображается в окне и продолжается игра
bool Window_dialog(RenderWindow& window, Texture Background, Sprite sprite, Font font, string str) {
	Text text_dialog(str, font, 18);
	Text text_move_on("Move on", font, 18);
	
	text_dialog.setPosition(500, 200);
	text_move_on.setPosition(500, 310);


	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			
			if (event.type == Event::Closed) {
				window.close();

			}
			
			if (IntRect(500, 310, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					return false;
				}
			}
			window.clear();
			window.draw(text_dialog);
			window.draw(text_move_on);
			
			window.display();
		}

	}
	window.close();
}