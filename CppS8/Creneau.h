#pragma once
#include "Patient.h"

class Creneau
{
private:
	bool disponible;
	Patient patient;

public:
	Creneau();
	bool getDisponible() { return disponible; }
	void setDisponible(bool value) { disponible = value; }
	Patient getPatient() { return patient; }
	void setPatient(Patient patient) { this->patient = patient; }
};

