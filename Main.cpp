// Tessa Ashlin (tea230000)

// A program that accepts a file from the user and then calculates fines for the ships in that file,
// depending on how long they stayed in a docking station and how many credits they paid for the
// parking spot. It prints all of the fines and the ships who recieved them to a file called
// Tickets.txt

#include "LinkedList.h"
#include "Dock.h"
#include "Ship.h"
#include "Ticket.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    // Create a dock to store ships in and a dock counter to store how many ships are in the dock
    // so the program can see if it's full or not

    Dock dock[10];
    int dockCount = 0;

    // Make a queue to store the ships who can't make it into the dock

    LinkedList queue;
    int queueCount = 0;

    // Create a ticket file to store information about overstaying ships

    ofstream outputFile("Tickets.txt");

    // Prompt the user for the file

    cout << "Enter the file name: ";
    string filename;
    cin >> filename;

    // Open the file. If the file cannot open correctly, send an error message to the user

    ifstream inputFile;
    inputFile.open(filename);

    if(inputFile)
    {
        // Get each line from the file

        string line;

        while (inputFile >> line)
        {
            // Analyze each line of the file

            // A ship is entering! The program must create a new ship and add it to the dock or
            // queue

            if (line == "enter")
            {

                // Initialize variables to create a new ship based on the file info

                int hour;
                int mins;
                char character;
                string name;
                string id;
                int credits;

                // Get the variable's values from the file-- "character" accepts the : between the 
                // time variables

                inputFile >> hour >> character >> mins >> name >> id >> credits;

                // Create a new ship based on the file info!

                Ship* newShip = new Ship(name, id, credits);
                // If there is room in the dock, let the entering ship in

                if (dockCount < 10)
                {
                    // Search the dock for an open space (the ship inside is nullptr)

                    for (int i = 0; i < 10; i++)
                    {
                        if(dock[i].getMooring() == nullptr)
                        {
                            // An open spot has been found-- enter the info into it

                            dock[i].setMooring(newShip);
                            dock[i].setHour_In(hour);
                            dock[i].setMinutes_In(mins);
                            
                            // Since a spot has been found, skip the rest of the loop

                            i += 10;
                        }
                    }

                    // Increase the dock count by one ship

                    dockCount++;
                }
                else
                {
                    // The dock is full right now-- put the new ship into the queue

                    queue += newShip;
                    queueCount++;
                }

                // Debug statement

                /*cout << "\nhi! time is " << hour << ":" << mins << ", name is " << name
                     << ", id is " << id << ", and credits spent is " << credits << " units.\n";*/

            }

            // A ship is exiting! The program must take that ship from the dock and replace the
            // a ship in the queue with it

            else if (line == "exit")
            {
                // Decrease the dock count

                dockCount--;

                // Initialize variables from the file

                string exitID;
                int hourOut;
                int minOut;
                char character;

                inputFile >> exitID >> hourOut >> character >> minOut;

                // Debug statement

                /*cout << "\nbye! leaving ship id is " << exitID << ", time of departure is "
                     << hourOut << ":" << minOut << ".\n";*/

                // Find the ship who is exiting from the dock

                for (int i = 0; i < 10; i++)
                {
                    Ship* tempDock = dock[i].getMooring();

                    // Only proceed if the dock holds an actual ship

                    // Debug statement

                    /*if (tempDock != nullptr)
                        cout << "tempdock ship id: " << tempDock->getShip_ID() << ", exit id: " << exitID << endl;*/

                    if (tempDock != nullptr && tempDock->getShip_ID() == exitID)
                    {
                        // The right dock has been found, check if the leaving ship needs
                        // to recieve a ticket

                        // First, get the correct time in and time out
                        
                        int timeIn = ((dock[i].getHour_In() * 60) + dock[i].getMinutes_In());
                        int timeOut = ((hourOut * 60) + minOut);

                        // Change the calculation depending on how long the ships have stayed--
                        // If a ship has stayed the whole day, it will need extra time

                        if (timeOut < timeIn)
                        {
                            timeOut += 1440;
                        }
                        
                        // Subtract the time out by the time in to get the difference

                        int timeDiff = timeOut - timeIn;

                        // Debug statement
                        // cout << "Time In for " << exitID << " : " << timeIn << ", Time Out: " << timeOut << ", Time Diff: " << timeDiff << endl;

                        // Subtract the amount of credits by the time difference to find out 
                        // if they stayed too long

                        timeDiff = dock[i].getMooring()->getCredit() - timeDiff;

                        if (timeDiff < 0)
                        {
                            // The ship has overstayed -- create a ticket

                            Ticket newTicket(dock[i].getMooring(), &dock[i], hourOut, minOut);

                            // Send the ticket information to the Tickets.txt file
                            
                            outputFile << endl; 
                            outputFile << newTicket;
                            outputFile << endl;
                        }

                        // Set the dock to nullptr to indicate that the spot is now empty, regardless
                        // of if it got a ticket or not. Make sure to delete the ship as well.

                        delete dock[i].getMooring();
                        dock[i].setMooring(nullptr);
                        
                    } // if (tempDock != nullptr && tempDock->getShip_ID() == exitID)
                } // for (int i = 0; i < 10; i++)

                // Place the first ship in the queue into the docking station if there's a space
                // available. First, Search the dock for an open space (the ship inside is nullptr)

                if (queueCount > 0)
                {
                    for (int i = 0; i < 10; i++)
                    {
                        if(dock[i].getMooring() == nullptr)
                        {
                            // An open spot has been found-- enter the info into it

                            // The ship will dock 15 minutes after the other ship left

                            int extraTime = 15;
                            minOut += extraTime;
                            
                            if (minOut >= 60)
                            {
                                hourOut += 1;
                                minOut = minOut - 60;
                                minOut *= 1;
                            }

                            // Set the information

                            dock[i].setMooring(--queue);
                            dock[i].setHour_In(hourOut);
                            dock[i].setMinutes_In(minOut);
                                
                            // Since a spot has been found, skip the rest of the loop

                            i += 10;
                            
                            // Increase the dock count by one ship and the queue count by -1

                            dockCount++;
                            queueCount--;
                            
                        }
                    }
                }
            } // else if (line == "exit")
        } // while (inputfile >> line)

    } // if(inputFile)
    else
    {
        // The file cannot be opened, so send an error message

        cout << filename << " could not be opened.";
    }

    inputFile.close();
    outputFile.close();

}