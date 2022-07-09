//INCLUDES
#include <fstream>
#include <cstring>
#include <iostream>
#include <numeric>
#include <complex> 
#include <vector>
//STRUCT
struct svgData{
    char identifier;
    std::vector<std::complex<double>> data;
};

//FUNC
std::complex<double> svg_line(void);
std::complex<double> svg_cubicBezier(void);

int main(int argc, char* argv[])
{
    std::ifstream ifs("./ressources/2052171.svg", std::ios_base::in);
    char* str;
    std::vector<svgData> curves;

    for(std::string line; std::getline(ifs, line);) 
    {
        str = strstr(line.c_str()," d=");
        int i = 0;
        if(str!=nullptr)
        {
            do
            {
                svgData svgDataTemp;
                std::getline(ifs,line);
                str = strstr(line.c_str(),"/>");
                if(str==nullptr)
                {
                    std::cout << line << std::endl; //DEBBUG
                    int j = 0;
                    double valueTemp;
                    char* token = strtok((char*)line.c_str()," ");
                    while(token != NULL)
                    {
                        if(strcmp(token,"z")!=0)
                        {
                            std::cout << token << std::endl; //DEBBUG
                            if(j==0)
                            {
                                svgDataTemp.identifier = token[0];
                            }
                            else if(j%2!=0)
                            {
                                valueTemp = strtod(token,nullptr);
                            }
                            else if(j%2==0)
                            {
                                std::complex<double> cmplxTemp(valueTemp, strtod(token,nullptr));
                                std::cout << cmplxTemp << std::endl;
                                svgDataTemp.data.push_back(cmplxTemp);
                            }
                            j++;
                        }
                        
                        token = strtok(NULL," ");
                    }
                }
                curves.push_back(svgDataTemp);
                svgDataTemp.data.clear();
            }while(str==nullptr);
            
        }
    }

    std::vector<svgData>::iterator x;
    std::vector<std::complex<double>>::iterator c;
    for(x=curves.begin(); x!=curves.end(); x++)
    {
        std::cout << (*x).identifier << std::endl;
        for(c=(*x).data.begin(); c!=(*x).data.end(); c++)
        {
            std::cout << *c << std::endl;   
        }
    }


    ifs.close();
    return 0;
}