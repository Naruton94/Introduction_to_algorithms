#include <vector>
#include <iostream>
using namespace std;
int h (int k) {
	// ³Ë·¨É¢ÁÐº¯Êý
	const double A = 0.6180339887;
	int m = 8;
	double rel = k * A;
	rel = rel - static_cast<int>(rel);
	rel = m * rel;
	return static_cast<int>(rel);
}
class Hpair {
public:
	Hpair() = default;
	Hpair(int k, int v) :key(k), value(v) {}
	int key = 0;
	int value = 0;
};
class HashTable {
public:
	Hpair& searchH(int k);
	int search(int k);
	bool insert(int k, int v);
	void re_key(int k);
private:
	vector<vector<Hpair>> T;

};
Hpair& HashTable::searchH(int k)
{
	if (h(k) < T.size()) {
		auto &tmp = T[h(k)];
		for (int i = 0; i < tmp.size(); ++i) {
			if (tmp[i].key == k)
				return tmp[i];
		}
		Hpair vo(INT_MAX, INT_MAX);
		return vo;
	}
	Hpair vo(INT_MAX, INT_MAX);
	return vo;
}
int HashTable::search(int k)
{
	if (searchH(k).key == k)
		return searchH(k).value;
	else
		return INT_MAX;
}

bool HashTable::insert(int k, int v)
{
	Hpair *tmp = new Hpair(k, v);
	int index = h(k);
	if (index >= T.size()) {
		T.resize(index + 1);
	}
	T[index].push_back(*tmp);
	delete tmp;
	return true;
}
void HashTable::re_key(int k)
{
	int index = h(k);
	if (index >= T.size())
		return;


	searchH(k).key = INT_MAX;
	searchH(k).value = INT_MAX;


}