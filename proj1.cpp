 /*****************************************                                                                                                                                                                     
** File: Proj1.cpp                                                                                                                                                                                              
** Project: CMSC 202 Project 1, Fall 2024                                                                                                                                                                       
** Author: Bob Smith                                                                                                                                                                                            
** Date: 9/16/2024                                                                                                                                                                                              
** Section: 10/12                                                                                                                                                                                               
** E-mail: sbanala1@gl.umbc.edu                                                                                                                                                                                 
**                                                                                                                                                                                                              
** This file contains the main driver program for Project 1.                                                                                                                                                    
** This program reads the file specified as the first command                                                                                                                                                   
** line argument, stores the special characters from the file                                                                                                                                                   
** into a multidimensional array, displays the characters                                                                                                                                                       
** as a special form of ASCII art, and asks the user to play                                                                                                                                                    
** a game, which tells them to identify the change in the ASCII art.                                                                                                                                            
**                                                                                                                                                                                                              
***********************************************/




#include <iostream>
#include <cstring>
#include <ctime>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std ;


const string fileName1= "pic1.txt"; //name of first file                                                                                                                                                        
const string fileName2="pic2.txt"; // name of second file                                                                                                                                                       
const string fileName3="pic3.txt"; // name of third file                                                                                                                                                        
const int numRows=10; // number of total rows                                                                                                                                                                   
const int numColumns=21; // number of total columns                                                                                                                                                             
const int minAs=33; // minimum value in ascii table of characters                                                                                                                                               
const int maxAs=126; // maximum value in ascii table of characters                                                                                                                                              


// Function name: LoadFile                                                                                                                                                                                      
// Pre-condition: Must pass a multidimensional array with dimensions;                                                                                                                                           
// dimensions are the number of rows and columns;correct file name must be given                                                                                                                                
// Post-condition: File reads into the variables correctly;                                                                                                                                                     
// array with the characters from the file are given                                                                                                                                                            

void LoadFile (char [][ numColumns] );

// Function name: displayArt                                                                                                                                                                                    
// Pre-condition: file must be opened first,                                                                                                                                                                    
// multidimensional array should be passed                                                                                                                                                                      
// Post-condition: displays the picture,                                                                                                                                                                        
// and in which column and row the character is located in                                                                                                                                                      


void displayArt(bool, char [][ numColumns] );

// Function name: clearArray                                                                                                                                                                                    
// Pre-condition: pass a multidimensional array                                                                                                                                                                 
//  containing dimensions:number of rows and columns                                                                                                                                                            
// Post-condition: clears the entire Array,                                                                                                                                                                     
//   by filling it with null values                                                                                                                                                                             


void clearArray(char[][numColumns]);

// Function name: playGame                                                                                                                                                                                      
// Pre-condition: must have a file open;                                                                                                                                                                        
// must have an array passed with dimensions                                                                                                                                                                    
// Post-condition: user has to guess the change in                                                                                                                                                              
// the picture; if correct, game is won(array is cleared)                                                                                                                                                       
//, else they have to guess again                                                                                                                                                                               

void playGame(bool , char[][numColumns]);

// Function name:guessChange                                                                                                                                                                                    
// Pre-condition: the new character that was added                                                                                                                                                              
// must be passed, as well as the multi-dimensional array                                                                                                                                                       
// Post-condition: if the user guesses the correct change                                                                                                                                                       
// returns true, else they have to guess again till correct                                                                                                                                                     

bool guessChange(char, char[][numColumns]);

// Function name: mainMenu                                                                                                                                                                                      
// Pre-condition: none                                                                                                                                                                                          
// Post-condition: user chooses what they                                                                                                                                                                       
// want to do ; load a file, display image,                                                                                                                                                                     
//play the game, or exit                                                                                                                                                                                        

int mainMenu() ;


int main() {
  cout <<"Welcome to the Spot The Difference Game" << endl;
  //calls mainMenu                                                                                                                                                                                              
  mainMenu();

}

// LoadFile                                                                                                                                                                                                     
// reads the contents of a file into an array                                                                                                                                                                   
void LoadFile(char Array[][ numColumns]) {
  string fileSelect;
  int row;
   int col;
    char character;
  cout<<"What is the name of the data file to import? " << endl;
  cin>>fileSelect;
  //three different file names                                                                                                                                                                                  
  if( (fileSelect==fileName1) or (fileSelect==fileName2) or (fileSelect==fileName3) ) {

    ifstream myFile(fileSelect);
    if (myFile.is_open()){
      //myFile reads into these three variables til the end of the file                                                                                                                                         
      while (myFile >> row >> col >>character ) {
        //adds these characters to the array                                                                                                                                                                    
        Array[row][col]=character;
      }
    }
    myFile.close();
    //checks for nullspace to space out characters                                                                                                                                                              
    for (int i=0;i<numRows;i++){
      for (int j=0; j<numColumns;j++){
        if(Array[i][j]=='\0'){
          //replaces null space with blank space                                                                                                                                                                
          Array[i][j]=' ';
            }
      }
    }
   cout <<"Done" <<endl;
  } else {
    cout<<"File not found "<<endl;
  }

}



// displayArt                                                                                                                                                                                                   
// displays the multimensional array into a picture                                                                                                                                                             
void displayArt(bool fileCheck, char array [][ numColumns]) {
  //condition for file loading                                                                                                                                                                                  
  if (fileCheck==true){
    cout << "   ";
    for (int j=0 ; j<numColumns;j++) {
      //space two times if single digits                                                                                                                                                                        
      if(j<9) {
        cout<<j<<"  ";
      }
      else{
        cout<<j<<" ";
      }
    }
    cout<<endl;
    for (int i=0; i<numRows;i++){
      cout << i << " " ;
      for (int j=0; j<numColumns;j++){
        //double space for single digits and double digits                                                                                                                                                      
        if (j<9){
        cout<<array[i][j]<<"  ";

        }else {
          cout<<array[i][j]<<"  ";
        }
      }

      cout<<endl;
    }
  } else {
    cout<<"no file loaded " << endl;
  }


}

// clearArray                                                                                                                                                                                                   
// parses through array and empties it                                                                                                                                                                          
void clearArray(char array[][numColumns]){
  for (int i=0; i<numRows;i++){
    for (int j=0; j<numColumns ; j++ ) {
      //make each character null                                                                                                                                                                                
      array[i][j]=0;
}
  }
}

void playGame(bool checkOpen , char array [][numColumns]){
  //conditional check for file loading                                                                                                                                                                          
  if (checkOpen==true) {
    //display old image                                                                                                                                                                                         
    displayArt(checkOpen,array);
    //seed randomizer                                                                                                                                                                                           
    srand(time(NULL));
    //generates row between 0 and 9                                                                                                                                                                             
    int randRow=rand() % numRows;
    //generates row between 0 and 20                                                                                                                                                                            
    int randCol= rand() % numColumns;
    //generates ascii value between 33 and 126                                                                                                                                                                  
    char randChar= (rand() % (maxAs + 1 - minAs)) + minAs;
    // store new character in array                                                                                                                                                                             
    array[randRow][randCol]=randChar;
    //display the change                                                                                                                                                                                        
    displayArt(checkOpen,array);

    //passes new character and array to guessChange in conditonal check                                                                                                                                         
    if (guessChange(array[randRow][randCol],array)==true){
      cout<<"Guess is correct"<< endl;
      //empties array                                                                                                                                                                                           
      clearArray(array);

  }
  }else {
    cout<<"File not Found" << endl;

  }



}
// guessChange                                                                                                                                                                                                  
// if character change guess is correct, return true                                                                                                                                                            
bool guessChange(char character,char array[][numColumns]){
  bool correctGuess=false;
  int guessRow;
  int guessColumn;
  //loops until guess is correct                                                                                                                                                                                
  while (correctGuess!=true){
//user input                                                                                                                                                                                                
  cout<<"Guess which row the change is in"<<endl;
  cin>>guessRow;
  cout<<"Guess which column the change is in" << endl;
  cin>> guessColumn;
  //sets true if row and colum guess is correct                                                                                                                                                                 
  if (array[guessRow][guessColumn]==character){
     correctGuess=true;
  } else {
    cout <<"That is incorrect" << endl;
   }
 }
   return correctGuess;

}

// mainMenu                                                                                                                                                                                                     
// provides user input with options                                                                                                                                                                             
int mainMenu() {
  int choice=0;
  //main multidimensional array                                                                                                                                                                                 
  char gameArray[numRows][numColumns]={} ;
  //set true if file is open                                                                                                                                                                                    
  bool checkOpen = false;
  do {
    cout << "What would you like to do " <<endl;
    cout <<" 1.) Load ASCII Art from File "  << endl ;
      cout <<" 2.) Display Art "  << endl;
      cout <<" 3.) Play Game "  << endl;
      cout <<" 4.) Exit"  << endl ;

      cin>>choice;
      //switch case to control user decision                                                                                                                                                                    
    switch (choice) {
    case 1:
      LoadFile(gameArray);
      checkOpen=true;
      break;
    case 2:
      displayArt(checkOpen,gameArray);
      break;
    case 3:
      playGame(checkOpen,gameArray);
      checkOpen=false;
      break;
    }
      } while(choice!=4);
  //4 will exit game                                                                                                                                                                                            
  if (choice==4) {
    clearArray(gameArray);
    cout <<"Thank You for playing" << endl;
    }
  return 0;
}
