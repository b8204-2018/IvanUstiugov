struct Place {
  int row;
  int column;
  int type;
};

struct Ticket {
  int row;
  int column;
  int type;

};

struct People {
  std:: string name;
  std:: string lastName;
};

struct Fanat {
  Ticket ticket;
  int count;
  int ban;
};