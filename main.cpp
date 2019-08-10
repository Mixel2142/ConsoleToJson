#include <QCoreApplication>
#include <iostream>
#include <readline/readline.h>
#include <readline/history.h>
#include <json-c/json.h>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string GetAllWords(json_object *json_obj,const string &str)
{
    stringstream tmp_stream(str);
    string tmp_str = "Null";
    unsigned CounterOfSpaces = count(str.begin(), str.end(), ' ') + 1 ;

    for(unsigned i = 0; i < CounterOfSpaces; i++) {
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


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Введите набор символов разделяя их пробелами."<<endl;
    cout << "Первый набор символов является командой, вторые два аргументами."<<endl;
    cout << "Пример: word1 word2 word3 ... wordN(word1-команда,word2 word3 ... wordN - аргументы)."<<endl;
    cout << "Перевод строки осуществляется нажатием клавиши Enter."<<endl;
    cout << "После того, как вы введёте команду EXIT и нажмёте Enter,"<<endl;
    cout << "на экране появится массив в формате JSON."<<endl;

    char* input_line = nullptr;
    json_object *JsonObjArrayMain = json_object_new_object();

    vector<json_object*> JsonObjArraySub(5);

    while (1) {
        input_line = readline("promt> ");
        static vector<json_object*>::size_type countSubArray = 0;
        if (input_line) {
            add_history(input_line);
            string str(input_line);
            free(input_line);
            input_line = nullptr;

            if (str.find("EXIT") != string::npos && str.length() == strlen("EXIT"))
                break;

            buildJson( JsonObjArrayMain, JsonObjArraySub.at(1), str);
            countSubArray++;
        }
    }//while

    cout << "Массив в формате JSON:"<< endl;
    cout << json_object_to_json_string_ext(JsonObjArrayMain, JSON_C_TO_STRING_SPACED | JSON_C_TO_STRING_PRETTY) << endl;
    json_object_put(JsonObjArrayMain);
    for(auto it : JsonObjArraySub)
        json_object_put(it);


    return 0;
}
