// Final Project
// Amy Chen and Chia-Hsin Yang
// CSCI2270, Hoenigman, Spring 2015

//The MovieTree code will create a BST of
//MovieNode structs for each store we read in. The movie will include title and price.
//The MovieStore class will create a MovieTree for each store and calculate transportation cost plus rental cost for total cost.

#ifndef MOVIETREE_H
#define MOVIETREE_H

using namespace std;


struct MovieNode{
    string title;
    double price;
    MovieNode *parent;
    MovieNode *leftChild;
    MovieNode *rightChild;

    MovieNode(){};

    MovieNode(string in_title, double in_price)
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
        void addMovieNode(string title, double price);
        void findMovie(string storename, string title);
        void rentMovieDrive(string storename, double storedist, string title, double coupon);
        void rentMovieWalk(string storename, string title, double coupon);
        void rentMovieBus(string storename, double busFare, string title, double coupon);
        bool compare(std::string one, std::string two);
        string searchTree(string title);
        MovieNode* searchTree(MovieNode * node, string title);
        double totalMovieCost(double distance, double efficiency, double gasprice, double rentalprice);
    protected:
    private:
        void printMovieInventory(MovieNode *node);
        MovieNode* searchTree(string storename, MovieNode * node, string title);
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
extern double busFare;
extern double BNdist;
extern double BBdist;
extern double DVDdist;
extern double RBdist;
extern double STARdist;


#endif // MOVIETREE_H
