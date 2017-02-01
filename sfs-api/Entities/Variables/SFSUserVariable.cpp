// ===================================================================
//
// Description		
//		Contains the implementation of SFSUserVariable
//
// Revision history
//		Date			Description
//		30-Nov-2012		First version
//
// ===================================================================
#include "SFSUserVariable.h"
#include <typeinfo>

namespace Sfs2X {
namespace Entities {
namespace Variables {

// -------------------------------------------------------------------
// FromSFSArray
// -------------------------------------------------------------------
boost::shared_ptr<UserVariable> SFSUserVariable::FromSFSArray(boost::shared_ptr<ISFSArray> sfsa)
{
	boost::shared_ptr<UserVariable> variable(new SFSUserVariable(
									 *(sfsa->GetUtfString(0)), 	// name
									 sfsa->GetElementAt(2),		// typed value
									 sfsa->GetByte(1)			// type id
									 ));

	return variable;
}

// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
SFSUserVariable::SFSUserVariable(string name, boost::shared_ptr<long int> val)
{
	this->name = boost::shared_ptr<string>(new string(name));
	SetValue(val);
}
SFSUserVariable::SFSUserVariable(string name, boost::shared_ptr<unsigned long int> val)
{
	this->name = boost::shared_ptr<string>(new string(name));
	SetValue(val);
}
SFSUserVariable::SFSUserVariable(string name, boost::shared_ptr<int> val)
{
	this->name = boost::shared_ptr<string>(new string(name));
	SetValue(val);
}
SFSUserVariable::SFSUserVariable(string name, boost::shared_ptr<unsigned int> val)
{
	this->name = boost::shared_ptr<string>(new string(name));
	SetValue(val);
}
SFSUserVariable::SFSUserVariable(string name, boost::shared_ptr<bool> val)
{
	this->name = boost::shared_ptr<string>(new string(name));
	SetValue(val);
}
SFSUserVariable::SFSUserVariable(string name, boost::shared_ptr<double> val)
{
	this->name = boost::shared_ptr<string>(new string(name));
	SetValue(val);
}
SFSUserVariable::SFSUserVariable(string name, boost::shared_ptr<string> val)
{
	this->name = boost::shared_ptr<string>(new string(name));
	SetValue(val);
}
SFSUserVariable::SFSUserVariable(string name, boost::shared_ptr<SFSObject> val)
{
	this->name = boost::shared_ptr<string>(new string(name));
	SetValue(val);
}
SFSUserVariable::SFSUserVariable(string name, boost::shared_ptr<SFSArray> val)
{
	this->name = boost::shared_ptr<string>(new string(name));
	SetValue(val);
}


// -------------------------------------------------------------------
// Constructor
// -------------------------------------------------------------------
SFSUserVariable::SFSUserVariable(string name, boost::shared_ptr<void> val, long int type)
{
	this->name = boost::shared_ptr<string>(new string(name));
			
	// If type is specfied let's use it
	if (type > -1) 
	{
		this->val = val;
		this->type = (VariableType)type;
	}
	// Otherwise let's autodetect the type
	else 
	{
		//SetValue(val);
	}
}

// -------------------------------------------------------------------
// Destructor
// -------------------------------------------------------------------
SFSUserVariable::~SFSUserVariable()
{
	this->name = boost::shared_ptr<string>();
	this->val = boost::shared_ptr<void>();

	/*
	switch(type)
	{
	case VARIABLETYPE_UNKNOWN :
		break;

	case VARIABLETYPE_NULL :
		break;
					
	case VARIABLETYPE_BOOL:
		(boost::static_pointer_cast<bool>)(val) = boost::shared_ptr<bool>();
		break;
					
	case VARIABLETYPE_INT:
		(boost::static_pointer_cast<long int>)(val) = boost::shared_ptr<long int>();
		break;
					
	case VARIABLETYPE_DOUBLE:
		(boost::static_pointer_cast<double>)(val) = boost::shared_ptr<double>();
		break;
					
	case VARIABLETYPE_STRING:
		(boost::static_pointer_cast<string>)(val) = boost::shared_ptr<string>();
		break;
					
	case VARIABLETYPE_OBJECT:
		(boost::static_pointer_cast<ISFSObject>)(val) = boost::shared_ptr<ISFSObject>();
		break;
					
	case VARIABLETYPE_ARRAY:
		(boost::static_pointer_cast<ISFSArray>)(val) = boost::shared_ptr<ISFSArray>();
		break;
	}
	*/
}

// -------------------------------------------------------------------
// Name
// -------------------------------------------------------------------
boost::shared_ptr<string> SFSUserVariable::Name()
{
	return name;
}

// -------------------------------------------------------------------
// Type
// -------------------------------------------------------------------
VariableType SFSUserVariable::Type()
{
	return type;
}

// -------------------------------------------------------------------
// Value
// -------------------------------------------------------------------
boost::shared_ptr<void> SFSUserVariable::Value()
{
	return val;
}

// -------------------------------------------------------------------
// GetBoolValue
// -------------------------------------------------------------------
boost::shared_ptr<bool> SFSUserVariable::GetBoolValue()
{
	return (boost::static_pointer_cast<bool>)(val);
}

// -------------------------------------------------------------------
// GetIntValue
// -------------------------------------------------------------------
boost::shared_ptr<long int> SFSUserVariable::GetIntValue()
{
	return (boost::static_pointer_cast<long int>)(val);
}

// -------------------------------------------------------------------
// GetDoubleValue
// -------------------------------------------------------------------
boost::shared_ptr<double> SFSUserVariable::GetDoubleValue()
{
	return (boost::static_pointer_cast<double>)(val);
}

// -------------------------------------------------------------------
// GetStringValue
// -------------------------------------------------------------------
boost::shared_ptr<string> SFSUserVariable::GetStringValue()
{
	return (boost::static_pointer_cast<string>)(val);
}

// -------------------------------------------------------------------
// GetSFSObjectValue
// -------------------------------------------------------------------
boost::shared_ptr<ISFSObject> SFSUserVariable::GetSFSObjectValue()
{
	return (boost::static_pointer_cast<ISFSObject>)(val);
}

// -------------------------------------------------------------------
// GetSFSArrayValue
// -------------------------------------------------------------------
boost::shared_ptr<ISFSArray> SFSUserVariable::GetSFSArrayValue()
{
	return (boost::static_pointer_cast<ISFSArray>)(val);
}

// -------------------------------------------------------------------
// IsNull
// -------------------------------------------------------------------
bool SFSUserVariable::IsNull()
{
	return type == VARIABLETYPE_NULL;
}

// -------------------------------------------------------------------
// ToSFSArray
// -------------------------------------------------------------------
boost::shared_ptr<ISFSArray> SFSUserVariable::ToSFSArray()
{
	boost::shared_ptr<ISFSArray> sfsa = SFSArray::NewInstance();
			
	// var name (0)
	sfsa->AddUtfString(name);
			
	// var type (1)
	boost::shared_ptr<unsigned char> ptrType(new unsigned char());
	*ptrType = type;
	sfsa->AddByte(ptrType);
			
	// var value (2)
	PopulateArrayWithValue(sfsa);
				
	return sfsa;
}

// -------------------------------------------------------------------
// ToString
// -------------------------------------------------------------------
boost::shared_ptr<string> SFSUserVariable::ToString()
{
	char buffer[512];

	switch (type)
	{
	case VARIABLETYPE_UNKNOWN:
		sprintf (buffer, "[UVar: %s, type: %d, value: Unknown]", name->c_str(), type);
		break;

	case VARIABLETYPE_NULL:
		sprintf (buffer, "[UVar: %s, type: %d, value: NULL]", name->c_str(), type);
		break;

	case VARIABLETYPE_BOOL:
		sprintf (buffer, "[UVar: %s, type: %d, value: %d]", name->c_str(), type, *(boost::static_pointer_cast<bool>(val)));
		break;

	case VARIABLETYPE_INT:
		sprintf (buffer, "[UVar: %s, type: %d, value: %d]", name->c_str(), type, *(boost::static_pointer_cast<long int>(val)));
		break;

	case VARIABLETYPE_DOUBLE:
		sprintf (buffer, "[UVar: %s, type: %d, value: %d]", name->c_str(), type, *(boost::static_pointer_cast<double>(val)));
		break;

	case VARIABLETYPE_STRING:
		sprintf (buffer, "[UVar: %s, type: %d, value: %s]", name->c_str(), type, (boost::static_pointer_cast<string>(val))->c_str());
		break;

	case VARIABLETYPE_OBJECT:
		sprintf (buffer, "[UVar: %s, type: %d, value: object]", name->c_str(), type);
		break;

	case VARIABLETYPE_ARRAY:
		sprintf (buffer, "[UVar: %s, type: %d, value: array]", name->c_str(), type);
		break;
	}

	boost::shared_ptr<string>returned (new string(buffer));

	return returned;
}

// -------------------------------------------------------------------
// PopulateArrayWithValue
// -------------------------------------------------------------------
void SFSUserVariable::PopulateArrayWithValue(boost::shared_ptr<ISFSArray> arr)
{
	switch(type)
	{
	case VARIABLETYPE_UNKNOWN :
		break;

	case VARIABLETYPE_NULL :
		arr->AddNull();
		break;
					
	case VARIABLETYPE_BOOL:
		arr->AddBool(GetBoolValue());
		break;
					
	case VARIABLETYPE_INT:
		arr->AddInt(GetIntValue());
		break;
					
	case VARIABLETYPE_DOUBLE:
		arr->AddDouble(GetDoubleValue());
		break;
					
	case VARIABLETYPE_STRING:
		arr->AddUtfString(GetStringValue());
		break;
					
	case VARIABLETYPE_OBJECT:
		arr->AddSFSObject(GetSFSObjectValue());
		break;
					
	case VARIABLETYPE_ARRAY:
		arr->AddSFSArray(GetSFSArrayValue());
		break;
	}
}

// -------------------------------------------------------------------
// SetValue
// -------------------------------------------------------------------
void SFSUserVariable::SetValue(boost::shared_ptr<long int> val)
{
	this->val = val;
			
	if (val == NULL) 
	{
		type = VARIABLETYPE_NULL;
	} 
	else 
	{
		type = VARIABLETYPE_INT;
	}	
}

void SFSUserVariable::SetValue(boost::shared_ptr<unsigned long int> val)
{
	this->val = val;
			
	if (val == NULL) 
	{
		type = VARIABLETYPE_NULL;
	} 
	else 
	{
		type = VARIABLETYPE_INT;
	}	
}

void SFSUserVariable::SetValue(boost::shared_ptr<int> val)
{
	this->val = val;
			
	if (val == NULL) 
	{
		type = VARIABLETYPE_NULL;
	} 
	else 
	{
		type = VARIABLETYPE_INT;
	}	
}

void SFSUserVariable::SetValue(boost::shared_ptr<unsigned int> val)
{
	this->val = val;
			
	if (val == NULL) 
	{
		type = VARIABLETYPE_NULL;
	} 
	else 
	{
		type = VARIABLETYPE_INT;
	}	
}

void SFSUserVariable::SetValue(boost::shared_ptr<bool> val)
{
	this->val = val;
			
	if (val == NULL) 
	{
		type = VARIABLETYPE_NULL;
	} 
	else 
	{
		type = VARIABLETYPE_BOOL;
	}	
}

void SFSUserVariable::SetValue(boost::shared_ptr<double> val)
{
	this->val = val;
			
	if (val == NULL) 
	{
		type = VARIABLETYPE_NULL;
	} 
	else 
	{
		type = VARIABLETYPE_DOUBLE;
	}	
}

void SFSUserVariable::SetValue(boost::shared_ptr<string> val)
{
	this->val = val;
			
	if (val == NULL) 
	{
		type = VARIABLETYPE_NULL;
	} 
	else 
	{
		type = VARIABLETYPE_STRING;
	}	
}

void SFSUserVariable::SetValue(boost::shared_ptr<SFSObject> val)
{
	this->val = val;
			
	if (val == NULL) 
	{
		type = VARIABLETYPE_NULL;
	} 
	else 
	{
		type = VARIABLETYPE_OBJECT;
	}	
}

void SFSUserVariable::SetValue(boost::shared_ptr<SFSArray> val)
{
	this->val = val;
			
	if (val == NULL) 
	{
		type = VARIABLETYPE_NULL;
	} 
	else 
	{
		type = VARIABLETYPE_ARRAY;
	}	
}

}	// namespace Variables
}	// namespace Entities
}	// namespace Sfs2X
