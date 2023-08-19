// Amaan Shah, UIC, Spring 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class MyNode
{
  private:
    int val;
    MyNode* next;

  public:
    MyNode(int n);
    MyNode(int a, MyNode* n);
    void setVal(int n);
    int getVal();
    void setNext(MyNode* n);
    MyNode* getNext();
};


class FileNode
{
  private:
    string val;
    FileNode* next;

  public:
    FileNode(string n);
    FileNode(string a, FileNode* n);
    void setVal(string n);
    string getVal();
    void setNext(FileNode* n);
    FileNode* getNext();
};


class MyList
{
  private:
    MyNode* head;

  public:
    MyList();
    //~MyList();
    void push_front(int v);
	void push_back(int v);
	void pop();
	MyNode* top();
	bool is_empty();
	void removeNode(int v);
	bool containsDest(int x);
	void show();
};

class FileList
{
  private:
    FileNode* head;

  public:
    FileList();
    //~FileList();
    void push_front(string v);
	void push_back(string v);
	void pop();
	FileNode* top();
	bool is_empty();
	void removeNode(string v);
	bool containsFile(string x);
};


class Island
{
	private:
		MyList adjList;
		bool visited;
		int prev;

	public:
		Island();
		void setVisited(bool x);
		bool getVisited();
		void setPrev(int x);
		int getPrev();
		void insert(int x);
		void remove(int x);
		void printList();
		MyNode* setTop();
};


class ArchipelagoExpedition
{
	private:
  		Island* darr;
  		int size;
  		FileList file;
  
  	public:
  		ArchipelagoExpedition();
		//~ArchipelagoExpedition();
		void resize (int a);
		void processCommandLoop (FILE* inFile);
		void showCommands();
		void doTravel();
		MyList breadthFirstSearch(int x, int y);
		bool bfs(int b, MyList IslandQ);
		void doResize();
		void doInsert();
		void doDelete();
		void doList();
		void doFile();
};

