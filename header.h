#pragma once
#include <ctime>
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>
#include <stdlib.h>
// h-файл, где собраны, библиотеки  и объ€влены все функции и структуры
using namespace std;
using namespace sf;

struct Agr
{
	string name;
	int HP;
	int damage;
	int dexterity;
	int gained_exp;
	
};

struct Class //классы персонажа
{
	string personage_class;
	int maxexp;
	int currentHP;
	int maxHP;
	int power;//8
	int intelligence;//18
	int dexterity;//12//38 ловкость
	int zelyeHP;
	int zelyeDamege;
	int zelyeIntelekt;
	int zelyeDexterity;
	int currentlevel = 1;// текущий уровень
	int currentexp = 0;// текущий exp

	int inventar(RenderWindow& window, Texture Background, Sprite sprite, Font font);
	int levelsystem(RenderWindow& window, Texture Background, Sprite sprite, Font font);
	int gainexp(int currentexp, int gained_exp);
	void check_level(int currentlevel, int currentexp, int maxexp, RenderWindow& window, Texture Background, Sprite sprite, Font font);
};

Class Personag(RenderWindow& window, Texture Background, Sprite sprite, Font font);
Class battle(Class personag, Agr mob, RenderWindow& window, Texture Background, Sprite sprite, Font font);
Class pyt1(Class personage, Agr mob, RenderWindow& window, Texture Background, Sprite sprite, Font font);

Class Window_Potion_Chest(Class personage, RenderWindow& window, Texture Background, Sprite sprite, Font font);

int Window_path(RenderWindow& window, Texture Background, Sprite sprite, Font font, int choise_of_path);
bool Window_dialog(RenderWindow& window, Texture Background, Sprite sprite, Font font, string str);
bool Window_close(RenderWindow& window, Texture Background, Sprite sprite, Font font);
void OknoIgri();