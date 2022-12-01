#include "Header.h"

// файл с функциями структуры создания персонажа и боя
Class Personag(RenderWindow& window, Texture Background, Sprite sprite, Font font) {
	
	string character_variant = "Выберите персонажа";
	string Wizard = "Wizard";
	string Archer = "Archer";
	string Thief = "Thief";
	string Warrior = "Warrior";

	sf::Text text_character_variant(character_variant, font, 18);
	sf::Text text_Wizard(Wizard, font, 18);
	sf::Text text_Archer(Archer, font, 18);
	sf::Text text_Thief(Thief, font, 18);
	sf::Text text_Warrior(Warrior, font, 18);

	text_Wizard.setPosition(600, 240); //первое значение Х - по горизонтали, второе У - по вертикале
	text_Archer.setPosition(600, 270);
	text_Thief.setPosition(600, 300);
	text_Warrior.setPosition(600, 330);
	bool close = true;
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {

			// закрытие приложения

			if (event.type == sf::Event::Closed) {
				close = Window_close(window, Background, sprite, font);
				if (close == false) {
					window.close();
					exit;
				}
				

			}

		}
		//IntRect (верхний левый угол по X, верхний левый угол по Y, размер по ширине, размер по высоте) эта функция рисует прямоугольник, и я заебался его редактировать

		if (IntRect(600, 240, 60, 25).contains(Mouse::getPosition(window))) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				text_Wizard.setFillColor(Color::Red);
				text_Wizard.setStyle(Text::Bold);

				Class personag = { "wizard", 300, 100, 100, 8, 18, 8, 10, 10, 10, 10, 1, 10 };
				/*cout << Wizard;*/
				return personag;
			}
		}

		if (IntRect(600, 270, 60, 25).contains(Mouse::getPosition(window))) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				text_Archer.setFillColor(Color::Red);
				text_Archer.setStyle(Text::Bold);
				Class personag = { "archer", 100,100,1,1,12,8,18,0,0,0,0,0 };
				/*cout << Archer;*/
				return personag;
			}
		}

		if (IntRect(600, 300, 60, 25).contains(Mouse::getPosition(window))) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				text_Thief.setFillColor(Color::Red);
				text_Thief.setStyle(Text::Bold);
				Class personag = { "thief", 80,80,1,1,6,12,20,0,0,0,0,0 };
				/*cout << Thief;*/
				return personag;
			}
		}

		if (IntRect(600, 330, 60, 25).contains(Mouse::getPosition(window))) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				text_Warrior.setFillColor(Color::Red);
				text_Warrior.setStyle(Text::Bold);
				Class personag = { "warrior", 300,150,150,18,8,12,0,0,0,0,1,0 };
				/*cout << Warrior;*/
				return personag;
			}
		}


		window.clear();
		window.draw(sprite);
		window.draw(text_Archer);
		window.draw(text_Wizard);
		window.draw(text_Thief);
		window.draw(text_Warrior);
		window.display();
		}
	window.close();
	}



Class battle(Class personage, Agr mob, RenderWindow& window, Texture Background, Sprite sprite, Font font) {

	/// <BATTLE TEXT> ///
	

	string what_do_u_want = "What do you want to do?";
	string kick = "Hit";
	string dodge = "Dodge";
	string magic_strike = "Magic strike";
	string escape_from_battle = "Escape from battle";
	string use_inventory = "Use inventory";

	sf::Text text_what_do_u_want(what_do_u_want, font, 22);
	sf::Text text_kick(kick, font, 18);
	sf::Text text_dodge(dodge, font, 18);
	sf::Text text_magic_strike(magic_strike, font, 18);
	sf::Text text_escape_from_battle(escape_from_battle, font, 18);
	sf::Text text_use_inventory(use_inventory, font, 18);

	text_what_do_u_want.setPosition(570, 200);
	text_kick.setPosition(600, 270);
	text_dodge.setPosition(600, 300);
	text_magic_strike.setPosition(600, 330);
	text_use_inventory.setPosition(600, 360);
	text_escape_from_battle.setPosition(600, 390);
	/// <MOB TEXT> ///
	

	Text text_str_mob_name(mob.name, font, 18);
	Text text_str_mob_HP(to_string(mob.HP), font, 18);
	Text text_str_mob_damage(to_string(mob.damage), font, 18);
	Text text_str_mob_dexterity(to_string(mob.dexterity), font, 18);

	text_str_mob_name.setPosition(150, 50);
	text_str_mob_HP.setPosition(150, 80);
	text_str_mob_damage.setPosition(150, 110);
	text_str_mob_dexterity.setPosition(150, 140);


	/// <PERSONAGE TEXT> ///

	Text text_str_personage_class(personage.personage_class, font, 18);
	Text text_str_personage_HP(to_string(personage.currentHP), font, 18);
	Text text_str_personage_power(to_string(personage.power), font, 18);
	Text text_str_personage_intelligence(to_string(personage.intelligence), font, 18);
	Text text_str_personage_dexterity(to_string(personage.dexterity), font, 18);
	Text text_str_personage_EXP(to_string(personage.currentexp), font, 18);

	text_str_personage_class.setPosition(1170, 50);
	text_str_personage_HP.setPosition(1170, 80);
	text_str_personage_power.setPosition(1170, 110);
	text_str_personage_intelligence.setPosition(1170, 140);
	text_str_personage_dexterity.setPosition(1170, 170);
	text_str_personage_EXP.setPosition(1170, 200);

	/// <WINDOW TEXT FOR PERSONAGE> ///

	Text window_text_personage_class("Class", font, 18);
	Text window_text_personage_HP("HP", font, 18);
	Text window_text_personage_power("Power", font, 18);
	Text window_text_personage_intelligence("Magic power", font, 18);
	Text window_text_personage_dexterity("Dexterity", font, 18);
	Text window_text_personage_EXP("EXP", font, 18);
	window_text_personage_class.setPosition(1050, 50);
	window_text_personage_HP.setPosition(1050, 80);
	window_text_personage_power.setPosition(1050, 110);
	window_text_personage_intelligence.setPosition(1050, 140);
	window_text_personage_dexterity.setPosition(1050, 170);
	window_text_personage_EXP.setPosition(1050, 200);

	/// <WINDOW TEXT FOR MOB> ///

	Text window_text_mob_name("Name", font, 18);
	Text window_text_mob_HP("HP", font, 18);
	Text window_text_mob_power("Power", font, 18);
	Text window_text_mob_dexterity("Dexterity", font, 18);
	Text window_text_mob_EXP("EXP", font, 18);
	window_text_mob_name.setPosition(30, 50);
	window_text_mob_HP.setPosition(30,80);
	window_text_mob_power.setPosition(30, 110);
	window_text_mob_dexterity.setPosition(30, 140);
	window_text_mob_EXP.setPosition(30, 170);
	bool close = true;
	bool bat = true;
	while (bat == true) { // цикл битвы, пока не закончатся хр моба или игрока
		if (mob.HP <= 0 || personage.currentHP < 0)
		{
			bat = false;
			break;
		}
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				close = Window_close(window, Background, sprite, font);
				if (close == false) {
					window.close();
					exit;
				}

				
			}

			if (IntRect(600, 270, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					mob.HP = mob.HP - personage.power;
					personage.currentHP = personage.currentHP - mob.damage;

					continue;
				}
			}

			if (IntRect(600, 300, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					if (mob.dexterity > personage.dexterity) {
						personage.currentHP = personage.currentHP - mob.damage;
						continue;
					}
					else {
						continue;
					}
				}
			}

			if (IntRect(600, 330, 60, 20).contains(Mouse::getPosition(window))) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					mob.HP = mob.HP - personage.intelligence;
					personage.currentHP = personage.currentHP - mob.damage;
					continue;
				}
			}

			if (IntRect(600, 360, 60, 20).contains(Mouse::getPosition(window))) {

				// реализовать графический интерфейс использования инвентаря
				if (Mouse::isButtonPressed(Mouse::Left)) {
					personage.inventar( window,Background,sprite,font);
					continue;
				}
			}
			if (IntRect(600, 390, 60, 20).contains(Mouse::getPosition(window))) {

				// реализовать графический интерфейс использования инвентаря
				if (Mouse::isButtonPressed(Mouse::Left)) {
					return personage;
				}
			}


		}
		text_str_mob_name.setString(mob.name);
		text_str_mob_HP.setString(to_string(mob.HP));
		text_str_mob_damage.setString(to_string(mob.damage));
		text_str_mob_dexterity.setString(to_string(mob.dexterity));
		text_str_personage_HP.setString(to_string(personage.currentHP));


		window.clear();
		window.draw(sprite);
		// DRA WINDOW TEXT FOR MOB
		window.draw(window_text_mob_name);
		window.draw(window_text_mob_HP);
		window.draw(window_text_mob_power);
		window.draw(window_text_mob_dexterity);
		window.draw(window_text_mob_EXP);

		// DRAW WINDOW TEXT FOR PERSONAGE
		window.draw(window_text_personage_class);
		window.draw(window_text_personage_HP);
		window.draw(window_text_personage_power);
		window.draw(window_text_personage_intelligence);
		window.draw(window_text_personage_dexterity);
		window.draw(window_text_personage_EXP);

		// DRAW TEXT FOR STAT PERSONAGE
		window.draw(text_str_personage_class);
		window.draw(text_str_personage_HP);
		window.draw(text_str_personage_power);
		window.draw(text_str_personage_intelligence);
		window.draw(text_str_personage_dexterity);
		window.draw(text_str_personage_EXP);


		// DRAW TEXT FOR STAT MOB
		window.draw(text_str_mob_name);
		window.draw(text_str_mob_HP);
		window.draw(text_str_mob_damage);
		window.draw(text_str_mob_dexterity);
	

		// DRAW TEXT PERS WANT TO DO
		window.draw(text_what_do_u_want);
		window.draw(text_kick);
		window.draw(text_dodge);
		window.draw(text_magic_strike);
		window.draw(text_use_inventory);
		window.draw(text_escape_from_battle);
		window.display();
	}
	if (personage.currentHP > 0) {
		personage.currentexp += personage.gainexp(personage.currentexp, mob.gained_exp);
		personage.check_level(personage.currentlevel, personage.currentexp, personage.maxexp, window, Background, sprite, font);
		return personage;
	}
	window.close();
}

