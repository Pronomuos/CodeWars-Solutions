#include <string>

std::vector<std::string> wave(std::string y){

  int length = y.size();
  std::vector<std::string> wave;
  wave[length];
  
  for (int index = 0; index < length; ++index)
    {
     y[index-1] = std::tolower(static_cast<unsigned char>(y[index-1]));
     
     if  (y[index] == ' ') continue;
   
     y[index] = std::toupper(static_cast<unsigned char>(y[index])); 
     wave.push_back(y);
     }
     
     return wave;

}
