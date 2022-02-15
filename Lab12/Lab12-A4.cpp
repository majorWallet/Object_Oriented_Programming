#include <iostream>
#include <string>
#include <ctime>
#include <random>
using namespace std;

#define IRON_MAN "IronMan"
#define CAP_AMERICA "CaptainAmerica"
#define THOR "Thor"

class Avengers {
public:
	Avengers() {
		name = "";
		attack_point = 0;
		defense_point = 0;
		health = 0;
	}
	~Avengers() { }
	virtual void set(string _name, int _attack, int _defense, int _health) { }
	virtual int attack() { return 0; }
	virtual void defense(int _attack_point) { }
	virtual void print_info() { }
protected:
	string name;
	int attack_point;
	int defense_point;
	int health;
};

class Character : public Avengers {
public:
	void set(string _name, int _attack, int _defense, int _health) override {
		name = _name;
		attack_point = _attack;
		defense_point = _defense;
		health = _health;
	}
	int attack() override {
		return attack_point;
	}
	void defense(int _attack_point) override {
		health -= _attack_point - defense_point;
	}
	void print_info() override {
		cout << "Name: " << name << endl;
		cout << "Attack_Point: " << attack_point << endl;
		cout << "Defense_Point: " << defense_point << endl;
		cout << "Health: " << health << endl;
	}
	int get_health() {
		return health;
	}
};

int main() {
	Character my_char;
	Character enemy_char;
	string my_char_name;
	int enemy_char_name;

	srand(time(NULL));
	enemy_char_name = rand() % 3;
	if(enemy_char_name == 0)
		enemy_char.set(IRON_MAN, 70, 40, 100);
	else if(enemy_char_name == 1)
		enemy_char.set(CAP_AMERICA, 60, 50, 100);
	else if(enemy_char_name == 2)
		enemy_char.set(THOR, 80, 30, 100);

	do {
		cout << "Choose your character(IronMan, CaptainAmerica, Thor): ";
		cin >> my_char_name;
	} while (my_char_name != IRON_MAN && my_char_name != CAP_AMERICA && my_char_name != THOR);
	if (my_char_name == IRON_MAN)
		my_char.set(IRON_MAN, 70, 40, 100);
	else if (my_char_name == CAP_AMERICA)
		my_char.set(CAP_AMERICA, 60, 50, 100);
	else if (my_char_name == THOR)
		my_char.set(THOR, 80, 30, 100);

	cout << "--My Character--" << endl;
	my_char.print_info();
	cout << "--Enemy Character--" << endl;
	enemy_char.print_info();

	cout << endl << "--Battle--" << endl;
	cout << "My Life: " << my_char.get_health() << "\t"
		<< "Enemy Life: " << enemy_char.get_health() << endl;

	while (1) {
		enemy_char.defense(my_char.attack());
		cout << "My Life: " << my_char.get_health() << "\t"
			<< "Enemy Life: " << enemy_char.get_health() << endl;
		if (enemy_char.get_health() <= 0) {
			cout << "You Win!" << endl;
			break;
		}
		my_char.defense(enemy_char.attack());
		cout << "My Life: " << my_char.get_health() << "\t"
			<< "Enemy Life: " << enemy_char.get_health() << endl;
		if (my_char.get_health() <= 0) {
			cout << "You Lose!" << endl;
			break;
		}
	}

	return 0;
}