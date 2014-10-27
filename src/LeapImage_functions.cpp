/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "LeapImage_functions.h"
#include "extension.h"
#include <Leap.h>

using namespace Fabric::EDK;

// Defined at src\LeapImage.kl:30:1
FABRIC_EXT_EXPORT void LeapImage_Destruct(
  KL::Traits< KL::LeapImage >::IOParam this_
) {
  Handle<Leap::Image>* image = (Handle<Leap::Image>*)this_->handle;
  if(image)
  {
    delete(image);
    this_->handle = NULL;
  }
}
