class DearPlaces : public Stadium {
private:
  Place place;
  std:: vector <Place> dearPlaces;
public:
  std:: vector <Place> getDearPlaces () {

  return this -> dearPlaces;
  }
  bool gen () {
  place. row = 1;
  place. column = 1;
  place. type = 1;

  return true;
  }
  int setPlaces () {
  this -> dearPlaces. push_back (this -> place);
  int number = this -> dearPlaces. size () - 1;

  return number;
  }
};