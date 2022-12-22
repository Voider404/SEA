#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include "Game.h"

#define CELLSIZE 50

using namespace sf;

void drawField(Field& field, Point topLeftCorner, bool selfField, RenderWindow& window, vector<Sprite>& sprites)
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			int cell = field.fieldData[j][i];
			if (!selfField && cell == 1)
			{
				--cell;
			}
			Sprite temp(sprites[cell]);
			temp.move(CELLSIZE * i + topLeftCorner.x, CELLSIZE * j + topLeftCorner.y);
			window.draw(temp);
		}
	}
	Sprite temp(sprites[4]);
	temp.move(0, CELLSIZE * 10);
	window.draw(temp);
}

void getPoint(int &x, int &y, bool &vert, int size)
{
	int choice = -1;
	do
	{
		printf("Добавление %d-палубного корабля:\nВведите координаты добавления\nx (строка) = ", size);
		cin >> x;
		cout << "y (столбец) = ";
		cin >> y;
		cout << "Введите 0, если корабль должен быть вертикальным, 1, если горизонтальным - ";
		cin >> choice;
	} while (x < 0 || x > 9 || y < 0 || y > 9 || (choice != 0 && choice != 1));
	if (choice == 0)
	{
		vert = true;
	}
	else
	{
		vert = false;
	}
}

void gameInit(Game& game)
{
	game.initGame();
	cout << "Заполнить поле случайным образом?\n 1 - да, любой другой символ - нет.\n";
	int ch = 0;
	cin >> ch;
	if (ch != 1)
	{
		int x = -1, y = -1;
		bool vert = false;
		while (game.player.field.ships.size() < 1)
		{
			getPoint(x, y, vert, 4);
			game.player.field.addShip(Point(x, y), vert, 4);
			cout << game.player.field << endl;
		}
		while (game.player.field.ships.size() < 3)
		{
			x = -1;
			y = -1;
			getPoint(x, y, vert, 3);
			game.player.field.addShip(Point(x, y), vert, 3);
			cout << game.player.field << endl;
		}
		while (game.player.field.ships.size() < 6)
		{
			x = -1;
			y = -1;
			getPoint(x, y, vert, 2);
			game.player.field.addShip(Point(x, y), vert, 2);
			cout << game.player.field << endl;
		}
		while (game.player.field.ships.size() < 10)
		{
			x = -1;
			y = -1;
			getPoint(x, y, vert, 1);
			game.player.field.addShip(Point(x, y), vert, 1);
			cout << game.player.field << endl;
		}
		game.player.initOutOfRange();
	}
	else
	{
		game.player.randFillField();
	}
}

void gameInProcess(RenderWindow& window, Game& game, vector<Sprite>& sprites)
{

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
			{
				int x = event.mouseButton.x;
				int y = event.mouseButton.y;
				//cout << "MOUSE CLICKED: " << (x - CELLSIZE * 12) / CELLSIZE << "\t" << y / CELLSIZE << endl;
				int cellX = (x - CELLSIZE * 12) / CELLSIZE;
				int cellY = y / CELLSIZE;
				if (cellX >= 0 && cellX <= 9 && cellY >= 0 && cellY <= 9)
				{
					game.makeStep(cellY, cellX);
					game.debugPrint();
				}
			}
		}
		window.clear(Color::Blue);
		if (game.gameOver() == 1)
		{
			sprites[4] = sprites[6];
		}
		else if (game.gameOver() == 2)
		{
			sprites[4] = sprites[5];
		}
		drawField(game.player.field, Point(0, 0), true, window, sprites);
		drawField(game.ai.field, Point(CELLSIZE * 12, 0), false, window, sprites);
		window.display();
	}
}

int main()
{
	srand(time(nullptr));
	setlocale(LC_ALL, "Russian");
	system("chcp 1251 > nul");

	RenderWindow window(VideoMode(CELLSIZE * 22, CELLSIZE * 14), "Sea Battle");

	vector<Sprite> sprites; // загрузка файлов
	Texture texture0, texture1, texture2, texture3;
	texture2.loadFromFile("Pictures\\empty.png"); // спрайт пустой ячейки
	sprites.push_back(Sprite(texture2));
	texture0.loadFromFile("Pictures\\alive.png"); // спрайт живого корабля
	sprites.push_back(Sprite(texture0));
	texture1.loadFromFile("Pictures\\dead.png"); // спрайт мёртвого корабля
	sprites.push_back(Sprite(texture1));
	texture3.loadFromFile("Pictures\\miss.png"); // спрайт промаха
	sprites.push_back(Sprite(texture3));

	Texture info, win, loss;
	info.loadFromFile("Pictures\\info.png");
	sprites.push_back(Sprite(info));
	win.loadFromFile("Pictures\\win.png"); // текст победы
	sprites.push_back(Sprite(win));
	loss.loadFromFile("Pictures\\loss.png"); // текст поражения
	sprites.push_back(Sprite(loss));

	Game game;
	gameInit(game);

	gameInProcess(window, game, sprites);

	return 0;
}