/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
    return 0;
}
}

//call Example::main() in main()








struct RecStudio 
{
    int numMicrophones;
    int numOutboardUnits;
    int sessionPerMonth;
    float multiDayDiscount;
    float revenewPerMonth;

    RecStudio() : numMicrophones(25),
                  numOutboardUnits(30),
                  sessionPerMonth(10),
                  multiDayDiscount(0.2f),
                  revenewPerMonth(6000.0f) {}

    void recordAlbum(int numMusicians, int genreCode, int amountTime);
    float chargeSession(int hoursUsed, float discount, float extraCosts = 0.0f);
    void testAllEquipment();

    float yearlyRevenew(float monthRevenew, int periodInMonths);
};

void RecStudio::recordAlbum(int numMusicians, int genreCode, int amountTime)
{
    // Price Preview + Booking

    std::cout << "\nAn album recording with " << numMusicians << " musicians and genre " << genreCode << " has been booked. It will cost approximately " << amountTime * 50.0f << " euros." << std::endl;
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

    std::cout << "\n" << numMicrophones << " microphones to be tested. " << numOutboardUnits << " outboard units to be tested." << std::endl;
}

float RecStudio::yearlyRevenew(float monthRevenew, int periodInMonths)
{
    int months = 0;
    float totalRevenew = 0.0f;
    
    while(months < periodInMonths)
    {
        totalRevenew += monthRevenew;
        ++months;
    }

    return totalRevenew;
}

struct Supermarket 
{
    int employPerShift { 15 };
    int numActiveChashiers { 5 };
    float salesPerDay { 10000.0f };
    float profitPerDay { 3000.0f };
    int topSellerID { 0 };

    Supermarket() {}

    struct Product 
    {
        int productID;
        std::string productName;
        float retailPrice;
        int currentStock;
        int orderedStock;

        Product();

        bool updatePrice(float newPrice);
        int stockPrediction(int salesPeriodInMonths, int salesAmount, int currentStock);
        float priceComparison(Product prodToCompareWith);
    };                       

    float chargeClient(float productTotal, float taxAmount = 0.21f, float discount = 0);
    bool restockProducts(Product prod, int restockQuantity);
    void bakeBread(int breadType, int bakeQuantity);

    void checkCashiers(int cashierAmount);
};

Supermarket::Product::Product()
{
    productID = 0;
    productName = "";
    retailPrice = 0.0f;
    currentStock = 0;
    orderedStock = 0;
}
#include <math.h>
bool Supermarket::Product::updatePrice(float newPrice)
{
    if(std::fabs(this->retailPrice - newPrice) < 0.005f)
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
    // Start baking method

    std::cout << "\n" << bakeQuantity << " units of bread type " << breadType << " have been added to the queue." << std::endl;
}

void Supermarket::checkCashiers(int cashierAmount)
{
    for(int i = 0; i < cashierAmount; ++i)
    {
        // Prints name of cashier

        std::cout << "\n" << i + 1 << " - Cashier Name: Placeholder" << std::endl;
    }
}

struct Bakery
{
    int numBagsFlour;
    int XBread_Amount;
    int XCake_Amount;
    float daySales;
    int XClient_totalProdDeliver;

    Bakery() : numBagsFlour(20),
               XBread_Amount(40),
               XCake_Amount(5),
               daySales(5000.0f),
               XClient_totalProdDeliver(5) {}

    struct Bread 
    {
        std::string name = ""; 
        int units = 0;

        Bread(std::string n, int u) : name(n), units(u) { } 
    };  

    void bakeCake(int cakeType, int bakeQuantity);
    bool deliverBread(int clientID, int orderID, int deliveryTime);
    float foodWaste_Kg(int amountDays);

    Bread makeBread(std::string breadName, int amountBake);
};

void Bakery::bakeCake(int cakeType, int bakeQuantity)
{
    // Start baking method

    std::cout << "\n" << bakeQuantity << " cakes of type " << cakeType << " have been added to the baking queue. There are " << numBagsFlour << " bags of flour left." << std::endl;
}

bool Bakery::deliverBread(int clientID, int orderID, int deliveryTime)
{
    // Start delivery method

    std::cout << "\nFor client (ID) " << clientID << " and order (ID) " << orderID << " there are " << XClient_totalProdDeliver << " products to be delivered at " << deliveryTime << "." << std::endl;

    return true;                                // Success simulation
}

float Bakery::foodWaste_Kg(int amountDays)
{
    amountDays = 15;

    float totalFoodWaste = 0.0f;

    // Calculate food waste

    return totalFoodWaste;
}

Bakery::Bread Bakery::makeBread(std::string breadName, int amountBake)
{
    Bakery::Bread bread(breadName, 0);

    while(bread.units < amountBake)
    {
        bread.units += 1;

        if(bread.units >= amountBake)
        {
            return bread;
        }
    }

    return Bread {breadName, 0};
}

/*

Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1};

*/

struct Bar 
{
    int XCategory_numProdStock { 200 };
    int XCategory_numProdOrder { 50 };
    float dayProfit { 4000.0f };
    int prodSoldPerDay { 150 };
    int numDailySpecials { 3 };

    Bar() {}

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
    float masterFaderLevel;
    float monitorLevel;
    int monitorSelID;
    float foldbackLevel;
    bool busCompressor;

    MasterSection();

    void selectSpeaker(int monitorSelID);
    void changeLevel(float gainChange);
    bool sendMasterToHP(float sendLevel = -20.0f);
};

MasterSection::MasterSection()
{
    masterFaderLevel = 0.0f;
    monitorLevel = -20.0f;
    monitorSelID = 0;
    foldbackLevel = -10.0f;
    busCompressor = false;
}

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
    float micGain;
    float lineGain;
    int inputSourceID;
    bool meterFlip;
    bool hpfEngage;

    InputSection();

    void gainInput(float gainAmount);
    void engageHPF(bool hpfEngage);
    void gainMtrRet(float gainAmount);

    std::string fadeInMic(float currentGain, float targetGain);
};

InputSection::InputSection()
{
    micGain = -80.0f;
    lineGain = 0.0f;
    inputSourceID = 0;
    meterFlip = false;
    hpfEngage = false;
}

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

std::string InputSection::fadeInMic(float currentGain, float targetGain)
{
    while(currentGain < targetGain)
    {
        currentGain += 1.0f;

        if(currentGain >= targetGain)
        {
            micGain = currentGain;
            return "Target Gain achieved.";
        }
    }
    return "Current Gain higher than Target.";
}

struct OutputSection
{
    int outputChannel;
    bool addToMix;
    float channelFader;
    float channelPanning;
    bool meterFlip;

    OutputSection();

    void sendToSubgroup(int subgroupID);
    void setChannelLevel(int channelID, float channelFader);
    void changePanning(int channelID, float channelPanning);
};

OutputSection::OutputSection()
{
    outputChannel = 0;
    addToMix = false;
    channelFader = -80.0f;
    channelPanning = 0.0f;
    meterFlip = false;
}

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
    float highShelfFreq;
    float highShelfGain;
    float ParamFreq;
    float ParamQ;
    float ParamGain;

    EQSection();

    void removeFreq(float freqToRemove, float amountInDb);
    void addPresence(float cutOffFreq, float amountInDb);
    void decreaseBoom(float centerFreq, float bandWidth, float amountInDb);
};

EQSection::EQSection()
{
    highShelfFreq = 20000.0f;
    highShelfGain = 0.0f;
    ParamFreq = 1000.0f;
    ParamQ = 1.0f;
    ParamGain = 0.0f;
}

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
    float compThresh;
    float compRatio;
    int compAttackMs;
    int compRelMs;
    bool compEngage;

    DynamicsSection();

    float limitSignal(float threshold, int lookaheadMs);
    void compSignal(float compThresh, float compRatio, float makeUpGain);
    void tameSignalTransients(int channelID);
};

DynamicsSection::DynamicsSection()
{
    compThresh = 0.0f;
    compRatio = 2.0f;
    compAttackMs = 10.0f;
    compRelMs = 200.0f;
    compEngage = false;
}

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

    MixingConsole();

    struct ChannelStrip
    {
        int channelID;
        float SF_Level;
        float LF_Level;
        bool SF_toMasterBus;
        bool LF_toMasterBus;

        ChannelStrip();
        
        bool resetChannel();
        bool copySettingsFromPath(std::string pathToCopy);
        void changeChannelID(int oldID, int newID);
    };

    void mixAllActiveChannels();
    void processChannel(ChannelStrip chStrp, DynamicsSection dynSec, EQSection eqSec, bool dynBeforeEq = true);
    void selectMainMonitors(int monitorID, float gainTrim = 0.0f);
};

MixingConsole::MixingConsole()
{
    // Custom type initialization
}

MixingConsole::ChannelStrip::ChannelStrip()
{
    channelID = 0;
    SF_Level = -80.0f;
    LF_Level = -80.0f;
    SF_toMasterBus = false;
    LF_toMasterBus = false;
}

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
    Example::main();

    RecStudio recStudio;
    recStudio.recordAlbum(5, 2, 10);
    recStudio.testAllEquipment();

    std::cout << "\nAmount to charge to the studio client is: " << recStudio.chargeSession(20, 0.1f,50.5f) << " euros." << std::endl;
    std::cout << "\nRevenew amount for the year is: " << recStudio.yearlyRevenew(recStudio.revenewPerMonth, 12) << " euros." << std::endl;

    Supermarket superMarket;
    superMarket.bakeBread(3, 30);

    std::cout << "\nAmount to charge to the supermarket client is: " << superMarket.chargeClient(25.6f) << " euros." << std::endl;
    superMarket.checkCashiers(superMarket.numActiveChashiers);

    Supermarket::Product prod1;
    Supermarket::Product prod2;

    prod1.productID = 1;
    prod1.productName = "Bananas";
    prod1.retailPrice = 1.95f;
    prod1.currentStock = 40;
    prod1.orderedStock = 20;

    Bakery bakery;
    bakery.bakeCake(1, 4);
    bakery.deliverBread(50, 724, 1345);

    auto bread = bakery.makeBread("White Bread", 40);
    std::cout << "\n" << bread.units << " units of " << bread.name << " have just been baked." << std::endl;

    Bar bar1;
    Bar bar2;

    std::cout << "\nAmount to charge to the bar client is: " << bar1.billClient(30.5f) << " euros." << std::endl;

    std::cout << "\nThe bar sells, in average, " << bar2.prodSoldPerDay << " products a day with a profit of " << bar2.dayProfit << " euros." << std::endl;

    MasterSection masterSection;

    InputSection inputSection;
    std::cout << "\nFading in Mic Input ... " << inputSection.fadeInMic(inputSection.micGain, -1.0f) << std::endl;
    std::cout << "\nFading in Mic Input ... " << inputSection.fadeInMic(inputSection.micGain, -10.0f) << std::endl;

    OutputSection outputSection;

    EQSection eqSection;

    DynamicsSection dynSection;

    MixingConsole mixConsole;

    MixingConsole::ChannelStrip chStrip;

    std::cout << "" << std::endl;

    std::cout << "good to go!" << std::endl;
}
