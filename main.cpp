 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
#include <math.h>       // included for comparison use

namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    struct Foot
    {
        int numOfSteps = 0;
        int stepSize_cm = 70; 

        void stepForward();
        int stepSize();
    };

    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::Foot::stepForward()
{
    numOfSteps += 1;
}

int Person::Foot::stepSize()
{
    return stepSize_cm;
}

void Person::run(int howFast, bool startWithLeftFoot)
{
    howFast = 3;

    if(startWithLeftFoot) 
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }

    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you decide to write empty functions, you will need to fill them in with code in part 3.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 */

struct RecStudio 
{
    int numMicrophones = 25;
    int numOutboardUnits = 30;
    int sessionPerMonth = 10;
    float multiDayDiscount = 0.20f;
    float revenewPerMonth = 6000.0f;

    void recordAlbum(int numMusicians, int genreCode, int amountTime);
    float chargeSession(int hoursUsed, float discount, float extraCosts = 0.0f);
    void testAllEquipment();
};

void RecStudio::recordAlbum(int numMusicians, int genreCode, int amountTime)
{
    // Price Preview + Booking

    numMusicians = 5;
    genreCode = 2;
    amountTime = 10;
}

float RecStudio::chargeSession(int hoursUsed, float discount, float extraCosts)
{
    float hourlyPrice = 50.0f;          // Variable would be created elsewhere
    float sessionPrice = 0.0f;

    sessionPrice = hoursUsed * hourlyPrice + extraCosts;
    sessionPrice -= sessionPrice * discount;

    return sessionPrice;
}

void RecStudio::testAllEquipment()
{
    // Check all equipment available + test procedure
}

struct Supermarket 
{
    int employPerShift = 15;
    int numActiveChashiers = 5;
    float salesPerDay = 10000.0f;
    float profitPerDay = 3000.0f;
    int topSellerID = 0;

    struct Product 
    {
        int productID = 0;
        std::string productName = "";
        float retailPrice = 0.0f;
        int currentStock = 0;
        int orderedStock = 0;

        bool updatePrice(float newPrice);
        int stockPrediction(int salesPeriodInMonths, int salesAmount, int currentStock);
        float priceComparison(Product prodToCompareWith);
    };                       

    float chargeClient(float productTotal, float taxAmount = 0.21f, float discount = 0);
    bool restockProducts(Product prod, int restockQuantity);
    void bakeBread(int breadType, int bakeQuantity);
};

bool Supermarket::Product::updatePrice(float newPrice)
{
    if(fabs(this->retailPrice - newPrice) < 0.005f)
    {
        this->retailPrice = newPrice;
        return true;
    }
    return false;
}

int Supermarket::Product::stockPrediction(int salesPeriodInMonths, int salesAmount, int curStock)
{
    salesPeriodInMonths = 6;
    salesAmount = 30;
    curStock = 5;

    int stockNeeded = 0;

    // Prediction based on sales

    return stockNeeded;
}

float Supermarket::Product::priceComparison(Supermarket::Product prodToCompareWith)
{
    float priceDiff = 0.0f;

    priceDiff = retailPrice - prodToCompareWith.retailPrice;

    return priceDiff;
}

float Supermarket::chargeClient(float productTotal, float taxAmount, float discount)
{
    float totalCharge = 0.0f;

    totalCharge = productTotal + (productTotal * taxAmount);
    totalCharge -= totalCharge * discount;

    return totalCharge;
}

bool Supermarket::restockProducts(Supermarket::Product prod, int restockQuantity)
{
    // Method to contact supplier
    bool contactSuccessful = true;              // Success simulation

    if(contactSuccessful)
    {
        prod.orderedStock = restockQuantity;
        return contactSuccessful;
    }

    return !contactSuccessful;
}

void Supermarket::bakeBread(int breadType, int bakeQuantity)
{
    breadType = 4;
    bakeQuantity = 30;

    // Start baking method
}

struct Bakery
{
    int numBagsFlour = 20;
    int XBread_Amount = 40;
    int XCake_Amount = 5;
    float daySales = 5000.0f;
    int XClient_totalProdDeliver = 5;

    void bakeCake(int cakeType, int bakeQuantity);
    bool deliverBread(int clientID, int orderID, int deliveryTime);
    float foodWaste_Kg(int amountDays);
};

void Bakery::bakeCake(int cakeType, int bakeQuantity)
{
    cakeType = 3;
    bakeQuantity = 2;

    // Start baking method
}

bool Bakery::deliverBread(int clientID, int orderID, int deliveryTime)
{
    clientID = 40;
    orderID = 937;
    deliveryTime = 1230;

    // Start delivery method

    return true;                                // Success simulation
}

float Bakery::foodWaste_Kg(int amountDays)
{
    amountDays = 15;

    float totalFoodWaste = 0.0f;

    // Calculate food waste

    return totalFoodWaste;
}

struct Bar 
{
    int XCategory_numProdStock = 200;
    int XCategory_numProdOrder = 50;
    float dayProfit = 4000.0f;
    int prodSoldPerDay = 150;
    int numDailySpecials = 3;

    bool serveDrink(int drinkID, int quantity = 1);
    float billClient(float productTotal, bool hasTabOpen = false, float taxAmount = 0.09f);
    void orderNewStock(int productID, int quantityOrder);
};

bool Bar::serveDrink(int drinkID, int quantity)
{
    drinkID = 33;
    quantity = 2;

    bool drinkServed = true;                    // Success simulation

    // check if drink is in stock, if yes serveDrink

    return drinkServed;
}

float Bar::billClient(float productTotal, bool hasTabOpen, float taxAmount)
{
    float totalCharge = 0.0f;
    float totalTab = 0.0f;                  // Variable would be created elsewhere

    if(!hasTabOpen)
    {
        totalCharge = productTotal + (productTotal * taxAmount);  
    }
    else
    {
        totalCharge = productTotal + totalTab;
        totalCharge += totalCharge * taxAmount;
    }

    return totalCharge;
}

void Bar::orderNewStock(int productID, int quantityOrder)
{
    productID = 564;
    quantityOrder = 55;

    // Method to order products
}

struct MasterSection
{
    float masterFaderLevel = 0.0f;
    float monitorLevel = -20.0f;
    int monitorSelID = 0;
    float foldbackLevel = -10.0f;
    bool busCompressor = false;

    void selectSpeaker(int monitorSelID);
    void changeLevel(float gainChange);
    bool sendMasterToHP(float sendLevel = -20.0f);
};

void MasterSection::selectSpeaker(int monitorID)
{
    monitorID = 3;

    // Change main speakers
}

void MasterSection::changeLevel(float gainChange)
{
    masterFaderLevel += gainChange;
}

bool MasterSection::sendMasterToHP(float sendLevel)
{
    sendLevel = -10.0f;

    // Send master fader to foldback

    return true;                        // Success simulation
}

struct InputSection
{
    float micGain = -80.0f;
    float lineGain = 0.0f;
    int inputSourceID = 0;
    bool meterFlip = false;
    bool hpfEngage = false;

    void gainInput(float gainAmount);
    void engageHPF(bool hpfEngage);
    void gainMtrRet(float gainAmount);
};

void InputSection::gainInput(float gainAmount)
{
    if(inputSourceID == 0)                // Would use a switch case instead
    {
        micGain += gainAmount;
    }
    else if(inputSourceID == 1)
    {
        lineGain += gainAmount;
    }
}

void InputSection::engageHPF(bool hpfEng)
{
    hpfEngage = hpfEng;
}

void InputSection::gainMtrRet(float gainAmount)
{
    gainAmount = -5.0f;

    // Change gain on MTR Return
}

struct OutputSection
{
    int outputChannel = 0;
    bool addToMix = false;
    float channelFader = -80.0f;
    float channelPanning = 0.0f;
    bool meterFlip = false;

    void sendToSubgroup(int subgroupID);
    void setChannelLevel(int channelID, float channelFader);
    void changePanning(int channelID, float channelPanning);
};

void OutputSection::sendToSubgroup(int subgroupID)
{
    subgroupID = 5;

    // Set output to given subgroup
}

void OutputSection::setChannelLevel(int channelID, float chFader)
{
    channelID = 16;
    chFader = -12.0f;

    // Set level on channels' fader
}

void OutputSection::changePanning(int channelID, float chPanning)
{
    channelID = 5;
    chPanning = -0.5f;

    // Set panning on channels' panner
}

struct EQSection
{
    float highShelfFreq = 20000.0f;
    float highShelfGain = 0.0f;
    float ParamFreq = 1000.0f;
    float ParamQ = 1.0f;
    float ParamGain = 0.0f;

    void removeFreq(float freqToRemove, float amountInDb);
    void addPresence(float cutOffFreq, float amountInDb);
    void decreaseBoom(float centerFreq, float bandWidth, float amountInDb);
};

void EQSection::removeFreq(float freqToRemove, float amountInDb)
{
    freqToRemove = 4000.0f;
    amountInDb = 50.0f;

    // Apply freq reduction
}

void EQSection::addPresence(float cutOffFreq, float amountInDb)
{
    cutOffFreq = 10000.0f;
    amountInDb = 3.0f;

    // Increase shelf at freq
}

void EQSection::decreaseBoom(float centerFreq, float bandWidth, float amountInDb)
{
    centerFreq = 300.0f;
    bandWidth = 2.0f;
    amountInDb = 6.0f;

    // Decrease peak at frequency
}

struct DynamicsSection
{
    float compThresh = 0.0f;
    float compRatio = 2.0f;
    int compAttackMs = 10.0f;
    int compRelMs = 200.0f;
    bool compEngage = false;

    float limitSignal(float threshold, int lookaheadMs);
    void compSignal(float compThresh, float compRatio, float makeUpGain);
    void tameSignalTransients(int channelID);
};

float DynamicsSection::limitSignal(float threshold, int lookaheadMs)
{
    threshold = -2.0f;
    lookaheadMs = 6;

    float newSampleLevel = 0.0f;

    // Create limiter

    return newSampleLevel;
}

void DynamicsSection::compSignal(float thresh, float ratio, float makeUpGain)
{
    thresh = -6.0f;
    ratio = 3.5f;
    makeUpGain = 4.0f;

    // Compress signal
}

void DynamicsSection::tameSignalTransients(int channelID)
{
    channelID = 10;

    // Fast peak reduction
}

struct MixingConsole
{
    MasterSection MS;
    InputSection IS;
    OutputSection OS;
    EQSection ES;
    DynamicsSection DS;

    struct ChannelStrip
    {
        int channelID = 0;
        float SF_Level = -80.0f;
        float LF_Level = -80.0f;
        bool SF_toMasterBus = false;
        bool LF_toMasterBus = false;
        
        bool resetChannel();
        bool copySettingsFromPath(std::string pathToCopy);
        void changeChannelID(int oldID, int newID);
    };

    void mixAllActiveChannels();
    void processChannel(ChannelStrip chStrp, DynamicsSection dynSec, EQSection eqSec, bool dynBeforeEq = true);
    void selectMainMonitors(int monitorID, float gainTrim = 0.0f);
};

bool MixingConsole::ChannelStrip::resetChannel()
{
    channelID = 0;
    SF_Level = -80.0f;
    LF_Level = -80.0f;
    SF_toMasterBus = false;
    LF_toMasterBus = false;

    return true;
}

bool MixingConsole::ChannelStrip::copySettingsFromPath(std::string pathToCopy)
{
    pathToCopy = "SF";

    // copy senttings from a channelto the other

    return true;                        // Success simulation
}

void MixingConsole::ChannelStrip::changeChannelID(int oldID, int newID)
{
    oldID = 12;
    newID = 15;

    // check if new id exists
    // if it doesn't, find channel with old id and change channel id for new id
}

void MixingConsole::mixAllActiveChannels()
{
    // Mix all active signals together
}

void MixingConsole::processChannel(MixingConsole::ChannelStrip chStrp, DynamicsSection dynSec, EQSection eqSec, bool dynBeforeEq)
{
    chStrp.channelID = 2;
    dynSec.compEngage = true;
    eqSec.ParamGain = 5.0f;
    dynBeforeEq = true;

    // Apply processing to channel passed
}

void MixingConsole::selectMainMonitors(int monitorID, float gainTrim)
{
    monitorID = 1;
    gainTrim = 5.0f;

    // Select main speakers
}

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
