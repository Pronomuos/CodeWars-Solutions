using namespace std;

int tv_remote(const string &word)
{
    char keyboard [5] [8] =
    {
    {'a','b','c','d','e','1','2','3'},
    {'f','g','h','i','j','4','5','6'},
    {'k','l','m','n','o','7','8','9'},
    {'p','q','r','s','t','.','@','0'},
    {'u','v','w','x','y','z','_','/'}
    };
    
    int i=0; 
    int j=0; 
    int count=0;
    
    
    for (char letter: word)
    {
        for (int iii = 0; iii <=4; ++iii)
          for (int jjj = 0; jjj <=7; ++jjj)
                  if (letter == keyboard [iii] [jjj])
                  {
                      count = count + abs(i-iii) + abs(j-jjj) + 1;
                      i = iii;
                      j = jjj;
                  }
    }
    
    return count;
}
