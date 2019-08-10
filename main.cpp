#include <QCoreApplication>
#include <iostream>
#include <readline/readline.h>
#include <readline/history.h>
#include <json-c/json.h>
#include <string>
#include <algorithm>

using namespace std;

void testFun() // test deleteMultiSpaces() & CountSpacesFromString() & GetWordFromString()
{


}


void deleteMultiSpaces(string& str)
{
    string::size_type position = 0;

    while( position !=  string::npos) {
        position = str.find_first_of(' ',position);

        if(position != (str.length()-1) && str.at(position+1) == ' ')
            str.replace(position, str.length()-position , str.substr( position, str.length()));
    }
}

string::size_type CountSpacesFromString(string& str)
{
    deleteMultiSpaces(str);
    return count(str.begin(), str.end(), ' ');
}


string GetWordFromString(string& str, const unsigned NumberOfWord)
{

   string::size_type NumberOfSpaces = CountSpacesFromString(str);

    for(auto i = 0; i < NumberOfWord; i++)
          ;
}

void buildJson(json_object *JsonObjArrayMain,json_object *JsonObjArraySub ,const string& str)
{
//GetWordFromString(str,1);
    json_object_array_add(JsonObjArraySub,json_object_new_string("word2, word3, wordN"));
    json_object_object_add(JsonObjArrayMain,"command",json_object_new_string("word1"));
    json_object_object_add(JsonObjArrayMain,"argiments",JsonObjArraySub);

    json_object_object_add(JsonObjArrayMain,"command1",json_object_new_string("word1"));
    json_object_object_add(JsonObjArrayMain,"argiments1",JsonObjArraySub);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char* input_line = nullptr;
    json_object *JsonObjArrayMain = json_object_new_object();
    json_object *JsonObjArraySub = json_object_new_array();

    while (1) {
        input_line = readline("promt> ");

        if (input_line) {
            add_history(input_line);
            string str(input_line);
            free(input_line);
            input_line = nullptr;

            if (str.find("EXIT") != string::npos && str.length() == strlen("EXIT"))
                break;
             buildJson( JsonObjArrayMain, JsonObjArraySub, str);
        }
    }//while

    cout << json_object_to_json_string_ext(JsonObjArrayMain, JSON_C_TO_STRING_SPACED | JSON_C_TO_STRING_PRETTY) << endl;

    json_object_put(JsonObjArrayMain);
    json_object_put(JsonObjArraySub);

    testFun();

    return 0;
}
