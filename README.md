#Final Project

##Project Summary:
Our project will have the user search for movies to rent from his home. To do this, we will create a binary search tree of each store (RedBox, Blockbuster, DVD Stop, Barnes&Noble, Splendidly Teriffic Asian Rentals) which will have the prices of individual movies. The user will then be able to see a store's inventory, compare rental prices from each store and find the grand total of all expenses (including transportation fees and coupons). The idea is to let the user keep track of his spending and ensuring that they will find the cheapest option available.


##How to Run:
In order to run this program, please download ALL files (including all text files). You may use the g++ compliler or import all files to a codeblocks project and run it from there.

From the start, the user will be asked to input the distances from his location to the nearest movie rental store. Then, the user will be allowed to choose from these four options:

```
1. Print the inventory of a store
2. Compare prices
3. Rent my movie
4. Quit
```
When selecting option 1, the user will be prompted to enter a store name. There, he can see the inventory.

When selecting option 2, the user will enter a movie title. Then, the program will search all the stores' binary search trees and output the prices from each store.

When selection option 3, the user will be prompted to enter a title, a method of transportation, a store and a coupon as seen below.
```
Please enter the name of a store.
  STAR
Please enter the movie title.
  Spirited Away
Please enter your coupon (in dollars). If you do not have a coupon, enter 0.
  2
Please enter your method of transportation (Walk, Drive or Bus)
  Walk
Your total is 1.40
```


##Dependancies:
None


##System Requirements:
Preferably Linux, but any system that can run C++.


##Group Members:
Amy Chen & Chia-hsin Yang


##Contributors:
Cash Johnson

##Open issues/Bugs:
No obvious bugs, but feel free to add a "cheapest option." If applicable, the program will take the user's preferred store and movie and attempt to find the cheapest price.

