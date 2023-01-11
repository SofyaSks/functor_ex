#include <iostream> 
#include <vector> 
using namespace std;

// класс, который считает сумму чётных и нечётных чисел
class summator : private vector<int> { 
public:
	summator(const vector<int>& ini) {
		for (auto x : ini) this->push_back(x);
	}

	int operator()(bool even) {
		int sum = 0;
		auto i = begin(); // итератор в начале вектора
		if (even) i++; // если even = true увеличиваем итератор
		while (i < end()) { // пока не конец
			sum += *i++; // сумма увеличивается на значение следующего итератора
			if (i == end()) break; // если итератор дошёл до конца - break
			i++; // увеличиваем итератор
		}
		return sum; // возвращаем сумму
	}
};

int main(void) {
	setlocale(LC_ALL, "rus");

	summator sums(vector<int>({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }));

	cout << "сумма чётных = " << sums(true) << endl
		<< "сумма нечётных = " << sums(false) << endl;
}