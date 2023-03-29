#include "Strings.h"


void Strings::insert_data()
{
	ofstream outfile;  //Object from the fstream class, this one is used to write on file
	outfile.open("instruments.txt", ios::out | ios::app); //Open the instruments file to write the data and write in the last part of file
	if (!outfile) //Condition if the file does not open
	{
		cout << "Error opening file!" << endl; //Message to the user
	}
	else
	{
		outfile << gen_type << endl;
		outfile << type << endl;
		outfile << price << endl;           //The object write the variables received from the user in the file
		outfile << description << endl;
	}
	outfile.close();                    //Closing the file after writing
}

void Strings::insert_acce()
{
	ofstream outfile; //Object from the fstream class, this one is used to write on file
	outfile.open("accessory.txt", ios::out | ios::app); //Open the accessory file to write the data and write in the last part of file
	if (!outfile) //Condition if the file does not open
	{
		cout << "Error opening file!" << endl; //Message to the user
	}
	else
	{
		outfile << gen_type << endl;
		outfile << type << endl;      //The object write the variables received from the user in the file
		outfile << price << endl;
		outfile << description << endl;
	}
	outfile.close(); //Closing the file after writing
}

void Strings::search()
{
	Strings* obj[1]; //Creating an object from the Strings class
	ifstream infile; //Object from the fstream class, this one is used to read on file
	string aux; //Auxiliary variable used to receive the option from the user
	int count_aux = 0; //Auxiliary variable used to see if the data wasn't found

	infile.open("instruments.txt", ios::in); //Open the instruments file to read the data
	if (!infile) //Condition if the file does not open
	{
		cout << "Error opening file!" << endl;
		cout << "The file does not exist!" << endl; //Message for thw user
		system("pause"); //Function used to pause the system and allow the user to read the message
	}
	else
	{
		cout << " " << endl;
		cout << "Write the type of instruments to search:" << endl;
		cin >> aux;                           //Receiving the option from the user
		infile >> gen_type;            //Reading the data from the file 
		while (infile)                      //Function used to read while the file until reaches the end
		{
			for (int i = 0; i < 1; i++)
			{
				infile >> type;
				infile >> price; //Reading the data from the file 
				infile >> description;
				obj[i] = new Strings(gen_type, type, description, price); //Receiving the data from the file and allocating it in position 0
				try
				{
					if (type == aux && gen_type == "String") //Comparing the data read with the given for the user
					{
						cout << "--------------------------------" << endl;
						cout << "Type: " << obj[i]->type << endl;
						cout << "Price: " << obj[i]->price << " HUF" << endl;
						cout << "Description: " << obj[i]->description << endl; //Printing the data founded
						cout << "--------------------------------" << endl;
						count_aux = count_aux + stock_count; //Auxiliary variable that increases if the data was founded in the file
					}
					infile >> gen_type;
				}
				catch (const bad_alloc& ex)            //If there is an error in the memory allocation, the user will receive a message
				{
					cout << ex.what() << "Caused the error!" << endl;
					cout << "Memory cannot be allocated!" << endl;
				}
			}
		}
		infile.close(); //Closing the file
	}
	if (count_aux == 0) //If the variable remains as 0 value, then it means that wasn't found 
	{
		cout << "Stock empty for: " << aux << endl; //Message for the user
	}
	delete obj[0]; //Deleting the memory allocated
	system("pause");
}

void Strings::search_acce() //This function works in the same way as the search function, 
{                           //the difference is the file read which in this case is the file of accessories

	Strings* obj[1]; //Creating an object from the Strings class
	ifstream infile; //Object from the fstream class, this one is used to read on file
	string aux;    //Auxiliary variable used to receive the option from the user
	int count_aux = 0; //Auxiliary variable used to see if the data wasn't found

	infile.open("accessory.txt", ios::in); //Open the accesory file to read the data
	if (!infile)
	{
		cout << "Error opening file!" << endl;
		cout << "The file does not exist!" << endl;
		system("pause");
	}
	else
	{
		cout << " " << endl;
		cout << "Write the type of accessory to search:" << endl;
		cin >> aux;
		infile >> gen_type;
		while (infile)
		{
			for (int i = 0; i < 1; i++)
			{
				infile >> type;
				infile >> price;
				infile >> description;
				obj[i] = new Strings(gen_type, type, description, price);
				try
				{
					if (type == aux && gen_type == "String")
					{
						cout << "--------------------------------" << endl;
						cout << "Type: " << obj[i]->type << endl;
						cout << "Price: " << obj[i]->price << "HUF" << endl;
						cout << "Description: " << obj[i]->description << endl;
						cout << "--------------------------------" << endl;
						count_aux = count_aux + stock_count;
					}
					infile >> gen_type;
				}
				catch (const bad_alloc& ex)
				{
					cout << ex.what() << "Caused the error!" << endl;
					cout << "Memory cannot be allocated!" << endl;
				}
			}
		}
		infile.close();
	}
	if (count_aux == 0)
	{
		cout << "Stock empty for: " << aux << endl;
	}
	delete obj[0];
	system("pause");
}

void Strings::sale()
{
	Strings* obj[1];                                         //Creating an object from the Strings class
	string aux_type;                                        //Auxiliary variable used to receive the option from the user
	string aux_description;                                //Auxiliary variable used to receive the option from the user

	ifstream infile;                                     //Object from the fstream class, this one is used to read on file
	infile.open("instruments.txt", ios::in);            //Open the instruments file to read the data
	ofstream out_sale;                                 //Object from the fstream class, this one is used to write on file
	out_sale.open("sales.txt", ios::out | ios::app);   //Open the sales file to write the data and write in the last part of file
	ofstream aux_file;                                //Object from the fstream class, this one is used to write on file
	aux_file.open("auxiliary.txt", ios::out);        //Open the auxiliary file to write the data and write in the last part of file

	if (!infile || !out_sale || !aux_file)  //Condition if the file does not open
	{
		cout << "Error opening file!" << endl;
		cout << "The file does not exist!" << endl;
		system("pause");
	}
	else
	{
		if (file_empty(infile))  //Returns a message error if the file is empty
		{
			cout << "File empty try to insert first";
			system("exit");
		}
		else
		{
			cout << " " << endl;
			cout << "Write the type of instruments to sale:" << endl;
			cin >> aux_type;
			cin.ignore();
			cout << "Write the description of instruments to sale:" << endl;
			cin >> aux_description;            //Receives the data from the user
			cin.ignore();
			infile >> gen_type;
			while (infile)                     //Function used to read while the file until reaches the end
			{
				for (int i = 0; i < 1; i++)
				{
					infile >> type;
					infile >> price;        //Reading the data from the file 
					infile >> description;
					obj[i] = new Strings(gen_type, type, description, price); //Receiving the data from the file and allocating it in position 0
					try
					{
						if (type == aux_type && description == aux_description) //Used to compare the data given by the user and the data readed into file
						{
							stock_count = 1;                                //If the comparison is true then the auxiliary variable turns to 1 value
							out_sale << obj[i]->type << endl;
							out_sale << obj[i]->price << endl;             //All the data found in the instruments file now are replaced to sale file
							out_sale << obj[i]->description << endl;
							out_sale << stock_count << endl;              //The value 1 is written in the sale file as well
						}
						else
						{
							aux_file << gen_type << endl;
							aux_file << type << endl;
							aux_file << price << endl;                    //If the read data wasn't the same as the given by the user then the data are written to auxiliary file
							aux_file << description << endl;
						}
						infile >> gen_type;
					}
					catch (const bad_alloc& ex)
					{
						cout << ex.what() << "Caused the error!" << endl;
						cout << "Memory cannot be allocated!" << endl;
					}
				}
			}
		}
	}
	infile.close();
	out_sale.close();                               //Closing all the files opened
	aux_file.close();
	remove("instruments.txt");                     //Delete the old instruments file with the old data
	rename("auxiliary.txt", "instruments.txt");   //Replace the auxiliary file to new instruments file, this way I can delete the data given by the user
	delete obj[0];                               //Deleting the memory allocated
	system("pause");
	
}

void Strings::sale_acce() //This function works in the same way as the sale function, 
                          //but with different files, like accessory and sale_acce using to store the data of sales
{
	Strings* obj[1];
	string aux_type;
	string aux_description;
	ifstream infile;
	infile.open("accessory.txt", ios::in);
	ofstream out_sale;
	out_sale.open("sales_acce.txt", ios::out | ios::app);
	ofstream aux_file;
	aux_file.open("auxiliary.txt", ios::out);
	
	if (!infile || !out_sale || !aux_file)
	{
		cout << "Error opening file!" << endl;	
		cout << "The file does not exist!" << endl;	
		system("pause");
	}
	else
	{
		if (file_empty(infile))
		{
			cout << "File empty try to insert first";
			system("exit");
		}
		else
		{
			cout << " " << endl;
			cout << "Write the type of accessory to sale:" << endl;
			cin >> aux_type;
			cin.ignore();
			cout << "Write the description of accessory to sale:" << endl;
			cin >> aux_description;
			cin.ignore();
			infile >> gen_type;
			while (infile)
			{
	
				for (int i = 0; i < 1; i++)
				{
					infile >> type;
					infile >> price;
					infile >> description;
					obj[i] = new Strings(gen_type, type, description, price);
					try
					{
						if (type == aux_type && description == aux_description)
						{
							stock_count = 1;
							out_sale << obj[i]->type << endl;
							out_sale << obj[i]->price << endl;
							out_sale << obj[i]->description << endl;
							out_sale << stock_count << endl;
						}
						else
						{
							aux_file << gen_type << endl;
							aux_file << type << endl;
							aux_file << price << endl;
							aux_file << description << endl;
						}
						infile >> gen_type;
					}
					catch (const bad_alloc& ex)
					{
						cout << ex.what() << "Caused the error!" << endl;
						cout << "Memory cannot be allocated!" << endl;
					}
				}
			}
		}
	}
	infile.close();
	out_sale.close();
	aux_file.close();
	remove("accessory.txt");
	rename("auxiliary.txt", "accessory.txt");
	delete obj[0];
	system("pause");	
}

void Strings::overview()                                //This function works returning the number of sales assigned to the type given by the user 
{
	Strings* obj[1];                                   //Creating an object from the Strings class
	int sum = 0;                                       //Auxiliary variable used to count the number of sales in file
	string aux;                                       //Auxiliary variable used to receives the type of data given by the user 
	 
	ifstream infile;                                 //Object from the fstream class, this one is used to read on file
	infile.open("sales.txt", ios::in);              //Open the instruments file to read the data 
	
	if (!infile)                                   //Condition if the file does not open 
	{
		cout << "Error opening file!" << endl;
		cout << "The file does not exist!" << endl;
		system("pause");
	}
	else
	{
		cout << "Write the type of instrument: " << endl;
		cin >> aux;                                        //Receive the data from the user
		infile >> type;                                    //Reading from the file
		while (!infile.eof())                              //Function used to read while the file until reaches the end 
		{
			for (int i = 0; i < 1; i++)
			{
				infile >> price;
				infile >> description;                     ////Reading from the file
				infile >> stock_count;
				obj[0] = new Strings("Strings", type, description, price); //Receiving the data from the file and allocating it in position 0
				try
				{
					if (type == aux)                               //If the type reading from the file is equal to the given from the user
					{                                             
						sum = sum + stock_count;                  //Sum if the type was found in the file, returning the total in the file

					}
					infile >> type;
				}
				catch (const bad_alloc& ex)
				{
					cout << ex.what() <<"Caused the error!"<< endl;
					cout << "Memory cannot be allocated!" << endl;
				}
			}
		}
		cout << " " << endl;
		cout << "Type: " << aux << endl;
		cout << "Number of sales: " << sum << endl;            //Printing the numbers of sales and the type
		infile.close();                                        //Closing the file
		system("pause");
	}
}

void Strings::overview_acce()         //This function works in the same way as the overview function, 
                                     //but with different files, like sale_acce using to read the number of sales
{
	Strings* obj[1];
	int sum = 0;
	string aux;
	ifstream infile;
	infile.open("sales_acce.txt", ios::in);
	if (!infile)
	{
		cout << "Error opening file!" << endl;
		cout << "The file does not exist!" << endl;
		system("pause");
	}
	else
	{
		cout << "Write the type of accessory: " << endl;
		cin >> aux;
		infile >> type;
		while (!infile.eof())
		{
			for (int i = 0; i < 1; i++)
			{
				infile >> price;
				infile >> description;
				infile >> stock_count;
				obj[0] = new Strings("Strings", type, description, price);
				try
				{
					if (type == aux)
					{
						sum = sum + stock_count;

					}
					infile >> type;
				}
				catch (const bad_alloc& ex)
				{
					cout << ex.what() << "Caused the error!" << endl;
					cout << "Memory cannot be allocated!" << endl;
				}
			}
		}
		cout << " " << endl;
		cout << "Type: " << aux << endl;
		cout << "Number of sales: " << sum << endl;
		infile.close();
		system("pause");
	}
}

bool Strings::file_empty(ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();  //Return if the file is empty
}
