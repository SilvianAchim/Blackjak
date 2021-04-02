#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "betText.h"
#include <Time.h>

using namespace sf;

int balance = 50;
bool betPlaced = false, betBarEnable = true, first = true, gameFinish = false;
int playerNrOfCards, dealerNrOfCards;
int playerCards, dealerCards;

struct card
{
	int color, value;
};

card player[6], dealer[6];

int randomGenerator()
{
	int nr = rand() % 14 + 1;
	return nr;
}

int randomColor()
{
	int nr = rand() % 4 + 1;
	return nr;
}

int main()
{
	RenderWindow window(VideoMode(1300, 900), "Blackjack made by Silvian Achim", Style::Titlebar | Style::Close);
	textBox bet;
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t18, t19, t20, t21, t22, t23, t24, t25, t17;
	Texture t26, t27, t28, t29, t30, t31, t32, t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47;
	Texture t48, t49, t50, t51, t52;
	Texture t53, t54, t55, t56, t57, t58, t59, t60, t61, t62, t63, t64, t65;

	t1.loadFromFile("images/2_of_clubs.png");
	t2.loadFromFile("images/2_of_diamonds.png");
	t3.loadFromFile("images/2_of_hearts.png");
	t4.loadFromFile("images/2_of_spades.png");

	t5.loadFromFile("images/3_of_clubs.png");
	t6.loadFromFile("images/3_of_diamonds.png");
	t7.loadFromFile("images/3_of_hearts.png");
	t8.loadFromFile("images/3_of_spades.png");

	t9.loadFromFile("images/4_of_clubs.png");
	t10.loadFromFile("images/4_of_diamonds.png");
	t11.loadFromFile("images/4_of_hearts.png");
	t12.loadFromFile("images/4_of_spades.png");

	t13.loadFromFile("images/5_of_clubs.png");
	t14.loadFromFile("images/5_of_diamonds.png");
	t15.loadFromFile("images/5_of_hearts.png");
	t16.loadFromFile("images/5_of_spades.png");

	t17.loadFromFile("images/6_of_clubs.png");
	t18.loadFromFile("images/6_of_diamonds.png");
	t19.loadFromFile("images/6_of_hearts.png");
	t20.loadFromFile("images/6_of_spades.png");

	t21.loadFromFile("images/7_of_clubs.png");
	t22.loadFromFile("images/7_of_diamonds.png");
	t23.loadFromFile("images/7_of_hearts.png");
	t24.loadFromFile("images/7_of_spades.png");

	t25.loadFromFile("images/8_of_clubs.png");
	t26.loadFromFile("images/8_of_diamonds.png");
	t27.loadFromFile("images/8_of_hearts.png");
	t28.loadFromFile("images/8_of_spades.png");

	t29.loadFromFile("images/9_of_clubs.png");
	t30.loadFromFile("images/9_of_diamonds.png");
	t31.loadFromFile("images/9_of_hearts.png");
	t32.loadFromFile("images/9_of_spades.png");

	t33.loadFromFile("images/10_of_clubs.png");
	t34.loadFromFile("images/10_of_diamonds.png");
	t35.loadFromFile("images/10_of_hearts.png");
	t36.loadFromFile("images/10_of_spades.png");

	t37.loadFromFile("images/ace_of_clubs.png");
	t38.loadFromFile("images/ace_of_diamonds.png");
	t39.loadFromFile("images/ace_of_hearts.png");
	t40.loadFromFile("images/ace_of_spades.png");

	t41.loadFromFile("images/jack_of_clubs.png");
	t42.loadFromFile("images/jack_of_diamonds.png");
	t43.loadFromFile("images/jack_of_hearts.png");
	t44.loadFromFile("images/jack_of_spades.png");

	t45.loadFromFile("images/king_of_clubs.png");
	t46.loadFromFile("images/king_of_diamonds.png");
	t47.loadFromFile("images/king_of_hearts.png");
	t48.loadFromFile("images/king_of_spades.png");

	t49.loadFromFile("images/queen_of_clubs.png");
	t50.loadFromFile("images/queen_of_diamonds.png");
	t51.loadFromFile("images/queen_of_hearts.png");
	t52.loadFromFile("images/queen_of_spades.png");

	t53.loadFromFile("images/cardBack.png");
	t54.loadFromFile("images/background1.png");
	t64.loadFromFile("images/background2.png");

	t55.loadFromFile("images/1.png");
	t56.loadFromFile("images/10.png");
	t57.loadFromFile("images/100.png");
	t58.loadFromFile("images/1000.png");
	t59.loadFromFile("images/max.png");

	t60.loadFromFile("images/double.png");
	t61.loadFromFile("images/hit.png");
	t62.loadFromFile("images/stand.png");
	t63.loadFromFile("images/place.png");
	t65.loadFromFile("images/deck.png");

	Sprite two_of_clubs(t1);
	Sprite two_of_diamonds(t2);
	Sprite two_of_hearts(t3);
	Sprite two_of_spades(t4);

	Sprite three_of_clubs(t5);
	Sprite three_of_diamonds(t6);
	Sprite three_of_hearts(t7);
	Sprite three_of_spades(t8);

	Sprite four_of_clubs(t9);
	Sprite four_of_diamonds(t10);
	Sprite four_of_hearts(t11);
	Sprite four_of_spades(t12);

	Sprite five_of_clubs(t13);
	Sprite five_of_diamonds(t14);
	Sprite five_of_hearts(t15);
	Sprite five_of_spades(t16);

	Sprite six_of_clubs(t17);
	Sprite six_of_diamonds(t18);
	Sprite six_of_hearts(t19);
	Sprite six_of_spades(t20);

	Sprite seven_of_clubs(t21);
	Sprite seven_of_diamonds(t22);
	Sprite seven_of_hearts(t23);
	Sprite seven_of_spades(t24);

	Sprite eight_of_clubs(t25);
	Sprite eight_of_diamonds(t26);
	Sprite eight_of_hearts(t27);
	Sprite eight_of_spades(t28);

	Sprite nine_of_clubs(t29);
	Sprite nine_of_diamonds(t30);
	Sprite nine_of_hearts(t31);
	Sprite nine_of_spades(t32);

	Sprite ten_of_clubs(t33);
	Sprite ten_of_diamonds(t34);
	Sprite ten_of_hearts(t35);
	Sprite ten_of_spades(t36);

	Sprite ace_of_clubs(t37);
	Sprite ace_of_diamonds(t38);
	Sprite ace_of_hearts(t39);
	Sprite ace_of_spades(t40);

	Sprite jack_of_clubs(t41);
	Sprite jack_of_diamonds(t42);
	Sprite jack_of_hearts(t43);
	Sprite jack_of_spades(t44);

	Sprite king_of_clubs(t45);
	Sprite king_of_diamonds(t46);
	Sprite king_of_hearts(t47);
	Sprite king_of_spades(t48);

	Sprite queen_of_clubs(t49);
	Sprite queen_of_diamonds(t50);
	Sprite queen_of_hearts(t51);
	Sprite queen_of_spades(t52);

	Sprite bet1(t55);
	Sprite bet10(t56);
	Sprite bet100(t57);
	Sprite bet1000(t58);
	Sprite betmax(t59);

	Sprite doubleButton(t60);
	Sprite hitButton(t61);
	Sprite standButton(t62);
	Sprite placeButton(t63);

	Sprite deck(t65);
	Sprite cardBack(t53);
	Sprite background1(t54);
	Sprite background2(t64);

	Sprite cardd;
	
	while (window.isOpen())
	{
		window.setFramerateLimit(60);
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			if (e.type == Event::TextEntered)
			{
				bet.input(e, betBarEnable);
			}
			if (e.type == Event::MouseButtonPressed)
			{
				if (e.key.code == Mouse::Left)
				{
					float x = Mouse::getPosition(window).x;
					float y = Mouse::getPosition(window).y;
					// place button
					if (x >= 560 && y >= 525 && x <= 740 && y <= 585 && bet.betValue > 0 && bet.betValue <= balance && betPlaced==false)
					{
						betBarEnable = false;
						betPlaced = true;
						balance -= bet.betValue;
					}
					// hit button
					else if (x >= 605 && y >= 525 && x <= 705 && y <= 685 && betBarEnable == false)
					{
						if (betPlaced == true && playerCards < 21 && playerNrOfCards<5)
						{
							playerNrOfCards++;
							int card = randomGenerator();
							if (card > 9)
							{
								playerCards++;
							}
							else
							{
								playerCards += card;
							}
							player[playerNrOfCards].value = card;
							card = randomColor();
							player[playerNrOfCards].color = card;
						}
					}
					// stand button
					else if (x >= 725 && y >= 525 && x <= 905 && y <= 585 && betBarEnable == false)
					{
						while (dealerCards < 17)
						{
							dealerNrOfCards++;
							int card = randomGenerator();
							if (card > 9)
							{
								dealerCards += 10;
							}
							else
							{
								dealerCards += card;
							}
							dealer[dealerNrOfCards].value = card;
							card = randomColor();
							dealer[dealerNrOfCards].color = card;

						}

						if (playerCards > 21 || dealerCards > playerCards&& dealerCards <= 21)
						{
							cout << "Lose\n";
							cout << "Player card=" << playerCards << " Dealer cards=" << dealerCards << "\n";
							gameFinish = true;
						}
						else if (playerCards > dealerCards&& playerCards <= 21 || dealerCards > 21)
						{
							cout << "Win\n";
							cout << "Player card=" << playerCards << " Dealer cards=" << dealerCards << "\n";
							balance += 2 * bet.betValue;
							gameFinish = true;
						}
						else
						{
							cout << "Tie\n";
							cout << "Player card=" << playerCards << " Dealer cards=" << dealerCards << "\n";
							balance += bet.betValue;
							gameFinish = true;

						}
					}
					// double button
					else if (x>=355 && y>=525 && y<=585 && x<=585 && betPlaced==true)
					{
						playerNrOfCards++;
						int card = randomGenerator();
						if (card > 9)
						{
							playerCards++;
						}
						else
						{
							playerCards += card;
						}
						player[playerNrOfCards].value = card;
						card = randomColor();
						player[playerNrOfCards].color = card;
						while (dealerCards < 17)
						{
							dealerNrOfCards++;
							int card = randomGenerator();
							if (card > 9)
							{
								dealerCards += 10;
							}
							else
							{
								dealerCards += card;
							}
							dealer[dealerNrOfCards].value = card;
							card = randomColor();
							dealer[dealerNrOfCards].color = card;
						}
						bet.betValue *= 2;
						balance -= bet.betValue;
						if (playerCards > 21 || dealerCards > playerCards&& dealerCards <= 21)
						{
							cout << "Lose\n";
							cout << "Player card=" << playerCards << " Dealer cards=" << dealerCards << "\n";
							gameFinish = true;
						}
						else if (playerCards > dealerCards&& playerCards <= 21 || dealerCards > 21)
						{
							cout << "Win\n";
							cout << "Player card=" << playerCards << " Dealer cards=" << dealerCards << "\n";
							balance += 2 * bet.betValue;
							gameFinish = true;
						}
						else
						{
							cout << "Tie\n";
							cout << "Player card=" << playerCards << " Dealer cards=" << dealerCards << "\n";
							balance += bet.betValue;
							gameFinish = true;

						}
					}
					
					// bet 1
					if (x >= 90 && y >= 600 && x <= 140 && y <= 650 && betBarEnable == true)
					{
						bet.addButton(1);
					}
					// bet 10
					if (x >= 90 && y >= 660 && x <= 140 && y <= 710 && betBarEnable == true)
					{
						bet.addButton(10);
					}
					// bet 100
					if (x >= 90 && y >= 720 && x <= 140 && y <= 770 && betBarEnable == true)
					{
						bet.addButton(100);
					}
					// bet 1000
					if (x >= 90 && y >= 780 && x <= 140 && y <= 830 && betBarEnable == true)
					{
						bet.addButton(1000);
					}
					// bet max
					if (x >= 90 && y >= 840 && x <= 140 && y <= 890 && betBarEnable == true)
					{
						bet.betValue = 0;
						bet.addButton(balance);
					}
				}
			}
		}
		window.clear(Color::Green);
		if (betPlaced == false)
		{
			window.draw(background1);
			placeButton.setPosition(560, 525);
			window.draw(placeButton);
		}
		else
		{
			window.draw(background2);
			doubleButton.setPosition(355, 525);
			window.draw(doubleButton);
			hitButton.setPosition(605, 525);
			window.draw(hitButton);
			standButton.setPosition(725, 525);
			window.draw(standButton);
		}
		bet1.setPosition(90, 600);
		window.draw(bet1);
		bet10.setPosition(90, 660);
		window.draw(bet10);
		bet100.setPosition(90, 720);
		window.draw(bet100);
		bet1000.setPosition(90, 780);
		window.draw(bet1000);
		betmax.setPosition(90, 840);
		window.draw(betmax);
		if (first == true && betPlaced == true)
		{
			playerNrOfCards++;
			int card = randomGenerator();
			if (card > 9)
			{
				playerCards+=10;
			}
			else
			{
				playerCards += card;
			}
			player[playerNrOfCards].value = card;
			card = randomColor();
			player[playerNrOfCards].color = card;
			playerNrOfCards++;
			card = randomGenerator();
			if (card > 9)
			{
				playerCards+=10;
			}
			else
			{
				playerCards += card;
			}
			player[playerNrOfCards].value = card;
			card = randomColor();
			player[playerNrOfCards].color = card;
			dealerNrOfCards++;
		    card = randomGenerator();
			if (card > 9)
			{
				dealerCards += 10;
			}
			else
			{
				dealerCards += card;
			}
			dealer[dealerNrOfCards].value = card;
			card = randomColor();
			dealer[dealerNrOfCards].color = card;
			dealerNrOfCards++;
		    card = randomGenerator();
			if (card > 9)
			{
				dealerCards += 10;
			}
			else
			{
				dealerCards += card;
			}
			dealer[dealerNrOfCards].value = card;
			card = randomColor();
			dealer[dealerNrOfCards].color = card;
			first = false;
		}

		deck.setPosition(30, 30);
		window.draw(deck);

		string b;
		b = "Balance: " + to_string(balance);
		Text balanceText;
		Font font;
		font.loadFromFile("fonts/Arial.ttf");
		balanceText.setFont(font);
		balanceText.setOutlineColor(Color::Black);
		balanceText.setOutlineThickness(2);
		balanceText.setString(b);
		balanceText.setPosition(30, 300);
		balanceText.setCharacterSize(45);
		window.draw(balanceText);
		int position = 260;
		for (int i = 1; i <= playerNrOfCards; i++)
		{
			if (player[i].value == 1 || player[i].value == 11)
			{
				if (player[i].color == 1)
				{
					cardd = ace_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = ace_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = ace_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = ace_of_spades;
				}
			}
			if (player[i].value == 2)
			{
				if (player[i].color == 1)
				{
					cardd = two_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = two_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = two_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = two_of_spades;
				}
			}
			if (player[i].value == 3)
			{
				if (player[i].color == 1)
				{
					cardd = three_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = three_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = three_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = three_of_spades;
				}
			}
			if (player[i].value == 4)
			{
				if (player[i].color == 1)
				{
					cardd = four_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = four_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = four_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = four_of_spades;
				}
			}
			if (player[i].value == 5)
			{
				if (player[i].color == 1)
				{
					cardd = five_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = five_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = five_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = five_of_spades;
				}
			}
			if (player[i].value == 6)
			{
				if (player[i].color == 1)
				{
					cardd = six_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = six_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = six_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = six_of_spades;
				}
			}
			if (player[i].value == 7)
			{
				if (player[i].color == 1)
				{
					cardd = seven_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = seven_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = seven_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = seven_of_spades;
				}
			}
			if (player[i].value == 8)
			{
				if (player[i].color == 1)
				{
					cardd = eight_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = eight_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = eight_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = eight_of_spades;
				}
			}
			if (player[i].value == 9)
			{
				if (player[i].color == 1)
				{
					cardd = nine_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = nine_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = nine_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = nine_of_spades;
				}
			}
			if (player[i].value == 10)
			{
				if (player[i].color == 1)
				{
					cardd = ten_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = ten_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = ten_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = ten_of_spades;
				}
			}
			if (player[i].value == 12)
			{
				if (player[i].color == 1)
				{
					cardd = jack_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = jack_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = jack_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = jack_of_spades;
				}
			}
			if (player[i].value == 13)
			{
				if (player[i].color == 1)
				{
					cardd = queen_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = queen_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = queen_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = queen_of_spades;
				}
			}
			if (player[i].value == 14)
			{
				if (player[i].color == 1)
				{
					cardd = king_of_clubs;
				}
				if (player[i].color == 2)
				{
					cardd = king_of_diamonds;
				}
				if (player[i].color == 3)
				{
					cardd = king_of_hearts;
				}
				if (player[i].color == 4)
				{
					cardd = king_of_spades;
				}
			}
			cardd.setPosition(position, 630);
			position += 260;
			window.draw(cardd);
		}
		position = 260;
		for (int i = 1; i <= dealerNrOfCards; i++)
		{
			if (i == 2 && gameFinish == false)
			{
				cardd = cardBack;
			}
			else if(i!=2 || gameFinish==true)
			{
				if (dealer[i].value == 1 || dealer[i].value == 11)
				{
					if (dealer[i].color == 1)
					{
						cardd = ace_of_clubs;
					}
					if (dealer[i].color == 2)
					{
						cardd = ace_of_diamonds;
					}
					if (dealer[i].color == 3)
					{
						cardd = ace_of_hearts;
					}
					if (dealer[i].color == 4)
					{
						cardd = ace_of_spades;
					}
				}
				if (dealer[i].value == 2)
				{
					if (dealer[i].color == 1)
					{
						cardd = two_of_clubs;
					}
					if (dealer[i].color == 2)
					{
						cardd = two_of_diamonds;
					}
					if (dealer[i].color == 3)
					{
						cardd = two_of_hearts;
					}
					if (dealer[i].color == 4)
					{
						cardd = two_of_spades;
					}
				}
				if (dealer[i].value == 3)
				{
					if (dealer[i].color == 1)
					{
						cardd = three_of_clubs;
					}
					if (dealer[i].color == 2)
					{
						cardd = three_of_diamonds;
					}
					if (dealer[i].color == 3)
					{
						cardd = three_of_hearts;
					}
					if (dealer[i].color == 4)
					{
						cardd = three_of_spades;
					}
				}
				if (dealer[i].value == 4)
				{
					if (dealer[i].color == 1)
					{
						cardd = four_of_clubs;
					}
					if (dealer[i].color == 2)
					{
						cardd = four_of_diamonds;
					}
					if (dealer[i].color == 3)
					{
						cardd = four_of_hearts;
					}
					if (dealer[i].color == 4)
					{
						cardd = four_of_spades;
					}
				}
				if (dealer[i].value == 5)
				{
					if (dealer[i].color == 1)
					{
						cardd = five_of_clubs;
					}
					if (dealer[i].color == 2)
					{
						cardd = five_of_diamonds;
					}
					if (dealer[i].color == 3)
					{
						cardd = five_of_hearts;
					}
					if (dealer[i].color == 4)
					{
						cardd = five_of_spades;
					}
				}
				if (dealer[i].value == 6)
				{
					if (dealer[i].color == 1)
					{
						cardd = six_of_clubs;
					}
					if (dealer[i].color == 2)
					{
						cardd = six_of_diamonds;
					}
					if (dealer[i].color == 3)
					{
						cardd = six_of_hearts;
					}
					if (dealer[i].color == 4)
					{
						cardd = six_of_spades;
					}
				}
				if (dealer[i].value == 7)
				{
					if (dealer[i].color == 1)
					{
						cardd = seven_of_clubs;
					}
					if (dealer[i].color == 2)
					{
						cardd = seven_of_diamonds;
					}
					if (dealer[i].color == 3)
					{
						cardd = seven_of_hearts;
					}
					if (dealer[i].color == 4)
					{
						cardd = seven_of_spades;
					}
				}
				if (dealer[i].value == 8)
				{
					if (dealer[i].color == 1)
					{
						cardd = eight_of_clubs;
					}
					if (dealer[i].color == 2)
					{
						cardd = eight_of_diamonds;
					}
					if (dealer[i].color == 3)
					{
						cardd = eight_of_hearts;
					}
					if (dealer[i].color == 4)
					{
						cardd = eight_of_spades;
					}
				}
				if (dealer[i].value == 9)
				{
					if (dealer[i].color == 1)
					{
						cardd = nine_of_clubs;
					}
					if (dealer[i].color == 2)
					{
						cardd = nine_of_diamonds;
					}
					if (dealer[i].color == 3)
					{
						cardd = nine_of_hearts;
					}
					if (dealer[i].color == 4)
					{
						cardd = nine_of_spades;
					}
				}
				if (dealer[i].value == 10)
				{
					if (dealer[i].color == 1)
					{
						cardd = ten_of_clubs;
					}
					if (dealer[i].color == 2)
					{
						cardd = ten_of_diamonds;
					}
					if (dealer[i].color == 3)
					{
						cardd = ten_of_hearts;
					}
					if (dealer[i].color == 4)
					{
						cardd = ten_of_spades;
					}
				}
				if (dealer[i].value == 12)
				{
					if (dealer[i].color == 1)
					{
						cardd = jack_of_clubs;
					}
					if (dealer[i].color == 2)
					{
						cardd = jack_of_diamonds;
					}
					if (dealer[i].color == 3)
					{
						cardd = jack_of_hearts;
					}
					if (dealer[i].color == 4)
					{
						cardd = jack_of_spades;
					}
				}
				if (dealer[i].value == 13)
				{
					if (dealer[i].color == 1)
					{
						cardd = queen_of_clubs;
					}
					if (dealer[i].color == 2)
					{
						cardd = queen_of_diamonds;
					}
					if (dealer[i].color == 3)
					{
						cardd = queen_of_hearts;
					}
					if (dealer[i].color == 4)
					{
						cardd = queen_of_spades;
					}
				}
				if (dealer[i].value == 14)
				{
					if (dealer[i].color == 1)
					{
						cardd = king_of_clubs;
					}
					if (dealer[i].color == 2)
					{
						cardd = king_of_diamonds;
					}
					if (dealer[i].color == 3)
					{
						cardd = king_of_hearts;
					}
					if (dealer[i].color == 4)
					{
						cardd = king_of_spades;
					}
				}
			}
			cardd.setPosition(position, 30);
			position += 260;
			window.draw(cardd);
		}
		bet.drawBetBar(window);
		window.display();
		if (gameFinish == true)
		{
			sleep(seconds(3));
			betBarEnable = true;
			betPlaced = false;
			playerCards = 0;
			playerNrOfCards = 0;
			dealerCards = 0;
			dealerNrOfCards = 0;
			first = true;
			gameFinish = false;
		}
	}
	return 0;
}