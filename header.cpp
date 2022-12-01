#include "header.h"
// файл с функциями структур, проверка уровня персонажа, работа с инвентарем
int Class::inventar(RenderWindow& window, Texture Background, Sprite sprite, Font font) {
	Text text_potion_selection("Choose which potion you want to use", font, 18);
	Text text_zelyeHP("Potion HP", font, 18);
	Text text_zelyeDamege("Potion Power", font, 18);
	Text text_zelyeDexterity("Potion Dexterity", font, 18);
	Text text_zelyeIntelekt("Potion Intelligence", font, 18);

	text_potion_selection.setPosition(550, 210);
	text_zelyeHP.setPosition(550, 240);
	text_zelyeDamege.setPosition(550, 270);
	text_zelyeDexterity.setPosition(550, 300);
	text_zelyeIntelekt.setPosition(550, 330);

	bool close = true;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				close = Window_close(window, Background, sprite, font);
				if (close == false) {
					window.close();
					exit;
				}
			}
			if (IntRect(550, 270, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					if (zelyeHP > 0) {
						currentHP += 50;
						zelyeHP--;
						return zelyeHP;
					}
					else {
						return zelyeHP;
					}

				}
			}
			if (IntRect(550, 300, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					if (zelyeDamege > 0) {
						power += 10;
						zelyeDamege--;
						return zelyeDamege;
					}
					else {
						return zelyeDamege;
					}
					

				}
			}
			if (IntRect(550, 330, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					if (zelyeDexterity > 0) {
						dexterity += 10;
						zelyeDexterity--;
						return zelyeDexterity;
					}
					else {
						return zelyeDexterity;
					}

				}
			}
			if (IntRect(550, 360, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					if (zelyeIntelekt > 0) {
						intelligence += 10;
						zelyeIntelekt--;
						return zelyeIntelekt;
					}
					else {
						return zelyeIntelekt;
					}
					

				}
			}

			window.clear();
			window.draw(text_potion_selection);
			window.draw(text_zelyeHP);
			window.draw(text_zelyeDamege);
			window.draw(text_zelyeDexterity);
			window.draw(text_zelyeIntelekt);
			window.display();
		}
	}
	
}



int Class::levelsystem(RenderWindow& window, Texture Background, Sprite sprite, Font font) {

	Text text_str_inprove("Choose what you want to improve", font, 18);
	Text text_str_maxHP("Max HP", font, 18);
	Text text_str_power("Power", font, 18);
	Text text_str_inteloligence("Intelligence", font, 18);
	Text text_str_dexterity("Dexterity", font, 18);

	text_str_inprove.setPosition(550, 240);
	text_str_maxHP.setPosition(550, 270);
	text_str_power.setPosition(550, 300);
	text_str_inteloligence.setPosition(550, 330);
	text_str_dexterity.setPosition(550, 360);

	bool close = true;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				close = Window_close(window, Background, sprite, font);
				if (close == false) {
					window.close();
					exit;
				}
			}
			if (IntRect(550, 270, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
				
					maxHP += 50;
					currentHP = maxHP;
					return maxHP, currentHP;

				}
			}
			if (IntRect(550, 300, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					power += 1;
					return power;

				}
			}
			if (IntRect(550, 330, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					intelligence += 1;
					return intelligence;

				}
			}
			if (IntRect(550, 360, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					dexterity += 1;
					return dexterity;

				}
			}

			window.clear();
			window.draw(text_str_inprove);
			window.draw(text_str_maxHP);
			window.draw(text_str_power);
			window.draw(text_str_inteloligence);
			window.draw(text_str_dexterity);
			window.display();
		}
	}
}

int Class::gainexp(int currentexp, int gained_exp) {//получение опыта
	currentexp = currentexp + gained_exp;
	return currentexp;
}
void Class::check_level(int currentlevel, int currentexp, int maxexp, RenderWindow& window, Texture Background, Sprite sprite, Font font) { //проверка на повышение уровня
	while (currentexp >= maxexp) {
		currentlevel++;
		currentexp = 1;
		maxexp = maxexp * 1.5;
		levelsystem(window, Background, sprite, font);
	}

}
