#include <iostream>
#include <String>


class Person {
protected:
    uint8_t age{}, weight{};
    std::string name{};
public:
    void setAge(uint8_t age) {
        this->age = age;
    }

    void setWeight(uint8_t weight) {
        this->weight = weight;
    }

    void setName(std::string name) {
        this->name = name;
    }
};

class Student : public Person {
    static uint16_t count;
    uint16_t yearOfStudy{};
public:
    Student() {
        ++count;
    }

    void setYear(uint16_t year) {
        this->yearOfStudy = year;
    }

    void print() {
        if (age == 0 || weight == 0 || name.empty() || yearOfStudy == 0) {
            std::cout << "Error! Some fields are empty." << std::endl;
            return;
        }
        std::cout << "Name   - " << name << std::endl;
        std::cout << "Age    - " << (int) age << std::endl;
        std::cout << "Weight - " << (int) weight << std::endl;
        std::cout << "Year   - " << yearOfStudy << std::endl;
    }

    static uint16_t getCount() {
        return count;
    }
};

uint16_t Student::count = 0;


class Fruit {
protected:
    std::string name{}, color{};
public:
    Fruit(std::string color) : color(color) {}

    const std::string &getName() const {
        return name;
    }

    const std::string &getColor() const {
        return color;
    }
};

class Apple : public Fruit {
public:
    Apple(std::string color) : Fruit(color) {
        this->name = "Apple";
    }
};

class Banana : public Fruit {
public:
    Banana() : Fruit("Yellow") {
        this->name = "Banana";
    }
};

class GrannySmith : public Apple {
public:
    GrannySmith() : Apple("Green") {
        this->name = "Granny Smith apple";
    }
};

int main() {

    Student s;
    s.setName("Nick");
    s.setAge(20);
    s.setWeight(80);
    s.setYear(2021);
    s.print();
    std::cout << "Student counter = " << Student::getCount() << std::endl;
    Student s1;
    std::cout << "Student counter = " << Student::getCount() << "\n\n\n";


    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";


    return 0;
}
