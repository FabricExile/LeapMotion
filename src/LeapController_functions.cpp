/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "LeapController_functions.h"
#include <Leap.h>

using namespace Fabric::EDK;

// Defined at src\LeapController.kl:53:1
FABRIC_EXT_EXPORT void LeapController_Construct(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapController >::IOParam this_
) {
  this_->handle = new Leap::Controller();
}

// Defined at src\LeapController.kl:56:1
FABRIC_EXT_EXPORT void LeapController_Destruct(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapController >::IOParam this_
) {
  Leap::Controller * controller = (Leap::Controller*)this_->handle;
  if(controller)
  {
    delete(controller);
    this_->handle = NULL;
  }
}

// Defined at src\LeapController.kl:75:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean LeapController_isConnected(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapController >::INParam this_
) {
  Leap::Controller * controller = (Leap::Controller*)this_->handle;
  if(!controller)
    return false;
  return controller->isConnected();
}

// Defined at src\LeapController.kl:82:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean LeapController_isServiceConnected(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapController >::INParam this_
) {
  Leap::Controller * controller = (Leap::Controller*)this_->handle;
  if(!controller)
    return false;
  return controller->isServiceConnected();
}

// Defined at src\LeapController.kl:99:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean LeapController_hasFocus(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapController >::INParam this_
) {
  Leap::Controller * controller = (Leap::Controller*)this_->handle;
  if(!controller)
    return false;
  return controller->hasFocus();
}

// Defined at src\LeapController.kl:180:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::UInt32 LeapController_policyFlags(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapController >::INParam this_
) {
  Leap::Controller * controller = (Leap::Controller*)this_->handle;
  if(!controller)
    return 0;
  return (Fabric::EDK::KL::UInt32)controller->policyFlags();
}

// Defined at src\LeapController.kl:199:1
FABRIC_EXT_EXPORT void LeapController_setPolicyFlags(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::UInt32 >::INParam flags
) {
  Leap::Controller * controller = (Leap::Controller*)this_->handle;
  if(!controller)
    return;
  controller->setPolicyFlags((Leap::Controller::PolicyFlag)flags);
}

// Defined at src\LeapController.kl:222:1
FABRIC_EXT_EXPORT void LeapController_frame(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam history
) {
  Leap::Controller * controller = (Leap::Controller*)this_->handle;
  if(!controller)
    return;
  // todo
}

// Defined at src\LeapController.kl:237:1
FABRIC_EXT_EXPORT void LeapController_config(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapConfig >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapController >::INParam this_
) {
  Leap::Controller * controller = (Leap::Controller*)this_->handle;
  if(!controller)
    return;
  // todo
}

// Defined at src\LeapController.kl:254:1
FABRIC_EXT_EXPORT void LeapController_devices(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::LeapDevice > >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapController >::INParam this_
) {
  Leap::Controller * controller = (Leap::Controller*)this_->handle;
  if(!controller)
    return;
  // todo
}

// Defined at src\LeapController.kl:259:1
FABRIC_EXT_EXPORT void LeapController_locatedScreens(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::LeapScreen > >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapController >::INParam this_
) {
  Leap::Controller * controller = (Leap::Controller*)this_->handle;
  if(!controller)
    return;
  // todo
}

// Defined at src\LeapController.kl:280:1
FABRIC_EXT_EXPORT void LeapController_enableGesture(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::UInt32 >::INParam gesture,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Boolean >::INParam enable
) {
  Leap::Controller * controller = (  Leap::Controller*)this_->handle;
  if(!controller)
    return;
  controller->enableGesture((Leap::Gesture::Type)gesture, enable);
}

// Defined at src\LeapController.kl:292:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean LeapController_isGestureEnabled(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapController >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::UInt32 >::INParam gesture
) {
  Leap::Controller * controller = (Leap::Controller*)this_->handle;
  if(!controller)
    return false;
  return controller->isGestureEnabled((Leap::Gesture::Type)gesture);
}
