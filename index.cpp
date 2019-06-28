#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>

class Reader {
  public:
    virtual void read (void) =  0;
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

class Decider {
  private:
  void degree (void) = 0;
  void amount (void) = 0;
  void subtraction (void) = 0;
  void multiplication (void) = 0;
  void division (void) = 0;
public:
  void selectNumberTypeTask (void) = 0;
  void checkTypeTask (void) = 0;
  void run (void);
};

class DecideTask : public Decider{
private:
  std:: string typeTasks = "^+-*/";
  int (DecideTask:: *meths [5]) (std:: string *) = {&DecideTask:: degree, &DecideTask:: amount, &DecideTask:: subtraction, &DecideTask:: multiplication, &DecideTask:: division};

  int degree (std:: string *task) { // разделителем выступает "0"
  int a = 1;
  int b = stoi (task [2]);
  int c = stoi (task [5]);
  int d = (b*b) - (4 *a *c);
  int sqD = sqrt (d);
  int x1 = (b - (b*b)) + sqD;
  int x1 = (b - (b*b)) - sqD;
  std:: string result = std:: to_string (x1) + "0" std:: to_string (x2);
  int res = stoi (result);

  return  res;

  }


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