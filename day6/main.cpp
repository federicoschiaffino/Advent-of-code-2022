#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int marker(string txt){
    for (int i =0; i< txt.length()- 3; i++){
        string new_string = txt.substr(i, 4);
        int res = 0;
        //cout << new_string << endl;
        for (int j =0; j<3; j++){
            for (int k=j+1; k< 4; k++){
                if(new_string[j]!=new_string[k]){
                    res +=1;
                    //cout << txt[j]<< " " << txt[k] << " " << res << endl;
                    if (res == 6){
                        return i +4;
                    }
                }
                else{
                    //cout << "OHOH" << endl;
                    break;
                }
            }
        }

    }
    return 0;
}


int marker2(string txt){
    for (int i =0; i< txt.length()- 13; i++){
        string new_string = txt.substr(i, 14);
        int res = 0;
        //cout << new_string << endl;
        for (int j =0; j<13; j++){
            for (int k=j+1; k< 14; k++){
                if(new_string[j]!=new_string[k]){
                    res +=1;
                    //cout << new_string[j]<< " " << new_string[k] << " " << res << endl;
                    if (res == 91){
                        return i + 14;
                    }
                }
                else{
                    //cout << "OHOH" << endl;
                    //res = 0;
                    break;
                }
            }
        }

    }
    return 0;
}


int main(){
    fstream data;
    string line; 
    data.open("input", ios::in);
    while (getline(data, line)){
        cout << marker2(line) << endl;
    }
    cout << marker2("nppdvjthqldpwncqszvftbrmjlhg") << endl;


}