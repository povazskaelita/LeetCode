#include <bits/stdc++.h> // Toto includuje vsetky podstatne libraries
using namespace std;

int longestPalindrome(vector<string>& words) {
  unordered_map<string, int> hMap;
  for(const string& word : words) hMap[word]++; // Do hash mapy pridame vsetky words
  int length = 0, oddCount = 0;
  for(auto& [word, count] : hMap){
    string rev = word;
    reverse(rev.begin(), rev.end()); // Otocime string, aby sme mohli porovnavat s terajsim word
    if(rev == word){
      if(count & 1){ // Neparna pocetnost, vtedy priratame count - 1 a na konci priratame + 1 iba ak sa nejake neparne vyskytli
        oddCount++;
        length += count - 1;
      }
      else length += count; // Vsetky parne mozu tvorit palindrom
    }
    else if(word < rev && hMap.find(rev)!=hMap.end()) length += 2*min(count, hMap[rev]); // Ak sa rev nachadza v hash mape, tak incrementujeme length 2 * minimum pocetnosti tychto dvoch. word < rev nam zaisti to, ze nebudeme toto iste robit pre word = rev, cize duplikaty.
  }
  if(oddCount) length++; // Ak je nejaka neparna pocetnost rovnakych words, prave jedno z nich moze byt neparne, takze priratame 1
  return 2*length; // Returnneme dvojnasobok length, pretoze kazdy words ma 2 znaky.
}
int main(){ // Test cases
  vector<string> words = {"lc", "cl", "ff"};
  cout << longestPalindrome(words) << endl;
  words = {"ab", "ty", "yt", "lc", "cl", "ab"};
  cout << longestPalindrome(words) << endl;
  words = {"cc", "ll", "xx"};
  cout << longestPalindrome(words) << endl;
}
