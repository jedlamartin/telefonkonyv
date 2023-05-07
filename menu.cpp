#include "menu.h"
#include <iostream>
#include <fstream>
#include "human.h"
#include "company.h"

bool isPhoneNumber(String const& number) {
    if (number.length() != 11 && number.length() != 10) { return false; }
    for (size_t i = 0; i < number.length(); i++) {
        if (!std::isdigit(number[i]))
            return false;
    }
    return true;
}

void Menu(List& a) {
    bool running = true;
    while (running) {
        while (running) {
            std::cout << "1. Bejegyzesek" << std::endl << "2. Bejegyzesek felvetele" << std::endl
                      << "3. Bejegyzesek torlese" << std::endl << "0. Kilepes" << std::endl;
            size_t option;
            std::cin >> option;
            switch (option) {
                case 1: {
                    std::cout << "1. Termeszetes szemelyek" << std::endl << "2. Cegek" << std::endl << "3. Osszes"
                              << std::endl;
                    std::cin >> option;
                    switch (option) {
                        case 1: {
                            std::cout << "Nev, Telefonszam, Cím, Becenev, Ceges telefonszam" << std::endl;
                            a.print(std::cout, ", ", true, human);
                            String tmp;
                            String::getline(std::cin, tmp);
                            String::getline(std::cin, tmp);
                            break;
                        }
                        case 2: {
                            std::cout << "Nev, Telefonszam, Cím, Tulajdonos, Tipus" << std::endl;
                            a.print(std::cout, ", ", true, company);
                            String tmp;
                            String::getline(std::cin, tmp);
                            String::getline(std::cin, tmp);
                            break;
                        }
                        case 3: {
                            std::cout << "Nev, Telefonszam, Cím, Becenev/Tulajdonos, Ceges telefonszam/Tipus"
                                      << std::endl;
                            a.print(std::cout, ", ", true, all);
                            String tmp;
                            String::getline(std::cin, tmp);
                            String::getline(std::cin, tmp);
                            break;
                        }
                        default: {
                            std::cout << "Nem megfelelo menupont" << std::endl;
                        }
                    }


                    /*std::cout << "Nev, Telefonszam, Cím, Becenev/Tulajdonos, Ceges telefonszam/Tipus" << std::endl;
                    a.print(std::cout, ", ", true, all);
                    String tmp;
                    String::getline(std::cin, tmp);
                    String::getline(std::cin, tmp);*/
                    //std::cout<<u8"\033[2J\033[1;1H";
                    break;
                }

                case 2: {
                    std::cout << "1. Termeszetes szemely" << std::endl << "2. Ceg" << std::endl;
                    int option;
                    std::cin >> option;

                    if (option != 1 && option != 2) {
                        std::cout << "Nem megfelelo menupont!" << std::endl;
                        break;
                    }

                    String name, number, address;

                    String::getline(std::cin, name); //Valamiert enelkul rossz az egesz (lehet a CLion miatt)
                    std::cout << "Nev: ";
                    String::getline(std::cin, name);
                    while (name.length() == 0) {
                        std::cout << "Kotelezo nevet megadni!" << std::endl;
                        std::cout << "Nev: ";
                        String::getline(std::cin, number);
                    }

                    std::cout << "Telefonszam (06112223333): ";
                    String::getline(std::cin, number);
                    while (!isPhoneNumber(number)) {
                        std::cout << "Rossz formatum!" << std::endl;
                        std::cout << "Telefonszam (06112223333): ";
                        String::getline(std::cin, number);
                    }

                    std::cout << "Cim: ";
                    String::getline(std::cin, address);

                    switch (option) {
                        case 1: {
                            String nickname, companyNumber;

                            std::cout << "Becenev: ";
                            String::getline(std::cin, nickname);

                            std::cout << "Ceges telefonszam (06112223333): ";
                            String::getline(std::cin, companyNumber);

                            while (!isPhoneNumber(companyNumber)) {
                                std::cout << "Rossz formatum!" << std::endl;
                                std::cout << "Ceges telefonszam (06112223333): ";
                                String::getline(std::cin, companyNumber);
                            }


                            Human* human = new Human(name, number, address, nickname, companyNumber);
                            a.insert(human);
                            break;
                        }
                        case 2: {
                            String owner, type;

                            std::cout << "Tulajdonos: ";
                            String::getline(std::cin, owner);

                            std::cout << "Tipus: ";
                            String::getline(std::cin, type);


                            Company* company = new Company(name, number, address, owner, type);
                            a.insert(company);
                            break;
                        }
                        default: {
                            std::cout << "Nem megfelelo menupont!" << std::endl;
                        }
                    }
                    break;


                }
                case 3: {
                    std::cout << "Nev, Telefonszam, Cím, Becenev/Tulajdonos, Ceges telefonszam/Tipus" << std::endl;
                    a.print(std::cout, ", ", true);
                    std::cout << "Hanyadikat?" << std::endl;
                    size_t num;
                    std::cin >> num;
                    if (num > a.size() || num < 1) std::cout << "Nem megfelelo menupont" << std::endl;
                    else a.erase(num);
                    break;
                }
                default: {

                    //system("clear");
                    std::ofstream out("records.txt");
                    a.print(out, ";", false, all);
                    out.close();
                    running = false;
                    break;
                }

            }
        }
    }
}
