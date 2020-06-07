/*
Project 3 - Part 1c / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

1) write the 10th UDT
    come up with an object that is made of 5 smaller parts.
    These parts will not be defined using Primitives, but instead will be their own UDTs you'll define in Part 1d
    
    Here is an example:
    Cell Phone

    A Cell Phone is made up of the following 5 properties:
        Display
        Memory
        CPU
        Radio
        Applications

    A Cell Phone has 3 things it can do:
        make a call
        send a text
        run an application.

    Notice that I did not use "has a display" or "Has memory" or "has a cpu" as one of the properties of the CellPhone
    
    Writing 'has a ___" checks whether or not your object **has the ability to do something**.
    Instead, I wrote "Display" or "CPU".  These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' (has a) as a member variable type.
    Instead, prefer the other primitive types.

    When you choose your 5 smaller parts, remember that each of these 5 Sub Objects will need 
    to be defined with 5 primitive properties and 3 actions EACH.  
*/

/*
Thing 1) Recording Studio
5 properties:
    1) number of microphones
    2) number of outboard units
    3) amount of sessions per month
    4) amount of discount for multiple day sessions
    5) amount of revenew per month
3 things it can do:
    1) record an album
    2) charge sessions to client
    3) test all equipment
 */

/*
Thing 2) Supermarket
5 properties:
    1) number of employees per shift
    2) number of active cashiers
    3) amount of sales per day
    4) amount of profit per day
    5) list with best sold products
3 things it can do:
    1) charge client for groceries
    2) restock products
    3) bake bread
 */

/*
Thing 3) Bakery
5 properties:
    1) number of bags of flour
    2) amount of bread per bread type
    3) amount of cake per cake type
    4) amount of sales per day
    5) amount of products to deliver per establishment
3 things it can do:
    1) bake cake
    2) deliver bread
    3) calculate food waste
 */

/*
Thing 4) Bar
5 properties:
    1) number of products in stock per category
    2) number of product to order per category
    3) amount of profit per day
    4) amount of products sold per day
    5) specials (dishes) per day
3 things it can do:
    1) serve drink
    2) charge costumer
    3) order new stock
 */

/*
Thing 10) Mixing Console
5 properties:
    1) Master Section
    2) Input Section
    3) Output Section
    4) EQ Section
    5) Dynamics Section
3 things it can do:
    1) mix signals together
    2) process signals individually
    3) choose which speakers to use
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
