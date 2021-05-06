#include <iostream>

using namespace std;

struct Partisipators {
	char surname[20];
	int place;
	double points;
}partisipator[7];

char ToUpper(char);
char ToLower(char);
void DoubleHash(Partisipators*, Partisipators, int, int);
void HashTable(Partisipators*, int, int, int);
void ViewHashTable(Partisipators*, int);
int HashFun1(int, int);
int HashFun2(int, int);
int Find(Partisipators*, int, int, int, int);

int main()
{
	int const M = 15;
	int const N = 7;
	int const Simple = 13;

	Partisipators hashtable[M];

	for (int i = 0; i < N; i++)
	{
		cout << "Enter the last name of " << i + 1 << " partisipator: ";
		cin >> partisipator[i].surname;
		partisipator[i].surname[0] = ToUpper(partisipator[i].surname[0]);
		for (int j = 1; j < strlen(partisipator[i].surname); j++)
			partisipator[i].surname[j] = ToLower(partisipator[i].surname[j]);
		cout << "Enter the points of " << i + 1 << " partisipator: ";
		cin >> partisipator[i].points;
		cout << "Enter the place of " << i + 1 << " partisipator: ";
		cin >> partisipator[i].place;
		cout << endl;
	}

	HashTable(hashtable, N, M, Simple);

	return 0;
	}

char ToUpper(char ch) {
	if (ch >= 'a' && ch <= 'z')
		return (char)(ch - 32);
	return ch;
}

char ToLower(char ch) {
	if (ch >= 'A' && ch <= 'Z')
		return (char)(ch + 32);
	return ch;
}

void DoubleHash(Partisipators* hashtable, Partisipators key, int M, int Simple)
{
	int index = HashFun1(key.place, Simple);

	if (hashtable[index].place != -1)
	{
		int index2 = HashFun2(key.place, Simple);
		int i = 1;
		while (1)
		{
			int newIndex = (index + i * index2) % M;
			if (hashtable[newIndex].place == -1)
			{
				hashtable[newIndex] = key;
				break;
			}
			i++;
		}
	}
	else
		hashtable[index] = key;
}

void HashTable(Partisipators* hashtable, int N, int M, int SIMPLE) {
	int find;
	for (int i = 0; i < M; i++)
		hashtable[i].place = -1;
	for (int i = 0; i < N; i++) {
		DoubleHash(hashtable, partisipator[i], M, SIMPLE);
	}
	cout << "Enter the search element: ";
	cin >> find;
	cout << endl;
	ViewHashTable(hashtable, M);
	Find(hashtable, N, M, SIMPLE, find);
}

void ViewHashTable(Partisipators* hashtable, int M) {
	cout << "Hash-Table:" << endl;
	for (int i = 0; i < M; i++)
		cout << "hashTable[" << i << "]: " << hashtable[i].place << endl;
	cout << endl;
}

int HashFun1(int key, int M) {
	return (key % M);
}

int HashFun2(int key, int SIMPLE) {
	return (SIMPLE - (key % SIMPLE));
}

int Find(Partisipators *hashtable, int N, int M, int SIMPLE, int find) {
	int index1 = HashFun1(find, M);
	int index2 = HashFun2(find, SIMPLE);
	int i = 0;
	while (i < M) {
		if (hashtable[index1].place == find) {
			cout << "Item found: " << endl << hashtable[index1].surname << endl << hashtable[index1].place << endl << hashtable[index1].points << endl;
			return 0;
		}
		index1 = (index1 + i * index2) % M;
		i++;
	}
	cout << "Item not found";
	return 1;
}

