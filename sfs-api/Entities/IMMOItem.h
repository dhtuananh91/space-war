// ===================================================================
//
// Description		
//		Contains the definition of IMMOItem interface
//
// Revision history
//		Date			Description
//		30-Nov-2013		First version
//
// ===================================================================
#ifndef __IMMOItem__
#define __IMMOItem__

#include "../Util/Common.h"
#include "Variables/IMMOItemVariable.h"
#include "Data/Vec3D.h"

#include <boost/shared_ptr.hpp>					// Boost Asio shared pointer

#if defined(_MSC_VER)
#pragma warning(disable:4786)			// STL library: disable warning 4786; this warning is generated due to a Microsoft bug
#endif
#include <string>						// STL library: string object
#include <vector>						// STL library: vector object
using namespace std;					// STL library: declare the STL namespace

using namespace Sfs2X::Entities::Variables;
using namespace Sfs2X::Entities::Data;

namespace Sfs2X {
namespace Entities {

	/// <summary>
	/// The IMMOItem interface defines all the methods and properties that an object representing a SmartFoxServer MMOItem entity exposes.
	/// </summary>
	/// 
	/// <remarks>
	/// In the SmartFoxServer 2X client API this interface is implemented by the <see cref="MMOItem"/> class. Read the class description for additional informations.
	/// </remarks>
	/// 
	/// <seealso cref="Sfs2X.Entities.MMOItem"/>
	class DLLImportExport IMMOItem
	{
	public:
		/// <summary>
		/// Indicates the id of this item.
		/// </summary>
		/// 
		/// <remarks>
		/// The id is unique and it is generated by the server when the item is created.
		/// </remarks>
		virtual long int Id() = 0;

		virtual void Dispose() = 0;

		/// <summary>
		/// Retrieves all the MMOItem Variables of this item.
		/// </summary>
		/// 
		/// <returns>A list of objects representing the MMOItem Variables associated to this item.</returns>
		virtual boost::shared_ptr<vector<boost::shared_ptr<IMMOItemVariable> > > GetVariables() = 0;
		
		/// <summary>
		/// Retrieves an MMOItem Variable from its name.
		/// </summary>
		/// 
		/// <param name="name">The name of the MMOItem Variable to be retrieved.</param>
		/// 
		/// <returns> The object representing the MMOItem Variable, or <c>null</c> if no MMOItem Variable with the passed name is associated to this item.</returns>
		virtual boost::shared_ptr<IMMOItemVariable> GetVariable(string name) = 0;
		
		/// <exclude/>
		virtual void SetVariable(boost::shared_ptr<IMMOItemVariable> variable) = 0;
		
		/// <exclude/>
		virtual void SetVariables(boost::shared_ptr<vector<boost::shared_ptr<IMMOItemVariable> > > variables) = 0;
		
		/// <summary>
		/// Indicates whether this item has the specified MMOItem Variable set or not.
		/// </summary>
		/// 
		/// <param name="name"> The name of the MMOItem Variable whose existance must be checked.</param>
		/// 
		/// <returns><c>true</c> if a MMOItem Variable with the passed name is set for this item.</returns>
		/// 
		/// <seealso cref="Sfs2X.Entities.Variables.MMOItemVariable"/>
		virtual bool ContainsVariable(string name) = 0;

		/// <summary>
		/// Returns the entry point of this item in the current user's AoI.
		/// </summary>
		/// 
		/// <remarks>
		/// The returned coordinates are those that the item had when its presence in the current user's Area of Interest was last notified by a <see cref="Sfs2X.Core.SFSEvent.PROXIMITY_LIST_UPDATE">PROXIMITY_LIST_UPDATE</see> event.
		/// This field is populated only if the MMORoom in which the item exists is configured to receive such data.
		/// </remarks>
		///
		/// <seealso cref="Sfs2X.Requests.MMO.MMORoomSettings.SendAOIEntryPoint"/>
		/// <seealso cref="Sfs2X.Core.SFSEvent.PROXIMITY_LIST_UPDATE"/>
		virtual boost::shared_ptr<Vec3D> AOIEntryPoint() = 0;
		virtual void AOIEntryPoint(boost::shared_ptr<Vec3D> value) = 0;
	};

}	// namespace Entities
}	// namespace Sfs2X

#endif

