#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class MateriePrima {
private:
	char* denumire = nullptr;
	int cantitateNecesara = 0;
	int cantitateDisponibila = 0;
public:

	MateriePrima() {
		//cout << "\nConstructor fara parametru.";
	}

	MateriePrima(const char* denumire, int cantitateNecesara, int cantitateDisponibila) {
		//cout << "\nConstructor cu toti parametrii.";
		if (denumire != nullptr) {
			this->denumire = new char[strlen(denumire) + 1];
			strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		}
		else {
			this->denumire = nullptr;
		}
		if (cantitateNecesara > 0) {
			this->cantitateNecesara = cantitateNecesara;
		}
		if (cantitateDisponibila > 0) {
			this->cantitateDisponibila = cantitateDisponibila;
		}
	}

	MateriePrima(int cantitateNecesara, int cantitateDisponibila) {
		if (cantitateNecesara > 0) {
			this->cantitateNecesara = cantitateNecesara;
		}
		if (cantitateDisponibila > 0) {
			this->cantitateDisponibila = cantitateDisponibila;
		}
	}

	MateriePrima(const MateriePrima& m) {
		if (m.denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = new char[strlen(m.denumire) + 1];
			strcpy_s(this->denumire, strlen(m.denumire) + 1, m.denumire);
		}
		else {
			this->denumire = nullptr;
		}
		if (m.cantitateNecesara > 0) {
			this->cantitateNecesara = m.cantitateNecesara;
		}
		if (m.cantitateDisponibila > 0) {
			this->cantitateDisponibila = m.cantitateDisponibila;
		}
	}

	MateriePrima& operator=(const MateriePrima& m) {
		if (this != &m) {
			delete[] this->denumire;
			this->denumire = nullptr;
			if (m.denumire != nullptr) {
				this->denumire = new char[strlen(m.denumire) + 1];
				strcpy_s(this->denumire, strlen(m.denumire) + 1, m.denumire);
			}
			if (m.cantitateNecesara > 0) {
				this->cantitateNecesara = m.cantitateNecesara;
			}
			if (m.cantitateDisponibila > 0) {
				this->cantitateDisponibila = m.cantitateDisponibila;
			}
		}
		return *this;
	}

	void setDenumire(char* denumireNou) {
		if (denumireNou != nullptr) {
			delete[] this->denumire;
			this->denumire = new char[strlen(denumireNou) + 1];
			strcpy_s(this->denumire, strlen(denumireNou) + 1, denumireNou);
		}
	}

	const char* getDenumire() const {
		return this->denumire;
	}

	void setCantitateNecesara(int cantitateNecesaraNou) {
		if (cantitateNecesaraNou > 0) {
			this->cantitateNecesara = cantitateNecesaraNou;
		}
	}

	int getCantitateNecesara() const {
		return this->cantitateNecesara;
	}

	void setCantitateDisponibila(int cantitateDisponibilaNou) {
		if (cantitateDisponibilaNou > 0) {
			this->cantitateDisponibila = cantitateDisponibilaNou;
		}
	}

	int getCantitateDisponibila() const {
		return this->cantitateDisponibila;
	}

	MateriePrima& operator++() {
		cout << "\nCantitatea disponibila creste.";
		this->cantitateDisponibila++;
		return *this;
	}

	MateriePrima operator++(int) {
		cout << "\nCantitatea disponibila creste.";
		MateriePrima copie = *this;
		this->cantitateDisponibila++;
		return copie;
	}

	MateriePrima& operator--() {
		cout << "\nCantitatea disponibila scade.";
		this->cantitateDisponibila--;
		return *this;
	}

	MateriePrima operator--(int) {
		cout << "\nCantitatea disponibila scade.";
		MateriePrima copie = *this;
		this->cantitateDisponibila--;
		return copie;
	}

	bool operator==(const MateriePrima& m) const {
		return (strcmp(this->denumire, m.denumire) == 0 && this->cantitateDisponibila == m.cantitateDisponibila && this->cantitateNecesara == m.cantitateNecesara);
	}

	bool operator!() const {
		return !this->cantitateDisponibila;
	}

	bool operator<=(const MateriePrima& m) const {
		if (strcmp(denumire, m.denumire) < 0) {
			return true;
		}
		else if (strcmp(denumire, m.denumire) == 0 && cantitateNecesara <= m.cantitateNecesara) {
			return true;
		}
		else if (strcmp(denumire, m.denumire) == 0 && cantitateNecesara == m.cantitateNecesara && cantitateDisponibila <= m.cantitateDisponibila) {
			return true;
		}
		return false;
	}

	MateriePrima operator+(int cantitateDisponibilaSuplimentara) {
		if (cantitateDisponibilaSuplimentara > 0) {
			MateriePrima rez = *this;
			rez.cantitateDisponibila += cantitateDisponibilaSuplimentara;
			return rez;
		}
	}

	char operator[](int pozitie) {
		if (pozitie >= 0 && pozitie < strlen(this->denumire)) {
			if (this->denumire != nullptr) {
				return this->denumire[pozitie];
			}
		}
	}

	operator int() const {
		return static_cast<int>(cantitateDisponibila);
	}

	friend istream& operator>>(istream& in, MateriePrima& m) {
		cout << "\nIntroduceti materiile prime: ";
		cout << "\nIntroduceti materia prima, cantitatea necesara si cantitatea disponibila: ";
		char temp[50];
		in >> temp;
		delete[] m.denumire;
		m.denumire = new char[strlen(temp) + 1];
		strcpy_s(m.denumire, strlen(temp) + 1, temp);
		in >> m.cantitateNecesara;
		in >> m.cantitateDisponibila;
		return in;
	}

	friend ostream& operator<<(ostream& out, const MateriePrima& m) {
		out << "\nAfisarea materiilor prime: ";
		out << "\nDenumirea materiilor prime, cantitatea necesara si cantitatea disponibila: \n";
		out << m.denumire << " " << m.cantitateNecesara << " " << m.cantitateDisponibila << endl;
		return out;
	}

	~MateriePrima() {
		//cout << "\nApel destructor.";
		delete[] this->denumire;
		this->denumire = nullptr;
	}
};

class Retete {
private:
	string numePizza = "Anonim";
	int nrIngrediente = 0;
	MateriePrima** ingrediente = nullptr;
public:
	Retete() {
	}

	Retete(string numePizza, int nrIngrediente, MateriePrima** ingrediente) {
		if (numePizza.size() >= 2) {
			this->numePizza = numePizza;
		}
		if (nrIngrediente > 0 && ingrediente != nullptr) {
			this->nrIngrediente = nrIngrediente;
			this->ingrediente = new MateriePrima * [this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				this->ingrediente[i] = new MateriePrima(*ingrediente[i]);
			}
		}
	}

	Retete(int nrIngrediente) {
		if (nrIngrediente > 0) {
			this->nrIngrediente = nrIngrediente;
		}
	}

	void setNumePizza(string numePizzaNou) {
		if (numePizzaNou.size() >= 1) {
			this->numePizza = numePizzaNou;
		}
	}

	string getDenumire() const {
		return this->numePizza;
	}

	void setNrIngrediente(int nrIngrediente) {
		if (nrIngrediente > 0) {
			this->nrIngrediente = nrIngrediente;
		}
	}

	int getNrIngrediente() const {
		return this->nrIngrediente;
	}

	void setIngrediente(MateriePrima** ingredienteNou) {
		if (ingredienteNou != nullptr && this->nrIngrediente > 0) {
			delete[] this->ingrediente;
			this->ingrediente = new MateriePrima * [this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				this->ingrediente[i] = new MateriePrima(*ingredienteNou[i]);
			}
		}
	}

	MateriePrima** getIngrediente() const {
		return this->ingrediente;
	}

	bool verificarePosibilitateProducere(MateriePrima** stocMateriePrima) {
		int ok = 1;
		for (int i = 0; i < this->nrIngrediente; i++) {
			if (stocMateriePrima[i]->getCantitateNecesara() > stocMateriePrima[i]->getCantitateDisponibila()) {
				ok = 0;
			}
		}
		if (ok == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	Retete(const Retete& r) {
		if (r.numePizza.size() >= 2) {
			this->numePizza = r.numePizza;
		}
		if (r.nrIngrediente > 0 && r.ingrediente != nullptr) {
			this->nrIngrediente = r.nrIngrediente;
			delete[] this->ingrediente;
			this->ingrediente = new MateriePrima * [this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				this->ingrediente[i] = new MateriePrima(*r.ingrediente[i]);
			}
		}
	}

	Retete& operator=(const Retete& r) {
		if (this != &r) {
			if (r.numePizza.size() >= 2) {
				this->numePizza = r.numePizza;
			}
			if (r.nrIngrediente > 0 && r.ingrediente != nullptr) {
				this->nrIngrediente = r.nrIngrediente;
				delete[] this->ingrediente;
				this->ingrediente = new MateriePrima * [this->nrIngrediente];
				for (int i = 0; i < this->nrIngrediente; i++) {
					this->ingrediente[i] = new MateriePrima(*r.ingrediente[i]);
				}
			}
		}
		return *this;
	}

	friend istream& operator>>(istream& in, Retete& r) {
		cout << "\nIntroduceti retetele pentru pizza: ";
		cout << "\nIntroduceti numele pentru pizza: ";
		in.ignore();
		getline(in, r.numePizza);
		cout << "\nIntroduceti nr. de ingrediente: ";
		in >> r.nrIngrediente;
		cout << "\nIntroduceti ingredientele: ";
		r.ingrediente = new MateriePrima * [r.nrIngrediente];
		for (int i = 0; i < r.nrIngrediente; i++) {
			r.ingrediente[i] = new MateriePrima();
			in >> *r.ingrediente[i];
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, const Retete& r) {
		out << "\nAfisarea retetei: ";
		if (r.numePizza.size() >= 1) {
			out << "\nNume pizza: " << r.numePizza;
			if (r.nrIngrediente > 0 && r.ingrediente != nullptr) {
				out << "\nNr. ingrediente: " << r.nrIngrediente;
				out << "\nIngrediente(Nume - Cantitate Necesara - Cantitate Disponibila): ";
				for (int i = 0; i < r.nrIngrediente; i++) {
					ostringstream oss;
					oss << "\n" << r.ingrediente[i]->getDenumire() << " - " << r.ingrediente[i]->getCantitateNecesara() << " - " << r.ingrediente[i]->getCantitateDisponibila();
					out << oss.str();
				}
			}
		}
		return out;
	}

	~Retete() {
		//cout << "\nApel destructor.";
		delete[] this->ingrediente;
		this->ingrediente = nullptr;
	}
};

class Preparat {
private:
	const int index = 1;
	Retete** reteta = nullptr;
	int nrRetete = 0;
	float pret = 0;
public:
	Preparat() {

	}

	Preparat(int index) : index(index++) {
		//cout<<"\nConstructor fara parametru";
	}

	Preparat(int index, Retete** reteta, int nrRetete, float pret) : index(index) {
		//cout << "\nConstructor cu toti parametrii.";
		if (reteta != nullptr && nrRetete > 0) {
			this->nrRetete = nrRetete;
			this->reteta = new Retete * [this->nrRetete];
			for (int i = 0; i < this->nrRetete; i++) {
				this->reteta[i] = new Retete(*reteta[i]);
			}
		}
		if (pret > 0) {
			this->pret = pret;
		}
	}

	Preparat(Retete** retete) {
		if (reteta != nullptr && this->nrRetete > 0) {
			this->reteta = new Retete * [this->nrRetete];
			for (int i = 0; i < this->nrRetete; i++) {
				this->reteta[i] = new Retete(*reteta[i]);
			}
		}
	}

	int getIndex() const {
		return this->index;
	}

	void setReteta(Retete** retetaNoua) {
		if (retetaNoua != nullptr && this->nrRetete > 0) {
			if (this->reteta != nullptr) {
				for (int i = 0; i < this->nrRetete; i++) {
					delete this->reteta[i];
				}
				delete[] this->reteta;
			}
			this->reteta = new Retete * [this->nrRetete];
			for (int i = 0; i < this->nrRetete; i++) {
				this->reteta[i] = new Retete(*retetaNoua[i]);
			}
		}
	}

	Retete** getReteta() const {
		return this->reteta;
	}

	void setNrRetete(int nrReteteNou) {
		if (nrReteteNou > 0) {
			this->nrRetete = nrReteteNou;
		}
	}

	int getNrRetete() const {
		return this->nrRetete;
	}

	void setPret(float pretNou) {
		if (pretNou > 0) {
			this->pret = pretNou;
		}
	}

	float getPret() const {
		return this->pret;
	}

	Preparat(const Preparat& p) : index(p.index) {
		if (p.reteta != nullptr && p.nrRetete > 0) {
			this->nrRetete = p.nrRetete;
			this->reteta = new Retete * [this->nrRetete];
			for (int i = 0; i < this->nrRetete; i++) {
				this->reteta[i] = new Retete(*p.reteta[i]);
			}
		}
		if (p.pret > 0) {
			this->pret = p.pret;
		}
	}

	Preparat& operator=(const Preparat& p) {
		if (this != &p) {
			if (p.reteta != nullptr && p.nrRetete > 0) {
				this->nrRetete = p.nrRetete;
				this->reteta = new Retete * [this->nrRetete];
				for (int i = 0; i < this->nrRetete; i++) {
					this->reteta[i] = new Retete(*p.reteta[i]);
				}
			}
			if (p.pret > 0) {
				this->pret = p.pret;
			}
		}
		return *this;
	}

	friend istream& operator>>(istream& in, Preparat& p) {
		cout << "\nIntroduceti preparatul: ";
		cout << "\nIntroduceti nr. de retete: ";
		in >> p.nrRetete;
		cout << "\nIntroduceti retetele: ";
		p.reteta = new Retete * [p.nrRetete];
		for (int i = 0; i < p.nrRetete; i++) {
			p.reteta[i] = new Retete();
			in >> *p.reteta[i];
		}
		cout << "\nIntroduceti pretul: ";
		in >> p.pret;
		return in;
	}

	friend ostream& operator<<(ostream& out, const Preparat& p) {
		out << "\nAfisarea preparatelor: ";
		out << "\nIndex: " << p.index;
		out << "\nNr. preparate: " << p.nrRetete;
		if (p.reteta != nullptr && p.nrRetete > 0) {
			out << "\nReteta: ";
			for (int i = 0; i < p.nrRetete; i++) {
				out << *p.getReteta()[i] << " ";
			}
			out << "\nPret: " << p.pret << "RON\n";
		}
		return out;
	}

	~Preparat() {
		//cout << "\nApel destructor.";
		delete[] this->reteta;
		this->reteta = nullptr;
	}
};

class Meniu {
private:
	Preparat** meniu = nullptr;
	int nrMeniu = 0;
public:
	Meniu() {
		//cout << "\nConstructor fara parametru.";
	}

	Meniu(Preparat** meniu, int nrMeniu) {
		//cout << "\nConstructor cu toti parametrii";
		if (meniu != nullptr && nrMeniu > 0) {
			this->nrMeniu = nrMeniu;
			this->meniu = new Preparat * [this->nrMeniu];
			for (int i = 0; i < this->nrMeniu; i++) {
				this->meniu[i] = new Preparat(*meniu[i]);
			}
		}
	}

	Meniu(int nrMeniu) {
		if (nrMeniu > 0) {
			this->nrMeniu = nrMeniu;
		}
	}

	void setMeniu(Preparat** meniuNou) {
		if (meniuNou != nullptr && this->nrMeniu > 0) {
			delete[] this->meniu;
			this->meniu = new Preparat * [this->nrMeniu];
			for (int i = 0; i < this->nrMeniu; i++) {
				this->meniu[i] = new Preparat(*meniuNou[i]);
			}
		}
	}

	Preparat** getMeniu() const {
		return this->meniu;
	}

	void setNrMeniu(int nrMeniuNou) {
		if (nrMeniuNou > 0) {
			this->nrMeniu = nrMeniuNou;
		}
	}

	int getNrMeniu() const {
		return this->nrMeniu;
	}

	Meniu(const Meniu& m) {
		if (m.meniu != nullptr && m.nrMeniu > 0) {
			this->nrMeniu = m.nrMeniu;
			delete[] this->meniu;
			this->meniu = new Preparat * [this->nrMeniu];
			for (int i = 0; i < this->nrMeniu; i++) {
				this->meniu[i] = new Preparat(*m.meniu[i]);
			}
		}
	}

	Meniu& operator=(const Meniu& m) {
		if (this != &m) {
			if (m.meniu != nullptr && m.nrMeniu > 0) {
				this->nrMeniu = m.nrMeniu;
				delete[] this->meniu;
				this->meniu = new Preparat * [this->nrMeniu];
				for (int i = 0; i < this->nrMeniu; i++) {
					this->meniu[i] = new Preparat(*m.meniu[i]);
				}
			}
		}
		return *this;
	}

	friend istream& operator>>(istream& in, Meniu& m) {
		cout << "\nIntroduceti meniul dorit: ";
		cout << "\nIntroduceti produselor: ";
		in >> m.nrMeniu;
		cout << "\nIntroduceti produsele din meniu: ";
		m.meniu = new Preparat * [m.nrMeniu];
		for (int i = 0; i < m.nrMeniu; i++) {
			m.meniu[i] = new Preparat(1);
			in >> *m.meniu[i];
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, const Meniu& m) {
		out << "\nMeniul este: ";
		out << "\nNr. produse: " << m.nrMeniu;
		if (m.meniu != nullptr && m.nrMeniu > 0) {
			out << "\nProduse din meniu: ";
			for (int i = 0; i < m.nrMeniu; i++) {
				out << *m.getMeniu()[i] << " ";
			}
		}
		return out;
	}

	~Meniu() {
		//cout << "\nApel destructor.";
		delete[] this->meniu;
		this->meniu = nullptr;
	}
};

class Comanda {
private:
	Preparat** comanda = nullptr;
	int nrComanda = 0;
	int listaIndex[100];
	static float bugetClient;
public:
	Comanda() {
		//cout << "\nConstructor fara parametru.";
	}

	Comanda(Preparat** listaMeniu, int nrComanda) {
		if (listaMeniu != nullptr && nrComanda > 0) {
			this->nrComanda = nrComanda;
			this->comanda = new Preparat * [this->nrComanda];
			for (int i = 0; i < this->nrComanda; i++) {
				this->comanda[i] = new Preparat(*listaMeniu[i]);
				this->comanda[i] = listaMeniu[i];
			}
		}
	}

	Comanda(Preparat** comanda, int nrComanda, int listaIndex[], float bugetClient) {
		//cout << "\nConstructor cu toti parametrii.";
		if (comanda != nullptr && nrComanda > 0) {
			this->nrComanda = nrComanda;
			this->comanda = new Preparat * [this->nrComanda];
			for (int i = 0; i < this->nrComanda; i++) {
				this->comanda[i] = new Preparat(*comanda[i]);
			}
		}
		for (int i = 0; i < 100; i++) {
			this->listaIndex[i] = listaIndex[i];
		}
		if (bugetClient > 0) {
			this->bugetClient = bugetClient;
		}
	}

	Comanda(int nrComanda) {
		if (nrComanda > 0) {
			this->nrComanda = nrComanda;
		}
	}

	void setComanda(Preparat** comandaNoua) {
		if (comandaNoua != nullptr && this->nrComanda > 0) {
			this->comanda = new Preparat * [this->nrComanda];
			for (int i = 0; i < this->nrComanda; i++) {
				this->comanda[i] = new Preparat(*comandaNoua[i]);
			}
		}
	}

	Preparat** getComanda() const {
		return this->comanda;
	}

	void setNrComanda(int nrComandaNou) {
		if (nrComandaNou > 0) {
			this->nrComanda = nrComandaNou;
		}
	}

	int getNrComanda() const {
		return this->nrComanda;
	}

	void setListaIndex(int listaIndexNoua[100]) {
		for (int i = 0; i < 100; i++) {
			this->listaIndex[i] = listaIndexNoua[i];
		}
	}

	const int* getListaIndex() const {
		return this->listaIndex;
	}

	static void setBugetClient(float bugetClientNou) {
		if (bugetClientNou > 0) {
			Comanda::bugetClient = bugetClientNou;
		}
	}

	static float getBugetClient() {
		return Comanda::bugetClient;
	}

	float calculNotaPlata() const {
		float notaPlata = 0;
		for (int i = 0; i < 100; i++) {
			if (listaIndex[i] != 0) {
				notaPlata += comanda[listaIndex[i] - 1]->getPret();
			}
			else {
				break;
			}
		}
		return notaPlata;
	}

	Comanda(const Comanda& c) {
		if (c.comanda != nullptr && c.nrComanda > 0) {
			this->nrComanda = c.nrComanda;
			this->comanda = new Preparat * [this->nrComanda];
			for (int i = 0; i < this->nrComanda; i++) {
				this->comanda[i] = new Preparat(*c.comanda[i]);
			}
		}
		for (int i = 0; i < 100; i++) {
			this->listaIndex[i] = c.listaIndex[i];
		}
		if (c.bugetClient > 0) {
			this->bugetClient = c.bugetClient;
		}
	}

	Comanda& operator=(const Comanda& c) {
		if (this != &c) {
			if (c.comanda != nullptr && c.nrComanda > 0) {
				this->nrComanda = c.nrComanda;
				this->comanda = new Preparat * [this->nrComanda];
				for (int i = 0; i < this->nrComanda; i++) {
					this->comanda[i] = new Preparat(*c.comanda[i]);
				}
			}
			for (int i = 0; i < 100; i++) {
				this->listaIndex[i] = c.listaIndex[i];
			}
			if (c.bugetClient > 0) {
				this->bugetClient = c.bugetClient;
			}
		}
		return *this;
	}

	friend istream& operator>>(istream& in, Comanda& c) {
		cout << "\nPlasati comanda pe care o doriti: ";
		cout << "\nIntroduceti nr. de produse pe care le doriti: ";
		in >> c.nrComanda;
		int nrIndex = 0;
		for (int i = 0; i < c.nrComanda; i++) {
			cout << "\nIntroduceti index-ul produsului pe care doriti sa il comandati(apasati 0 daca nu mai doriti niciun alt produs): ";
			int index;
			in >> index;

			while (index < 0) {
				cout << "\nIndexul nu poate fi negativ. Reintroduceti index-ul: ";
				in >> index;
			}
			if (index == 0) {
				break;
			}
			c.listaIndex[nrIndex++] = index;
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, const Comanda& c) {
		if (c.calculNotaPlata() > c.bugetClient) {
			cout << "\nBugetul clientului este insuficient pentru comanda facuta!";
		}
		else {
			if (c.getNrComanda() != 0) {
				out << "\nComanda contine: ";
				for (int i = 0; i < 100; i++) {
					if (c.listaIndex[i] != 0) {
						out << *c.comanda[c.listaIndex[i] - 1] << "\n";
					}
					else {
						break;
					}
				}
				out << "\nBugetul clientului: " << c.bugetClient;
				out << "\nNota de plata: " << c.calculNotaPlata();
			}
			else {
				out << "\nNu ati comandat nimic!";
			}
		}
		return out;
	}

	~Comanda() {
		delete[] this->comanda;
		this->comanda = nullptr;
	}
};

float Comanda::bugetClient = 100;

int main() {
	MateriePrima m1_p1("Mozzarella", 10, 50);
	MateriePrima m2_p1("Sunca", 20, 100);
	MateriePrima m3_p1("Masline", 7, 70);

	/*m1_p1++;
	++m1_p1;
	cout << m1_p1;
	m1_p1--;
	--m2_p1;
	cout << m1_p1;*/

	/*if (m1_p1==m2_p1) {
		cout << "\nSunt egale.";
	}
	else {
		cout << "\nNU sunt egale.";
	}*/

	/*if (!m1_p1.getCantitateDisponibila()) {
		cout << "\nMateria prima pentru reteta 1 NU are stoc.";
	}
	else {
		cout << "\nMateria prima pentru reteta 1 are stoc.";
	}*/

	/*if (m1_p1 < m2_p1) {
		cout << "\nMateria 1 pt. reteta 1 este mai mica sau egala decat materia 2 pt. reteta 1.";
	}
	else {
		cout << "\nMateria 1 pt. reteta 1 NU este mai mica sau egala decat materia 2 pt. reteta 1.";
	}*/

	/*m1_p1 = m1_p1 + 10;
	cout << "\nCantitatea disponibila pentru materia prima 1 din reteta 1 este: " << m1_p1.getCantitateDisponibila();*/

	/*for (int i = 0; i < strlen(m1_p1.getDenumire()); i++) {
		cout << "\nCaracterul de pe pozitia " << i << " este: " << m1_p1[i];
	}*/

	/*MateriePrima materie;

	materie.setCantitateDisponibila(40);
	cout << "\nCantitate disponibila(int): " << static_cast<int>(materie.getCantitateDisponibila());*/

	MateriePrima* listaIngrediente_p1[] = { &m1_p1, &m2_p1, &m3_p1 };
	Retete r1("Pizza Specialitatea Noastra", 3, listaIngrediente_p1);
	//cout << r1;

	MateriePrima m1_p2("Rosii", 10, 40);
	MateriePrima m2_p2("Porumb", 20, 80);
	MateriePrima m3_p2("Ciuperci", 15, 60);
	MateriePrima m4_p2("Ananas", 5, 60);

	MateriePrima* listaIngrediente_p2[] = { &m1_p2, &m2_p2, &m3_p2, &m4_p2 };
	Retete r2("Pizza Casei", 4, listaIngrediente_p2);
	//cout << r2;

	MateriePrima m1_p3("Salam", 15, 75);
	MateriePrima m2_p3("Branza", 10, 50);

	MateriePrima* listaIngrediente_p3[] = { &m1_p3, &m2_p3 };
	Retete r3("Pizza Zilei", 2, listaIngrediente_p3);
	//cout << r3;

	MateriePrima m1_p4("Sunca italiana", 10, 50);
	MateriePrima m2_p4("Legume", 10, 40);
	MateriePrima m3_p4("Sos de rosii", 5, 40);

	MateriePrima* listaIngrediente_p4[] = { &m1_p4, &m2_p4, &m3_p4 };
	Retete r4("Pizza Casei", 3, listaIngrediente_p4);
	//cout << r4;

	Retete* listaReteta1[] = { &r1 };
	Preparat p1(1, listaReteta1, 1, 39.99);

	Retete* listaReteta2[] = { &r2 };
	Preparat p2(2, listaReteta2, 1, 74.99);

	Retete* listaReteta3[] = { &r3 };
	Preparat p3(3, listaReteta3, 1, 40);

	Retete* listaReteta4[] = { &r4 };
	Preparat p4(4, listaReteta4, 1, 63);

	//cout << p1 << p2 << p3 << p4;

	Preparat* listaMeniu[] = { &p1, &p2, &p3, &p4 };
	Meniu m1(listaMeniu, 4);
	//cout << m1;

	Preparat* listaComanda[] = { &p1, &p3 };
	int listaIndex[] = { 1,3 };
	//Comanda c1(listaComanda, 2, listaIndex, 2, 100);
	Comanda c1(listaMeniu, 4);

	int optiune;
	do {
		cout << "\nMeniu: ";
		cout << "\n1. Afiseaza preparatele disponibile. ";
		cout << "\n2. Comandati produse. ";
		cout << "\n3. Aratati produsele comandate. ";
		cout << "\n0. Iesire.";
		cout << "\nAlege o optiune: ";
		cin >> optiune;
		switch (optiune) {
		case 1:
			cout << m1;
			break;
		case 2:
			cin >> c1;
			break;
		case 3:
			cout << c1;
			break;
		case 0:
			cout << "\nIesire.";
			exit(0);
		default:
			cout << "\nOptiunea nu exista. Alegeti o optiune valida!";
			break;
		}
	} while (optiune != 4);
	return 0;
}