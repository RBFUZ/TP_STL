#ifndef TYPE_H
#define TYPE_H

#include <QSqlRecord>

class Type
{
public:
    Type();

    // Getters and Setters
    int getId() { return id; }
    void setId(int id) { this->id = id; }
    QString getLabel() { return label; }
    void setLabel(QString label) { this->label = label; }

private:
    int id;
    QString label;
};

#endif // TYPE_H
