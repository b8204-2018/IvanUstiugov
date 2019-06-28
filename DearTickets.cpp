class DearTickets : public Tickets {
private:
  Ticket ticket;
  std:: vector <Ticket> dearTickets;
public:
  std:: vector <Ticket> getTickets () {

  return this -> dearTickets;
  }
  bool gen () {
  this -> ticket. row = 2;
  this -> ticket. column = 2;
  this -> ticket. type = 1;

  return true;
  }
  int setTickets () {
  this -> dearTickets. push_back (ticket);
  int number = this -> dearTickets. size () - 1;

  return number;
  }
};