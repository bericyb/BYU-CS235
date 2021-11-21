#include <iostream>
#include <fstream>
#include "TodoList.h"
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	TodoList mylist;
	for (int i = 0; i < argc; i++) {
		cout << "argc[" << i << "]=" << argv[i] << endl;
	}
	string taskInput = argv[1];
	if (taskInput == "add") {
		cout << "Doing an add\n";
		string addDate = argv[2];
		string addTask = argv[3];
		cout << "Date: " << addDate << endl << "Task: " << addTask << endl;
		mylist.add(addDate, addTask);
	}
	else if (taskInput == "remove") {
		cout << "Doing a remove\n";
		string removeTask = argv[2];
		cout << "Task: " << removeTask << endl;
		mylist.remove(removeTask);
	}
	else if (taskInput == "printList") {
		cout << "Doing a print list\n";
		mylist.printTodoList();
	}
	else if (taskInput == "printDay") {
		cout << "Doing a print day\n";
		string printDate = argv[2];
		mylist.printDaysTasks(printDate);
	}
	else {
		cout << "Input not recongnized\n";
	}
}
