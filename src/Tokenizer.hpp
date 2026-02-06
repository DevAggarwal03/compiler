#pragma once
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cstddef>

// changing return type to optional
// make this tokenKind {keyword, identifiers, Symbol, Integer, Eof}
enum class TokenList {
  _return,
  int_lit,
  semi,
  variable,
  _if,
  _else,
  _for,
  _while,
  _do,
};

struct Token {
  // make a list of valid tokens
  TokenList type;
  std::string val;
};

struct CharReturnType {
  bool isChar;
  char val;
};

struct TokenReturnType {
  bool istoken;
  Token tkn;
};

class Tokenizer {

private:
  std::string code; 
  std::size_t position = 0;
  std::vector<Token> tokens;


public:
  explicit Tokenizer (const std::string& _code): code(_code){ 
  }

  TokenReturnType createAndReturnTkn(TokenList type, std::string& val){
    Token newTkn = {.type = type, .val = val};
    val = "";
    return {true, newTkn};
  }

  // checkVariable
  TokenReturnType check() {
    std::string buffer = "";
    CharReturnType c = peek(0); 
    if(c.isChar && (c.val == '_' || std::isalpha(static_cast<unsigned char>(c.val)))){
        buffer += consume().val;
        c = peek();
        while(c.isChar && (c.val == '_' || std::isalnum(static_cast<unsigned char>(c.val)))){
            buffer += consume().val;
            c = peek();
        }

        if(buffer == "return"){
          return createAndReturnTkn(TokenList::_return, buffer);
        }

        if(buffer == "if"){
          return createAndReturnTkn(TokenList::_if, buffer);
        }

        if(buffer == "else"){
          return createAndReturnTkn(TokenList::_else, buffer);
        }

        if(buffer == "do"){
          return createAndReturnTkn(TokenList::_do, buffer);
        }

        if(buffer == "while"){
          return createAndReturnTkn(TokenList::_while, buffer);
        }

        if(buffer == "for"){
          return createAndReturnTkn(TokenList::_for, buffer);
        }

        return createAndReturnTkn(TokenList::variable, buffer);
    }

    if(c.isChar && c.val == ';'){
      buffer += consume().val;
      return createAndReturnTkn(TokenList::semi, buffer);
    }

    if(c.isChar && c.val == ' '){
      consume();
      return {false};
    }

    if(c.isChar && isnumber(static_cast<unsigned char>(c.val))){
      buffer += consume().val;
      while(c.isChar && isnumber(static_cast<unsigned char>(c.val))){
        buffer += consume().val;
        c = peek();
      }

      return createAndReturnTkn(TokenList::int_lit, buffer);
    }

    return {false};
  }


  std::vector<Token> Tokenize() {
    std::vector<Token> tokens;
    while(!isEof()) {
      if(peek().isChar && isspace(static_cast<unsigned char>(peek().val))){
        consume();
        continue;
      }
      TokenReturnType tkn = check();
      if(tkn.istoken){
        tokens.push_back(tkn.tkn);
      }
    }
    return tokens;
  }

  // returns true if curr pos is equal to the length of the code. 
  bool isEof() {
    if(this -> position == this -> code.length()){
      return true;
    }
    return false;
  }

  CharReturnType peek(const size_t idx = 0) const {
    if(this -> position + idx >= code.length()){
      return {false};
    } 

    return {true, code[this -> position + idx]};
  }


  CharReturnType consume() {
    if(this->position >= this->code.length()){
      return {false};
    }
    char _val = code[this->position];
    position += 1;
    return {true, _val};
  }

};
