// Task18. Original solution by Denis Kiprov, extended by Chris Vachev.
//
using namespace std;
#include <iostream>

int main()
{
    unsigned char lamps = 0b00001111;
   
    char operation = 0;
    cout << "A - Check state of a specific lamp." << endl;
    cout << "B - Show all lamps" << endl;
    cout << "C - Turn one specific lamp ON" << endl;
    cout << "D - Turn one specific lamp OFF" << endl;
    cout << "E - Switch the state of a specific lamp" << endl;
    cout << "F - Switch the state of all lamps" << endl;
    cout << "G -  Turn all lamps OFF" << endl;
    cout << "Choose an operation (A-G):" << endl;

    cin >> operation;

    if (operation == 'A') // Check lamp state
    {
        cout << "Choose which lamp to show (1 to 8)" << endl;

        int lampNumber = 0;
        cin >> lampNumber;
        int bitToShow = 8 - lampNumber;

        int chosenLamp = lamps & (1 << bitToShow);

        cout << "Lamp " << lampNumber << " is " << (chosenLamp ? "ON" : "OFF") << endl;
    }
    else if (operation == 'B') // Show all lamps
    {
        cout << "Showing all lamps:" << endl;

        int lamp1 = ((lamps & (1 << 7)));
        int lamp2 = ((lamps & (1 << 6)));
        int lamp3 = ((lamps & (1 << 5)));
        int lamp4 = ((lamps & (1 << 4)));
        int lamp5 = ((lamps & (1 << 3)));
        int lamp6 = ((lamps & (1 << 2)));
        int lamp7 = ((lamps & (1 << 1)));
        int lamp8 = ((lamps & (1 << 0)));

        cout << "Lamp 1 = " << (lamp1 ? "ON" : "OFF") << endl;
        cout << "Lamp 2 = " << (lamp2 ? "ON" : "OFF") << endl;
        cout << "Lamp 3 = " << (lamp3 ? "ON" : "OFF") << endl;
        cout << "Lamp 4 = " << (lamp4 ? "ON" : "OFF") << endl;
        cout << "Lamp 5 = " << (lamp5 ? "ON" : "OFF") << endl;
        cout << "Lamp 6 = " << (lamp6 ? "ON" : "OFF") << endl;
        cout << "Lamp 7 = " << (lamp7 ? "ON" : "OFF") << endl;
        cout << "Lamp 8 = " << (lamp8 ? "ON" : "OFF") << endl;
    }
    else if (operation == 'C') //Turn one specific lamp ON
    {
        cout << "Choose which lamp to turn ON (1-8):" << endl;

        int lampNumber = 0;
        cin >> lampNumber;
        int bitToFlip = 8 - lampNumber;

        lamps = (lamps | (1 << bitToFlip)); 

        int lamp1 = ((lamps & (1 << 7)));
        int lamp2 = ((lamps & (1 << 6)));
        int lamp3 = ((lamps & (1 << 5)));
        int lamp4 = ((lamps & (1 << 4)));
        int lamp5 = ((lamps & (1 << 3)));
        int lamp6 = ((lamps & (1 << 2)));
        int lamp7 = ((lamps & (1 << 1)));
        int lamp8 = ((lamps & (1 << 0)));

        cout << "Lamp " << lampNumber << " is now ON!" << endl;
        cout << "Lamp 1 = " << (lamp1 ? "ON" : "OFF") << endl;
        cout << "Lamp 2 = " << (lamp2 ? "ON" : "OFF") << endl;
        cout << "Lamp 3 = " << (lamp3 ? "ON" : "OFF") << endl;
        cout << "Lamp 4 = " << (lamp4 ? "ON" : "OFF") << endl;
        cout << "Lamp 5 = " << (lamp5 ? "ON" : "OFF") << endl;
        cout << "Lamp 6 = " << (lamp6 ? "ON" : "OFF") << endl;
        cout << "Lamp 7 = " << (lamp7 ? "ON" : "OFF") << endl;
        cout << "Lamp 8 = " << (lamp8 ? "ON" : "OFF") << endl;
    }
    else if (operation == 'D') //turn one specific lamp OFF
    {
        int lampNumber = 0;
        cin >> lampNumber;

        int bitToFlip = 8 - lampNumber;
        lamps = (lamps ^ (1 << bitToFlip));
        
        int lamp1 = ((lamps & (1 << 7)));
        int lamp2 = ((lamps & (1 << 6)));
        int lamp3 = ((lamps & (1 << 5)));
        int lamp4 = ((lamps & (1 << 4)));
        int lamp5 = ((lamps & (1 << 3)));
        int lamp6 = ((lamps & (1 << 2)));
        int lamp7 = ((lamps & (1 << 1)));
        int lamp8 = ((lamps & (1 << 0)));

        cout << "Lamp " << lampNumber << " is now OFF!";
        cout << "Lamp 1 = " << (lamp1 ? "ON" : "OFF") << endl;
        cout << "Lamp 2 = " << (lamp2 ? "ON" : "OFF") << endl;
        cout << "Lamp 3 = " << (lamp3 ? "ON" : "OFF") << endl;
        cout << "Lamp 4 = " << (lamp4 ? "ON" : "OFF") << endl;
        cout << "Lamp 5 = " << (lamp5 ? "ON" : "OFF") << endl;
        cout << "Lamp 6 = " << (lamp6 ? "ON" : "OFF") << endl;
        cout << "Lamp 7 = " << (lamp7 ? "ON" : "OFF") << endl;
        cout << "Lamp 8 = " << (lamp8 ? "ON" : "OFF") << endl;

    }
    else if (operation=='E') // Switch the state of a specific lamp
    {
        int lampNumber = 0;
        cin >> lampNumber;
        int bitToFlip = 8 - lampNumber;

        lamps = (lamps ^ (1 << bitToFlip));
        ((lamps << (bitToFlip - 1)) >> 7) ? (cout << "Lamp " << lampNumber << " is now OFF!" << endl) : (cout << "Lamp " << lampNumber << " is now ON!" << endl);
        
        int lamp1 = ((lamps & (1 << 7)));
        int lamp2 = ((lamps & (1 << 6)));
        int lamp3 = ((lamps & (1 << 5)));
        int lamp4 = ((lamps & (1 << 4)));
        int lamp5 = ((lamps & (1 << 3)));
        int lamp6 = ((lamps & (1 << 2)));
        int lamp7 = ((lamps & (1 << 1)));
        int lamp8 = ((lamps & (1 << 0)));
        
        cout << "Lamp 1 = " << (lamp1 ? "ON" : "OFF") << endl;
        cout << "Lamp 2 = " << (lamp2 ? "ON" : "OFF") << endl;
        cout << "Lamp 3 = " << (lamp3 ? "ON" : "OFF") << endl;
        cout << "Lamp 4 = " << (lamp4 ? "ON" : "OFF") << endl;
        cout << "Lamp 5 = " << (lamp5 ? "ON" : "OFF") << endl;
        cout << "Lamp 6 = " << (lamp6 ? "ON" : "OFF") << endl;
        cout << "Lamp 7 = " << (lamp7 ? "ON" : "OFF") << endl;
        cout << "Lamp 8 = " << (lamp8 ? "ON" : "OFF") << endl;

    }
    else if (operation == 'F') //Switch the state of all lamps
    {
        lamps = (~lamps);
        
        int lamp1 = ((lamps & (1 << 7)));
        int lamp2 = ((lamps & (1 << 6)));
        int lamp3 = ((lamps & (1 << 5)));
        int lamp4 = ((lamps & (1 << 4)));
        int lamp5 = ((lamps & (1 << 3)));
        int lamp6 = ((lamps & (1 << 2)));
        int lamp7 = ((lamps & (1 << 1)));
        int lamp8 = ((lamps & (1 << 0)));

        cout << "Lamp 1 = " << (lamp1 ? "ON" : "OFF") << endl;
        cout << "Lamp 2 = " << (lamp2 ? "ON" : "OFF") << endl;
        cout << "Lamp 3 = " << (lamp3 ? "ON" : "OFF") << endl;
        cout << "Lamp 4 = " << (lamp4 ? "ON" : "OFF") << endl;
        cout << "Lamp 5 = " << (lamp5 ? "ON" : "OFF") << endl;
        cout << "Lamp 6 = " << (lamp6 ? "ON" : "OFF") << endl;
        cout << "Lamp 7 = " << (lamp7 ? "ON" : "OFF") << endl;
        cout << "Lamp 8 = " << (lamp8 ? "ON" : "OFF") << endl;
    } 
    else if (operation == 'G') // Turn all lamps OFF
    {
        lamps = (lamps & 1) & 0;

        int lamp1 = ((lamps & (1 << 7)));
        int lamp2 = ((lamps & (1 << 6)));
        int lamp3 = ((lamps & (1 << 5)));
        int lamp4 = ((lamps & (1 << 4)));
        int lamp5 = ((lamps & (1 << 3)));
        int lamp6 = ((lamps & (1 << 2)));
        int lamp7 = ((lamps & (1 << 1)));
        int lamp8 = ((lamps & (1 << 0)));

        cout << "Lamp 1 = " << (lamp1 ? "ON" : "OFF") << endl;
        cout << "Lamp 2 = " << (lamp2 ? "ON" : "OFF") << endl;
        cout << "Lamp 3 = " << (lamp3 ? "ON" : "OFF") << endl;
        cout << "Lamp 4 = " << (lamp4 ? "ON" : "OFF") << endl;
        cout << "Lamp 5 = " << (lamp5 ? "ON" : "OFF") << endl;
        cout << "Lamp 6 = " << (lamp6 ? "ON" : "OFF") << endl;
        cout << "Lamp 7 = " << (lamp7 ? "ON" : "OFF") << endl;
        cout << "Lamp 8 = " << (lamp8 ? "ON" : "OFF") << endl;
    }
  
}