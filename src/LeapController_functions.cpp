/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "LeapController_functions.h"
#include "extension.h"
#include <Leap.h>

using namespace Fabric::EDK;

// Defined at src\LeapController.kl:53:1
FABRIC_EXT_EXPORT void LeapController_Construct(
  KL::Traits< KL::LeapController >::IOParam this_
) {
  this_->handle = new Handle<Leap::Controller>();
}

// Defined at src\LeapController.kl:56:1
FABRIC_EXT_EXPORT void LeapController_Destruct(
  KL::Traits< KL::LeapController >::IOParam this_
) {
  Handle<Leap::Controller>* controller = (Handle<Leap::Controller>*)this_->handle;
  if(controller)
  {
    delete(controller);
    this_->handle = NULL;
  }
}

// Defined at src\LeapController.kl:75:1
FABRIC_EXT_EXPORT KL::Boolean LeapController_isConnected(
  KL::Traits< KL::LeapController >::INParam this_
) {
  Handle<Leap::Controller>* controller = (Handle<Leap::Controller>*)this_->handle;
  if(!controller)
    return false;
  return controller->t.isConnected();
}

// Defined at src\LeapController.kl:82:1
FABRIC_EXT_EXPORT KL::Boolean LeapController_isServiceConnected(
  KL::Traits< KL::LeapController >::INParam this_
) {
  Handle<Leap::Controller>* controller = (Handle<Leap::Controller>*)this_->handle;
  if(!controller)
    return false;
  return controller->t.isServiceConnected();
}

// Defined at src\LeapController.kl:99:1
FABRIC_EXT_EXPORT KL::Boolean LeapController_hasFocus(
  KL::Traits< KL::LeapController >::INParam this_
) {
  Handle<Leap::Controller>* controller = (Handle<Leap::Controller>*)this_->handle;
  if(!controller)
    return false;
  return controller->t.hasFocus();
}

// Defined at src\LeapController.kl:180:1
FABRIC_EXT_EXPORT KL::UInt32 LeapController_policyFlags(
  KL::Traits< KL::LeapController >::INParam this_
) {
  Handle<Leap::Controller>* controller = (Handle<Leap::Controller>*)this_->handle;
  if(!controller)
    return 0;
  return (KL::UInt32)controller->t.policyFlags();
}

// Defined at src\LeapController.kl:199:1
FABRIC_EXT_EXPORT void LeapController_setPolicyFlags(
  KL::Traits< KL::LeapController >::INParam this_,
  KL::Traits< KL::UInt32 >::INParam flags
) {
  Handle<Leap::Controller>* controller = (Handle<Leap::Controller>*)this_->handle;
  if(!controller)
    return;
  controller->t.setPolicyFlags((Leap::Controller::PolicyFlag)flags);
}

// Defined at src\LeapController.kl:222:1
FABRIC_EXT_EXPORT void LeapController_frame(
  KL::Traits< KL::LeapFrame >::Result _result,
  KL::Traits< KL::LeapController >::INParam this_,
  KL::Traits< KL::SInt32 >::INParam history
) {
  Handle<Leap::Controller>* controller = (Handle<Leap::Controller>*)this_->handle;
  if(!controller)
    return;
  _result = KL::LeapFrame::Create();
  _result->handle = new Handle<Leap::Frame>(controller->t.frame(history));
}

// Defined at src\LeapController.kl:237:1
FABRIC_EXT_EXPORT void LeapController_config(
  KL::Traits< KL::LeapConfig >::Result _result,
  KL::Traits< KL::LeapController >::INParam this_
) {
  Handle<Leap::Controller>* controller = (Handle<Leap::Controller>*)this_->handle;
  if(!controller)
    return;
  _result = KL::LeapConfig::Create();
  _result->handle = new Handle<Leap::Config>(controller->t.config());
}

// Defined at src\LeapController.kl:254:1
FABRIC_EXT_EXPORT void LeapController_devices(
  KL::Traits< KL::VariableArray< KL::LeapDevice > >::Result _result,
  KL::Traits< KL::LeapController >::INParam this_
) {
  Handle<Leap::Controller>* controller = (Handle<Leap::Controller>*)this_->handle;
  if(!controller)
    return;
  Leap::DeviceList list = controller->t.devices();
  _result.resize(list.count());
  for(unsigned int i=0;i<list.count();i++)
  {
    _result[i] = KL::LeapDevice::Create();
    _result[i]->handle = new Handle<Leap::Device>(list[i]);
  }  
}

// Defined at src\LeapController.kl:259:1
FABRIC_EXT_EXPORT void LeapController_locatedScreens(
  KL::Traits< KL::VariableArray< KL::LeapScreen > >::Result _result,
  KL::Traits< KL::LeapController >::INParam this_
) {
  Handle<Leap::Controller>* controller = (Handle<Leap::Controller>*)this_->handle;
  if(!controller)
    return;
  Leap::ScreenList list = controller->t.locatedScreens();
  _result.resize(list.count());
  for(unsigned int i=0;i<list.count();i++)
  {
    _result[i] = KL::LeapScreen::Create();
    _result[i]->handle = new Handle<Leap::Screen>(list[i]);
  }  
}

// Defined at src\LeapController.kl:280:1
FABRIC_EXT_EXPORT void LeapController_enableGesture(
  KL::Traits< KL::LeapController >::INParam this_,
  KL::Traits< KL::UInt32 >::INParam gesture,
  KL::Traits< KL::Boolean >::INParam enable
) {
  Handle<Leap::Controller>* controller = (  Handle<Leap::Controller>*)this_->handle;
  if(!controller)
    return;
  controller->t.enableGesture((Leap::Gesture::Type)gesture, enable);
}

// Defined at src\LeapController.kl:292:1
FABRIC_EXT_EXPORT KL::Boolean LeapController_isGestureEnabled(
  KL::Traits< KL::LeapController >::INParam this_,
  KL::Traits< KL::UInt32 >::INParam gesture
) {
  Handle<Leap::Controller>* controller = (Handle<Leap::Controller>*)this_->handle;
  if(!controller)
    return false;
  return controller->t.isGestureEnabled((Leap::Gesture::Type)gesture);
}
