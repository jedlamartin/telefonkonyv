//#include "memtrace.h"
#include "list.h"
#include "menu.h"

int main() {
    //setlocale(LC_ALL, "hu_HU.UTF-8");
    /*List list;
    Human* a=new Human("e","f","g","a","a");
    Human* b=new Human("k","fh","gi","ff","a");
    Human* c=new Human("a","fh","gi","ff","a");
    list.insert(a);
    list.insert(b);
    list.insert(c);
    //list.insert(Human("a","b","c"));
    //list.insert(Record("x","y","z"));
    //list.insert(Human("x","x","x"));
    list.print(std::cout, "\t\t", 1);

    list.erase(3);
    list.print(std::cout, "\t\t", 1);*/
    /*String asd("alma");
    asd.erase(0,2);
    std::cout<<asd<<std::endl;*/
    //PhoneBook a("asd");
    //a.Menu();
    List a;
    a.config();
    Menu(a);
    return 0;
}
