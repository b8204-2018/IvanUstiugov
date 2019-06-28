#include <iostream>
#include <cstring>
#include <vector>
#include "./Structs.cpp"
#include "./Stadium.cpp"
#include "./Peoples.cpp"
#include "./Tickets.cpp"
#include "./CheapTickets.cpp"
#include "./DearTickets.cpp"
#include "./CheapPlaces.cpp"
#include "./DearPlaces.cpp"
#include "./Fan.cpp"

int count = 0;

int main () {
  CheapPlaces cheapPlaces;
  DearPlaces dearPlaces;
  CheapTickets cheapTickets;
  DearTickets dearTickets;
  Peoples peoples;
  Fan fan;
  std:: string name = "";
  std:: string lastName = "";
  std:: cout << "\n Введите своё имя \n";
  std:: cin >>name;
  std:: cout << "\n Введите свою фамилию \n";
  std:: cin >> lastName;
  bool resSetName = peoples. setName (name);
  bool resSetLastName = peoples. setLastName (lastName);
  int numberPeople = peoples. setPeoples ();
  std:: cout << "\n Ваш порядковый номер " << (numberPeople + 1) << " \n";
  int typeTicket;
  std:: cout << "\n Отлично! Теперь купите билет. Укажите интересующий тип билета \n";
  std:: cout << "\n Эконом класс -- нажмите 1. Бизнес класс -- нажмите 2 \n";
  std:: cin >> typeTicket;
  std:: cout << "Вы взяли билет типа " << typeTicket;
  if (typeTicket == 1) {
    dearTickets. gen ();
    dearTickets. setTickets ();
    }
  if (typeTicket == 2) {
    cheapTickets. gen ();
    cheapTickets. setTickets ();
    }
  std:: cout << "\n Спасибо! Билет куплен! \n";
  int next;
  std:: cout << "\n Для входа введите 1, если не входим, то 0 \n";
  std:: cin >> next;
  while (next != 0) {
    int vef;
    std:: cout << "\n Показываем билет? Да - 1, нет - 2 \n";
    std:: cin >> vef;
    if (vef == 2) break;
    int typeTicketVef;
    std:: cout << "\n Введите свой тип билета \n";
    std:: cin >> typeTicketVef;
    if (count == 3) break;
    if (typeTicket == typeTicketVef) {
      std:: cout << "\n Тип билета не верен! \n";
      count++;
      continue;
    }
    std:: cout << " \n Вы успешно прошли на стадион!\n";
  }

return 0;
}