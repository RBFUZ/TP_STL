#ifndef RDV_H
#define RDV_H


class Rdv
{
private:
    int id;
    int idClient;
    int idPersonnel;

public:
    Rdv();
    Rdv(int idClient, int idPersonnel);

    // Getters and Setters
    int getId() { return id; }
    void setId(int id) {this->id = id; }
    int getIdClient() { return idClient; }
    void setIdClient(int idClient) { this->idClient = idClient; }
    int getIdPersonnel() { return idPersonnel; }
    void setIdPersonnel(int idPersonnel) { this->idPersonnel = idPersonnel; }
};

#endif // RDV_H
