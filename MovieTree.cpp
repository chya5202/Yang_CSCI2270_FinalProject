// Final Project
// Amy Chen and Chia-Hsin Yang
// CSCI2270, Hoenigman, Spring 2015

#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "MovieTree.h"

using namespace std;

//helper method
MovieTree::MovieTree(){
    root = NULL;
}

//helpter method
void MovieTree::printMovieInventory(){
    printMovieInventory(root);
}

/*
Function prototype:
void MovieTree::printMovieInventory(MovieNode *node)

Function description:
This method uses a binary search tree traversal to print out the movies a store carreis in alphabtical order. 
Example:
BlockBuster->printMovieIncentory(root);

Precondition: Root of MovieTree must exist. MovieTree must be filled out and established. 
Post condition: MovieTree is unchanged, contents printed out for user. 
*/
void MovieTree::printMovieInventory(MovieNode *node){
    if (node->leftChild != NULL){
    printMovieInventory(node->leftChild);
    }
    cout << "Movie: " << node->title << endl;
    if (node->rightChild != NULL){
    printMovieInventory(node->rightChild);
    }
}

/*
Function prototype:
void MovieTree::addMovieNode(string title, double price)

Function description:
This method reads in a .txt file to add movies to a store and stores them in a binary search tree.  
Example:
BlockBuster->addMovieNode(title, price);

Precondition: Root of MovieTree must exist. MovieTree must be established. title and price must be read in from .txt file. 
Post condition: adds a movie node to the movie tree.
*/
void MovieTree::addMovieNode(string title, double price){
    MovieNode *z = new MovieNode; //creates a new movie node
    z->parent = NULL;
    //z->quantity = quantity;
    //z->ranking = ranking;
    z->title = title;
    z->price = price;
    if(root == NULL){ //if root is null, tree is empty
        root = z;
        root->parent = NULL;
        root->rightChild = NULL;
        root->leftChild = NULL;
    }
    else { //tree is not empty
        MovieNode *x = new MovieNode; //x is root
        //we don't have an empty tree, which means that root isn't NULL
        x = root;
        while (z->parent != x){
            if (z->title > x->title && x->rightChild == NULL){
                x->rightChild = z;
                z->parent = x;
                z->leftChild = NULL;
                z->rightChild = NULL;
            }
            else if (z->title < x->title && x->leftChild == NULL){
                x->leftChild = z;
                z->parent = x;
                z->leftChild = NULL;
                z->rightChild = NULL;
            }
            else if (z->title > x->title && x->rightChild != NULL){
                x = x->rightChild;
            }
            else if(z->title < x->title && x->leftChild != NULL){
                x = x->leftChild;
            }
        }
    }
}

/*
Function prototype:
MovieNode* MovieTree::searchTree(string storename, MovieNode * node, string title)

Function description:
Called by findMovie. This method uses a binary search tree traversal to find and return the movie node that corresponds to the title to user desires. 
If movie is not carried by particular store, will return that the store "currently does not carry" the title. 
Example:
 p = MovieTree::searchTree("BlockBuster", root, "Whiplash");

Precondition: Root of MovieTree must exist. MovieTree must be filled out and established. 
Post condition: Find the corresponding movieNode with the information for title desired by user. 
*/
MovieNode* MovieTree::searchTree(string storename, MovieNode * node, string title){
    if (title == node->title){
        return node;
    }
    else if(title < node->title){
        if(node->leftChild == NULL){
            cout << "\t" << storename << " currently does not carry " << title << "." << endl;
        }
        else{
            return(searchTree(storename, node->leftChild, title));
        }
    }
    else if(title > node->title){
        if(node->rightChild == NULL){
            cout << "\t" << storename << " currently does not carry " << title << "."<< endl;
        }
        else{
            return(searchTree(storename, node->rightChild, title));
        }
    }
}

/*
Function prototype:
void MovieTree::rentMovieBus(string storename, double busFare, string title, double coupon)

Function description:
Finds the total price of renting the movie if the user takes the bus. Calls searchTree function to determine if the store carries the title or not. 

Example:
STAR->rentMovieBus("STAR", 2, "The Dark Knight Rises", 0)

Precondition: Root of MovieTree must exist. MovieTree must be filled out and established. Storename must be valid, busFare must be valid, title must be a string, coupon must be a number greater than or equal to 0.
Post condition: Calculuates how much it would be to rent the movie from a certain store if user rides bus. 
*/

void MovieTree::rentMovieBus(string storename, double busFare, string title, double coupon){
    MovieNode *p = new MovieNode();
    double totalprice;
    p = MovieTree::searchTree(storename, root, title);
        if(p->title == title){
        totalprice = p->price + (2*busFare) - coupon;
        cout << "The total price to rent " << title << " from " << storename << " by taking the bus is " << fixed << setprecision(2) << totalprice << "." << endl;
    }
}

/*
Function prototype:
void MovieTree::rentMovieDrive(string storename, double storedist, string title, double coupon)

Function description:
Finds the total price of renting the movie if the user drives. Asks for fuel efficiency and price of gas. Calls searchTree function to determine if the store carries the title or not. 

Example:
STAR->rentMovieDrive("STAR", 2, "Spirited Away", 0)

Precondition: Root of MovieTree must exist. MovieTree must be filled out and established. Storename must be valid, distance must be valid, title must be a string, coupon must be a number greater than or equal to 0. User must have inputted a efficiency and a gas price previously.
Post condition: Calculuates how much it would be to rent the movie from a certain store if user drives. 
*/

void MovieTree::rentMovieDrive(string storename, double storedist, string title, double coupon){
    MovieNode *p = new MovieNode();
    double totalprice;
    double rentalprice;
    p = MovieTree::searchTree(storename, root, title);
        if(p->title == title){
        rentalprice = p->price;
        totalprice = MovieTree::totalMovieCost(storedist, efficiency, gasprice, rentalprice);
        cout << "The total price to rent " << title << " from " << storename << " by driving is " << fixed << setprecision(2) << totalprice - coupon << "." << endl;
    }
}

/*
Function prototype:
void MovieTree::rentMovieWalk(string storename, string title, double coupon)

Function description:
Finds the total price of renting the movie if the user walks. Calls searchTree function to determine if the store carries the title or not. 

Example:
STAR->rentMovieWalk("STAR","Spirited Away", 0)

Precondition: Root of MovieTree must exist. MovieTree must be filled out and established. Storename must be valid, title must be a string, coupon must be a number greater than or equal to 0.
Post condition: Calculuates how much it would be to rent the movie from a certain store if user drives. 
*/

void MovieTree::rentMovieWalk(string storename, string title, double coupon){
    MovieNode *p = new MovieNode();
    double totalprice;
    p = MovieTree::searchTree(storename, root, title);
        if(p->title == title){
        totalprice = p->price - coupon;
        cout << "The total price to rent " << title << " from " << storename << " by walking is " << fixed << setprecision(2) << totalprice << "." << endl;
    }
}

/*
Function prototype:
void MovieTree::findMovie(string storename, string title)

Function description:
Finds movie in tree. Calls searchTree function to determine if the store carries the title or not. 

Example:
BlockBuster->findMovie("BlockBuster","Shawshank Redemption")

Precondition: Root of MovieTree must exist. MovieTree must be filled out and established. Storename must be valid, title must be a string.
Post condition: Finds movie in tree and outputs movie and price if available. 
*/
void MovieTree::findMovie(string storename, string title){
    MovieNode *p = new MovieNode();
    double totalprice;
    p = MovieTree::searchTree(storename, root, title);
        if(p->title == title){
        totalprice = p->price;
        cout << "\t" << storename << " is " << fixed << setprecision(2) << totalprice << "." << endl;
    }
}

/*
Function prototype:
double MovieTree::totalMovieCost(double distance, double efficiency, double gasprice, double rentalprice)

Function description:
Calculates total movie cost if user drives.

Example:
totalcost = totalMovieCost(4, 20, 2, 1.40);

Precondition: distance, efficiency, gasprice, and rentalprice must be valid numbers.
Post condition: Returns total cost of movie if user drives. 
*/

double MovieTree::totalMovieCost(double distance, double efficiency, double gasprice, double rentalprice){
    double transportationcost;
    double totalprice;
    transportationcost = double((double(distance/efficiency))*(gasprice));
    totalprice = double(double(2*transportationcost) + rentalprice); //you should probably return from the store...
    return totalprice;
}

