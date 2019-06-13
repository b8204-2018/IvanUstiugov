#include <iostream>
#include <vector>
#include <fstream>
#include <string>




class ReadTask {
public:
  std::vector <std::string> read (std:: string path) {
  std::vector <std::string> vec;
  std::fstream dataFile (path);
  while (dataFile) {
    std::string str;
    std::getline (dataFile, str);
    if (str != "\0") {
    vec. push_back (str);
  }
 }
  return vec;
  }
};

class DecideTask {
private:
  std::vector <std::string> typeTasks = {"^", "+", "-", "*", "/"};
public:
  bool checkTypeTask (std:: string typeTask, std:: string task) {
    if (typeTask != task) {
      return false;
    }
    return true;
  }
  std:: string selectTypeTask (std::string numberTypeTask) {
    int numTask = stoi (numberTypeTask);
    std:: string typeTask = this -> typeTasks [numTask - 1];
  
    return typeTask;
  }
  int amount (std:: vector <int> task) {
    int result = task [0] + task [1];
  
    return result;
  }
  int difference (std:: vector <int> task) {
    int result = task [0] - task [1];
  
    return result;
  }
  int multiplication (std:: vector <int> task) {
    int result = task [0] * task [1];
  
    return result;
  }
  int division (std:: vector <int> task) {
    int result = task [0] / task [1];
    return result;
  }
  std:: vector <int> convert (std:: vector <std::string> vec) {
    std:: vector <int> task;
    int tmp;
    tmp = stoi (vec [0]);
    task. push_back (tmp);
    tmp = stoi (vec [2]);
    task. push_back (tmp);

    return task;
  }
  int print (std:: string message) {
    std:: cout << "\n" << message << "\n";

    return 0;
  }
  int run (std:: vector <std:: string> vec) {
    std::string numberTypeTask = this -> selectTypeTask (vec [0]);
    this -> print ("");
    if (this -> checkTypeTask (numberTypeTask, vec [1]) == false) {
      this -> print ("Ошибка! Номер задачи неверен!");

      return 0;
    }
    this -> print (vec [1]);
  }
};

int main () {
  ReadTask readTask;
  DecideTask decideTask;
  std::vector <std::string> vec = readTask. read ("./task.txt");
  decideTask. run (vec);

  return 0;

}