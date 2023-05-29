#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

class Color_sym{
    int sym_color;
    int back_color;
};
// массив с цветами символов, в виде строк
vector < string > arr_color;
// Create custom split() function.  
void string_split(string str, char separator, vector <string> &fin_str) {
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= str.size(); i++) {
        
        // If we reached the end of the word or the end of the input.
        if (str[i] == separator || i == str.size()) {
            endIndex = i;
            string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            fin_str.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
}
int main(){
    //* переменная, в которой будет строчка из файла помещаться
    string line;
 
    //* открываем файл, и запихиваем файл в переменную file_txt
    ifstream file_txt("assets/maps/map1_color.txt"); // окрываем файл для чтения

    string all_str = "";
    //* проверка, открылся ли файл
    if (file_txt.is_open()){
        //* каждую строчку файла, записываем в переменную line
        while (getline(file_txt, line)){
            //TODO: каждую строчку запихиваем(сливаем) в одну большую
            all_str += line;
        }
    }
    string_split(all_str, ';', arr_color);
    vector < string > arr_color_true[arr_color.size()];
    for(int i = 0; i < 100; i++){
        string_split(arr_color[i], '-', arr_color_true[i]);

        // arr_color["1-6","2-6","3-5"...]
    }
    for(int i = 0; i < 100; i++){
        cout << arr_color[i] << endl;
    }
    // arr_color[i].back_color;

    file_txt.close();     // закрываем файл
    
    cin >> line;

}
