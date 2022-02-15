#include <iostream>
using namespace std;

int main()
{
	char grade = 'X';
	int score;
	cout << "Enter your score: ";
	cin >> score;

	if (score >= 0 && score <= 100)
	{
		if (score >= 90)
			grade = 'A';
		else if (score >= 80)
			grade = 'B';
		else if (score >= 70)
			grade = 'C';
		else if (score >= 60)
			grade = 'D';
		else
			grade = 'F';
		cout << "Your grade is " << grade << endl;
	}
	else
		cout << "The score (" << score << ") is invalid" << endl;
	return 0;
}