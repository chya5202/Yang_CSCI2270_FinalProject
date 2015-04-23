// Final Project
// Amy Chen and Chia-Hsin Yang
// CSCI2270, Hoenigman, Spring 2015

#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "MovieTree.h"


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

void MovieTree::addMovieNode(std::string title, int price){
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
            std::cout << storename << " currently does not carry " << title << "." << std::endl;
        }
        else{
            return(searchTree(storename, node->leftChild, title));
        }
    }
    else if(title > node->title){
        if(node->rightChild == NULL){
            std::cout << storename << " currently does not carry " << title << "."<< std::endl;
        }
        else{
            return(searchTree(storename, node->rightChild, title));
        }
    }
}

void MovieTree::findMovie(std::string storename, std::string title){
    MovieNode *p = new MovieNode();
    p = searchTree(storename, root, title);
    if(p->title == title){
        double distance;
        double efficiency;
        double gasprice;
        double totalprice;
        std::cout << storename << "carries the movie you requested, " << title << " for " << p->price << "." << std::endl;
        std::cout << "How far away is " << storename << "? (in miles)" << std::endl;
        std::cin >> std::ws;
        std::cin >> distance;
        std::cout << "What is your fuel efficiency? (in miles per gallon)" << std::endl;
        std::cin >> std::ws;
        std::cin >> efficiency;
        std::cout << "What is the current price of gasoline? (dollars per gallon)" << std::endl;
        std::cin >> std::ws;
        std::cin >> gasprice;
        double transportationcost;
        transportationcost = (distance)*(1/efficiency)*(gasprice);
        totalprice = p->price + transportationcost;
        std::cout << "The total price to rent " << title << " from " << storename << " is " << std::fixed << std::setprecision(2) << totalprice << "." << std::endl;
    }
    else{
        std::cout << storename << "does not have the movie you requested." << std::endl;
    }
}

void MovieTree::rentMovie(std::string storename, std::string title){
    MovieNode *q = new MovieNode();
    q = searchTree(storename, root, title);
    if(q->title == title){
            int rentalprice = 0;
        //if(q->quantity == 0){
            //std::cout << "Movie out of stock" << std::endl;
        //}
        //else{
            //q->quantity = q->quantity - 1;
            if (storename == "Barnes&Noble"){
                BarnesNoble->findMovie("BarnesNoble", title);
            }
            else if (storename == "BlockBuster"){
                BlockBuster->findMovie("BlockBuster", title);
            }
            else if (storename == "DVDRentals"){
                DVDRentals->findMovie("DVDRentals", title);
            }
            else if (storename == "Redbox"){
                RedBox->findMovie("Redbox", title);
            }
            else if (storename == "STAR"){
                STAR->findMovie("STAR", title);
            }
            //std::cout << "Your movie, " << title << ", has been rented from " << storename << " for " << std::fixed << std::setprecision(2) << totalcost << "." << std::endl;
        //}
    }
}


double totalMovieCost(double distance, double efficiency, double gasprice, double rentalprice){
    double transportationcost;
    double rentprice;
    transportationcost = (distance)*(1/efficiency)*(gasprice);
    double totalprice = rentprice + transportationcost;
    return totalprice;
    //std::cout << std::fixed << std::setprecision(2) << total price << std::endl;
}







