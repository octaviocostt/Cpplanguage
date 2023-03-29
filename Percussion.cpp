#include "Percussion.h"

void Percussion::insert_data()
{
	ofstream outfile;
	outfile.open("instruments.txt", ios::out | ios::app);
	if (!outfile)
	{
		cout << "Error opening file!" << endl;
	}
	else
	{
		outfile << gen_type << endl;
		outfile << type << endl;
		outfile << price << endl;
		outfile << description << endl;
	}
	outfile.close();
}

void Percussion::insert_acce()
{
	ofstream outfile;
	outfile.open("accessory.txt", ios::out | ios::app);
	if (!outfile)
	{
		cout << "Error opening file!" << endl;
	}
	else
	{
		outfile << gen_type << endl;
		outfile << type << endl;
		outfile << price << endl;
		outfile << description << endl;
	}
}

void Percussion::search()
{
	Percussion* obj[1];
	ifstream infile;
	string aux;
	int count_aux = 0;
	infile.open("instruments.txt", ios::in);
	if (!infile)
	{
		cout << "Error opening file!" << endl;
		cout << "The file does not exist!" << endl;
		system("pause");
	}
	else
	{
		cout << " " << endl;
		cout << "Write the type of instruments to search:" << endl;
		cin >> aux;
		infile >> gen_type;
		while (infile)
		{
			for (int i = 0; i < 1; i++)
			{
				infile >> type;
				infile >> price;
				infile >> description;
				obj[i] = new Percussion(gen_type, type, description, price);
				try
				{
					if (type == aux && gen_type == "Percussion")
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

void Percussion::search_acce()
{
	Percussion* obj[1];
	ifstream infile;
	string aux;
	int count_aux = 0;
	infile.open("accessory.txt", ios::in);
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
				obj[i] = new Percussion(gen_type, type, description, price);
				try
				{
					if (type == aux && gen_type == "Percussion")
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

void Percussion::sale()
{
	Percussion* obj[1];
	string aux_type;
	string aux_description;
	ifstream infile;
	infile.open("instruments.txt", ios::in);
	ofstream out_sale;
	out_sale.open("sales.txt", ios::out | ios::app);
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
			cout << "Write the type of instruments to sale:" << endl;
			cin >> aux_type;
			cin.ignore();
			cout << "Write the description of instruments to sale:" << endl;
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
					obj[i] = new Percussion(gen_type, type, description, price);
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
	remove("instruments.txt");
	rename("auxiliary.txt", "instruments.txt");
	delete obj[0];
	system("pause");
}

void Percussion::sale_acce()
{
	Percussion* obj[1];
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
					obj[i] = new Percussion(gen_type, type, description, price);
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

void Percussion::overview()
{
	Percussion* obj[1];
	int sum = 0;
	string aux;
	ifstream infile;
	infile.open("sales.txt", ios::in);
	if (!infile)
	{
		cout << "Error opening file!" << endl;
		cout << "The file does not exist!" << endl;
		system("pause");
	}
	else
	{
		cout << "Write the type of instrument: " << endl;
		cin >> aux;
		infile >> type;
		while (!infile.eof())
		{
			for (int i = 0; i < 1; i++)
			{
				infile >> price;
				infile >> description;
				infile >> stock_count;
				obj[i] = new Percussion("Percussion", type, description, price);
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

void Percussion::overview_acce()
{
	Percussion* obj[1];
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
				obj[i] = new Percussion("Percussion", type, description, price);
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

bool Percussion::file_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}
