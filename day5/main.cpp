#include <iostream>
#include <fstream> 
#include <string>
#include <vector>


using namespace std;

vector<string> splitString(string str, string delimiter = " ")
{
    vector<string> res;
    int start = 0;
    int end = str.find(delimiter);
    while (end != -1) {
        //cout << str.substr(start, end - start) << endl;
        start = end + delimiter.size();
        end = str.find(delimiter, start);
        res.push_back(str.substr(start, end - start));
    }
    return res;
}

vector<vector<char> > move(int number_of_obj, int from_stack, int to_stack, vector<vector<char> > v){
    for (int i = 0; i<number_of_obj; i++){
        char to_move = v[from_stack-1][i];
        //cout<< to_move<< endl;
        v[to_stack-1].insert(v[to_stack-1].begin(), to_move);
        }

    for (int i = 0; i<number_of_obj; i++)
        v[from_stack-1].erase(v[from_stack-1].begin());

    return v;
}

vector<vector<char> > move2(int number_of_obj, int from_stack, int to_stack, vector<vector<char> > v){
    for (int i = number_of_obj-1; i>=0; i--){
        char to_move = v[from_stack-1][i];
        v[to_stack-1].insert(v[to_stack-1].begin(), to_move);
    }

    for (int i = 0; i<number_of_obj; i++)
        v[from_stack-1].erase(v[from_stack-1].begin());

    return v;
}

int main(){
    vector<char> stack_1;
    vector<char> stack_2;
    vector<char> stack_3;
    vector<char> stack_4;
    vector<char> stack_5;
    vector<char> stack_6;
    vector<char> stack_7;
    vector<char> stack_8;
    vector<char> stack_9;
    vector<vector<char> > final_vec;
    string line;
    string line_2;
    fstream input;
    input.open("input", ios::in);
    
    if (input.is_open()){
        while (getline(input, line)){
            if (line[1] != ' ')
                stack_1.push_back(line[1]);
            if (line[5] != ' ')
                stack_2.push_back(line[5]);
            if (line[9] != ' ')
                stack_3.push_back(line[9]);
            if (line[13] != ' ')
                stack_4.push_back(line[13]);
            if (line[17] != ' ')
                stack_5.push_back(line[17]);
            if (line[21] != ' ')
                stack_6.push_back(line[21]);
            if (line[25] != ' ')
                stack_7.push_back(line[25]);
            if (line[29] != ' ')
                stack_8.push_back(line[29]);
            if (line[33] != ' ')
                stack_9.push_back(line[33]);
        }
    }

    final_vec.push_back(stack_1);
    final_vec.push_back(stack_2);
    final_vec.push_back(stack_3);
    final_vec.push_back(stack_4);
    final_vec.push_back(stack_5);
    final_vec.push_back(stack_6);
    final_vec.push_back(stack_7);
    final_vec.push_back(stack_8);
    final_vec.push_back(stack_9);


    fstream moves;
    vector <string> t;
    moves.open("moves.txt", ios::in);
    if (moves.is_open()){
        while (getline(moves, line_2)){
            //cout<< line_2 << endl;
            t = splitString(line_2);
            //cout<< atoi(t[0].c_str()) << endl;
            final_vec = move2(atoi(t[0].c_str()), atoi(t[2].c_str()), atoi(t[4].c_str()), final_vec);
        }
    }


 //   final_vec = move2(2, 2, 1, final_vec);
    for (int i =0; i<final_vec.size(); i++){
        cout<< final_vec[i].front() << endl;
    }
    return 0;
}