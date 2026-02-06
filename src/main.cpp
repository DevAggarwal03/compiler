#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include "./Tokenizer.hpp"

using namespace std; 

// enum Token_list {
//   _return,
//   int_lit,
//   semi
// };
//
// struct Token {
//   Token_list tokenType;
//   string val = "";
// };
//
// bool isDig(char c){
//   return c >= '0' && c <= '9';
// }

// vector<Token> tokenize(string code){
//   vector<Token> tokens;
//   string exp = "";
//   for(int i=0; i < code.size(); i++){
//     if(isspace(code[i])){
    //   continue;
    // }
    // if(isalpha(code[i])){
    //   exp += code[i];
    //   i += 1;
    //   while(isalnum(code[i]) || code[i] == '_'){
    //     exp+=code[i];
    //     i+=1;
    //   }
    //   i -= 1;

      // // do more checks  
      // if(exp == "return"){
      //   tokens.push_back({.tokenType = Token_list::_return, .val = ""}); 
      // }

//       exp = "";
//       continue;
//     }else if(code[i] == '-' || isDig(code[i])){
//       if(code[i] == '-' && (i+1 == code.length() || !isDig(code[i+1]))){
//         cerr << "invalid string at character " << i;
//         exit(EXIT_FAILURE) ;
//       }
//
//       exp+=code[i];
//       i++;
//
//       while(isDig(code[i])){
//         exp += code[i];
//         i++;
//       }
//       i -= 1;
//
//       tokens.push_back({.tokenType = Token_list::int_lit, .val = exp});
//
//       exp = ""; 
//       continue;
//     }else if(code[i] == ';'){
//       cout<<i<<endl;
//       tokens.push_back({.tokenType = Token_list::semi, .val = ";"});
//       continue;
//     }else{
//       cerr << "invalid string at character " << i;
//       exit(EXIT_FAILURE);
//     }
//
//   }
//     return tokens;
// }

int main(int argc, char* argv[]) {

  if(argc != 2){
    cerr << "invalid usage" << endl;
    cerr << "correct useage: bottle <input>"<<endl;
    return EXIT_FAILURE;
  }
    
  string code = "";
  stringstream input;
  fstream file(argv[1], ios::in);
  input << file.rdbuf();
  code = input.str();
  file.close();

  Tokenizer* Tokenizer = new class::Tokenizer(code);


  vector<Token> tokens = Tokenizer -> Tokenize();
  for(Token tkn: tokens){
    cout<<tkn.val<<" "<<static_cast<int>(tkn.type)<<endl;
  }

  cout << "code: " << code << endl;

  return 0;
}
