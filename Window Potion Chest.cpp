#include "header.h"
// функция востановления зелий персонажа
Class Window_Potion_Chest(Class personage, RenderWindow& window, Texture Background, Sprite sprite, Font font) {
	srand(time(NULL));
	string str;

	Text text_Potion_Chest;
	Text text_inventar("Potions in inventory:", font, 18);
	Text text_move_on("Move on", font, 18);

	text_Potion_Chest.setPosition(600, 200);
	text_inventar.setPosition(500,200);
	text_move_on.setPosition(500, 310);

	int random_zelye = rand() % 4;
	switch (random_zelye)
	{
	case 0:
		personage.zelyeHP += 3;
		text_Potion_Chest.setString(to_string(personage.zelyeHP));
		break;
	case 1:
		personage.zelyeDamege += 3;
		text_Potion_Chest.setString(to_string(personage.zelyeDamege));
		break;
	case 2:
		personage.zelyeDexterity += 3;
		text_Potion_Chest.setString(to_string(personage.zelyeDexterity));
		break;
	case 3: 
		personage.zelyeIntelekt += 3;
		text_Potion_Chest.setString(to_string(personage.zelyeIntelekt));
		break;
	}

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed) {
				window.close();

			}

			if (IntRect(500, 310, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					return personage;
				}
			}
			window.clear();
			window.draw(text_Potion_Chest);
			window.draw(text_inventar);
			window.draw(text_move_on);

			window.display();
		}

	}
	window.close();
}