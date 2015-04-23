// Final Project
// Amy Chen and Chia-Hsin Yang
// CSCI2270, Hoenigman, Spring 2015

#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "MovieTree.h"

//using namespace std;


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
    std::cout << "Movie: " << node->title << std::endl;
    if (node->rightChild != NULL){
    printMovieInventory(node->rightChild);
    }
}

void MovieTree::addMovieNode(std::string title, double price){
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
        //std::cout << z->parent->title << std::endl;
    }
}

MovieNode* MovieTree::searchTree(std::string storename, MovieNode * node, std::string title){
    if (title == node->title){
        return node;
    }
    else if(title < node->title){
        if(node->leftChild == NULL){
            std::cout << "\t" << storename << " currently does not carry " << title << "." << std::endl;
        }
        else{
            return(searchTree(storename, node->leftChild, title));
        }
    }
    else if(title > node->title){
        if(node->rightChild == NULL){
            std::cout << "\t" << storename << " currently does not carry " << title << "."<< std::endl;
        }
        else{
            return(searchTree(storename, node->rightChild, title));
        }
    }
}

void MovieTree::findMovie(std::string storename, double storedist, std::string title){
    MovieNode *p = new MovieNode();
    double totalprice;
    double rentalprice;
    p = MovieTree::searchTree(storename, root, title);
        if(p->title == title){
        rentalprice = p->price;
        totalprice = MovieTree::totalMovieCost(storedist, efficiency, gasprice, rentalprice);
        std::cout << "\t" << storename << " is " << std::fixed << std::setprecision(2) << totalprice << "." << std::endl;
    }
}

double MovieTree::totalMovieCost(double distance, double efficiency, double gasprice, double rentalprice){
    double transportationcost;
    double totalprice;
    transportationcost = double((double(distance/efficiency))*(gasprice));
    totalprice = double(double(2*transportationcost) + rentalprice); //you should probably return from the store...
    return totalprice;
}










