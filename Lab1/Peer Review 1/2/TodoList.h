#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TodoListInterface.h"

using namespace std;

class TodoList: public TodoListInterface {
public:
	vector <string> tasks;
	TodoList() {
		cout << "In Constructor\n";
		ifstream myfile("TODOList.txt");
		if (myfile.is_open()) {
			string line;
			while (getline(myfile, line)) {
				cout << line << endl;
				tasks.push_back(line);
			}
			myfile.close();
		}
	}
	virtual ~TodoList() {
		cout << "In Destructor\n";
		ofstream outfile;
		outfile.open("TODOList.txt", ofstream::out | ofstream::trunc);
		for (int i = 0; i < tasks.size(); i++) {
			outfile << tasks[i] << endl;
		}
	}

	virtual void add(string _duedate, string _task) {
		cout << "In add\n";
		tasks.push_back(_duedate);
		tasks.push_back(_task);
		cout << "End add\n";
	}

	virtual int remove(string _task) {
		cout << "In remove\n";
		for (int i = 0; i < tasks.size(); i++) {
			if (tasks[i] == _task) {
				tasks.erase(tasks.begin() + i - 1);
				tasks.erase(tasks.begin() + i - 1);
				cout << "Task Removed\n";
				return 1;
			}
		}
		cout << "No task Removed\n";
		return 0;
	}

	/*
	*   Prints out the full todo list to the console
	*/
	virtual void printTodoList() {
		cout << "In print list\n";
		for (int i = 0; i < tasks.size(); i++) {
			cout << tasks[i] << endl;
		}
		cout << "End print list\n";
	}

	/*
	*   Prints out all items of a todo list with a particular due date (specified by _duedate)
	*/
	virtual void printDaysTasks(string _date) {
		cout << "In print day\n";
		for (int i = 0; i < tasks.size(); i++) {
			if (tasks[i] == _date) {
				cout << tasks[i + 1] << endl;
			}
		}
		cout << "End print day\n";
	}
};

#endif