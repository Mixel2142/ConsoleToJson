#include "jsonpack.h"

JsonPack::JsonPack(QObject *parent) : QObject(parent)
{
    JsonObjArrayMain = json_object_new_object();

    JsonObjArraySub.emplace_back();
    JsonObjArraySub.at(0) = json_object_new_array();
}

JsonPack::~JsonPack()
{
    json_object_put(JsonObjArrayMain);

    for(auto it : JsonObjArraySub)
        json_object_put(it);
}

void JsonPack::EmplaceArraySub()
{
    JsonObjArraySub.emplace_back();
    JsonObjArraySub.back() = json_object_new_array();
}

json_object* JsonPack::getArrayMain()
{
    return JsonObjArrayMain;
}

json_object* JsonPack::getArraySub()
{
    return JsonObjArraySub.back();
}
