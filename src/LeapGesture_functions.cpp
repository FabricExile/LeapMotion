/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "LeapGesture_functions.h"
#include "extension.h"
#include <Leap.h>

using namespace Fabric::EDK;

// Defined at src\LeapGesture.kl:84:1
FABRIC_EXT_EXPORT void LeapGesture_Destruct(
  KL::Traits< KL::LeapGesture >::IOParam this_
) {
  Handle<Leap::Gesture>* gesture = (Handle<Leap::Gesture>*)this_->handle;
  if(gesture)
  {
    delete(gesture);
    this_->handle = NULL;
  }
}

// Defined at src\LeapGesture.kl:147:1
FABRIC_EXT_EXPORT KL::SInt32 LeapGesture_gestureType(
  KL::Traits< KL::LeapGesture >::INParam this_
) {
  Handle<Leap::Gesture>* gesture = (Handle<Leap::Gesture>*)this_->handle;
  if(!gesture)
    return 0;
  return (KL::SInt32)gesture->t.type();
}

// Defined at src\LeapGesture.kl:161:1
FABRIC_EXT_EXPORT KL::SInt32 LeapGesture_state(
  KL::Traits< KL::LeapGesture >::INParam this_
) {
  Handle<Leap::Gesture>* gesture = (Handle<Leap::Gesture>*)this_->handle;
  if(!gesture)
    return 0;
  return (KL::SInt32)gesture->t.state();
}

// Defined at src\LeapGesture.kl:175:1
FABRIC_EXT_EXPORT KL::SInt32 LeapGesture_id(
  KL::Traits< KL::LeapGesture >::INParam this_
) {
  Handle<Leap::Gesture>* gesture = (Handle<Leap::Gesture>*)this_->handle;
  if(!gesture)
    return 0;
  return (KL::SInt32)gesture->t.id();
}

// Defined at src\LeapGesture.kl:191:1
FABRIC_EXT_EXPORT KL::SInt64 LeapGesture_duration(
  KL::Traits< KL::LeapGesture >::INParam this_
) {
  Handle<Leap::Gesture>* gesture = (Handle<Leap::Gesture>*)this_->handle;
  if(!gesture)
    return 0;
  return (KL::SInt32)gesture->t.duration();
}

// Defined at src\LeapGesture.kl:202:1
FABRIC_EXT_EXPORT KL::Float32 LeapGesture_durationSeconds(
  KL::Traits< KL::LeapGesture >::INParam this_
) {
  Handle<Leap::Gesture>* gesture = (Handle<Leap::Gesture>*)this_->handle;
  if(!gesture)
    return 0.0f;
  return (KL::Float32)gesture->t.durationSeconds();
}

// Defined at src\LeapGesture.kl:214:1
FABRIC_EXT_EXPORT void LeapGesture_hands(
  KL::Traits< KL::VariableArray< KL::LeapHand > >::Result _result,
  KL::Traits< KL::LeapGesture >::INParam this_
) {
  Handle<Leap::Gesture>* gesture = (Handle<Leap::Gesture>*)this_->handle;
  if(!gesture)
    return;
  Leap::HandList list = gesture->t.hands();
  _result.resize(list.count());
  for(unsigned int i=0;i<list.count();i++)
  {
    _result[i] = KL::LeapHand::Create();
    _result[i]->handle = new Handle<Leap::Hand>(list[i]);
  }  
}

// Defined at src\LeapGesture.kl:226:1
FABRIC_EXT_EXPORT void LeapGesture_pointables(
  KL::Traits< KL::VariableArray< KL::LeapPointable > >::Result _result,
  KL::Traits< KL::LeapGesture >::INParam this_
) {
  Handle<Leap::Gesture>* gesture = (Handle<Leap::Gesture>*)this_->handle;
  if(!gesture)
    return;
  Leap::PointableList list = gesture->t.pointables();
  _result.resize(list.count());
  for(unsigned int i=0;i<list.count();i++)
  {
    _result[i] = KL::LeapPointable::Create();
    _result[i]->handle = new Handle<Leap::Pointable>(list[i]);
  }  
}
