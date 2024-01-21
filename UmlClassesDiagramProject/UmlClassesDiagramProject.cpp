#include <iostream>

class City
{
    std::string name;
public:
    std::string& Name() { return name; }
    City()
    {
        std::cout << "city construct\n";
    }
    ~City()
    {
        std::cout << "city destruct\n";
    }
};

class Country
{
    int citizien;
    City capital;
public:
    Country(std::string capitalName)
    {
        capital.Name() = capitalName;
        std::cout << "country construct\n";
        std::cout << "capital addr: " << &capital << "\n"
                    << "this addr: " << this << "\n";
    }
    ~Country()
    {
        std::cout << "country destruct\n";
    }
    
};

class Company
{
    City* city;
public:
    Company(City* city = nullptr) : city{ city }
    {
        std::cout << "company construct\n";
    }
    ~Company()
    {
        std::cout << "company destruct\n";
    }
    City*& City() { return city; }
};

class Patient;
class Doctor
{
    Patient* patient;
};
class Patient
{
    Doctor* doctor;
};

class Person
{
    std::string name;
public:
    Person(std::string name) : name{ name } 
    {
        std::cout << "person construct\n";
        std::cout << "person address: " << this << "\n";
    }
    ~Person()
    {
        std::cout << "person destruct\n";
    }
    std::string& Name() { return name; }
};

class User : public Person
{
    int age;
public:
    User(std::string name, int age)
        : Person(name), age{ age } 
    {
        std::cout << "user construct\n";
        std::cout << "user address: " << this << "\n";
    }
    ~User()
    {
        std::cout << "user destruct\n";
    }
};

int main()
{
    /*Country* russia = new Country("Moscow");
    delete russia;*/

    /*City* moscow = new City();
    moscow->Name() = "Moscow";

    Company company(moscow);*/
    User* user = new User("Bob", 35);
    delete user;
}
