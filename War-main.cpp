/** 
  Author: Luke Wilson
  Project Name: L4 War
  Purpose: Learn the properties of stacks, queues, and deques and understand when to use them
  Sources: Ala Qasema -Debugging
  Jan Pearce - Created the GetRandom Class
 */
#include <iostream> 
#include <algorithm>  
#include <vector>
#include <stack>
#include <queue>
#include <random>
#include <chrono>

using namespace std;


class GetRandom {
	/** Uses <random> from C++11 to return a random integer in range [1..size] */
public:
	GetRandom(int size) {
		random_device rd; // declares a random_device object that need to generate a random number.
		mt19937 gen(rd()); //mt19937 is an efficient pseudo-random number generator using the Mersenne twister algorithm.
		uniform_int_distribution<int> intdist(1, size); //create a uniform distribution object to turn the pseudorandom result into a random digit between 1 and size.
		self_rand_int_ = intdist(gen); //generates the random number.
	}
	int roll() {
		return self_rand_int_;
	}
private:
	int self_rand_int_;
}; 

class War {
public:
	War() {
		//initalizes 
		dealing_deck;
		player_play;
		player_storage;
		computer_play;
		computer_storage;
		loot;
		// This code makes the 5 decks of cards that are in order
		dealing_deck.reserve(125);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 10; j++) {
				dealing_deck.push_back(j);
			}
		}
		// This code gets a time-based seed for randomness
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		//The following code shuffles
		shuffle(dealing_deck.begin(), dealing_deck.end(), std::default_random_engine(seed));
	}
	//deals 25 shuffled cards to each playing deck
	void deal() {
		for (int i = 0; i < 25; i++) {
			player_play.push(dealing_deck[i]);
			computer_play.push(dealing_deck[49 - i]);
		}
	}
	//get functions
	int get_player_play_top() {
		return player_play.top();
	}
	int get_computer_play_top() {
		return computer_play.top();
	}
	int get_player_play_size() {
		return player_play.size();
	}
	int get_computer_play_size() {
		return computer_play.size();
	}
	int get_player_storage_size() {
		return player_storage.size();
	}
	int get_computer_storage_size() {
		return computer_storage.size();
	}
	//refills the playing deck if empty
	void refill() {
			if (computer_play.size()==0 && computer_storage.size() > 0) {//fills computer's playing deck
				for (int i = 0; i = computer_storage.size(); i++) {
					computer_play.push(computer_storage.front());
					computer_storage.pop();
				}
			}
			if (player_play.size()==0 && player_storage.size() > 0) {//fills player's playing deck
				for (int i = 0; i = player_storage.size(); i++) {
					player_play.push(player_storage.front());
					player_storage.pop();
				}
			}
			else { return; }
		}
//checks to see which player won
	int win() {
		refill();
		if (player_play.size() == 0 && player_storage.size() == 0) {//computer wins game
			return 3;
		}
		if (computer_play.size() == 0 && computer_storage.size() == 0) {//player wins game
			return 2;
		}
		else {//continue game
			return 1;
		}
	}
	//plays a round of the game
	
	string play() {
		win();
		//ends game if computer runs out of cards in a war scenerio
		if (player_play.top() == computer_play.top() && player_play.size() + player_storage.size() > 2 && computer_play.size() + computer_storage.size() < 3) {
			for (int i=0; i < computer_play.size(); i++) {
				computer_play.pop();
			}
			win();
			return "\n";
		}
		//runs out of cards if player runs out of cards in a war scenerio
		if (player_play.top() == computer_play.top() && player_play.size() + player_storage.size() < 3 && computer_play.size() + computer_storage.size() > 2) {
			for (int i=0; i < player_play.size(); i++) {
				player_play.pop();
			}
			win();
			return "\n";
		}
		//war scenerio
		if (player_play.top() == computer_play.top() && player_play.size() + player_storage.size() > 2 && computer_play.size() + computer_storage.size() > 2) {
				for (int i = 0; i < 2; i++) {
					loot.push(player_play.top());
					loot.push(computer_play.top());
					player_play.pop();
					win();
					computer_play.pop();
					win();
				}
			}
		if (player_play.top() > computer_play.top()) {//player wins and takes cards
			player_storage.push(computer_play.top());
			computer_play.pop();
			player_storage.push(player_play.top());
			player_play.pop();
			if (loot.empty()) {
				win();
				return "player wins round\n";
			}
			else {
				for (int i; i = loot.size(); i++) {
					player_storage.push(loot.top());
					loot.pop();
				}
				win();
				return "player wins round\n";
			}
		}
		if (player_play.top() < computer_play.top()) {//computer wins and takes cards
			computer_storage.push(player_play.top());
			player_play.pop();
			computer_storage.push(computer_play.top());
			computer_play.pop();
			if (loot.empty()) {
				win();
				return "computer wins round\n";
			}
			else {
				for (int i; i = loot.size(); i++) {
					computer_storage.push(loot.top());
					loot.pop();
				}
				win();
				return "computer wins round\n";
			}
		}
		else {
			return "war continues\n";
		}
	}
private:
	vector<int>dealing_deck;
	stack<int>player_play;
	queue<int>player_storage;
	stack<int>computer_play;
	queue<int>computer_storage;
	stack<int>loot;
}; 

int main() {
	War game;
	game.deal();
	char a;
	while (game.win() == 1) {//keeps playing game till someone reaches 0 cards, also prints # of card left in each deck
		game.win();
		cout << "player has drawn: " << game.get_player_play_top() << " computer has drawn: " << game.get_computer_play_top() << "\n";
		cout << game.play();
		cout << "# player cards: " << game.get_player_play_size() + game.get_player_storage_size() << "\n# computer cards : " << game.get_computer_play_size() + game.get_computer_storage_size() << "\n";
		cin >>  a;
	}
	if (game.win() == 2) {//prints a winning screen depending on who wins
		cout << "PLAYER WINS GAME";
	}
	if (game.win() == 3) {
		cout << "COMPUTER WINS GAME";
	}
}