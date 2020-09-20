std::string spinWords(const std::string &str)
{
   int begin_word = 0;
   int end_word = 0;
   std::string str2 (str);

   for (int i=0; i<=str.size(); ++i)
     {
       if (std::isspace(str2[i]) || str2[i] == '\0')
         {
           end_word = i-1;
           if (end_word - (begin_word-1) >= 5)
             for (int j=0; j<((end_word-begin_word+1)/2); ++j)
               {
                 char temp;
                 temp = str2[end_word-j];
                 str2[end_word-j] = str2[begin_word+j];
                 str2[begin_word+j] = temp;
               }
           begin_word = i+1;
          }
     }

     return str2;
}
