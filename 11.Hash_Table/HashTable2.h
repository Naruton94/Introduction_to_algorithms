#include <vector>
#include <iostream>
using namespace std;
template<typename T>
int h (T key) {
	// ³Ë·¨É¢ÁÐº¯Êý
	T k = static_cast<T> (key);
	const double A = 0.6180339887;
	int m = 8;
	double rel = k * A;
	rel = rel - static_cast<int>(rel);
	rel = m * rel;
	return static_cast<int>(rel);
}

template<typename T1, typename T2>
class Hpair {
public:
	Hpair() = default;
	Hpair(T1 k, T2 v) :key(k), value(v) {}
	T1 key;
	T2 value;
};


template<typename T1, typename T2>
class HashTable {
public:
	Hpair<T1, T2>& searchH(T1 k);
	T2 search(T1 k);
	bool insert(T1 k, T2 v);
	void re_key(T1 k);
private:
	vector<vector<Hpair<T1, T2>>> T;
};
template<typename T1, typename T2>
Hpair<T1, T2>& HashTable<T1, T2>::searchH(T1 k)
{
	if (h(k) < T.size()) {
		auto &tmp = T[h(k)];
		for (int i = 0; i < tmp.size(); ++i) {
			if (tmp[i].key == k)
				return tmp[i];
		}

		exit(0);
		
	}
	exit(0);
}
template<typename T1, typename T2>
T2 HashTable<T1, T2>::search(T1 k)
{
	auto tmp = &searchH(k);
	if (tmp != nullptr)
		return tmp->value;
	if (tmp->key != k)
		cout << "Cannot find key = " << k << endl;
		return INT_MAX;
}
template<typename T1, typename T2>
bool HashTable<T1, T2>::insert(T1 k, T2 v)
{
	Hpair<T1, T2> *tmp = new Hpair<T1, T2>(k, v);
	int index = h(k);
	if (index >= T.size()) {
		T.resize(index + 1);
	}
	T[index].push_back(*tmp);
	delete tmp;
	return true;
}
template<typename T1, typename T2>
void HashTable<T1, T2>::re_key(T1 k)
{
	int index = h(k);
	if (index >= T.size())
		return;
	Hpair<T1, T2>& tmp = searchH(k);
	tmp.key = INT_MAX;
	tmp.value = INT_MIN;
}