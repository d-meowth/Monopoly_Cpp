/// Plays monopoly /// No jail ///
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
	// Game count
	int game = 1;
	int totalgame = 1;

	// Loop count
	int loop = 1;
	const int totalloop = 10;

	// Position; Block count; Move number; Excess number
	int position = 0;
	const int block = 19; //! Default 19 [17 properties; 1 jail; 1 go to jail; 1 start]
	int moved;
	int excess = 0;

	// Die
	int froll;
	int sroll;

	// Doubles counter
	int doubles;

	// Buy
	bool buy;

	// Properties
	int bluep = 100;
	int yellp = 200;
	int oranp = 300;
	int purpp = 400;

	// Pass go $200
	int salary = 25;

	// Is property available?
	bool ai = true;
	bool er = true;
	bool pr = true;
	bool wr = true;
	bool ls = true;
	bool cs = true;
	bool pc = true;
	bool tq = true;
	bool na = true;
	bool vs = true;
	bool ms = true;
	bool bs = true;
	bool ts = true;
	bool mf = true;
	bool pl = true;
	bool fs = true;

	// Close game
	const string Y = "Y";
	const string N = "N";
	string close;

	do // Program
	{
		cout << "How many games do you want to play?" << endl;
		cout << ">";
		cin >> totalgame;
		if (totalgame == 0)
		{
			cout << "Closing..." << endl;
			Sleep(250);
			return 0;
		}
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << ">";
			cin >> totalgame;
		}
		cout << "Starting game...\n" << endl;

		do // Game
		{
			// Money
			int money = 1500;

			cout << "Game: " << game << endl; // Debug
			do // Loop
			{
				cout << "Loop: " << loop << endl; // Debug
				cout << "-----------" << endl; // Debug separator
				while (position < block) // Position
				{
					// Random buy bool
					srand(time(0));
					buy = rand() & 1;

					// Rolls the die
					srand(time(0));

					froll = rand() % 6 + 1;
					cout << "First dice rolled: " << froll << endl;

					Sleep(1000); // Pause between rolls

					sroll = rand() % 6 + 1;
					cout << "Second dice rolled: " << sroll << endl;
					moved = froll + sroll;
					cout << "You rolled: " << moved << endl;
					cout << endl;

					// Sets/resets doubles
					doubles = 0;

					// Moves the player
					position = position + moved;

					// Buys blue property
					//
					if (position == 1 && buy && money > bluep && ai)
					{
						cout << "You have bought The Angel Islington" << endl;
						money = money - bluep;
						ai = false;
					}
					if (position == 2 && buy && money > bluep && er)
					{
						cout << "You have bought Euston Road" << endl;
						money = money - bluep;
						er = false;
					}
					if (position == 3 && buy && money > bluep && pr)
					{
						cout << "You have bought Pentonville Road" << endl;
						money = money - bluep;
						pr = false;
					}
					if (position == 4 && buy && money > bluep && wr)
					{
						cout << "You have bought Whitechapel Road" << endl;
						money = money - bluep;
						wr = false;
					}
					// Buys yellow property
					//
					if (position == 6 && buy && money > yellp && ls)
					{
						cout << "You have bought Leicester Square" << endl;
						money = money - yellp;
						ls = false;
					}
					if (position == 7 && buy && money > yellp && cs)
					{
						cout << "You have bought Coventry Street" << endl;
						money = money - yellp;
						cs = false;
					}
					if (position == 8 && buy && money > yellp && pc)
					{
						cout << "You have bought Piccadilly" << endl;
						money = money - yellp;
						pc = false;
					}
					if (position == 9 && buy && money > yellp && tq)
					{
						cout << "You have bought Trafalgar Square" << endl;
						money = money - yellp;
						tq = false;
					}
					// Buys orange property
					//
					if (position == 11 && buy && money > oranp && na)
					{
						cout << "You have bought Northumberland Avenue" << endl;
						money = money - oranp;
						na = false;
					}
					if (position == 12 && buy && money > oranp && vs)
					{
						cout << "You have bought Vine Street" << endl;
						money = money - oranp;
						vs = false;
					}
					if (position == 13 && buy && money > oranp && ms)
					{
						cout << "You have bought Marlborough Street" << endl;
						money = money - oranp;
						ms = false;
					}
					if (position == 14 && buy && money > oranp && bs)
					{
						cout << "You have bought Bow Street" << endl;
						money = money - oranp;
						bs = false;
					}
					// Buys purple property
					//
					if (position == 16 && buy && money > purpp && ts)
					{
						cout << "You have bought The Strand" << endl;
						money = money - purpp;
						ts = false;

					}
					if (position == 17 && buy && money > purpp && mf)
					{
						cout << "You have bought Mayfair" << endl;
						money = money - purpp;
						mf = false;
					}
					if (position == 18 && buy && money > purpp && pl)
					{
						cout << "You have bought Park Lane" << endl;
						money = money - purpp;
						pl = false;
					}
					if (position == 19 && buy && money > purpp && fs)
					{
						cout << "You have bought Fleet Street" << endl;
						money = money - purpp;
						fs = false;
					}

					// Shows position
					if (position < block)
					{
						cout << "Your position: " << position + 1 << "/" << block + 1 << endl;
						cout << "Balance: $" << money << endl;
					}
					else if (position >= block)
					{
						cout << "Your position: " << position + 1 << "/" << block + 1 << " Take $" << salary << endl;
						money = money + salary;
						cout << "Balance: $" << money << endl;
					}
					cout << "_____________________" << endl;

					if (froll == sroll)
					{
						do
						{
							// Rolls the die
							cout << endl;
							cout << "You rolled a double" << endl;
							froll = rand() % 6 + 1;
							cout << "First dice rolled: " << froll << endl;

							Sleep(1000); // Pause between rolls

							sroll = rand() % 6 + 1;
							cout << "Second dice rolled: " << sroll << endl;
							moved = froll + sroll;
							cout << "You rolled: " << moved << endl;
							cout << endl;

							// Moves the player
							position = position + moved;

							// Counts doubles
							doubles++;
							if (doubles == 3)
							{
								cout << "Go to jail" << endl;
							}

							// Shows position
							if (position < block)
							{
								cout << "Your position: " << position + 1 << "/" << block + 1 << endl;
								cout << "Balance: $" << money << endl;
							}
							else if (position >= block)
							{
								cout << "Your position: " << position + 1 << "/" << block + 1 << " Take $" << salary << endl;
								money = money + salary;
								cout << "Balance: $" << money << endl;
							}
							cout << "_____________________" << endl;
						} while (froll == sroll);
					}
					cout << endl;

				}
				if (position >= block)
				{
					excess = position - block;
					loop++;
					position = 0 + excess;
					//cout << excess << endl; // Debug
				}
			} while (loop < totalloop + 1);
			if (loop > totalloop)
			{
				game++;
				loop = 1;
			}
		} while (game < totalgame + 1);

		//system("pause");
		cout << "Continue? Y/N" << endl;
		cout << ">";
		cin >> close;
		if (close == Y)
		{
			game = 0;
		}
		else if (close == N)
		{
			cout << "Closing..." << endl;
			Sleep(500);
		}
		else
		{
			cout << "Invalid input" << endl;

		}
	} while (close != N);
	return 0;
}


/// 0.9 Debug build