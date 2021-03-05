#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class obraz {
  public:
    ifstream fileIn;
  char obr[20][20];
  char ob[20][20];
  int liczR = 0;
  void run();
  void rekure(char obraz[20][20]);
  bool rekur(char obraz[20][20]);
};
void obraz::run() {
  fileIn.open("dane_obrazki.txt");
  string lin;
  string skipL;
  bool first = true;
  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < 20; j++) {
      fileIn >> lin;
      for (int l = 0; l < 20; l++) {
        obr[j][l] = lin[l];
      }
    }
    fileIn >> skipL;

    if (rekur(obr)) {
      if (first == true) {
        if (rekur(obr)) {
          first == false;
        }
        cout << "Jest obrazem rekurencyjnym\n";
        liczR++;
      }
    } else {
      cout << "Nie jest obrazem rekurencyjnym\n";
    }
  }
  cout << "obrazow rekurencyjnych jest: " << liczR << "\n";
}

bool obraz::rekur(char obr[20][20]) {

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; ++j) {
      if (!(obr[i][j] == obr[i + 10][j] &&
          obr[i][j] == obr[i][j + 10] &&
          obr[i][j] == obr[i + 10][j + 10])) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  obraz IsReImg;
  IsReImg.run();
  return 0;
}
