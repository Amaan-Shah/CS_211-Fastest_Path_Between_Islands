// Amaan Shah, UIC, Spring 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#include "header.h"

// MyNode:
MyNode :: MyNode(int n) {
	val = n;
	next = nullptr;
}
      
MyNode :: MyNode(int a, MyNode* n) {
	val = a;
    next = n;
}

void MyNode :: setVal(int n) {
	val = n;
}

int MyNode :: getVal() {
	return val;
}

void MyNode :: setNext(MyNode* n) {
	next = n;
}

MyNode* MyNode :: getNext() {
	if (next == nullptr){
		return nullptr;
	}
	return next;
}



// FileNode:
FileNode :: FileNode(string n) {
	val = n;
    next = nullptr;
}
      
FileNode :: FileNode(string a, FileNode* n) {
    val = a;
    next = n;
}

void FileNode :: setVal(string n) {
    val = n;
}

string FileNode :: getVal() {
    return val;
}

void FileNode :: setNext(FileNode* n) {
    next = n;
}

FileNode* FileNode :: getNext() {
    if (next == nullptr){
		return nullptr;
	}
	return next;
}



// MyList:
MyList :: MyList() {
   head = nullptr;
}

// MyList :: ~MyList() {
//    	MyNode* cur = this->head;
// 	MyNode* temp = nullptr;

// 	while (cur != nullptr) {
// 		temp = cur;
// 		cur = cur->getNext();
// 		delete temp;
// 	}
// 	this->head = nullptr;
// }

void MyList :: push_front(int v) {
	MyNode* temp = new MyNode(v);
	temp->setNext(head);
	head = temp;
}

void MyList :: push_back(int v) {
	MyNode* cur = head;
	MyNode* temp = new MyNode(v);
	if (cur == nullptr) {
		head = temp;
		return;
	}
	while (cur->getNext() != nullptr) {
		cur = cur->getNext();
	}
	cur->setNext(temp);
	return;
}

void MyList :: pop() {
	MyNode* temp = head;
	if (temp != nullptr) {
		head = temp->getNext();
		delete temp;
	}
}

MyNode* MyList :: top() {
	return head;
}

bool MyList :: is_empty() {
	if (head == nullptr) {
		return true;
	} else {
		return false;
	}
}

void MyList :: removeNode(int v) {
	MyNode* curr = head;
	MyNode* prev = NULL;
	  
	while ( ( curr != NULL ) && ( curr->getVal() != v ) )
	{
	  prev = curr;
   	  curr = curr->getNext();
	}

	if ( curr == NULL )
	  return;

	if ( prev == NULL )
	{
	  head = curr->getNext();
	  delete curr;
	}
	else
	{
	  prev->setNext( curr->getNext() );
	  delete curr;
	}
}

bool MyList :: containsDest(int x) {
	MyNode* temp = head;
	while (temp != nullptr){
		if (temp->getVal() == x) {
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

void MyList :: show() {
	MyNode* temp = head;
	while (temp != nullptr) {
		cout << "  " << temp->getVal();
		temp = temp->getNext();
	}
	cout << endl;
}





// FileList:
FileList :: FileList() {
    head = nullptr;
}

// FileList :: ~FileList() {
//     FileNode* cur = this->head;
// 	FileNode* temp = nullptr;
	
// 	while (cur != nullptr) {
// 		temp = cur;
// 		cur = cur->getNext();
// 		delete temp;
// 	}
// 	this->head = nullptr;
// }

void FileList :: push_front(string v) {
	FileNode* temp = new FileNode(v);
	temp->setNext(head);
	head = temp;
}

void FileList :: push_back(string v) {
	FileNode* cur = head;
	FileNode* temp = new FileNode(v);
	if (cur == nullptr) {
		head = temp;
		return;
	}
	while (cur->getNext() != nullptr) {
		cur = cur->getNext();
	}
	cur->setNext(temp);
	return;
}

void FileList :: pop() {
	FileNode* temp = head;
	if (temp != nullptr) {
		head = temp->getNext();
		delete temp;
	}
}

FileNode* FileList :: top() {
	return head;
}

bool FileList :: is_empty() {
	if (head == nullptr) {
		return true;
	} else {
		return false;
	}
}

void  FileList :: removeNode(string v) {
	FileNode* curr = head;
	FileNode* prev = NULL;
	  
	while ( ( curr != NULL ) && ( curr->getVal() != v ) )
	{
	  prev = curr;
	  curr = curr->getNext();
	}

	if ( curr == NULL )
	  return;

	if ( prev == NULL )
	{
	  head = curr->getNext();
	  delete curr;
	}
	else
	{
	  prev->setNext( curr->getNext() );
	  delete curr;
	}
}

bool FileList :: containsFile(string x) {
	FileNode* temp = head;
	while (temp != nullptr){
		if (temp->getVal() == x) {
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}



// Island:
Island :: Island() {
	visited = false;
	prev = -1;
}

void Island :: setVisited(bool x) {
	visited = x;
}

bool Island :: getVisited() {
	return visited;
}

void Island :: setPrev(int x) {
	prev = x;
}

int Island :: getPrev() {
	return prev;
}

void Island :: insert(int x) {
	if (adjList.containsDest(x) == true) {
		cout << "Ferry ride already added!" << endl;
		return;
	}
	adjList.push_back(x);
}

void Island :: remove(int x) {
	if (adjList.containsDest(x) == false) {
		cout << "Ferry ride does not exist" << endl;
		return;
	}
	adjList.removeNode(x);
}

void Island :: printList() {
	adjList.show();
}

MyNode* Island :: setTop() {
	return adjList.top();
}




// ArchipelagoExpedition
ArchipelagoExpedition :: ArchipelagoExpedition() {
  darr = new Island[10];
  size = 10;
}

// ArchipelagoExpedition :: ~ArchipelagoExpedition() {
// 	delete[] darr;
// 	size = 0;
// }

void ArchipelagoExpedition :: resize (int a) {
	delete[] darr;
  	darr = new Island[a + 1];
  	this->size = a;
}
  
void ArchipelagoExpedition :: processCommandLoop (FILE* inFile) {
  char  buffer[300];
  char* input;

  input = fgets ( buffer, 300, inFile );   
  while (input != NULL) {
    char* command;
    command = strtok (input , " \r\n\t");
    printf ("*%s*\n", command);
    
    if (command == NULL)
      printf ("Blank Line\n");
 
    else if ( strcmp (command, "q") == 0) 
      return;
     
    else if ( strcmp (command, "?") == 0) 
      showCommands();
     
    else if ( strcmp (command, "t") == 0) 
      doTravel();
     
    else if ( strcmp (command, "r") == 0) 
      doResize();

    else if ( strcmp (command, "i") == 0) 
      doInsert();

    else if ( strcmp (command, "d") == 0) 
      doDelete();

    else if ( strcmp (command, "l") == 0) 
      doList();

    else if ( strcmp (command, "f") == 0) 
      doFile();

    else if ( strcmp (command, "#") == 0) 
      ;
     
    else
      printf ("Command is not known: %s\n", command);
     
    input = fgets ( buffer, 300, inFile );
  }
}
 
void ArchipelagoExpedition :: showCommands() {
   printf ("The commands for this project are:\n");
   printf ("  q\n");
   printf ("  ?\n");
   printf ("  #\n");
   printf ("  t <int1> <int2>\n");
   printf ("  r <int>\n");
   printf ("  i <int1> <int2>\n");
   printf ("  d <int1> <int2>\n");
   printf ("  l\n");
   printf ("  f <filename>\n");
}
 
void ArchipelagoExpedition :: doTravel() {
	int val1 = 0;
   	int val2 = 0;

    char* next = strtok (NULL, " \n\t");
  
   	if (next == NULL)
	{
	    printf ("Integer value expected\n");
	    return;
	}
	val1 = atoi (next);
	if (val1 == 0 && strcmp (next, "0") != 0)
	{
	    printf ("Integer value expected\n");
	    return;
	}
	   
	next = strtok (NULL, " \n\t");

	if ( next == NULL )
	{
	    printf ("Integer value expected\n");
	    return;
	}
	val2 = atoi ( next );
	if ( val2 == 0 && strcmp (next, "0") != 0)
	{
	    printf ("Integer value expected\n");
	    return;
	}
	printf ("Performing the Travel Command from %d to %d\n", val1, val2);
	   
	MyList Path = breadthFirstSearch(val1, val2);

	if (Path.is_empty() == false) {
		MyNode* island = Path.top();
	   	cout << "shortest path from " << val1 << " to " << val2 << ":";

		cout << " " << island->getVal();
		island = island->getNext();

	   	while (island != nullptr) {
	   		cout << " - " << island->getVal();
	   		island = island->getNext();
	   	}
	   	cout << endl;
	}
 }
 
MyList ArchipelagoExpedition :: breadthFirstSearch(int x, int y) {
 	for (int i = 1; i < size + 1; i++) {
 		darr[i].setVisited(false);
 		darr[i].setPrev(-1);
 	}

 	MyList IslandQ;
 	MyList Path;
 	IslandQ.push_back(x);
 	if (bfs(y, IslandQ) == false) {
 		cout << "You can NOT get from island " << x << " to island " << y << endl;
 		return Path;
 	}

 	cout << "You can get from island " << x << " to island " << y << endl;
 	int currentIsland = y;
 	Path.push_front(currentIsland);
 	while (true) {
 		currentIsland = darr[currentIsland].getPrev();
 		if (currentIsland == x) {
 			Path.push_front(currentIsland);
 			break;
 		}
 		Path.push_front(currentIsland);
 	}
 	return Path;
}

bool ArchipelagoExpedition :: bfs(int b, MyList IslandQ) {
 	while (IslandQ.is_empty() == false) {
 		int a = IslandQ.top()->getVal();
 		IslandQ.pop();

 		MyNode* neighbor = darr[a].setTop();
 		while (true) {
 			if (neighbor == nullptr) {
 				break;
 			}
 			int c = neighbor->getVal();
 			if(darr[c].getPrev() == -1) {
 				darr[c].setVisited(true);
 				darr[c].setPrev(a);
 				if (c == b) {
 					return true;
 				}
 				IslandQ.push_back(c);
 			}
 			neighbor = neighbor->getNext();
 		}
 	}
 	return false;
}

void ArchipelagoExpedition :: doResize() {
   int val = 0;
   char* next = strtok (NULL, " \n\t");
   if (next == NULL)
   {
     printf ("Integer value expected\n");
     return;
   }
   val = atoi ( next );
   if (val <= 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   printf ("Performing the Resize Command with %d\n", val);

   resize(val);
}
 
void ArchipelagoExpedition :: doInsert() {
 	int src = 0;
 	int dest = 0;
 	char* next = strtok (NULL, " \n\t");
	if (next == NULL)
	{
	  printf ("Integer value expected\n");
	  return;
	}

	src = atoi(next);
	if (src <= 0 || src > this->size)
	{
	   cout << "Invalid value for island" << endl;
	   return;
	}

	next = strtok (NULL, " \n\t");
	if (next == NULL)
    {
      printf ("Integer value expected\n");
      return;
    }

    dest = atoi(next);
    if (dest <= 0 || dest > this->size)
	{
	   cout << "Invalid value for island" << endl;
	   return;
	}

	if (src == dest) {
		cout << "Can not add ferry ride to self" << endl;
		return;
	}

 	cout << "Performing the Insert Command for " << src << endl;

 	darr[src].insert(dest);
}
 
void ArchipelagoExpedition :: doDelete() {
 	int src = 0;
 	int dest = 0;
 	char* next = strtok (NULL, " \n\t");
	if (next == NULL)
	{
	  printf ("Integer value expected\n");
	  return;
	}

	src = atoi(next);
	if (src <= 0 || src > this->size)
	{
	   cout << "Invalid value for island" << endl;
	   return;
	}

	next = strtok (NULL, " \n\t");
	if (next == NULL)
    {
      printf ("Integer value expected\n");
      return;
    }

    dest = atoi(next);
    if (dest <= 0 || dest > this->size)
	{
	   cout << "Invalid value for island" << endl;
	   return;
	}
 	cout << "Performing the Delete Command for " << src << endl;
 	darr[src].remove(dest);
}
 
void ArchipelagoExpedition :: doList() {
   	cout << "Displaying the adjacency list:" << endl;
 	for (int i = 1; i < size + 1; i++) {
 		cout << i << " -->";
 		darr[i].printList();
 	}
}

void ArchipelagoExpedition :: doFile() {
   // get a filename from the input
   char* fname = strtok (NULL, " \r\n\t");
   if ( fname == NULL )
   {
     printf ("Filename expected\n");
     return;
   }
   
   printf ("Performing the File command with file: %s\n", fname);
   
   // next steps:  (if any step fails: print an error message and return ) 
   //  1. verify the file name is not currently in use
   if (file.containsFile(fname) == true) {
   	cout << "File is already in use" << endl;
   	return;
   }
   //  2. open the file using fopen creating a new instance of FILE*
   FILE* infile;
   infile = fopen(fname, "r");
   if (infile == NULL) {
   	cout << "Cannot open the file" << endl;
   	return;
   }
   file.push_back(fname);

   //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
   this->processCommandLoop(infile);
   //  4. close the file when processCommandLoop() returns
   fclose(infile);
   file.removeNode(fname);
}