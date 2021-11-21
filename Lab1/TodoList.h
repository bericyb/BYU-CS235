#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include "TodoListInterface.h"
#include <fstream>
#include <vector>

using namespace std;

class TodoList : public TodoListInterface {
public:
    std::vector<string> myTasks;
    TodoList() {
        ifstream infile ("TODOList.txt");
        string line;
        if (infile.is_open()) {
            while(getline (infile, line)) {
                myTasks.push_back(line);
            }
            infile.close();
        }
    }
    virtual ~TodoList() {
        ofstream outfile;
        outfile.open ("TODOList.txt", ofstream::out | ofstream::trunc);
        for (int i = 0; i < myTasks.size(); i++) {
            outfile << myTasks[i] << endl;
        }
        outfile.close();
    }

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task)
    {
        myTasks.push_back(_duedate+" "+_task);
    }

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task)
    {
        for(int i = 0; i < myTasks.size(); i++){
            int finder = 5000;
            finder = myTasks[i].find(_task);
            if(finder != -1) {
                myTasks.erase (myTasks.begin() + i);
                cout << "Task #" << i+1 << " deleted." << endl;
                return 1;
            }
        }
        cout << "No match found" << endl;
        return 0;
    }

    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList()
    {
        for (int i = 0; i < myTasks.size(); i++) {
            cout << myTasks[i] << endl;
        }
    }

    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date)
    {
        for (int i = 0; i < myTasks.size(); i++) {
            int finder = -1;
            finder = myTasks[i].find(_date);
            if(finder != -1) {
                int space = myTasks[i].find(" ");
                cout << myTasks[i].substr(space + 1) << endl;
            }
        }
        cout << "All tasks for "  << _date << endl;
    }
};
#endif
