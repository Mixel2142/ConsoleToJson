#ifndef JSONPACK_H
#define JSONPACK_H

#include <QObject>
#include <json-c/json.h>
#include <vector>

class JsonPack : public QObject
{
    Q_OBJECT
public:

    explicit JsonPack(QObject *parent = nullptr);
    ~JsonPack();

    void EmplaceArraySub();

    json_object* getArrayMain();
    json_object* getArraySub();

private:
     json_object* JsonObjArrayMain;
     std::list<json_object*> JsonObjArraySub;
};

#endif // JSONPACK_H
