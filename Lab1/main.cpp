#include <iostream>
#include<string>
using std::string;
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

string Parsing(string token) {
	int estado=0;
	int p=0;
	while (p<token.length()) {
		char c = token[p];
		switch (estado) {
		case 0:
			if (isalpha(c)) {
				estado =1;
				p++;
			} else
				return "Identificador não inicia com alpha";
			break;
		case 1:	
		if (p==9)
				return "Identificador muito longo";
			if (isalnum(c)) {
				estado =1;
				p++;
			} else
				return "Identificador contém simbolos inválidos";
			break;
		}
	}
	return "ID";
}
struct token {
    string data;
    struct token *next;
};

typedef struct token Token;

Token *addtoken(Token *list, string token) {
	Token *t = new Token();
	t->data = token;
	t->next = list;
	return t;
}

Token *Tokens(string line) {
	int p=0;
	int lastbreak=0;
	Token *list=NULL;
	while (p<line.length()) {
		char c = line[p];
		if (c=='\b' || c=='\n' || c== '\t')
			if (p-lastbreak>0) {
				list = addtoken(list, line.substr(lastbreak,p-1));
				lastbreak = p;
			}
		if (c=='+' || c=='-' || c== '/'|| c== '*'|| c== ';')
			if (p-lastbreak>0) {
				list = addtoken(list, line.substr(lastbreak,p-1));
				lastbreak =p;
				list = addtoken(list, line.substr(lastbreak,p));
			}
		p++;	
	}
	return list;
}

int main(int argc, char** argv) {
	cout << "1Var" <<Parsing("1Var")<< "\n";
	cout << "Variavel1" << Parsing("Variavel1")<< "\n";
	cout << "SaldoBancario" <<Parsing("SaldoBancario")<< "\n";

	Token *tokens;
	
	tokens = Tokens("X = X + 1;");
	cout << tokens;
	return 0;
}
