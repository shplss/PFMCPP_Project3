/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 1) Add a constructor for each User-Defined-Type.
 
 2) amend some of your UDT's member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main() function

 4) call some of your UDT's amended member functions in main().
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    a = 0;
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




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
    Example::main();
    std::cout << "good to go!" << std::endl;
}
