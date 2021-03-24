#include "NodeFact.h"
#include "node/SubExpression.h"
#include "node/AddExpression.h"

Node* NodeFact::newNode(string t, string v)
{
    if (t == "AddExpression") {
        return new AddExpression(v);
    }
    if (t == "SubExpression") {
        return new SubExpression(v);
    }
    return new Node(t,v);
}