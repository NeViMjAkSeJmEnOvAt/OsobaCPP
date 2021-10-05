#include "Osoba.h"

string DefRodneCislo = "9999999999";

Osoba::Osoba() {
	this->RodneCislo = DefRodneCislo;
}

Osoba::Osoba(string RodneCislo) {
	this->RodneCislo = RodneCislo;
}

Osoba::Osoba(const Osoba & o) {
	this->RodneCislo = o.GetRodneCislo();
}

Osoba::~Osoba() { 
	//destruktor
}

string Osoba::GetRodneCislo()const {
	return(this->RodneCislo);
}

bool Osoba::SetRodneCislo(const string RodneCislo) {
	if (CheckRodneCislo(RodneCislo)) {
		this->RodneCislo = RodneCislo;
		return true;
	}
	else {
		this->RodneCislo = DefRodneCislo;
		return false;
	}
}

string Osoba::GetBirthDate()const {
	if (this->RodneCislo == DefRodneCislo) {
		return "";
	}
	else{
		return to_string(GetDay() + '. ' + GetMonth() + '. ' + GetYear());
	}
}

string Osoba::GetGender()const {
	if (stoi(this->RodneCislo.substr(2, 2)) > 50) {
		return "zena";
	}
	else {
		return "muz";
	}
}

int Osoba::GetAge()const {
	if (this->RodneCislo == DefRodneCislo) {
		return 0;
	}
	time_t cas = time(0);
	struct tm* now = localtime(&cas);
	int rok = now->tm_year + 1900;
	int mesic = now->tm_mon + 1;
	int den = now->tm_mday;

	int vyslednyVek = rok - GetYear();
	if (mesic > GetMonth()) {
		vyslednyVek++;
	}
	if (mesic == GetMonth() && den > GetDay()) {
		vyslednyVek++;
	}
	return vyslednyVek;

}

bool Osoba::CheckRodneCislo(string RodneCislo) {

}

int Osoba::GetDay()const {
	return stoi(this->RodneCislo.substr(4, 2));
}

int Osoba::GetMonth()const {
	int month = stoi(this->RodneCislo.substr(2, 2));
	return(month > 50 ? month - 50 : month); //u žen +50
	}
	
int Osoba::GetYear()const {
	return stoi(this->RodneCislo.substr(0, 2));
}

ostream& operator<<(ostream& os, const Osoba &o) {
	os << "RC: " << o.GetRodneCislo() << " Narozen: " << o.GetBirthDate() << " Vek: " << o.GetAge() << " Pohlavi: " << o.GetGender() << endl;
	return os;
}

Osoba & Osoba::operator=(const Osoba &o ) {
	this -> RodneCislo = o.GetRodneCislo();
	return *this;
}

bool Osoba::operator==(const Osoba &o) {
	return (this->RodneCislo == o.GetRodneCislo());
}