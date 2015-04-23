// Final Project
// Amy Chen and Chia-Hsin Yang
// CSCI2270, Hoenigman, Spring 2015
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "MovieTree.h"
#include "MovieTree.cpp"


using namespace std;

int menu();
int atoi_replace(string myString);
void buildMovieStore();
MovieTree *BarnesNoble = new MovieTree();
MovieTree *BlockBuster = new MovieTree();
MovieTree *DVDRentals = new MovieTree();
MovieTree *RedBox = new MovieTree();
MovieTree *STAR = new MovieTree();

int main(){

    buildMovieStore();
    int choice = 0;
    choice = menu(); //initiates the menu
    while (choice != 4){ //as long as the user does not choose to quit
        if (choice == 1){ //find a movie
            cout << "Enter title:" << endl;
            string findtitle;
            getline(cin,findtitle);
            getline(cin,findtitle);
            BarnesNoble->findMovie("Barnes&Noble", findtitle);
            BlockBuster->findMovie("BlockBuster", findtitle);
            DVDRentals->findMovie("DVDRentals", findtitle);
            RedBox->findMovie("Redbox", findtitle);
            STAR->findMovie("STAR", findtitle);
        }
        if (choice == 2){ //rent a movie
            cout << "Enter title:" << endl;
            string renttitle;
            getline(cin,renttitle);
            getline(cin,renttitle);
            cout << "Would you like to rent " << renttitle << " from Barnes&Noble, BlockBuster, DVDRentals, Redbox, or STAR?" << endl;
            string storename;
            getline(cin, storename);
            getline(cin, storename);
            if (storename == "Barnes&Noble"){
                BarnesNoble->rentMovie(storename, renttitle);
            }
            else if (storename == "BlockBuster"){
                BlockBuster->rentMovie(storename, renttitle);
            }
            else if (storename == "DVDRentals"){
                DVDRentals->rentMovie(storename, renttitle);
            }
            else if (storename == "Redbox"){
                RedBox->rentMovie(storename, renttitle);
            }
            else if (storename == "STAR"){
                STAR->rentMovie(storename, renttitle);
            }
            else{
                cout << "Please enter a valid movie rental store." << endl;
            }
        }
        if (choice == 3){ //print inventory of a store
            cout << "Would you like to print the inventory of Barnes&Noble, BlockBuster, DVDRentals, Redbox, or STAR?" << endl;
            string storename;
            getline(cin, storename);
            getline(cin, storename);
            if (storename == "Barnes&Noble"){
                BarnesNoble->printMovieInventory();
            }
            else if (storename == "BlockBuster"){
                BlockBuster->printMovieInventory();
            }
            else if (storename == "DVDRentals"){
                DVDRentals->printMovieInventory();
            }
            else if (storename == "Redbox"){
                RedBox->printMovieInventory();
            }
            else if (storename == "STAR"){
                STAR->printMovieInventory();
            }
            else{
                cout << "Please enter a valid movie rental store." << endl;
            }
        }
       choice = menu(); //brings up the menu again
    }
    cout << "Goodbye!" << endl; //
}


int menu() //main menu and decisions
{
    cout << "======Movie Deals====="<< endl;
    cout << "1. Compare prices" << endl;
    cout << "2. Rent a movie" << endl;
    cout << "3. Print the inventory of a store" << endl;
    cout << "4. Quit" << endl;

    int choice1;
    cin >> ws;
    cin >> choice1;
    return choice1;
}


int atoi_replace(string myString){
    int myInt;
    istringstream buffer(myString);
    buffer >> myInt;
    return myInt;
}

void buildMovieStore(){ //builds the movie trees for each store
    ifstream infile;
    infile.open("Barnes&Nobles.txt");
    MovieNode theRoot;
    string line;
    string title;
    string sprice;
    int price;
    while (getline(infile, line)){
        stringstream infile(line);
        MovieNode newMovie;
        getline(infile, title, ','); //breaks up until the first comma into own string
        //cout << title << " ";
        getline(infile, sprice, '\n');
        price = atoi_replace(sprice);
        BarnesNoble->addMovieNode(title, price);
    }
    infile.close();

    infile.open("BlockBuster.txt");
    //MovieNode theRoot;
    //string line;
    //string title;
    //string sprice;
    //int price;
    while (getline(infile, line)){
        //stringstream infile(line);
        //MovieNode newMovie;
        getline(infile, title, ','); //breaks up until the first comma into own string
        //cout << title << " ";
        getline(infile, sprice, '\n');
        price = atoi_replace(sprice);
        BlockBuster->addMovieNode(title, price);
    }
    infile.close();

    infile.open("DVDRentals.txt");
    //MovieNode theRoot;
    //string line;
    //string title;
    //string sprice;
    //int price;
    while (getline(infile, line)){
        stringstream infile(line);
        //MovieNode newMovie;
        getline(infile, title, ','); //breaks up until the first comma into own string
        //cout << title << " ";
        getline(infile, sprice, '\n');
        price = atoi_replace(sprice);
        DVDRentals->addMovieNode(title, price);
    }
    infile.close();

    infile.open("Redbox.txt");
    //MovieNode theRoot;
    //string line;
    //string title;
    //string sprice;
    //int price;
    while (getline(infile, line)){
        stringstream infile(line);
        //MovieNode newMovie;
        getline(infile, title, ','); //breaks up until the first comma into own string
        //cout << title << " ";
        getline(infile, sprice, '\n');
        price = atoi_replace(sprice);
        RedBox->addMovieNode(title, price);
    }
    infile.close();

    infile.open("STAR.txt");
    //MovieNode theRoot;
    //string line;
    //string title;
    //string sprice;
    //int price;
    while (getline(infile, line)){
        stringstream infile(line);
        //MovieNode newMovie;
        getline(infile, title, ','); //breaks up until the first comma into own string
        //cout << title << " ";
        getline(infile, sprice, '\n');
        price = atoi_replace(sprice);
        STAR->addMovieNode(title, price);
    }
    infile.close();
}
