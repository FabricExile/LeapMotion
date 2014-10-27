/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "LeapFinger_functions.h"
#include "extension.h"
#include <Leap.h>

using namespace Fabric::EDK;

// Defined at src\LeapFinger.kl:32:1
FABRIC_EXT_EXPORT void LeapFinger_Destruct(
  KL::Traits< KL::LeapFinger >::IOParam this_
) {
  Handle<Leap::Finger>* finger = (Handle<Leap::Finger>*)this_->handle;
  if(finger)
  {
    delete(finger);
    this_->handle = NULL;
  }
}

// Defined at src\LeapFinger.kl:63:1
FABRIC_EXT_EXPORT void LeapFinger_bone(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapBone >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFinger >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::UInt32 >::INParam boneIx
) {
  Handle<Leap::Finger>* finger = (Handle<Leap::Finger>*)this_->handle;
  if(!finger)
    return;
  _result = KL::LeapBone::Create();
  _result->handle = new Handle<Leap::Bone>(finger->t.bone((Leap::Bone::Type)boneIx));
}

// Defined at src\LeapFinger.kl:74:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::UInt32 LeapFinger_fingerType(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFinger >::INParam this_
) {
  Handle<Leap::Finger>* finger = (Handle<Leap::Finger>*)this_->handle;
  if(!finger)
    return 0;
  return (KL::UInt32)finger->t.type();
}