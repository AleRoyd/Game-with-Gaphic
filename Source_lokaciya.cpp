#include "header.h"

// основная функция игры, в нее передаются: персонаж, графические объекты, и структура монстра
Class pyt1(Class personage, Agr mob, RenderWindow& window, Texture Background, Sprite sprite, Font font) {
	
	int choise_of_path = 0;
	bool dialog;
	mob = { "Training manikin", 50, 0, 0, 100 };
	sprite.setTexture(Background);
	personage = battle(personage, mob, window, Background, sprite, font);
	choise_of_path =  Window_path(window, Background, sprite, font, choise_of_path);
	switch (choise_of_path)
	{
	case 1: mob = { "Goblin", 25, 5, 1, 100 };
		  personage = battle(personage, mob, window, Background, sprite, font);
		  break;
	case 2: Window_dialog(window, Background, sprite, font, "Character dialogue");
		if (dialog = false) {
			break;
		}
	case 3:personage = Window_Potion_Chest(personage, window, Background, sprite, font);
		break;
	}
	//
	choise_of_path =  Window_path(window, Background, sprite, font, choise_of_path);
	switch (choise_of_path)
	{
	case 1: mob = { "Orc",120, 15, 0, 200 };
		  personage = battle(personage, mob, window, Background, sprite, font);
		  break;
	case 2: mob = { "Goblin", 25, 5, 1, 100 };
		  personage = battle(personage, mob, window, Background, sprite, font);
		  break; 
	case 3: Window_dialog(window, Background, sprite, font, "Character dialogue");
		if (dialog = false) {
			break;
		}
	}

	//
	choise_of_path = Window_path(window, Background, sprite, font, choise_of_path);
	switch (choise_of_path)
	{
	case 1: mob = { "Orc",120, 15, 0, 200 };
		  personage = battle(personage, mob, window, Background, sprite, font);
		  Window_dialog(window, Background, sprite, font, "Character dialogue");
		  if (dialog = false) {
			  break;
		  }
	case 2: mob = { "Goblin", 25, 5, 1, 100 };
		  personage = battle(personage, mob, window, Background, sprite, font);
		  break; 
	case 3: break;
	}

	//
	choise_of_path = Window_path(window, Background, sprite, font, choise_of_path);
	switch (choise_of_path)
	{
	case 1: mob = { "Orc",120, 15, 0, 200 };
		  personage = battle(personage, mob, window, Background, sprite, font);
		  break;
	case 2: mob = { "Goblin", 25, 5, 1, 100 };
		  personage = battle(personage, mob, window, Background, sprite, font);
		  break;
	case 3: Window_dialog(window, Background, sprite, font, "Character dialogue");
		if (dialog = false) {
			break;
		}
	}


	choise_of_path = Window_path(window, Background, sprite, font, choise_of_path);
	switch (choise_of_path)
	{
	case 1:
		Window_dialog(window, Background, sprite, font, "Character dialogue");
		mob = { "Orc",120, 15, 0, 200 };
		personage = battle(personage, mob, window, Background, sprite, font);
		break;
	case 2:
		mob = { "Goblin", 25, 5, 1, 100 };
		personage = battle(personage, mob, window, Background, sprite, font);
		break;
	case 3:
		Window_dialog(window, Background, sprite, font, "Character dialogue");
		if (dialog = false) {
			break;
		}

	}
	return personage;
	
}



