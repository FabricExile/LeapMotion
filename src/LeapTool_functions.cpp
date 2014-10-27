/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "LeapTool_functions.h"
#include "extension.h"
#include <Leap.h>

using namespace Fabric::EDK;

// Defined at src\LeapTool.kl:27:1
FABRIC_EXT_EXPORT void LeapTool_Destruct(
  KL::Traits< KL::LeapTool >::IOParam this_
) {
  Handle<Leap::Tool>* tool = (Handle<Leap::Tool>*)this_->handle;
  if(tool)
  {
    delete(tool);
    this_->handle = NULL;
  }
}
