#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<chrono>
#include<fcntl.h>
#include<errno.h>
using namespace std;

int main()
{
	string ch = "bbbb";
	_sleep(5000);
	int slot = 0;
	while(1)
	{
		_sleep(1000);
		ifstream check("checker.txt", ios::in);
		cout << slot << endl;
		check.seekg(0);
		getline(check, ch);
		check.close();
		if(ch.compare("aaaa") == 0)
		{
			break;
		}
		slot++;
	}
	ifstream file("bus.txt", ios::in);
	string line;
	if(file.is_open())
	{
        while(!file.eof())
		{
            getline(file, line);
            cout << line << endl;
            if(line[0] == '0')
            {
            	ofstream m0("rec0.txt", ios :: app);
            	m0 << line[1];
            	m0.close();
			}
			else if(line[0] == '1')
            {
            	ofstream m1("rec1.txt", ios :: app);
            	m1 << line[1];
            	m1.close();
			}
			else if(line[0] == '2')
            {
            	ofstream m2("rec2.txt", ios :: app);
            	m2 << line[1];
            	m2.close();
			}
			else if(line[0] == '3')
            {
            	ofstream m3("rec3.txt", ios :: app);
            	m3 << line[1];
            	m3.close();
			}
        }
        file.close();
    }
    int ccc = std::cin.get();
	return 0;
}
