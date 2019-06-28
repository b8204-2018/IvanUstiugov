class Peoples {
private:
  People people;
  std:: vector <People> peoples;
public:
  std:: vector <People> getPeoples () {

  return this -> peoples;
  }
  bool setName (std:: string name) {
  this -> people. name = name;
  
  return true;
  }
  bool setLastName (std:: string lastName) {
  this -> people. lastName = lastName;

  return true;
  }
  int setPeoples () {
  this -> peoples. push_back (this -> people);
  int number = this -> peoples. size () - 1;

  return number;
  }
};