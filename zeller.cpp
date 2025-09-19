/* A command-line utility for finding the day of the week." 
 * Written by dev-dmitrii-g */

#include <getopt.h>
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <cmath>

using std::cout, std::cin, std::endl;

#define PROGRAM_NAME "zeller" 
#define VERSION "1.0"
#define AUTHOR "dev-dmitrii-g"

/* Displays a hint message */
void hint() 
{
	cout << "Try '" << PROGRAM_NAME << " --help' for more information." << endl; 
}

/* Displays intended program usage */
void help()
{
	cout << "Usage: "<< PROGRAM_NAME << " [OPTIONS]..." << endl;
	cout << "A command-line utility for finding the day of the week." << endl;
	cout << "  -h, --help\t\tdisplay this help and exit" << endl;
	cout << "  -v, --version\t\toutput version information and exit" << endl;
}

/* Displays program version */
void version()
{
	cout << PROGRAM_NAME << " " << VERSION << endl;
	cout << "Written by " << AUTHOR << "." << endl;
}

void georgian()
{
	int y, m, q, h, K, J = -1;

	cout << "Enter year: "; cin >> y;
	while (y <= 0)
	{
		cout << "Invalid year, please try again." << endl;
		cout << "Enter year: "; cin >> y;
	}

	cout << "Enter month: "; cin >> m;
	while (m <= 0 || m > 12)
	{
		cout << "Invalid month, please try again." << endl;
		cout << "Enter month: "; cin >> m;
	}

	cout << "Enter day: "; cin >> q;
	while (q <= 0 || q > 31)
	{
		cout << "Invalid day, please try again." << endl;
		cout << "Enter day: "; cin >> q;
	}

	if (m < 3)
	{
		m += 12;
		y--;
	}

	K = y % 100;
	J = floor((y/100));

	h = (q + floor((13*(m+1))/(5)) + K + floor(K/4) + floor(J/4) - 2 * J);
	h = h % 7;
	(m > 12) ? m -= 12 : m;
	(m < 3) ? y += 1 : y;

	if (q < 10) cout << "0";
	cout << q << ".";
	if (m <= 12)
	{
		if (m < 10) cout << "0";
	}
	cout << m << "." << y << " - ";

	switch (h)
	{
		case 0: cout << "Saturday" << endl; break;
		case 1: cout << "Sunday" << endl; break;
		case 2: cout << "Monday" << endl; break;
		case 3: cout << "Tuesday" << endl; break;
		case 4: cout << "Wednesday" << endl; break;
		case 5: cout << "Thursday" << endl; break;
		case 6: cout << "Friday" << endl; break;
	}

}

int main(int argc, char* argv[])
{
	int opt;
	int option_index = 0;

	static struct option long_options[] = {
		{"help",		no_argument,		0,	'h'},
		{"version",		no_argument,		0,	'v'},
		{0,				0,					0,	0}
	};

	while ((opt = getopt_long(argc, argv, "hv", long_options, &option_index)) != -1)
	{
		switch (opt)
		{
			case 'h': help(); break;
			case 'v': version(); break;
			default: hint(); return 1;
		}
	}

	georgian();
	return 0;
}
