class CheapPlaces : public Stadium {
private:
  Place place;
  std:: vector <Place> cheapPlaces;
public:
  std:: vector <Place> getCheapPlaces () {

  return this -> cheapPlaces;
  }
  bool gen () {
  place. row = 2;
  place. column = 2;
  place. type = 2;

  return true;
  }
  int setPlaces () {
  this -> cheapPlaces. push_back (this -> place);
  int number = this -> cheapPlaces. size () - 1;

  return number;
  }
};