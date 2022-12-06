#include<iostream>
#include <fstream>
#include<vector>


int ruck_prio(std::string vect)
{   
    std::string prio = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";  
    int res = 0;
    int len = vect.length();
    int half_len = len / 2;
    std::string comp_1 = vect.substr(0, half_len);
    std::string comp_2 = vect.substr(half_len, half_len);

    for (int j=0; j<comp_1.length(); j++)
        {
            if (comp_2.find(comp_1[j]) != std::string::npos){
                //std::cout << comp_1[j] <<std::endl;
                res += prio.find(comp_1[j]) +1 ;
                break;
            }
        }
    //std::cout<< vect << ": " << res << std::endl;
    return res;
}



int ruck_prio2(std::string text)
{   
    std::string prio = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";  
    int res = 0;
    int hyphen_1 = text.find("-");
    std::string w1 = text.substr(0, hyphen_1);
    std::string rest = text.substr(hyphen_1+1);
    int hyphen_2 = rest.find("-");
    std::string w2 = rest.substr(0, hyphen_2);
    std::string w3 = rest.substr(hyphen_2+1);
    for (int i=0; i<w1.length(); i++){
        if(w2.find(w1[i])!= std::string::npos){
            if (w3.find(w1[i])!= std::string::npos){
                //std::cout << w1[i] << std::endl;
                res += prio.find(w1[i]) +1;
                break;
            }
        }
    }



    return res;
}



int main()
{

    std::ifstream myfile ("input"); 
    std::string myText;
    std::string line3;
    int sum = 0;
    int l = 0;
    //std::cout << myfile.is_open() << std::endl;
    while (getline (myfile, myText)){
        line3.append(myText);
        line3.append("-");
        l+=1;
        //std::cout << myText << " " << line3 << std::endl;
        if (l%3 == 0){
            line3.pop_back();
            sum += ruck_prio2(line3);
            //std::cout << sum << std::endl;
            line3.clear();
        }
    }
    myfile.close();

    std::cout<< sum << std::endl;
    return 0;
}
