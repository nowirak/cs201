//
//

#include <iostream>
using std::cout;
using std::endl;
#include <cmath>
using std::sqrt;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <vector>
using std::vector;
#include <string>
using std::string;

class MyVector {
public:

    MyVector() : _xcoord({ 0.0 }), _ycoord({ 0.0 }), _zcoord({ 0.0 }) {}
    MyVector(string filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "Error opening file." << endl;
            fin.close();
            exit(1);
        }
        unsigned int counter(0);
        while (true) {
            fin >> _xcoord.at(counter);
            if (fin) counter++;
            fin >> _ycoord.at(counter);
            if (fin) counter++;
            fin >> _zcoord.at(counter);
            if (fin) counter++;
            else {
                if (fin.eof() && counter % 3 == 0) {
                    cout << "File Successfully read." << endl;
                    fin.close();
                    break;
                }
                else {
                    cout << "Error reading file data." << endl;
                    fin.close();
                    exit(2);
                }
            }
        }
    }
    ~MyVector() {}

    unsigned int size() const {
        return _xcoord.size();
    }
    double length(unsigned int index) const {
        return sqrt(_xcoord.at(index) * _xcoord.at(index) + 
                    _ycoord.at(index) * _ycoord.at(index) +
                    _zcoord.at(index) * _zcoord.at(index));
    }
    void storeLengths(string filename) const {
        ofstream fout(filename);
        if (!fout) {
            cout << "Error creating file." << endl;
            exit(3);
        }
        for (unsigned int i = 0; i < size(); i++) {
            fout << length(i) << endl;
            if (!fout) {
                cout << "Error writing to file." << endl;
                exit(4);
            }
        }
        fout.close();
    }

private:

    vector<double> _xcoord;
    vector<double> _ycoord;
    vector<double> _zcoord;

};

int main()
{

    MyVector vectors("vectors.txt");
    vectors.storeLengths("lengths.txt");

    return 0;
}
