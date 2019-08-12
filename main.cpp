#include <QCoreApplication>
#include <allheaders.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Введите набор символов разделяя их пробелами."<<endl;
    cout << "Первый набор символов является командой, вторые два аргументами."<<endl;
    cout << "Пример: word1 word2 word3 ... wordN(word1-команда,word2 word3 ... wordN - аргументы)."<<endl;
    cout << "Перевод строки осуществляется нажатием клавиши Enter."<<endl;
    cout << "После того, как вы введёте команду EXIT и нажмёте Enter,"<<endl;
    cout << "на экране появится массив в формате JSON."<<endl;

    JsonPack JsonP;

    char* input_line = nullptr;

    while (1) {
        input_line = readline("Ввод> ");


        if (isNotEmpty(input_line)) {
            add_history(input_line);

            string str(input_line);

            free(input_line);

            input_line = nullptr;

            if (isExit(str))
                break;

            buildJson(JsonP, str);
        }
    }//while

    cout << "Массив в формате JSON:"<< endl;
    cout << json_object_to_json_string_ext(JsonP.getArrayMain(), JSON_C_TO_STRING_SPACED | JSON_C_TO_STRING_PRETTY) << endl;

    return 0;
}
