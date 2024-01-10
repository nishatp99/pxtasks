#include <iostream>
using namespace std;

char arr[5][7] = {{'#', '#', '.', '#', '#', '.', '#'},
                  {'#', '.', '.', '#', '#', '.', '#'},
                  {'#', '.', '#', '#', '#', '.', '#'},
                  {'#', '.', '.', '#', '#', '.', '#'},
                  {'#', '#', '.', '#', '#', '.', '#'}};
int counter = 0; 
int main() {

  for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 7; y++) {
      if (arr[x][y] == '.') {
        arr[x][y] = counter + '0'; 
        counter++;         

        
          if (arr[x][y + 1] == '.') {
            arr[x][y + 1] = counter + '0';
          } else if (arr[x][y - 1] == '.') {
            arr[x][y - 1] = counter + '0';
          } else if (arr[x + 1][y] == '.') {
            arr[x + 1][y] = counter + '0';
          }
        counter++; 
      }
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 7; j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }

  return 0;
}

// Couldnt finish the code
