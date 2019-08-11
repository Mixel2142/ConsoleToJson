#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H
#include <allheaders.h>

using namespace std;

string GetAllWords(json_object *json_obj,const string &str);

void deleteMultiSpaces(string &str);

void buildJson(json_object *JsonObjArrayMain, json_object *JsonObjArraySub , string &str);

bool isExit(const string& str);

#endif // MYFUNCTIONS_H
