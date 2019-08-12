#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <allheaders.h>

using namespace std;

class JsonPack;

string GetAllWords(json_object *json_obj,const string &str);

void deleteMultiSpaces(string &str);

void buildJson(JsonPack &JsonObjArrayMain, string &str);

bool isExit(const string& str);

bool isNotEmpty(const char* str);

#endif // MYFUNCTIONS_H
