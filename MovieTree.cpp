// Final Project
// Amy Chen and Chia-Hsin Yang
// CSCI2270, Hoenigman, Spring 2015

//The MovieTree code will create a BST of
//MovieNode structs for each store we read in. The movie will include title and price.
//The MovieStore class will create a MovieTree for each store and calculate transportation cost plus rental cost for total cost.

#ifndef MOVIETREE_H
#define MOVIETREE_H


struct MovieNode{
    std::string title;
    double price;
    MovieNode *parent;
    MovieNode *leftChild;
    MovieNode *rightChild;

    MovieNode(){};

    MovieNode(std::string in_title, double in_price)
    {
        title = in_title;
        price = in_price;
    }

};

class MovieTree
{
    public:
        MovieTree();
        //virtual ~MovieTree();
        void printMovieInventory();
        void addMovieNode(std::string title, double price);
        void findMovie(std::string storename, double storedist, std::string title);
        double totalMovieCost(double distance, double efficiency, double gasprice, double rentalprice);
    protected:
    private:
        void printMovieInventory(MovieNode *node);
        MovieNode* searchTree(std::string storename, MovieNode * node, std::string title);
        MovieNode *root;
};

class MovieStore
{
    public:
    MovieStore ();
    void buildMovieStore();
};


extern MovieTree *BarnesNoble;
extern MovieTree *BlockBuster;
extern MovieTree *DVDRentals;
extern MovieTree *RedBox;
extern MovieTree *STAR;
extern double efficiency;
extern double gasprice;
extern double BNdist;
extern double BBdist;
extern double DVDdist;
extern double RBdist;
extern double STARdist;


#endif // MOVIETREE_H
