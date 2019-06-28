#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Reader {
  public:
    virtual void read (void) =0;
};

class ReaderTask : Reader {
public:
  std:: vector <std:: string> read (std:: string path) {
  std:: vector <std:: string> vec;
  std:: fstream dataFile (path);
  while (dataFile) {
    std:: string str;
    std:: getline (dataFile, str);
    if (str != "\0") {
    vec. push_back (str);
    }
  }
  return vec;
  }
};

class DecideTask {
private:
  std:: string typeTasks = "^+-*/";
  int degree (std:: string *task) { return 0; }
  int amount (std:: string *task) {
  int item1 = stoi (task [0]);
  int item2 = stoi (task [2]);
  int result = item1 + item2;

  return result;

  }

  int subtraction (std:: string *task) {
  int item1 = stoi (task [0]);
  int item2 = stoi (task [2]);
  int result = item1 - item2;
 
  return result;

  }

  int multiplication (std:: string *task) {
  int item1 = stoi (task [0]);
  int item2 = stoi (task [2]);
  int result = item1 * item2;

  return result;

  }

  int division (std:: string *task) {
  int item1 = stoi (task [0]);
  int item2 = stoi (task [2]);
  int result = item1 / item2;

  return result;

  }

public:
  int selectNumberTypeTask (std:: string &strNumberTypeTask) {
  int numberTypeTask = stoi (strNumberTypeTask);

  return numberTypeTask - 1;

  }

  bool checkTypeTask (int numberTask, std:: string &strTask) {
  char task = strTask [1];
  char typeTask = this -> typeTasks [numberTask];
  if (typeTask == task) {
  
    return true;

  }

  return false;

  }

  int print (std:: string msg) {
  std:: cout << "\n" << msg << "\n";

  return 0;

  }

  int run (std:: vector <std:: string> &vec) {
  int numberTypeTask = this -> selectNumberTypeTask (vec [0]);
  if (this -> checkTypeTask (numberTypeTask, vec [1]) == false) {
    this -> print ("Ошибка! Тип примера не верен!");

    return 1;

  }

  return 0;

  }

};

int main () {
  ReaderTask readerTask;
  DecideTask decideTask;
  std:: vector <std:: string> vec = readerTask. read ("./task.txt");
  decideTask. run (vec);

  return 0;
}