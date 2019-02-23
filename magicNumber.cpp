#include <iostream>
using namespace std;
#include <iomanip>

int press0, pileNum, pileNum2, pileNum3, temp;
int tempArray[7][3];
int tempArray2[7][3];
int table_shuffled[7][3];
int table[7][3] = {
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9},
  {10, 11, 12},
  {13, 14, 15},
  {16, 17, 18},
  {19, 20, 21},
};

void shuffle(int table[7][3]);
void pick_column (int table[7][3]);
void choice1(int array[7][3]);
void choice2(int array[7][3]);
void choice3(int array[7][3]);
void round3 (int tempArray2[7][3]);
void guessNumber(int tempArray2[7][3]);

void print_table(int table[7][3]) {
  cout << "  " << "#1   " << "#2   " << "#3"<< endl;
  cout << endl; 
  for (int i = 0; i < 7; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << setw(4) << table[i][j] << " ";
    }
    cout << endl;
  }
} 

// If 1st column is chosen --shift in the middle
void choice1(int array[7][3]) {
  for (int i = 0; i < 7; ++i) {
      temp = array[i][1];
      array[i][1] = array[i][0];
      array[i][0] = temp;
      for (int j = 0; j < 3; ++j){
      }
    }
}

//if 2nd column is chosen--no columns shifting
void choice2(int array[7][3]) {
  for (int i = 0; i < 7; ++i) {
    for (int j = 0; j < 3; ++j){ 
    }
  }
}

//if 3rd column is chosen -- shift in the middle
void choice3(int array[7][3]) {
  for (int i = 0; i < 7; ++i) {
    temp = array[i][1];
    array[i][1] = array[i][2];
    array[i][2] = temp;
    for (int j = 0; j < 3; ++j){ 
    }
  }
}

// Round2
void round2 (int tempArray[7][3]) {
  cout << "which pile your card resides in? ";
  cin >> pileNum2;
  cout << endl;
  if(pileNum2 == 1) {
    choice1(tempArray);
    shuffle(tempArray);
    // assigns a shuffled array to a temp value
    for (int i = 0; i < 7; ++i) {
      for (int j = 0; j < 3; ++j) {
        tempArray2[i][j] = table_shuffled[i][j];
      }
    }
    round3(tempArray2);
  }
  else if(pileNum2 == 2) {
    choice2(tempArray);
    shuffle(tempArray);
    // assigns a shuffled array to a temp value
    for (int i = 0; i < 7; ++i) {
      for (int j = 0; j < 3; ++j) {
        tempArray2[i][j] = table_shuffled[i][j];
      }
    }
    round3(tempArray2);
  }
  else if(pileNum2 == 3) {
    choice3(tempArray);
    shuffle(tempArray);
    // assigns a shuffled array to a temp value
    for (int i = 0; i < 7; ++i) {
      for (int j = 0; j < 3; ++j) {
        tempArray2[i][j] = table_shuffled[i][j];
      }
    }
    round3(tempArray2);
  }
  else {
    cout << "Invalid pile number";
  }
}

// Round 3 
void round3 (int tempArray2[7][3]) {
  cout << "which pile your card resides in? ";
  cin >> pileNum3;
  cout << endl;
  if(pileNum3 == 1) {
    choice1(tempArray2);
    shuffle(tempArray2);
    cout << endl;
    cout << "Your number is: "<< tempArray2[3][1];
  }
  else if(pileNum3 == 2) {
    choice2(tempArray2);
    shuffle(tempArray2);
    cout << endl;
    cout << "Your number is: "<< tempArray2[3][1];
  }
  else if(pileNum3 == 3) {
    choice3(tempArray2);
    shuffle(tempArray2);
    cout << endl;
    cout << "Your number is: "<< tempArray2[3][1];
  }
  else {
    cout << "Invalid pile number";
  }
}

//Picks a column round1, 2 and 3
void pick_column(int table[7][3]) {
  cout << "which pile your card resides in? ";
  cin >> pileNum;
  cout << endl;
  
  if (pileNum == 1) {
    choice1(table);
    shuffle(table);
    cout << endl;
    // assigns a shuffled array to a temp value
    for (int i = 0; i < 7; ++i) {
      for (int j = 0; j < 3; ++j) {
        tempArray[i][j] = table_shuffled[i][j];
      }
    }
    round2(tempArray);
  }
  else if (pileNum == 2) {
    choice2(table);
    shuffle(table);
    // assigns a shuffled array to a temp value
    for (int i = 0; i < 7; ++i) {
      for (int j = 0; j < 3; ++j) {
        tempArray[i][j] = table_shuffled[i][j];
      }
    }
    round2(tempArray);
  }
  else if (pileNum == 3) {
    choice3(table);
    shuffle(table);
    // assigns a shuffled array to a temp value
    for (int i = 0; i < 7; ++i) {
      for (int j = 0; j < 3; ++j) {
        tempArray[i][j] = table_shuffled[i][j];
      }
    }
    round2(tempArray);
  }
  else {
    cout << "Invalid pile number";
  }
}

// SHUFFLES THE ARRAY
void shuffle(int array[7][3]) {
  for (int p = 0; p < 21; ++p) {

    // index before shuffle
    int i_before = p % 7;
    int j_before = p / 7;

    // index after shuffle
    int i_after = p / 3;
    int j_after = p % 3;

    table_shuffled[i_after][j_after] = array[i_before][j_before];
  }
  cout << endl;
  print_table(table_shuffled);
}

int main() {

  cout<< "PRESS 0 TO START: ";
  cin >> press0;
  if (press0 == 0){
    print_table(table);
    pick_column(table);
  } 
  else {
    cout<< "INVALID INPUT";
  }
}
