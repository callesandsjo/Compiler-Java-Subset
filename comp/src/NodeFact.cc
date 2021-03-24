#include "NodeFact.h"
#include "SubExpression.h"
#include "AddExpression.h"
#include "ClassDeclaration.h"
#include "MethodDeclaration.h"
#include "MulExpression.h"
#include "SystemPrint.h"
#include "IfStatement.h"
#include "WhileStatement.h"
#include "MainClass.h"
#include "Return.h"
#include "Integer.h"
#include "Identifier.h"
#include "Boolean.h"
#include "Goal.h"
#include "Arguments.h"
#include "ClassDeclarations.h"
#include "Expression.h"
#include "ExpressionNew.h"
#include "Expressions.h"
#include "MethodCall.h"
#include "StatementAssigning.h"
#include "MethodDeclarations.h"
#include "Statements.h"
#include "Statement.h"
#include "VarDeclaration.h"
#include "VarDeclarations.h"
#include "Type.h"
#include "LessThanOperation.h"
#include "AndOperation.h"
#include "StatementAssigning.h"
#include "ExpressionExmark.h"

Node *NodeFact::newNode(string type, string v)
{
    if (type == "Goal")
    {
        return new Goal(v);
    }
    if (type == "AddExpression")
    {
        return new AddExpression(v);
    }
    if (type == "SubExpression")
    {
        return new SubExpression(v);
    }
    if (type == "MethodDeclaration")
    {
        return new MethodDeclaration(v);
    }
    if (type == "ClassDeclaration")
    {
        return new ClassDeclaration(v);
    }
    if (type == "MulExpression")
    {
        return new MulExpression(v);
    }
    if (type == "SystemPrint")
    {
        return new SystemPrint(v);
    }

    if (type == "IfStatement")
    {
        return new IfStatement(v);
    }

    if (type == "WhileStatement")
    {
        return new WhileStatement(v);
    }
    if (type == "MainClass")
    {
        return new MainClass(v);
    }
    if (type == "Return")
    {
        return new Return(v);
    }

    if (type == "Integer")
    {
        return new Integer(v);
    }
    if (type == "Identifier")
    {
        return new Identifier(v);
    }
    if (type == "Boolean")
    {
        return new Boolean(v);
    }
    if (type == "Arguments")
    {
        return new Arguments(v);
    }
    if (type == "ClassDeclarations")
    {
        return new ClassDeclarations(v);
    }
    if (type == "Expression")
    {
        return new Expression(v);
    }
    if (type == "ExpressionNew")
    {
        return new ExpressionNew(v);
    }
    if (type == "Expressions")
    {
        return new Expressions(v);
    }
    if (type == "MethodCall")
    {
        return new MethodCall(v);
    }
    if (type == "MethodDeclarations")
    {
        return new MethodDeclarations(v);
    }
    if (type == "StatementsAssigning")
    {
        return new StatementAssigning(v);
    }
    if (type == "Statements")
    {
        return new Statements(v);
    }
    if (type == "Type")
    {
        return new Type(v);
    }
    if (type == "VarDeclaration")
    {
        return new VarDeclaration(v);
    }
    if (type == "VarDeclarations")
    {
        return new VarDeclarations(v);
    }
    if (type == "AndOperation")
    {
        return new AndOperation(v);
    }
    if (type == "LessThanOperation")
    {
        return new LessThanOperation(v);
    }
    if (type == "StatementAssigning")
    {
        return new StatementAssigning(v);
    }
    if (type == "Statement")
    {
        return new Statement(v);
    }
    if (type == "ExpressionExmark")
    {
        return new ExpressionExmark(v);
    }

    std::cout << "Missing " << type << std::endl;
    return new Node(type, v);
}