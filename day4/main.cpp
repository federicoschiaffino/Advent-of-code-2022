#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

vector<string> splitString(string str, string delimiter = " ")
{
    vector<string> res;
    int start = 0;
    int end = str.find(delimiter);
    while (end != -1) {
        res.push_back(str.substr(start, end - start));
        start = end + delimiter.size();
        end = str.find(delimiter, start);
        if (end == -1)
            res.push_back(str.substr(start, end - start));
    }
    return res;
}

int count_clean(int t1, int t2, int t3, int t4){
    int res = 0;
    if (t1 <= t3 && t2 >= t4)
        res += 1;
    else if(t3 <= t1 && t4 >= t2)
        res += 1;
    return res;
}

int overlap(int t1, int t2, int t3, int t4){
    int res = 0; 
    if ((t1 <= t3 && t3 <= t2 )|| (t1 <= t4 && t4 <= t2 ))
        res += 1;
    else if ((t3 <= t1 && t1 <= t4) || (t3 <= t2 && t2 <= t4))
        res +=1;
    return res;
}

int main(){
    string line;
    fstream input;
    input.open("input", ios::in);
    vector <string> t;
    vector <string> v;
    int final_res =0;
    //t = splitString("Hello my name is Federico");
    while (getline(input, line)){
        vector <string> v0;
        vector <string> v1;
        t = splitString(line, ",");
        v0 = splitString(t[0], "-");
        v1 = splitString(t[1], "-");
//        if (count_clean(atoi(v0[0].c_str()), atoi(v0[1].c_str()), atoi(v1[0].c_str()), atoi(v1[1].c_str())) == 1){
//            cout << t[0] << " " << t[1] << endl;
//            cout << atoi(v0[0].c_str()) <<  " " << atoi(v0[1].c_str()) <<   " " << atoi(v1[0].c_str()) << " " << atoi(v1[1].c_str())<< endl;}
        final_res += overlap(atoi(v0[0].c_str()), atoi(v0[1].c_str()), atoi(v1[0].c_str()), atoi(v1[1].c_str()));

    }
    
    cout << final_res << endl;
    return 0;
}