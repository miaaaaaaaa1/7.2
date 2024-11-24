#include <iostream>
#include <string>
using namespace std;

class Flat {
private:
    double area;
    double price;  
    string address; 

public:
    Flat(double a = 0.0, double p = 0.0, string addr = "")
        : area(a), price(p), address(addr) {}

    Flat(const Flat& other) : area(other.area), price(other.price), address(other.address) {}

    Flat& operator=(const Flat& other) {
        if (this != &other) { 
            area = other.area;
            price = other.price;
            address = other.address;
        }
        return *this;
    }

    bool operator==(const Flat& other) const {
        return area == other.area;
    }

    bool operator>(const Flat& other) const {
        return price > other.price;
    }

    friend ostream& operator<<(ostream& os, const Flat& f) {
        os << "Area: " << f.area << " sq.m, Price: " << f.price << " USD, Address: " << f.address;
        return os;
    }

    friend istream& operator>>(istream& is, Flat& f) {
        cout << "Enter area (sq.m): ";
        is >> f.area;
        cout << "Enter price (USD): ";
        is >> f.price;
        is.ignore(); 
        cout << "Enter address: ";
        getline(is, f.address);
        return is;
    }
};

int main() {
    try {
        Flat flat1(50.0, 100000.0, "123 Main Street");
        Flat flat2(70.0, 150000.0, "456 Elm Street");
        Flat flat3;

        cout << "flat1: " << flat1 << "\n";
        cout << "flat2: " << flat2 << "\n";

        cout << "Enter details for flat3:\n";
        cin >> flat3;
        cout << "flat3: " << flat3 << "\n";

        cout << "flat1 == flat2: " << (flat1 == flat2 ? "Yes" : "No") << "\n";
        cout << "flat1 == flat3: " << (flat1 == flat3 ? "Yes" : "No") << "\n";

        Flat flat4;
        flat4 = flat1;
        cout << "flat4 (after assignment): " << flat4 << "\n";

        cout << "flat2 > flat1: " << (flat2 > flat1 ? "Yes" : "No") << "\n";
        cout << "flat3 > flat1: " << (flat3 > flat1 ? "Yes" : "No") << "\n";

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
}
