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
    int price;
    MovieNode *parent;
    MovieNode *leftChild;
    MovieNode *rightChild;

    MovieNode(){};

    MovieNode(std::string in_title, int in_price)
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
        void addMovieNode(std::string title, int price);
        void findMovie(std::string storename, std::string title);
        void rentMovie(std::string storename, std::string title);
    protected:
    private:
        void DeleteAll(MovieNode *node);
        void printMovieInventory(MovieNode *node);
        MovieNode* searchTree(std::string storename, MovieNode * node, std::string title);
        MovieNode *root;
};

class MovieStore
{
    public:
    MovieStore ();
    void buildMovieStore();
    double totalMovieCost(double distance, double efficiency, double gasprice, double rentalprice);
};


extern MovieTree *BarnesNoble;
extern MovieTree *BlockBuster;
extern MovieTree *DVDRentals;
extern MovieTree *RedBox;
extern MovieTree *STAR;


#endif // MOVIETREE_H
