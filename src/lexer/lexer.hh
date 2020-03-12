#ifndef _FLANER_LEXER_LEXER_HH_
#define _FLANER_LEXER_LEXER_HH_

#include <lexer/context.hh>
#include <vector>

namespace flaner
{
namespace lexer
{
	class Lexer
	{
	public:
		Lexer(std::string path)
			: context(path),
			sequence()
		{}

		~Lexer() {}

	private:
		Context context;

	public:
		enum class TokenType
		{
			UNKNOWN,
			NUMBER,
			OP_ADD,
			OP_MINUS,
			OP_MUL,
			OP_INTDIV,
			OP_DIV,
			OP_MOD,
			OP_QUOTE,
			OP_POW,
		};

		struct Token
		{
			TokenType type;
			std::wstring value;
			Token(TokenType a, std::wstring b) : type(a), value(b) {}
		};

	private:
		std::vector<Token> sequence;
		
	public:
		std::vector<Token> process();
	};
}
}

#endif // !_FLANER_LEXER_LEXER_HH_
