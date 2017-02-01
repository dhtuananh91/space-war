// ===================================================================
//
// Description		
//		Contains the implementation of MatchExpression
//
// Revision history
//		Date			Description
//		30-Nov-2012		First version
//
// ===================================================================
#include "MatchExpression.h"

namespace Sfs2X {
namespace Entities {
namespace Match {

// -------------------------------------------------------------------
// ChainedMatchExpression
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::ChainedMatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned char> value, MatchExpressionValueType valueType, boost::shared_ptr<LogicOperator> logicOp, boost::shared_ptr<MatchExpression> parent)
{
	boost::shared_ptr<MatchExpression> matchingExpression (new MatchExpression(varName, condition, value, valueType));
	matchingExpression->logicOp = logicOp;
	matchingExpression->parent = parent;

	return matchingExpression;
}

// -------------------------------------------------------------------
// ChainedMatchExpression
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::ChainedMatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<short int> value, MatchExpressionValueType valueType, boost::shared_ptr<LogicOperator> logicOp, boost::shared_ptr<MatchExpression> parent)
{
	boost::shared_ptr<MatchExpression> matchingExpression (new MatchExpression(varName, condition, value, valueType));
	matchingExpression->logicOp = logicOp;
	matchingExpression->parent = parent;

	return matchingExpression;
}

// -------------------------------------------------------------------
// ChainedMatchExpression
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::ChainedMatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned short int> value, MatchExpressionValueType valueType, boost::shared_ptr<LogicOperator> logicOp, boost::shared_ptr<MatchExpression> parent)
{
	boost::shared_ptr<MatchExpression> matchingExpression (new MatchExpression(varName, condition, value, valueType));
	matchingExpression->logicOp = logicOp;
	matchingExpression->parent = parent;

	return matchingExpression;
}

// -------------------------------------------------------------------
// ChainedMatchExpression
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::ChainedMatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<int> value, MatchExpressionValueType valueType, boost::shared_ptr<LogicOperator> logicOp, boost::shared_ptr<MatchExpression> parent)
{
	boost::shared_ptr<MatchExpression> matchingExpression (new MatchExpression(varName, condition, value, valueType));
	matchingExpression->logicOp = logicOp;
	matchingExpression->parent = parent;

	return matchingExpression;
}

// -------------------------------------------------------------------
// ChainedMatchExpression
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::ChainedMatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned int> value, MatchExpressionValueType valueType, boost::shared_ptr<LogicOperator> logicOp, boost::shared_ptr<MatchExpression> parent)
{
	boost::shared_ptr<MatchExpression> matchingExpression (new MatchExpression(varName, condition, value, valueType));
	matchingExpression->logicOp = logicOp;
	matchingExpression->parent = parent;

	return matchingExpression;
}

// -------------------------------------------------------------------
// ChainedMatchExpression
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::ChainedMatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<long int> value, MatchExpressionValueType valueType, boost::shared_ptr<LogicOperator> logicOp, boost::shared_ptr<MatchExpression> parent)
{
	boost::shared_ptr<MatchExpression> matchingExpression (new MatchExpression(varName, condition, value, valueType));
	matchingExpression->logicOp = logicOp;
	matchingExpression->parent = parent;

	return matchingExpression;
}

// -------------------------------------------------------------------
// ChainedMatchExpression
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::ChainedMatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned long int> value, MatchExpressionValueType valueType, boost::shared_ptr<LogicOperator> logicOp, boost::shared_ptr<MatchExpression> parent)
{
	boost::shared_ptr<MatchExpression> matchingExpression (new MatchExpression(varName, condition, value, valueType));
	matchingExpression->logicOp = logicOp;
	matchingExpression->parent = parent;

	return matchingExpression;
}

// -------------------------------------------------------------------
// ChainedMatchExpression
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::ChainedMatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<long long> value, MatchExpressionValueType valueType, boost::shared_ptr<LogicOperator> logicOp, boost::shared_ptr<MatchExpression> parent)
{
	boost::shared_ptr<MatchExpression> matchingExpression (new MatchExpression(varName, condition, value, valueType));
	matchingExpression->logicOp = logicOp;
	matchingExpression->parent = parent;

	return matchingExpression;
}

// -------------------------------------------------------------------
// ChainedMatchExpression
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::ChainedMatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned long long> value, MatchExpressionValueType valueType, boost::shared_ptr<LogicOperator> logicOp, boost::shared_ptr<MatchExpression> parent)
{
	boost::shared_ptr<MatchExpression> matchingExpression (new MatchExpression(varName, condition, value, valueType));
	matchingExpression->logicOp = logicOp;
	matchingExpression->parent = parent;

	return matchingExpression;
}

// -------------------------------------------------------------------
// ChainedMatchExpression
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::ChainedMatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<float> value, MatchExpressionValueType valueType, boost::shared_ptr<LogicOperator> logicOp, boost::shared_ptr<MatchExpression> parent)
{
	boost::shared_ptr<MatchExpression> matchingExpression (new MatchExpression(varName, condition, value, valueType));
	matchingExpression->logicOp = logicOp;
	matchingExpression->parent = parent;

	return matchingExpression;
}

// -------------------------------------------------------------------
// ChainedMatchExpression
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::ChainedMatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<double> value, MatchExpressionValueType valueType, boost::shared_ptr<LogicOperator> logicOp, boost::shared_ptr<MatchExpression> parent)
{
	boost::shared_ptr<MatchExpression> matchingExpression (new MatchExpression(varName, condition, value, valueType));
	matchingExpression->logicOp = logicOp;
	matchingExpression->parent = parent;

	return matchingExpression;
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned char> varValue, MatchExpressionValueType valueType)
{
	this->varName = varName;
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeUnsignedChar;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<short int> varValue, MatchExpressionValueType valueType)
{
	this->varName = varName;
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeShortInt;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned short int> varValue, MatchExpressionValueType valueType)
{
	this->varName = varName;
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeUnsignedShortInt;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<int> varValue, MatchExpressionValueType valueType)
{
	this->varName = varName;
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeInt;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned int> varValue, MatchExpressionValueType valueType)
{
	this->varName = varName;
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeUnsignedInt;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}


// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<long int> varValue, MatchExpressionValueType valueType)
{
	this->varName = varName;
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeLongInt;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned long int> varValue, MatchExpressionValueType valueType)
{
	this->varName = varName;
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeUnsignedLongInt;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<long long> varValue, MatchExpressionValueType valueType)
{
	this->varName = varName;
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeLongLong;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned long long> varValue, MatchExpressionValueType valueType)
{
	this->varName = varName;
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeUnsignedLongLong;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<float> varValue, MatchExpressionValueType valueType)
{
	this->varName = varName;
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeFloat;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<double> varValue, MatchExpressionValueType valueType)
{
	this->varName = varName;
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeDouble;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned char> varValue, MatchExpressionValueType valueType)
{
	this->varName = boost::shared_ptr<string>(new string(varName));
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeUnsignedChar;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<short int> varValue, MatchExpressionValueType valueType)
{
	this->varName = boost::shared_ptr<string>(new string(varName));
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeShortInt;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned short int> varValue, MatchExpressionValueType valueType)
{
	this->varName = boost::shared_ptr<string>(new string(varName));
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeUnsignedShortInt;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<int> varValue, MatchExpressionValueType valueType)
{
	this->varName = boost::shared_ptr<string>(new string(varName));
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeInt;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned int> varValue, MatchExpressionValueType valueType)
{
	this->varName = boost::shared_ptr<string>(new string(varName));
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeUnsignedInt;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<long int> varValue, MatchExpressionValueType valueType)
{
	this->varName = boost::shared_ptr<string>(new string(varName));
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeLongInt;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned long int> varValue, MatchExpressionValueType valueType)
{
	this->varName = boost::shared_ptr<string>(new string(varName));
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeUnsignedLongInt;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<long long> varValue, MatchExpressionValueType valueType)
{
	this->varName = boost::shared_ptr<string>(new string(varName));
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeLongLong;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned long long> varValue, MatchExpressionValueType valueType)
{
	this->varName = boost::shared_ptr<string>(new string(varName));
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeUnsignedLongLong;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<float> varValue, MatchExpressionValueType valueType)
{
	this->varName = boost::shared_ptr<string>(new string(varName));
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeFloat;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
MatchExpression::MatchExpression(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<double> varValue, MatchExpressionValueType valueType)
{
	this->varName = boost::shared_ptr<string>(new string(varName));
	this->condition = condition;
	this->varValue = varValue;
	this->varValueDataType = MatchExpression::ValueTypeDouble;
	this->valueType = valueType;
	this->logicOp = boost::shared_ptr<LogicOperator>();
	this->parent = boost::shared_ptr<MatchExpression>();
	this->next = boost::shared_ptr<MatchExpression>();
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned char> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<short int> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned short int> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<int> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned int> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<long int> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned long int> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<long long> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned long long> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<float> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<double> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}


// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned char> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<short int> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned short int> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<int> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned int> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<long int> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned long int> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<long long> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned long long> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<float> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// And
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::And(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<double> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::AND, shared_from_this());
	return this->next;
}


// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned char> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<short int> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned short int> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<int> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned int> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<long int> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned long int> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<long long> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned long long> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<float> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(boost::shared_ptr<string> varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<double> varValue, MatchExpressionValueType valueType)
{
	this->next = ChainedMatchExpression(varName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned char> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<short int> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned short int> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<int> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned int> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<long int> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned long int> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<long long> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<unsigned long long> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<float> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// Or
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Or(string varName, boost::shared_ptr<IMatcher> condition, boost::shared_ptr<double> varValue, MatchExpressionValueType valueType)
{
	boost::shared_ptr<string> refVarName (new string(varName));
	this->next = ChainedMatchExpression(refVarName, condition, varValue, valueType, LogicOperator::OR, shared_from_this());
	return this->next;
}

// -------------------------------------------------------------------
// VarName
// -------------------------------------------------------------------
boost::shared_ptr<string> MatchExpression::VarName()
{
	return this->varName;
}

// -------------------------------------------------------------------
// Condition
// -------------------------------------------------------------------
boost::shared_ptr<IMatcher> MatchExpression::Condition()
{
	return this->condition;
}

// -------------------------------------------------------------------
// VarValue
// -------------------------------------------------------------------
boost::shared_ptr<void> MatchExpression::VarValue()
{
	return this->varValue;
}

// -------------------------------------------------------------------
// LogicOp
// -------------------------------------------------------------------
boost::shared_ptr<LogicOperator> MatchExpression::LogicOp()
{
	return this->logicOp;
}

// -------------------------------------------------------------------
// HasNext
// -------------------------------------------------------------------
bool MatchExpression::HasNext()
{
	return this->next != NULL;
}

// -------------------------------------------------------------------
// Next
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Next()
{
	return this->next;
}

// -------------------------------------------------------------------
// Rewind
// -------------------------------------------------------------------
boost::shared_ptr<MatchExpression> MatchExpression::Rewind()
{
	boost::shared_ptr<MatchExpression> currNode = shared_from_this();

	while (true) {
		if (currNode->parent != NULL)
			currNode = currNode->parent;
		else
			break;
	}

	return currNode;
}

// -------------------------------------------------------------------
// AsString
// -------------------------------------------------------------------
boost::shared_ptr<string> MatchExpression::AsString()
{
	boost::shared_ptr<string> returned (new string());

	if (logicOp != NULL)
		returned->append(" " + *(logicOp->Id()) + " ");

	returned->append("(");

	if (valueType == MatchExpression_ValueString)
	{
		returned->append(*varName + " " + *(condition->Symbol()) + " " + "'" + *((string*)varValue.get()) + "'");
	}
	else
	{
		char bufferVarValue[512];

		switch (varValueDataType)
		{
		case ValueTypeUnsignedChar: 
			{
				unsigned char valueNative = *((boost::static_pointer_cast<unsigned char>)(varValue));
				sprintf (bufferVarValue, "%d", (double)valueNative);
				break;
			}
		case ValueTypeShortInt:
			{
				short int valueNative = *((boost::static_pointer_cast<short int>)(varValue));
				sprintf (bufferVarValue, "%d", (double)valueNative);
				break;
			}
		case ValueTypeUnsignedShortInt:
			{
				unsigned short int valueNative = *((boost::static_pointer_cast<unsigned short int>)(varValue));
				sprintf (bufferVarValue, "%d", (double)valueNative);
				break;
			}
		case ValueTypeInt:
			{
				int valueNative = *((boost::static_pointer_cast<int>)(varValue));
				sprintf (bufferVarValue, "%d", (double)valueNative);
				break;
			}
		case ValueTypeUnsignedInt:
			{
				unsigned int valueNative = *((boost::static_pointer_cast<unsigned int>)(varValue));
				sprintf (bufferVarValue, "%d", (double)valueNative);
				break;
			}
		case ValueTypeLongInt:
			{
				long int valueNative = *((boost::static_pointer_cast<long int>)(varValue));
				sprintf (bufferVarValue, "%d", (double)valueNative);
				break;
			}
		case ValueTypeUnsignedLongInt:
			{
				unsigned long int valueNative = *((boost::static_pointer_cast<unsigned long int>)(varValue));
				sprintf (bufferVarValue, "%d", (double)valueNative);
				break;
			}
		case ValueTypeLongLong:
			{
				long long valueNative = *((boost::static_pointer_cast<long long>)(varValue));
				sprintf (bufferVarValue, "%d", (double)valueNative);
				break;
			}
		case ValueTypeUnsignedLongLong:
			{
				unsigned long long valueNative = *((boost::static_pointer_cast<unsigned long long>)(varValue));
				sprintf (bufferVarValue, "%d", (double)valueNative);
				break;
			}
		case ValueTypeFloat:
			{
				float valueNative = *((boost::static_pointer_cast<float>)(varValue));
				sprintf (bufferVarValue, "%d", (double)valueNative);
				break;
			}
		case ValueTypeDouble:
			{
				sprintf (bufferVarValue, "%d", *(boost::static_pointer_cast<double>(varValue)));
				break;
			}
		}

		string stringVarValue = bufferVarValue;

		returned->append(*varName + " " + *(condition->Symbol()) + " " + stringVarValue);
	}

	returned->append(")");

	return returned;
}

// -------------------------------------------------------------------
// ToString
// -------------------------------------------------------------------
boost::shared_ptr<string> MatchExpression::ToString()
{
	boost::shared_ptr<MatchExpression> expr = Rewind();

	boost::shared_ptr<string> sb = expr->AsString();
			
	while (expr->HasNext()) {
		expr = expr->next;

		boost::shared_ptr<string> exprString = expr->AsString();
		sb->append(*exprString.get());
	}
			
	return sb;
}

// -------------------------------------------------------------------
// ToSFSArray
// -------------------------------------------------------------------
boost::shared_ptr<ISFSArray> MatchExpression::ToSFSArray()
{
	boost::shared_ptr<MatchExpression> expr = Rewind();
			
	// Start with the main expression
	boost::shared_ptr<ISFSArray> sfsa (new SFSArray());
	sfsa->AddSFSArray(expr->ExpressionAsSFSArray());
			
	// continue with other linked expressions, if any
	while (expr->HasNext()) {
		expr = expr->Next();
		sfsa->AddSFSArray(expr->ExpressionAsSFSArray());
	}
			
	return sfsa;
}

// -------------------------------------------------------------------
// ExpressionAsSFSArray
// -------------------------------------------------------------------
boost::shared_ptr<ISFSArray> MatchExpression::ExpressionAsSFSArray()
{
	boost::shared_ptr<ISFSArray> expr (new SFSArray());

	// 0 -> Logic operator
	if (logicOp.get() != NULL)
		expr->AddUtfString(logicOp->Id());
	else
		expr->AddNull();

	// 1 -> Var name
	expr->AddUtfString(varName);

	// 2 -> Matcher type
	boost::shared_ptr<unsigned char> ptrType (new unsigned char());
	*ptrType = (unsigned char)condition->Type();
	expr->AddByte(ptrType);

	// 3 -> Condition symbol
	expr->AddUtfString(condition->Symbol());

	// 4 -> Value to match against
	if (condition->Type() == 0)
		expr->AddBool((boost::static_pointer_cast<bool>)(varValue));

	else if (condition->Type() == 1)
	{
		switch (varValueDataType)
		{
		case ValueTypeUnsignedChar: 
			{
				unsigned char valueNative = *((boost::static_pointer_cast<unsigned char>)(varValue));
				boost::shared_ptr<double> matchValueAsDouble(new double(valueNative));
				expr->AddDouble(matchValueAsDouble);
				break;
			}
		case ValueTypeShortInt:
			{
				short int valueNative = *((boost::static_pointer_cast<short int>)(varValue));
				boost::shared_ptr<double> matchValueAsDouble(new double(valueNative));
				expr->AddDouble(matchValueAsDouble);
				break;
			}
		case ValueTypeUnsignedShortInt:
			{
				unsigned short int valueNative = *((boost::static_pointer_cast<unsigned short int>)(varValue));
				boost::shared_ptr<double> matchValueAsDouble(new double(valueNative));
				expr->AddDouble(matchValueAsDouble);
				break;
			}
		case ValueTypeInt:
			{
				int valueNative = *((boost::static_pointer_cast<int>)(varValue));
				boost::shared_ptr<double> matchValueAsDouble(new double(valueNative));
				expr->AddDouble(matchValueAsDouble);
				break;
			}
		case ValueTypeUnsignedInt:
			{
				unsigned int valueNative = *((boost::static_pointer_cast<unsigned int>)(varValue));
				boost::shared_ptr<double> matchValueAsDouble(new double(valueNative));
				expr->AddDouble(matchValueAsDouble);
				break;
			}
		case ValueTypeLongInt:
			{
				long int valueNative = *((boost::static_pointer_cast<long int>)(varValue));
				boost::shared_ptr<double> matchValueAsDouble(new double(valueNative));
				expr->AddDouble(matchValueAsDouble);
				break;
			}
		case ValueTypeUnsignedLongInt:
			{
				unsigned long int valueNative = *((boost::static_pointer_cast<unsigned long int>)(varValue));
				boost::shared_ptr<double> matchValueAsDouble(new double(valueNative));
				expr->AddDouble(matchValueAsDouble);
				break;
			}
		case ValueTypeLongLong:
			{
				long long valueNative = *((boost::static_pointer_cast<long long>)(varValue));
				boost::shared_ptr<double> matchValueAsDouble(new double(valueNative));
				expr->AddDouble(matchValueAsDouble);
				break;
			}
		case ValueTypeUnsignedLongLong:
			{
				unsigned long long valueNative = *((boost::static_pointer_cast<unsigned long long>)(varValue));
				boost::shared_ptr<double> matchValueAsDouble(new double(valueNative));
				expr->AddDouble(matchValueAsDouble);
				break;
			}
		case ValueTypeFloat:
			{
				float valueNative = *((boost::static_pointer_cast<float>)(varValue));
				boost::shared_ptr<double> matchValueAsDouble(new double(valueNative));
				expr->AddDouble(matchValueAsDouble);
				break;
			}
		case ValueTypeDouble:
			{
				expr->AddDouble((boost::static_pointer_cast<double>)(varValue));
				break;
			}
		}
	}

	else
		expr->AddUtfString((boost::static_pointer_cast<string>)(varValue));

	return expr;
}

}	// namespace Match
}	// namespace Entities
}	// namespace Sfs2X


