/*
Project 3 - Part 1e / 5
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

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct for each of your 10 types. i.e.:
*/
struct CellPhone
{

};
/*
2) Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};







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

struct RecStudio 
{
    // number of microphones
    int numMicrophones = 25;
    // number of outboard units
    int numOutboardUnits = 30;
    // amount of sessions per month
    int sessionPerMonth = 10;
    // amount of discount for multiple day sessions
    float multiDayDiscount = 20.0f;
    // amount of revenew per month
    float revenewPerMonth = 6000.0f;

    // record an album
    void recordAlbum(int numMusicians, int genreCode, int amountTime);
    // charge sessions to client
    float chargeSession(int hoursUsed, float discount, float extraCosts = 0.0f);
    // test all equipment
    void testAllEquipment();
};

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

struct Supermarket 
{
    // number of employees per shift
    int employPerShift = 15;
    // number of active cashiers
    int numActiveChashiers = 5;
    // amount of sales per day
    float salesPerDay = 10000.0f;
    // amount of profit per day
    float profitPerDay = 3000.0f;
    // list with best sold products
    int topSellerID = 0;

    struct Product 
    {
        int productID = 0;
        std::string productName = "";
        float retailPrice = 0.0f;
        int currentStock = 0;
        int orderedStock = 0;

        // updates product price
        bool updatePrice(float newPrice);
        // predicts needed stock based on previous sales
        int stockPrediction(int salesPeriodInMonths, int salesAmount, int currentStock);
        // compares two prices and gives the difference
        float priceComparison(Product prodToCompareWith);
    };                       

    // charge client for groceries
    float chargeClient(float productTotal, float taxAmount = 21.0f, float discount = 0);
    // restock products
    bool restockProducts(Product prod, int restockQuantity);
    // bake bread
    void bakeBread(int breadType, int bakeQuantity);
};

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

struct Bakery
{
    // number of bags of flour
    int numBagsFlour = 20;
    // amount of bread per bread type
    int XBread_Amount = 40;
    // amount of cake per cake type
    int XCake_Amount = 5;
    // amount of sales per day
    float daySales = 5000.0f;
    // amount of products to deliver per establishment
    int XCliente_totalProdDeliver = 5;

    // bake cake
    void bakeCake(int cakeType, int bakeQuantity);
    // deliver bread
    bool deliverBread(int clientID, int orderID, int deliveryTime);
    // calculate food waste
    float foodWaste_Kg(int amountDays);
};

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

struct Bar 
{
    // number of products in stock per category
    int XCategory_numProdStock = 200;
    // number of product to order per category
    int XCategory_numProdOrder = 50;
    // amount of profit per day
    float dayProfit = 4000.0f;
    // amount of products sold per day
    int prodSoldPerDay = 150;
    // specials (dishes) per day
    int numDailySpecials = 3;

    // serve drink
    bool serveDrink(int drinkID, int quantity = 1);
    // charge costumer
    float billClient(float productTotal, bool hasTabOpen = false, float taxAmount = 9.0f);
    // order new stock
    void orderNewStock(int productID, int quantityOrder);
};

/*
Thing 5) Master Section
5 properties:
    1) Master Fader Level in dB
    2) Speaker Level in dB
    3) Monitor Selection
    4) Foldback Level in dB
    5) Bus Compressor On/Off
3 things it can do:
    1) select different set of speakers
    2) change monitoring level
    3) send audio to headphones
 */

struct MasterSection
{
    // Master Fader Level in dB
    float masterFaderLevel = 0.0f;
    // Speaker Level in dB
    float monitorLevel = -20.0f;
    // Monitor Selection
    int monitorSelID = 0;
    // Foldback Level in dB
    float foldbackLevel = -10.0f;
    // Bus Compressor On/Off
    bool busCompressor = false;

    // select different set of speakers
    void selectSpeaker(int monitorSelID);
    // change monitoring level
    void changeLevel(float gainChange);
    // send audio to headphones
    bool sendMasterToHP(float sendLevel = -20.0f);
};

/*
Thing 6) Input Section
5 properties:
    1) Mic Gain Level in dB
    2) Line Level in dB
    3) Input Source
    4) Meter Flip
    5) HPF On/Off
3 things it can do:
    1) amplify input signal
    2) apply hpf on input
    3) attenuate MTR return
 */

struct InputSection
{
    // Mic Gain Level in dB
    float micGain = -80.0f;
    // Line Level in dB
    float lineGain = 0.0f;
    // Input Source
    int inputSourceID = 0;
    // Meter Flip
    bool meterFlip = false;
    // HPF On/Off
    bool hpfEngage = false;

    // amplify input signal
    void gainInput(float gainAmount);
    // apply hpf on input
    void engageHPF(bool hpfEngage);
    // attenuate MTR return
    void gainMtrRet(float gainAmount);
};

/*
Thing 7) Output Section
5 properties:
    1) Matrix Output Channel
    2) Mix Switch On/Off
    3) Output Level
    4) Channel Panning
    5) Meter Flip
3 things it can do:
    1) include singnal in subgroup
    2) set channel output level
    3) position signal in stereo field
 */

struct OutputSection
{
    // Matrix Output Channel
    int outputChannel = 0;
    // Mix Switch On/Off
    bool addToMix = false;
    // Output Level
    float channelFader = -80.0f;
    // Channel Panning
    float channelPanning = 0.0f;
    // Meter Flip
    bool meterFlip = false;

    // include singnal in subgroup
    void sendToSubgroup(int subgroupID);
    // set channel output level
    void setChannelLevel(int channelID, float channelFader);
    // position signal in stereo field
    void changePanning(int channelID, float channelPanning);
};

/*
Thing 8) EQ Section
5 properties:
    1) High Shelf Frequency
    2) High Shelf Gain
    3) Parametric Frequency
    4) Parametric Q
    5) Parametric Gain
3 things it can do:
    1) remove unwanted frequencies
    2) increase presence in the signal
    3) decrease low end boominess
 */

struct EQSection
{
    // High Shelf Frequency
    float highShelfFreq = 20000.0f;
    // High Shelf Gain
    float highShelfGain = 0.0f;
    // Parametric Frequency
    float ParamFreq = 1000.0f;
    // Parametric Q
    float ParamQ = 1.0f;
    // Parametric Gain
    float ParamGain = 0.0f;

    // remove unwanted frequencies
    void removeFreq(float freqToRemove, float amountInDb);
    // increase presence in the signal
    void addPresence(float cutOffFreq, float amountInDb);
    // decrease low end boominess
    void decreaseBoom(float centerFreq, float bandWidth, float amountInDb);
};

/*
Thing 9) Dynamics Section
5 properties:
    1) Compressor Threshold
    2) Compressor Ratio
    3) Compressor Attack
    4) Compressor Release
    5) Compressor Engage Switch
3 things it can do:
    1) limit signal to avoid clipping
    2) make signal louder
    3) tame signal transients
 */

struct DynamicsSection
{
    // Compressor Threshold
    float compThresh = 0.0f;
    // Compressor Ratio
    float compRatio = 2.0f;
    // Compressor Attack
    int compAttackMs = 10.0f;
    // Compressor Release
    int compRelMs = 200.0f;
    // Compressor Engage Switch
    bool compEngage = false;

    // limit signal to avoid clipping
    float limitSignal(float threshold, int lookaheadMs);
    // make signal louder
    void compSignal(float compThresh, float compRatio, float makeUpGain);
    // tame signal transients
    void tameSignalTransients(int channelID);
};

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

struct MixingConsole
{
    // Master Section
    MasterSection MS;
    // Input Section
    InputSection IS;
    // Output Section
    OutputSection OS;
    // EQ Section
    EQSection ES;
    // Dynamics Section
    DynamicsSection DS;

    struct ChannelStrip
    {
        int channelID = 0;
        float SF_Level = -80.0f;
        float LF_Level = -80.0f;
        bool SF_toMasterBus = false;
        bool LF_toMasterBus = false;
        
        // resets channelstrip
        bool resetChannel();
        // copies from sf to lf or vice-versa
        bool copySettingsFromPath(std::string pathToCopy);
        // change channel position
        void changeChannelID(int oldID, int newID);
    };

    // mix signals together
    void mixAllActiveChannels();
    // process signals individually
    void processChannel(ChannelStrip chStrp, DynamicsSection dynSec, EQSection eqSec, bool dynBeforeEq = true);
    // choose which speakers to use
    void selectMainMonitors(int monitorID, float gainTrim = 0.0f);
};

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
