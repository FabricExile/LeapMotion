/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "LeapPointable_functions.h"
#include "extension.h"
#include <Leap.h>

using namespace Fabric::EDK;

// Defined at src\LeapPointable.kl:39:1
FABRIC_EXT_EXPORT void LeapPointable_Destruct(
  KL::Traits< KL::LeapPointable >::IOParam this_
) {
  Handle<Leap::Pointable>* pointable = (Handle<Leap::Pointable>*)this_->handle;
  if(pointable)
  {
    delete(pointable);
    this_->handle = NULL;
  }
}

// Defined at src\LeapPointable.kl:83:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::SInt32 LeapPointable_id(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::INParam this_
) {
  Handle<Leap::Pointable>* pointable = (Handle<Leap::Pointable>*)this_->handle;
  if(!pointable)
    return 0;
  return pointable->t.id();
}

// Defined at src\LeapPointable.kl:93:1
FABRIC_EXT_EXPORT void LeapPointable_tipPosition(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::INParam this_
) {
  Handle<Leap::Pointable>* pointable = (Handle<Leap::Pointable>*)this_->handle;
  if(!pointable)
    return;
  Leap::Vector result = pointable->t.tipPosition();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapPointable.kl:103:1
FABRIC_EXT_EXPORT void LeapPointable_tipVelocity(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::INParam this_
) {
  Handle<Leap::Pointable>* pointable = (Handle<Leap::Pointable>*)this_->handle;
  if(!pointable)
    return;
  Leap::Vector result = pointable->t.tipVelocity();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapPointable.kl:119:1
FABRIC_EXT_EXPORT void LeapPointable_direction(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::INParam this_
) {
  Handle<Leap::Pointable>* pointable = (Handle<Leap::Pointable>*)this_->handle;
  if(!pointable)
    return;
  Leap::Vector result = pointable->t.direction();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapPointable.kl:129:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapPointable_width(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::INParam this_
) {
  Handle<Leap::Pointable>* pointable = (Handle<Leap::Pointable>*)this_->handle;
  if(!pointable)
    return 0.0f;
  return pointable->t.width();
}

// Defined at src\LeapPointable.kl:139:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapPointable_length(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::INParam this_
) {
  Handle<Leap::Pointable>* pointable = (Handle<Leap::Pointable>*)this_->handle;
  if(!pointable)
    return 0.0f;
  return pointable->t.length();
}

// Defined at src\LeapPointable.kl:149:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean LeapPointable_isFinger(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::INParam this_
) {
  Handle<Leap::Pointable>* pointable = (Handle<Leap::Pointable>*)this_->handle;
  if(!pointable)
    return false;
  return pointable->t.isFinger();
}

// Defined at src\LeapPointable.kl:159:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean LeapPointable_isTool(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::INParam this_
) {
  Handle<Leap::Pointable>* pointable = (Handle<Leap::Pointable>*)this_->handle;
  if(!pointable)
    return false;
  return pointable->t.isTool();
}

// Defined at src\LeapPointable.kl:173:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean LeapPointable_isExtended(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::INParam this_
) {
  Handle<Leap::Pointable>* pointable = (Handle<Leap::Pointable>*)this_->handle;
  if(!pointable)
    return false;
  return pointable->t.isExtended();
}

// Defined at src\LeapPointable.kl:201:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::UInt32 LeapPointable_touchZone(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::INParam this_
) {
  Handle<Leap::Pointable>* pointable = (Handle<Leap::Pointable>*)this_->handle;
  if(!pointable)
    return 0;
  return (KL::UInt32)pointable->t.touchZone();
}

// Defined at src\LeapPointable.kl:224:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapPointable_touchDistance(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::INParam this_
) {
  Handle<Leap::Pointable>* pointable = (Handle<Leap::Pointable>*)this_->handle;
  if(!pointable)
    return 0.0f;
  return pointable->t.touchDistance();
}

// Defined at src\LeapPointable.kl:240:1
FABRIC_EXT_EXPORT void LeapPointable_stabilizedTipPosition(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::INParam this_
) {
  Handle<Leap::Pointable>* pointable = (Handle<Leap::Pointable>*)this_->handle;
  if(!pointable)
    return;
  Leap::Vector result = pointable->t.stabilizedTipPosition();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapPointable.kl:250:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapPointable_timeVisible(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::INParam this_
) {
  Handle<Leap::Pointable>* pointable = (Handle<Leap::Pointable>*)this_->handle;
  if(!pointable)
    return 0.0f;
  return pointable->t.timeVisible();
}
