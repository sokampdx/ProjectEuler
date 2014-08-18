#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

// global constant
const int MAX = 6000;
const string FILENAME = "pe022.txt";
const char DELIMITER = ',';

// global variable
string nameList[MAX];
unsigned long long result[MAX];
int size;

// node
struct node {
	string value;
	node * left;
	node * right;
};

// binary tree
class btree {
	public:
		btree();
		~btree();

		void insert(string key);
		void destroy(); 
		void display();
		void write();

	private:
		void insert(string key, node *leaf);
		void destroy(node *leaf);
		void display(node *leaf);
		int write(node *leaf, int position);

		node *root;
}; 

// constructor
btree::btree() {
	root = NULL;
}

// destructor
btree::~btree() {
	destroy();
}

// destroy the tree
void btree::destroy() {
	destroy(root);
}

// destroy a node
void btree::destroy(node *leaf) {
	if (leaf != NULL) {
		destroy(leaf->left);
		destroy(leaf->right);
		delete leaf;
	}
}

// insert a node
void btree::insert(string key, node *leaf) {
	int compare = key.compare(leaf->value);

	if (compare < 0) {
		if (leaf->left == NULL) {
			leaf->left = new node;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
			leaf->left->value = key;
		} else {
			insert(key, leaf->left);
		}
	} else {
		if (leaf->right == NULL) {
			leaf->right  = new node;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
			leaf->right->value = key;
		} else {
			insert(key, leaf->right);
		}
	}
}

// insert into tree
void btree::insert(string key) {
	if (root == NULL) {
		root = new node;
		root->left = NULL;
		root->right = NULL;
		root->value = key;
	} else {
		insert(key, root);
	}
}

// display the tree in order
void btree::display() {
	display(root);
}

// display the node
void btree::display(node *current) {
	if (current != NULL) {
		display(current->left);
		cout << current->value << endl;
		display(current->right);
	}
}

// write the list back
void btree::write() {
	write(root, 0);
}

// write each element
int btree::write(node *current, int position) {
	if (current == NULL)
		return position;

	int next = write(current->left, position);
	nameList[next] = current->value;
	return write(current->right, next+1);
}			
		






// read file
int readFile() {
	int isValid = 1;
	int position = 0;
	string line;
	ifstream myfile (FILENAME);

	// read file
	if (myfile.is_open())	{
		while (getline(myfile,line))	{		
   		// read line
			stringstream linestream(line);
			string data;

			while(getline(linestream, data, DELIMITER)) {	 
				nameList[position] = data.substr(1, data.length()-2);
				++position;
			}
		} // end while
		size = position;
		myfile.close();
	} else {
		cout << "File Read Error" << endl;
		isValid = 0;
	}
	
	return isValid;
}


// print name list
void printList() {
	for (int i = 0; i < size; ++i) {
		cout << nameList[i] << endl;
	}
}

// score each name
unsigned long long score(string name) {
	int limit = name.length();
	int total = 0;
	
	for (int i = 0; i < limit; ++i) {
		total += (name[i] - 'A' + 1);
	}
	return (unsigned long long) total;
}



// main program
int main () 
{
	unsigned long long result = 0;	
	unsigned long long temp = 0;
	btree nameTree;

	readFile();
	
	for (int i = 0; i < size; ++i) {
		nameTree.insert(nameList[i]);
	}		
	nameTree.write();

	for (int i = 0; i < size; ++i) {
		temp = (score(nameList[i]));
		cout << i << ":" << temp << ":" << nameList[i] << endl;
		result = result + (temp * ((unsigned long long) i+1));
	}

	cout << "The result = " << result << endl;

	return 0;
}

