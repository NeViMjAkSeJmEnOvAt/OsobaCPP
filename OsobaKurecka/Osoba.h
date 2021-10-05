#include <ostream>
#include <iostream>
#include <time.h>
#include <string>
using namespace std;


class Osoba {
	public:
		Osoba();
		Osoba(string);
		Osoba(const Osoba&);
		~Osoba();

		string GetRodneCislo()const;
		bool SetRodneCislo(const string);

		string GetBirthDate()const;
		string GetGender()const;
		int GetAge()const;
	
		bool operator==(const Osoba&);
		Osoba& operator=(const Osoba&);
		friend std::ostream& operator<<(ostream&, const Osoba&);

	private:
		string RodneCislo;
		
		bool CheckRodneCislo(string);
		int GetYear()const;
		int GetMonth()const;
		int GetDay()const;


		

};