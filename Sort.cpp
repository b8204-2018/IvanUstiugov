#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Sorts {
  public:
    virtual int sheker (std::vector <int> &vec) = 0;
};




class ShekerSort : public Sorts {
public:

int sheker (std:: vector <int> &vec) override {
  int count = vec. size ();
  int left = 0;
  int right = count - 1;
  int flag = 1;

  while ((left < right)  &&  flag > 0) {
    flag = 0;
    for (int i = left;  i < right;  i++) {
      if (vec [i] > vec [i + 1]) {
        int t = vec [i];

        vec [i] = vec [i + 1];
        vec [i + 1] = t;

        flag = 1;
      }
    }

    right--;

    for (int i = right;  i > left;  i--) {
      if (vec [i - 1] > vec [i]) {
        int t = vec [i];

        vec [i] = vec [i - 1];
        vec [i - 1] = t;

        flag = 1;
      }
    }

    left++;

  }

  return 0;

}
};

int print (std::vector <int> vec) {
  for (int i = 0;  i < vec. size ();  i++) {
    std::cout <<"\n" << vec [i];
  }

  return 0;

}

std::vector <int> createReadVector (std:: string path) {
  std::vector <int> vec;
  std::ifstream dataFile (path);

  while (dataFile) {
    std::string str;
    std::getline (dataFile, str);

    if (str != "\0") {

      vec. push_back (std::stoi (str));
    }
  }

  return vec;

}

int main () {
  std:: vector <int> vec = createReadVector ("./data/input.txt");

  ShekerSort shekerSort;
  shekerSort. sheker (vec);
  print (vec);

  return 0;

}