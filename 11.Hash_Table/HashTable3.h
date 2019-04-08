#include <vector>
#include <iostream>
using namespace std;
class Hpair {
public:
	Hpair() = default;
	Hpair(int k, int v) :key(k), value(v) {}
	int key = 0;
	int value = 0;
};
class HashTable {
public:
	bool insert(int k, int v); 
	int search(int k);
	bool rmKey(int k);
private:
	int m;
	vector<Hpair> T;
	int h(int, int);
	int h(int);
};