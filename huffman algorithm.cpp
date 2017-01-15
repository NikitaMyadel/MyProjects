#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath> 

using namespace std;

struct Node
{
	double key;
	Node* parent;

	bool operator()(const Node* a, const Node* b) const
	{
		return a->key < b->key;
	}
};

int length(Node* node)
{
	if (node->parent == NULL)
		return 0;
	else
		return length(node->parent) + 1;
}


int main()
{
	setlocale(LC_ALL, "russian");

	vector < Node* > v;
	vector < Node* > v2;
	vector < Node* > v3;

	int k;
	cout << "Введите количество узлов k: ";
	cin >> k;

	cout << "Введите веро€тность  дл€ каждого узла" << endl;
	
	while (k > 0)
	{
		double value;
		cin >> value;
		Node* node = new Node;
		node->key = value;
		node->parent = NULL;
		v.push_back(node);
		v3.push_back(node);
		k--;
	}

	double sum = 0;

	for (Node* n : v3)
		sum += n->key;
	

	if (abs(sum - 1)>0.00000001)
	{
		cout << "Сумма веро€тностей узлов не равна 1" << endl;
		return 1;
	}	

	while (v.begin() != v.end() - 1)
	{

		sort(v.rbegin(), v.rend(), Node());

		Node* k1 = *(v.end() - 1);
		Node* k2 = *(v.end() - 2);

		Node* root = new Node;
		root->parent = NULL;

		root->key = k1->key + k2->key;
		k1->parent = root;
		k2->parent = root;

		v2.push_back(k1);
		v2.push_back(k2);

		v.erase(v.end() - 1);
		v.erase(v.end() - 1);
		v.push_back(root);
	}

	Node* end_node = *v.begin();
	v2.push_back(end_node);
	v.clear();	

	double W=0;

	for (Node* n : v3)
		W += (n->key)*length(n);

	cout << "\nСредн€€ длина кодового слова равна " << W << endl;

	double H = 0;

	for (Node* n : v3)
		H += -(n->key)*log2(n->key);

	cout << "\nЭнтропи€ источника сообщений равна " << H << endl<<endl;

	return 0;
}