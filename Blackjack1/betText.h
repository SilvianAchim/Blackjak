#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>

#define DELETE_KEY 8

using namespace sf;
using namespace std;

class textBox
{
public:
	Text balanceBet;
	int betValue = 0;
	string h;
	

	void input(Event input, bool Enable)
	{
		if (Enable == true)
		{
			int charTyped = input.text.unicode;
			if (charTyped <= 57 && charTyped >= 48)
			{
				if (charTyped == 48)
				{
					add(0);
				}
				if (charTyped == 49)
				{
					add(1);
				}
				if (charTyped == 50)
				{
					add(2);
				}
				if (charTyped == 51)
				{
					add(3);
				}
				if (charTyped == 52)
				{
					add(4);
				}
				if (charTyped == 53)
				{
					add(5);
				}
				if (charTyped == 54)
				{
					add(6);
				}
				if (charTyped == 55)
				{
					add(7);
				}
				if (charTyped == 56)
				{
					add(8);
				}
				if (charTyped == 57)
				{
					add(9);
				}
			}
			else if (betValue > 0 && charTyped == DELETE_KEY)
			{
				deleteLastChar();
			}
		}
	}

	void drawBetBar(RenderWindow& window)
	{
		Font font;
		font.loadFromFile("fonts/Arial.ttf");
		balanceBet.setFont(font);
		balanceBet.setOutlineColor(Color::Black);
		balanceBet.setOutlineThickness(2);
		balanceBet.setPosition(30, 545);
		balanceBet.setCharacterSize(35);
		h = "Bet value: " + to_string(betValue);
		balanceBet.setString(h);
		window.draw(balanceBet);
	}
	void addButton(int num)
	{
		betValue += num;
	}
private:
	void add(int value)
	{
		betValue = betValue * 10 + value;
	}
	void deleteLastChar()
	{
		betValue /= 10;
	}
};