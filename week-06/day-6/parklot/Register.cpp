#include "Register.hpp"

Register::Register(ParkingLot in_pl) {
  int counter = 0;
std::cout << "               _______                        " << std::endl;
std::cout << "              //  ||\ \\                       " << std::endl;
std::cout << "        _____//___||_\ \\___   " << in_pl.get_parking_name() << "           " << std::endl;
std::cout << "        )  _          _    \\                  " << std::endl;
std::cout << "        |_/ \\________/ \\___|                  " << std::endl;
std::cout << "__________\\_/________\\_/_____________________________________________________ " << std::endl;

  for (int i = 0; i < in_pl.get_level(); i++) {
    std::cout << "" << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<| " << i + 1 << ". level " << " |>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    for (int j = 0; j < in_pl.get_col(); j++) {
      std::cout << "================================| " << j + 1 << ".  col  " << " |================================" << std::endl;
      for (int k = 0; k < in_pl.get_row(); k++) {
        std::cout << "--------------------------------| " << k + 1 << ".  row  " << " |--------------------------------" << std::endl << std::endl;
        std::cout << "\t\t\t" << ++counter << ". ";
        std::cout << in_pl.get_cars_from_parking_house(i, j, k)->get_color() << " ";
        std::cout << in_pl.get_cars_from_parking_house(i, j, k)->get_type() << " ";
        std::cout << in_pl.get_cars_from_parking_house(i, j, k)->get_car_plate() << " " << std::endl << std::endl;
      }
    }
  }
}

void Register::print_all_parking_car() {
}

 //cout << city_center.get_cars_from_parking_house(0, 0, 0)->get_CAR_ID() << endl;

 //std::cout << pl.get_cars_from_parking_house(pl.get_row, pl.get_col, pl.get_level)->get_type() << std::endl;
