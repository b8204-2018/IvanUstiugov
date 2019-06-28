class CheapTickets : public Tickets {
private: 
  Ticket ticket;
  std:: vector <Ticket> cheapTickets;
public:
  std:: vector <Ticket> getTickets () {

  return this -> cheapTickets;
  }
  bool gen () {
  this -> ticket. row = 1;
  this -> ticket. column = 1;
  this -> ticket. type = 2;

  return true;
  }
  int setTickets () {
  this -> cheapTickets. push_back (this -> ticket);
  int number = this -> cheapTickets. size () - 1;

  return number;
  }
};