
/**
	Title: Stock manager program in a music store
	@file MusicStore.cpp
	@author Octavio Costa
	@version 1.1 5/09/21
*/

#include <iostream>
#include "Instruments.h"
#include "Strings.h"
#include "Wind.h"
#include "Percussion.h"					//Libraries used
#include <string.h>
#include <string>
#include<fstream>
#include <windows.h>

using namespace std;


void header();               //Function that returns the header


int main()
{

	
	Instruments* obj[1];   //Creates an object member of the class instruments with 2 positions

	string name;
	string text;			//Variables used to receive the values from the user
    long double value;
	int op;                //Auxiliary variable used to receive the user's choice in one of the options
	
	do
	{
		system("cls");    //Command that "cleans" the screen, used in this function so that the header is presented in a "new screen" to the user.
		header();
		cout << "Choose the equipment type:" << endl;
		cout << "1 - Instrument" << endl;
		cout << "2 - Accessory" << endl;				//Used to print the first menu options in the program.
		cout << "3 - Exit" << endl;
		cout << "Option: ";
		cin >> op;                               //Used to receive the option
		cin.ignore();                           //Used to ignore the character remained on buffer 
		switch (op)							   //Command used to execute the various options for choosing from the first menu
		{
			case 1:						//Command that is executed after receiving the user's option, in this case option Instrument
				system("cls");
				header();
				int op2;			 //Auxiliary variable used to receive the user's choice in one of the options
				do
				{
					system("cls");
					header();
					cout << "Choose the type of instrument:" << endl;
					cout << "1 - String" << endl;
					cout << "2 - Wind" << endl;
					cout << "3 - Percussion" << endl;       //Used to print the second menu options in the program.
					cout << "4 - Exit" << endl;
					cout << "Option: ";
					cin >> op2;
					cin.ignore();
					switch (op2)
					{
						case 1:             ////First case of the second menu, choosing the option String
							system("cls");
							header();
							int op3;		//Auxiliary variable used to receive the user's choice in one of the options
							do
							{
								system("cls");
								header();
								cout << "Choose an option:" << endl;
								cout << "1 - Insert the instrument in stock" << endl;
								cout << "2 - Sale" << endl;				//Used to print the menu options in the program from the option String
								cout << "3 - Search" << endl;
								cout << "4 - Overview" << endl;
								cout << "5 - Exit" << endl;
								cout << "Option: ";
								cin >> op3;
								cin.ignore();
								switch (op3)
								{
									case 1:
										system("cls");
										header();
									
										cout << "Write the type of instrument(Guitar, Bass, Violin, etc.):" << endl;								
										cin >> name;
										cin.ignore();
										cout << "Write the price of instrument:" << endl;
										cin >> value;											//Reading the values from the user
										cin.ignore();
										cout << "Write the description of instrument:" << endl;
										cin >> text;
										cin.ignore();
										cout << " " << endl;
										obj[0] = new Strings("String",name,text,value); //Allocate the object in 0 position as a String type and gives the parameters 
										try     //Exception Handling
										{
											obj[0]->insert_data(); //The object on the given position executes the function to insert the data with the values allocated
											delete obj[0];  //Deletes the values allocated from the memory
										}
										catch (const bad_alloc& ex) //If there is an error in the memory allocation, the user will receive a message 
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;   //Break used indicating to the program that after the condition is true that it does not execute the other options.
									case 2:
										system("cls");
										header();

										obj[0] = new Strings("String", " ", " ", 1); //Allocate the object in 0 position as a String type and gives the parameters as default
										try
										{
											obj[0]->sale(); //The object on the given position executes the function to register the sale of the instrument 
											delete obj[0];  //Deletes the values allocated from the memory
										}
										catch (const bad_alloc& ex) //If there is an error in the memory allocation, the user will receive a message
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 3:
										system("cls");
										header();

										obj[0] = new Strings("String", " "," ", 1); //Allocate the object in 0 position as a String type and gives the parameters as default
										try
										{
											obj[0]->search(); //The object on the given position executes the function to search the instrument into stock 
											delete obj[0]; //Deletes the values allocated from the memory
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
								    case 4:
										system("cls");
										header();

										obj[0] = new Strings("String", " ", " ", 1);//Allocate the object in 0 position as a String type and gives the parameters as default
										try
										{
											obj[0]->overview(); //The object on the given position executes the function to show the number of sales 
											delete obj[0]; //Deletes the values allocated from the memory
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 5:
										system("exit"); //Command that terminates the program upon receiving the true entry condition, which in this case is 5.
										break;
									default:
										cout << "Invalid option!" << endl; //If the user enters a different option, the program returns showing the invalid entry in the menu.
										break;
								}
							} while (op3 != 5); //If the user option is 5, the program is terminated.
							break;
						case 2:                 //Second case of the second menu, choosing the option WIND
							system("cls");
							header();
							int op4;
							do
							{
								system("cls");
								header();
								cout << "Choose an option:" << endl;
								cout << "1 - Insert the instrument in stock" << endl;
								cout << "2 - Sale" << endl;                   //Used to print the menu options in the program from the option Wind
								cout << "3 - Search" << endl;
								cout << "4 - Overview" << endl;
								cout << "5 - Exit" << endl;
								cout << "Option: ";
								cin >> op4;
								cin.ignore();
								switch (op4)
								{
									case 1:
										system("cls");
										header();
										cout << "Write the type of instrument(Saxophone, Trombone, Trumpet, etc.):" << endl;
										cin >> name;
										cin.ignore();
										cout << "Write the price of instrument:" << endl;   //Reading the values from the user
										cin >> value;
										cin.ignore();
										cout << "Write the description of instrument:" << endl;
										cin >> text;
										cin.ignore();
										cout << " " << endl;
										obj[0] = new Wind("Wind", name, text, value); //Allocate the object in 0 position as a Wind type and gives the parameters
										try
										{
											obj[0]->insert_data(); //The object on the given position executes the function to insert the data with the values allocated
											delete obj[0]; //Deletes the values allocated from the memory
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 2:
										system("cls");
										header();

										obj[0] = new Wind("Wind", " ", " ", 1);//Allocate the object in 0 position as a Wind type and gives the parameters as default
										try
										{
											obj[0]->sale(); //The object on the given position executes the function to register the sale of the instrument
											delete obj[0];  //Deletes the values allocated from the memory
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 3:
										system("cls");
										header();

										obj[0] = new Wind("Wind", " ", " ", 1); //Allocate the object in 0 position as a Wind type and gives the parameters as default
										try
										{
											obj[0]->search(); //The object on the given position executes the function to search the instrument into stock
											delete obj[0];  //Deletes the values allocated from the memory
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 4:
										system("cls");
										header();

										obj[0] = new Wind("Wind", " ", " ", 1); //Allocate the object in 0 position as a Wind type and gives the parameters as default
										try
										{
											obj[0]->overview(); //The object on the given position executes the function to show the number of sales
											delete obj[0];  //Deletes the values allocated from the memory
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 5:
										system("exit");
										break;
									default:
										cout << "Invalid option!" << endl;
										break;
								}
							} while (op4 != 5);
							break;
						case 3:                   //Second case of the second menu, choosing the option PERCUSSION
							system("cls");
							header();
							int op5;
							do
							{
								system("cls");
								header();
								cout << "Choose an option:" << endl;
								cout << "1 - Insert the instrument in stock" << endl;
								cout << "2 - Sale" << endl;
								cout << "3 - Search" << endl;       //Used to print the menu options in the program from the option Percussion
								cout << "4 - Overview" << endl;
								cout << "5 - Exit" << endl;
								cout << "Option: ";
								cin >> op5;
								cin.ignore();
								switch (op5)
								{
									case 1:
										system("cls");
										header();

										cout << "Write the type of instrument(Drum, Triangle, Tambourine, etc.):" << endl;
										cin >> name;
										cin.ignore();
										cout << "Write the price of instrument:" << endl;   //Reading the values from the user
										cin >> value;
										cin.ignore();                                          
										cout << "Write the description of instrument:" << endl;
										cin >> text;
										cin.ignore();
										cout << " " << endl;
										obj[0] = new Percussion("Percussion", name, text, value); //Allocate the object in 0 position as a Percussion type and gives the parameters
										try
										{
											obj[0]->insert_data();   //The object on the given position executes the function to insert the data with the values allocated
											delete obj[0];
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 2:
										system("cls");
										header();

										obj[0] = new Percussion("Percussion", " ", " ", 1); //Allocate the object in 0 position as a Percussion type and gives the parameters as default
										try
										{
											obj[0]->sale(); //The object on the given position executes the function to register the sale of the instrument
											delete obj[0];
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 3:
										system("cls");
										header();

										obj[0] = new Percussion("Percussion", " ", " ", 1);//Allocate the object in 0 position as a Percussion type and gives the parameters as default
										try
										{
											obj[0]->search(); //The object on the given position executes the function to search the instrument into stock
											delete obj[0];
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 4:
										system("cls");
										header();

										obj[0] = new Percussion("Percussion", " ", " ", 1);//Allocate the object in 0 position as a Percussion type and gives the parameters as default
										try
										{
											obj[0]->overview();  //The object on the given position executes the function to show the number of sales
											delete obj[0];
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 5:
										system("exit");
										break;
									default:
										cout << "Invalid option!" << endl;
										break;
								}
							} while (op5 != 5);
							break;
						case 4:
							system("exit");
							break;
						default:
							cout << "Invalid option!" << endl;
							break;
					}
				} while(op2 != 4);
				break;
			case 2: //Command that is executed after receiving the user's option, in this case option Accessory
				system("cls");
				header();
				int op6;
				do
				{
					system("cls");
					header();
					cout << "Choose the type of accessory:" << endl;
					cout << "1 - String" << endl;
					cout << "2 - Wind" << endl;
					cout << "3 - Percussion" << endl;  //Used to print the second menu options in the program for Accessory
					cout << "4 - Exit" << endl;
					cout << "Option: ";
					cin >> op6;
					fflush(stdin);
					switch (op6)
					{
						case 1:
							system("cls");
							header();
							int op7;
							do
							{
								system("cls");
								header();
								cout << "Choose an option:" << endl;
								cout << "1 - Insert the accessory in stock" << endl;
								cout << "2 - Sale" << endl;
								cout << "3 - Search" << endl;
								cout << "4 - Overview" << endl; //Used to print the menu options in the program from the option String
								cout << "5 - Exit" << endl;
								cout << "Option: ";
								cin >> op7;
								fflush(stdin);
								switch (op7)
								{
									case 1:
										system("cls");
										header();
										cout << "Write the type of accessory(Cable, Pedal, Tuner, etc.):" << endl;
										cin >> name;
										cin.ignore();
										cout << "Write the price of accessory:" << endl; //Reading the values from the user
										cin >> value;
										cin.ignore();
										cout << "Write the description of accessory:" << endl;
										cin >> text;
										cin.ignore();
										cout << " " << endl;
										obj[0] = new Strings("String", name, text, value); //Allocate the object in 0 position as a String type and gives the parameters
										try
										{
											obj[0]->insert_acce(); //The object on the given position executes the function to insert the data in accessory file with the values allocated
											delete obj[0];
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 2:
										system("cls");
										header();

										obj[0] = new Strings("String", " ", " ", 1);
										try
										{
											obj[0]->sale_acce(); //The object on the given position executes the function to register the sale of the accessory
											delete obj[0];
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 3:
										system("cls");
										header();

										obj[0] = new Strings("String", " ", " ", 1);
										try
										{
											obj[0]->search_acce(); //The object on the given position executes the function to search the accessory into stock
											delete obj[0];
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 4:
										system("cls");
										header();

										obj[0] = new Strings("String", " ", " ", 1);
										try
										{
											obj[0]->overview_acce(); //The object on the given position executes the function to show the number of sales
											delete obj[0];
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 5:
										system("exit");
										break;
									default:
										cout << "Invalid option!" << endl;
										break;
								}
							} while (op7 != 5);
						break;
						case 2:  // This will do the same but for WIND accessories
							system("cls");
							header();
							int op8;
							do
							{
								system("cls");
								header();
								cout << "Choose an option:" << endl;
								cout << "1 - Insert the accessory in stock" << endl;
								cout << "2 - Sale" << endl;
								cout << "3 - Search" << endl;
								cout << "4 - Overview" << endl;
								cout << "5 - Exit" << endl;
								cout << "Option: ";
								cin >> op8;
								fflush(stdin);
								switch (op8)
								{
									case 1:
										system("cls");
										header();
										cout << "Write the type of accessory(Mouthpiece, Case, Reed, etc.):" << endl;
										cin >> name;
										cin.ignore();
										cout << "Write the price of accessory:" << endl;
										cin >> value;
										cin.ignore();
										cout << "Write the description of accessory:" << endl;
										cin >> text;
										cin.ignore();
										cout << " " << endl;
										obj[0] = new Wind("Wind", name, text, value);
										try
										{
											obj[0]->insert_acce();
											delete obj[0];
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 2:
										system("cls");
										header();

										obj[0] = new Wind("Wind", " ", " ", 1);
										try
										{
											obj[0]->sale_acce();
											delete obj[0];
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 3:
										system("cls");
										header();

										obj[0] = new Wind("Wind", " ", " ", 1);
										try
										{
											obj[0]->search_acce();
											delete obj[0];
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 4:
										system("cls");
										header();
										obj[0] = new Wind("Wind", " ", " ", 1);
										try
										{
											obj[0]->overview_acce();
											delete obj[0];
										}
										catch (const bad_alloc& ex)
										{
											cout << ex.what() << "Caused the error!" << endl;
											cout << "Memory cannot be allocated!" << endl;
										}
										break;
									case 5:
										system("exit");
										break;
									default:
										cout << "Invalid option!" << endl;
										break;
								}
							} while (op8 != 5);
						break;
						case 3:  //// This will do the same but for PERCUSSION accessories
							system("cls");
							header();
							int op9;
							do
							{
								system("cls");
								header();
								cout << "Choose an option:" << endl;
								cout << "1 - Insert the accessory in stock" << endl;
								cout << "2 - Sale" << endl;
								cout << "3 - Search" << endl;
								cout << "4 - Overview" << endl;
								cout << "5 - Exit" << endl;
								cout << "Option: ";
								cin >> op9;
								fflush(stdin);
								switch (op9)
								{
								case 1:
									system("cls");
									header();

									cout << "Write the type of accessory(Drumstick, Pedal, SuitCase, etc.):" << endl;
									cin >> name;
									cin.ignore();
									cout << "Write the price of accessory:" << endl;
									cin >> value;
									cin.ignore();
									cout << "Write the description of accessory:" << endl;
									cin >> text;
									cin.ignore();
									cout << " " << endl;
									obj[0] = new Percussion("Percussion", name, text, value);
									try
									{
										obj[0]->insert_acce();
										delete obj[0];
									}
									catch (const bad_alloc& ex)
									{
										cout << ex.what() << "Caused the error!" << endl;
										cout << "Memory cannot be allocated!" << endl;
									}
									break;
								case 2:
									system("cls");
									header();

									obj[0] = new Percussion("Percussion", " ", " ", 1);
									try
									{
										obj[0]->sale_acce();
										delete obj[0];
									}
									catch (const bad_alloc& ex)
									{
										cout << ex.what() << "Caused the error!" << endl;
										cout << "Memory cannot be allocated!" << endl;
									}
									break;
								case 3:
									system("cls");
									header();

									obj[0] = new Percussion("Percussion", " ", " ", 1);
									try
									{
										obj[0]->search_acce();
										delete obj[0];
									}
									catch (const bad_alloc& ex)
									{
										cout << ex.what() << "Caused the error!" << endl;
										cout << "Memory cannot be allocated!" << endl;
									}
									break;
								case 4:
									system("cls");
									header();

									obj[0] = new Percussion("Percussion", " ", " ", 1);
									try
									{
										obj[0]->overview_acce();
										delete obj[0];
									}
									catch (const bad_alloc& ex)
									{
										cout << ex.what() << "Caused the error!" << endl;
										cout << "Memory cannot be allocated!" << endl;
									}
									break;
								case 5:
									system("exit");
									break;
								default:
									cout << "Invalid option!" << endl;
									break;
								}
							} while (op9 != 5);
						break;
						case 4:
							system("exit");
						break;
						default:
							cout << "Invalid option!" << endl;
						break;
					}
				} while (op6 != 4);
				break;
			case 3:
				system("exit");
				break;
			default:
				cout << "Invalid option!" << endl;
				break;
		}

	} while (op != 3);
	return 0;
}

void header()
{
	cout << "*--------------------------------------------------*" << endl;
	cout << "                    MUSIC STORE" << endl;
	cout << "*--------------------------------------------------*" << endl;	 //Header function
	cout << " " << endl;
}
