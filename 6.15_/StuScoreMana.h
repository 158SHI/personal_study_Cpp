#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

class StuMana
{
	friend ostream& operator<<(ostream& cout, const StuMana& mana)
	{
		printf("%9s\t%9s\t%7s\t%7s\t%7s\t%7s\t%7s\t%7s\t%12s\n", "name", "number",
			"Math Score", "English Score", "DS_ Score", "_Net Score", "_SQL Score",
			"Total", "Avarage");
		for (auto& stu : mana._stus) {
			cout << stu << endl;
		}
		return cout;
	}

private:
	struct Score
	{
		size_t _MathScore;
		size_t _EnglishScore;
		size_t _DS_Score;
		size_t _NetScore;
		size_t _SQL_Score;
		size_t _Total;
		size_t _Avarage;
		
		Score(size_t MathScore = 0, size_t EnglishScore = 0, 
			size_t DS_Score = 0, size_t NetScore = 0, size_t SQL_Score = 0)
			:_MathScore(MathScore),
			_EnglishScore(EnglishScore),
			_DS_Score(DS_Score),
			_NetScore(NetScore),
			_SQL_Score(SQL_Score),
			_Total(MathScore + EnglishScore + DS_Score + NetScore + SQL_Score),
			_Avarage(_Total / 5)
		{ }
	};

	struct Stu
	{
		friend ostream& operator<<(ostream& cout, const Stu& stu)
		{
			printf("%9s\t%9s\t%9u\t%9u\t%9u\t%9u\t%8u\t%8u\t%9u", stu._name.c_str(),
				stu._num.c_str(), stu._score._MathScore, stu._score._EnglishScore, 
				stu._score._DS_Score, stu._score._NetScore, stu._score._SQL_Score, 
				stu._score._Total, stu._score._Avarage);
			return cout;
		}

		friend ofstream& operator<<(ofstream& file, const Stu& stu)
		{
			file << stu._name << ' ' << stu._num << ' ' << stu._score._MathScore << ' ' <<
				stu._score._EnglishScore << ' ' << stu._score._DS_Score << ' ' <<
				stu._score._NetScore << ' ' << stu._score._SQL_Score << ' ' <<
				stu._score._Total << ' ' << stu._score._Avarage;
			return file;
		}

		friend istream& operator>>(istream& cin, Stu& stu)
		{
			cout << "name:"; cin >> stu._name;
			cout << "student num:"; cin >> stu._num;
			cout << "Math Score:"; cin >> stu._score._MathScore;
			cout << "English Score:"; cin >> stu._score._EnglishScore;
			cout << "DS_ Score:"; cin >> stu._score._DS_Score;
			cout << "Net Score:"; cin >> stu._score._NetScore;
			cout << "SQL_ Score:"; cin >> stu._score._SQL_Score;
			stu._score._Total = stu._score._MathScore + stu._score._EnglishScore +
				stu._score._DS_Score + stu._score._NetScore + stu._score._SQL_Score;
			stu._score._Avarage = stu._score._Total / 5;
			return cin;
		}

		string _name;
		string _num;
		Score _score;
		
		Stu()
		{
			_score._MathScore = _score._EnglishScore = _score._SQL_Score =
				_score._DS_Score = _score._Total = _score._Avarage 
				= _score._NetScore = 0;
		}
	};


private:
	static bool _compare(const Stu& s1, const Stu& s2)
	{
		if (s1._score._Total < s2._score._Total) {
			return true;
		}
		else {
			return false;
		}
	}

	list<Stu>::iterator _search()
	{
		string _NumToSearch;
		cout << "Student Num:"; cin >> _NumToSearch;
		auto it = _stus.begin();
		for (; it != _stus.end(); ++it)
		{
			if (it->_num == _NumToSearch) {
				return it;
			}
		}
		return _stus.end();
	}

private:
	list<Stu> _stus;
	static const char* filename;

public:
	void Load()
	{
		ifstream file(filename);
		while (file && file.peek() != EOF)
		{
			Stu newStu;
			while (file)
			{
				file >> newStu._name >> newStu._num >>
					newStu._score._MathScore >> newStu._score._EnglishScore >>
					newStu._score._DS_Score >> newStu._score._NetScore >>
					newStu._score._SQL_Score >> newStu._score._Total >>
					newStu._score._Avarage;
				_stus.push_back(newStu);
				break;
			}
		}
		_stus.pop_back();
		file.close();
	}

	void Save()
	{
		ofstream file(filename);
		for (auto& stu : _stus) {
			file << stu << endl;
		}
		file << '$';
		file.close();
	}

	void Push()
	{
		Stu newStu;
		cin >> newStu;
		_stus.push_back(newStu);
	}

	Stu& Search()
	{
		auto it = _search();
		if (it != _stus.end()) {
			return *it;
		}
		else {
			cout << "Not Found" << endl;
		}
	}

	void Delete()
	{
		auto it = _search();
		if (it == _stus.end()) {
			cout << "Not Found" << endl;
			return;
		}
		_stus.erase(it);
		cout << "Delete Complete" << endl;
	}

	void Modify()
	{
		auto it = _search();
		if (it == _stus.end()) {
			cout << "Not Found" << endl;
			return;
		}
		cin >> (*it);
		cout << "Modify Complete" << endl;
	}

	void Sort()
	{
		_stus.sort(_compare);
	}
};

const char* StuMana::filename = "data.txt";