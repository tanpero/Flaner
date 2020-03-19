#ifndef _FLANER_PARSER_STATEMENT_HH_
#define _FLANER_PARSER_STATEMENT_HH_

#include <lexer/token.hh>
#include <parser/expression.hh>
#include <vector>

namespace flaner
{
namespace parser
{
namespace syntax
{
	class Statement
	{
	public:
		Statement()
		{}
	};

	class StatementSequence
	{
	public:
		void insert(Statement statement);
		bool isEnd();
		Statement head();
		Statement next();
	private:
		std::vector<Statement> sequence;
		size_t offset;
	};

	class NullStatement : public Statement
	{
	public:
	};

	class BlockStatement : public Statement
	{
	public:
		BlockStatement() : body({}) {}
		BlockStatement(StatementSequence sequence) : body(sequence) {}

	private:
		StatementSequence body;
	};

	class ExpressionStatement : public Statement
	{
	public:
		ExpressionStatement(std::shared_ptr<Expression> expr)
		    : expression(expr)
		{
		}
		std::shared_ptr<Expression> expression;
	};



}
}
}

#endif // !_FLANER_PARSER_STATEMENT_HH_
