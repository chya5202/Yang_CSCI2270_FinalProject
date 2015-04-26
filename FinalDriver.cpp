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

using namespace std;

int menu();
double atoi_replace(string myString);
void buildMovieStore();
MovieTree *BarnesNoble = new MovieTree();
MovieTree *BlockBuster = new MovieTree();
MovieTree *DVDRentals = new MovieTree();
MovieTree *RedBox = new MovieTree();
MovieTree *STAR = new MovieTree();
double gasprice;
double efficiency;
double busFare;
double BNdist;
double BBdist;
double DVDdist;
double RBdist;
double STARdist;

int main(){

    buildMovieStore();
    int choice = 0;
    cout << "Welcome to SuperDuperMovieRenter!" << endl;
    cout << "In order for us to serve you better, please provide the following information:" << endl;
    cout << "How far away is your nearest Barnes&Noble? (miles) "<< endl;
    cin >> BNdist;
    cout << "How far away is your nearest BlockBuster? (miles)" << endl;
    cin >> BBdist;
    cout << "How far away is your nearest DVDRental? (miles)" << endl;
    cin >> DVDdist;
    cout << "How far away is your nearest Redbox? (miles)" << endl;
    cin >> RBdist;
    cout << "How far away is your nearest STAR? (miles)"<< endl;
    cin >> STARdist;

    choice = menu(); //initiates the menu
    while (choice != 3){ //as long as the user does not choose to quit
        if (choice == 1){ //compare price
            cout << "Enter title:" << endl;
            string findtitle;
            getline(cin,findtitle);
            getline(cin,findtitle);
            string walkDriveBus;
            cout<<"Would you like to walk, drive or bus?"<<endl;
            cin >> walkDriveBus;
            if (walkDriveBus=="Drive"){
                cout << "What is your car's fuel efficiency? (miles per gallon)" << endl;
                cin >> efficiency;
                cout << "How much is gasoline right now? (dollars per gallon)" << endl;
                cin >> gasprice;
                cout << "The total price to rent " << findtitle << " from:" << endl;
                BarnesNoble->findMovieDrive("Barnes&Noble", BNdist, findtitle);
                BlockBuster->findMovieDrive("BlockBuster", BBdist, findtitle);
                DVDRentals->findMovieDrive("DVDRentals", DVDdist, findtitle);
                RedBox->findMovieDrive("Redbox", RBdist, findtitle);
                STAR->findMovieDrive("STAR", STARdist, findtitle);
            }
            if (walkDriveBus=="Walk"){
                cout << "The total price to rent " << findtitle << " from:" << endl;
                BarnesNoble->findMovieWalk("Barnes&Noble", findtitle);
                BlockBuster->findMovieWalk("BlockBuster", findtitle);
                DVDRentals->findMovieWalk("DVDRentals", findtitle);
                RedBox->findMovieWalk("Redbox", findtitle);
                STAR->findMovieWalk("STAR", findtitle);
            }
            if (walkDriveBus=="Bus")
                cout<<"How much is your bus fare?"<<endl;
                cin >> busFare;
                cout << "The total price to rent " << findtitle << " from:" << endl;
                BarnesNoble->findMovieBus("Barnes&Noble",busFare, findtitle);
                BlockBuster->findMovieBus("BlockBuster",busFare, findtitle);
                DVDRentals->findMovieBus("DVDRentals", busFare, findtitle);
                RedBox->findMovieBus("Redbox", busFare, findtitle);
                STAR->findMovieBus("STAR", busFare, findtitle);
        }

        if (choice == 2){ //print inventory of a store
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
    cout<<"   "<<endl;
    cout << "======Movie Deals====="<< endl;
    cout << "1. Compare prices" << endl;
    cout << "2. Print the inventory of a store" << endl;
    cout << "3. Quit" << endl;

    int choice1;
    cin >> ws;
    cin >> choice1;
    return choice1;
}


double atoi_replace(string myString){
    double myInt;
    istringstream buffer(myString);
    buffer >> myInt;
    return myInt;
}

void buildMovieStore(){ //builds the movie trees for each store
    ifstream infile;
    infile.open("Barnes&Noble.txt");
    MovieNode theRoot;
    string line;
    string title;
    string sprice;
    double price;
    while (getline(infile, line)){
        stringstream infile(line);
        MovieNode newMovie;
        getline(infile, title, ','); //breaks up until the first comma into own string
        getline(infile, sprice, '\n');
        price = atoi_replace(sprice);
        BarnesNoble->addMovieNode(title, price);
    }
    infile.close();

    infile.open("BlockBuster.txt");
    while (getline(infile, line)){
        stringstream infile(line);
        getline(infile, title, ','); //breaks up until the first comma into own string
        getline(infile, sprice, '\n');
        price = atoi_replace(sprice);
        BlockBuster->addMovieNode(title, price);
    }
    infile.close();

    infile.open("DVDRentals.txt");
    while (getline(infile, line)){
        stringstream infile(line);
        getline(infile, title, ','); //breaks up until the first comma into own string
        getline(infile, sprice, '\n');
        price = atoi_replace(sprice);
        DVDRentals->addMovieNode(title, price);
    }
    infile.close();

    infile.open("Redbox.txt");
    while (getline(infile, line)){
        stringstream infile(line);
        getline(infile, title, ','); //breaks up until the first comma into own string
        getline(infile, sprice, '\n');
        price = atoi_replace(sprice);
        RedBox->addMovieNode(title, price);
    }
    infile.close();

    infile.open("STAR.txt");
    while (getline(infile, line)){
        stringstream infile(line);
        getline(infile, title, ','); //breaks up until the first comma into own string
        getline(infile, sprice, '\n');
        price = atoi_replace(sprice);
        STAR->addMovieNode(title, price);
    }
    infile.close();
}
