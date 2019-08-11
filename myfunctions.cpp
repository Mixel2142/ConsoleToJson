#include <allheaders.h>

string GetAllWords(json_object *json_obj,const string &str)
{
    stringstream tmp_stream(str);
    string tmp_str = "Null";
    string::size_type CounterOfSpaces = count(str.begin(), str.end(), ' ') + 1 ;

    for(string::size_type i = 0; i < CounterOfSpaces; i++) {
        tmp_stream >> tmp_str;
        json_object_array_add(json_obj, json_object_new_string(tmp_str.data()));
    }
    return tmp_str;
}


void deleteMultiSpaces(string &str)
{
    if(str.find(' ') == 0 && str.length() > 1)
        str = str.substr(1);

    while(str.find("  ",0) != string::npos)
        str.replace(str.find("  "), 2, " ");
    if(str.find_last_of(' ') == str.length()-1)
        str.pop_back();
}

void buildJson(json_object *JsonObjArrayMain, json_object *JsonObjArraySub , string &str)
{
    JsonObjArraySub = json_object_new_array();

    static unsigned numberOfInputLine = 1;
    string command = "command"+to_string(numberOfInputLine);
    string arguments = "arguments"+to_string(numberOfInputLine);

    numberOfInputLine++;

    deleteMultiSpaces(str);

    string commadWord = str.substr(0,str.find_first_of(' '));
    json_object_object_add(JsonObjArrayMain, command.data(), json_object_new_string(commadWord.data()));

    string argumetsWords = str.substr(str.find_first_of(' ')+1);

    GetAllWords(JsonObjArraySub,argumetsWords);

    json_object_object_add(JsonObjArrayMain, arguments.data(), JsonObjArraySub);
}

bool isExit(const string& str) {
    string tmp_str = str;

    transform(tmp_str.begin(), tmp_str.end(), tmp_str.begin(), [](unsigned char c){ return tolower(c); });

    return (tmp_str.find("exit") != string::npos && tmp_str.length() == strlen("EXIT"));
}
