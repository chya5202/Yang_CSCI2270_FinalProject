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


MovieTree::MovieTree(){
    root = NULL;
}

void MovieTree::printMovieInventory(){
    printMovieInventory(root);
}

void MovieTree::printMovieInventory(MovieNode *node){
    if (node->leftChild != NULL){
    printMovieInventory(node->leftChild);
    }
    cout << "Movie: " << node->title << endl;
    if (node->rightChild != NULL){
    printMovieInventory(node->rightChild);
    }
}

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

void MovieTree::rentMovieBus(string storename, double busFare, string title, double coupon){
    MovieNode *p = new MovieNode();
    double totalprice;
    p = MovieTree::searchTree(storename, root, title);
        if(p->title == title){
        totalprice = p->price + busFare - coupon;
        cout << "The total price to rent " << title << " from " << storename << " by taking the bus is " << fixed << setprecision(2) << totalprice << "." << endl;
    }
}

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

void MovieTree::rentMovieWalk(string storename, string title, double coupon){
    MovieNode *p = new MovieNode();
    double totalprice;
    p = MovieTree::searchTree(storename, root, title);
        if(p->title == title){
        totalprice = p->price - coupon;
        cout << "The total price to rent " << title << " from " << storename << " by walking is " << fixed << setprecision(2) << totalprice << "." << endl;
    }
}

void MovieTree::findMovie(string storename, string title){
    MovieNode *p = new MovieNode();
    double totalprice;
    p = MovieTree::searchTree(storename, root, title);
        if(p->title == title){
        totalprice = p->price;
        cout << "\t" << storename << " is " << fixed << setprecision(2) << totalprice << "." << endl;
    }
}


double MovieTree::totalMovieCost(double distance, double efficiency, double gasprice, double rentalprice){
    double transportationcost;
    double totalprice;
    transportationcost = double((double(distance/efficiency))*(gasprice));
    totalprice = double(double(2*transportationcost) + rentalprice); //you should probably return from the store...
    return totalprice;
}

