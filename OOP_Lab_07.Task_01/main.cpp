#include <iostream>
#include <deque>
#include <algorithm>
#include <fstream>

using namespace std;

template <typename T> void DequeReverse(deque<T>* Deque);
template <typename T> void PrintDeque(ostream& out, deque<T>* Deque);
template <typename T> void GetDeque(istream& in, deque<T>* Deque);
void OpenFile(fstream& file, std::ios_base::openmode mode);

int main()
{
	try {
		fstream fin, fout;
		deque<int>* Deque = new deque<int>;
		cout << "\nIf number is even it will be added to the end of que, else - to the beginning of que\n"
			 << "\n*Entering from console*\n"
			 << "\nFor stopping enter the non-numeric value\n";
		GetDeque(cin, Deque);
		OpenFile(fin, fstream::in);
		GetDeque(fin, Deque);
		OpenFile(fout, fstream::out);
		cout << "\nDeque before reverse:\n";
		fout << "\nDeque before reverse:\n";
		PrintDeque(fout, Deque);
		PrintDeque(cout, Deque);
		DequeReverse(Deque);
		cout << "\nDeque after reverse:\n";
		fout << "\nDeque after reverse:\n";
		PrintDeque(fout, Deque);
		PrintDeque(cout, Deque);
		delete Deque;
		return 0;
	}
	catch (const string error)
	{
		cout << "Error: " << error;
	}
}

template<typename T> void DequeReverse(deque<T>* Deque)
{
	typename deque<T>::iterator begin = Deque->begin();
	typename deque<T>::iterator end = Deque->end();
	std::reverse(begin, end);
}

template<typename T> void PrintDeque(ostream& out, deque<T>* Deque)
{
	for (int value : *Deque)
	{
		out << "  " << value << endl;
	}
}

template<typename T> void GetDeque(istream& in, deque<T>* Deque)
{
	int tmp;
	int parity;
	while (in >> tmp)
	{
		parity = tmp & 1;
		if (1 == parity)
		{
			Deque->push_front(tmp);
		}
		else
		{
			Deque->push_back(tmp);
		}
	}
}

void OpenFile(fstream& file, std::ios_base::openmode mode)
{
	string FileName;
	if (std::ios_base::in == mode)
	{
		cout << "\nEnter the file name for enetering data:  ";
	}
	else if (std::ios_base::out == mode)
	{
		cout << "\nEnter the file name for outputting data:  ";
	}
	else
	{
		throw "incorrect mode for file opening!";
	}

	constexpr auto size_of_error_string = numeric_limits<streamsize>::max();
	cin.clear();
	cin.ignore(size_of_error_string,'\n');

	cin >> FileName;
	file.open(FileName, mode);
	if (!file.is_open())
	{
		throw "can not open file \"" + FileName + "\"!";
	}
}