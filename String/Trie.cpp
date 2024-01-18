
//Ref: shafaetsplanet

#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<climits>
#include<cstdlib>
#include<climits>
#include<utility>
using namespace std;

struct node {
	bool endmark;
	node* next[26+1];
	node() {
		endmark = false;
		for(int i=0; i<26; i++) {
			next[i] = NULL;
		}
	}
} *root;

void insert(string str) {
	int len = str.size();
	node* curr = root;
	for(int i=0; i<len; i++) {
		int id = str[i] - 'a';
		if(curr->next[id] == NULL) {
			curr->next[id] = new node();
		}
		curr = curr->next[id];
	}
	curr->endmark = 1;
}

bool search(string str) {
	int len = str.size();
	node* curr = root;
	for(int i=0; i<len; i++) {
		int id = str[i] - 'a';
		if(curr->next[id] == NULL) {
			return false;
		}
		curr = curr->next[id];
	}
	return curr->endmark;
}


//if there are multiple test cases, delete all nodes at each test case
//send root as parameter
void del(node* curr) {
	for(int i=0; i<26; i++) {
		if(curr->next[i])
			del(curr->next[i]);
	}

	delete(curr);
}

int main()
{
	root = new node();

	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		string word;
		cin>>word;
		insert(word);
	}

	int m;
	cin>>m;
	for(int i=0; i<m; i++) {
		string word;
		cin>>word;
		if(search(word))
			cout <<"FOUND\n";
		else
			cout << "NOT FOUND\n";
	}

	del(root);
}