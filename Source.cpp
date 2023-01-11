#include <iostream> 
#include <vector> 
using namespace std;

// �����, ������� ������� ����� ������ � �������� �����
class summator : private vector<int> { 
public:
	summator(const vector<int>& ini) {
		for (auto x : ini) this->push_back(x);
	}

	int operator()(bool even) {
		int sum = 0;
		auto i = begin(); // �������� � ������ �������
		if (even) i++; // ���� even = true ����������� ��������
		while (i < end()) { // ���� �� �����
			sum += *i++; // ����� ������������� �� �������� ���������� ���������
			if (i == end()) break; // ���� �������� ����� �� ����� - break
			i++; // ����������� ��������
		}
		return sum; // ���������� �����
	}
};

int main(void) {
	setlocale(LC_ALL, "rus");

	summator sums(vector<int>({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }));

	cout << "����� ������ = " << sums(true) << endl
		<< "����� �������� = " << sums(false) << endl;
}