/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "LeapInteractionBox_functions.h"
#include "extension.h"
#include <Leap.h>

using namespace Fabric::EDK;

// Defined at src\LeapInteractionBox.kl:11:1
FABRIC_EXT_EXPORT void LeapInteractionBox_Destruct(
  KL::Traits< KL::LeapInteractionBox >::IOParam this_
) {
  Handle<Leap::InteractionBox>* box = (Handle<Leap::InteractionBox>*)this_->handle;
  if(box)
  {
    delete(box);
    this_->handle = NULL;
  }
}

// Defined at src\LeapInteractionBox.kl:34:1
FABRIC_EXT_EXPORT void LeapInteractionBox_normalizePoint(
  KL::Traits< KL::Vec3 >::Result _result,
  KL::Traits< KL::LeapInteractionBox >::INParam this_,
  KL::Traits< KL::Vec3 >::INParam position,
  KL::Traits< KL::Boolean >::INParam clamp
) {
  Handle<Leap::InteractionBox>* box = (Handle<Leap::InteractionBox>*)this_->handle;
  if(!box)  
    return;
  Leap::Vector result = box->t.normalizePoint(Leap::Vector(position.x, position.y, position.z), clamp);
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapInteractionBox.kl:48:1
FABRIC_EXT_EXPORT void LeapInteractionBox_denormalizePoint(
  KL::Traits< KL::Vec3 >::Result _result,
  KL::Traits< KL::LeapInteractionBox >::INParam this_,
  KL::Traits< KL::Vec3 >::INParam normalizedPosition
) {
  Handle<Leap::InteractionBox>* box = (Handle<Leap::InteractionBox>*)this_->handle;
  if(!box)  
    return;
  Leap::Vector result = box->t.denormalizePoint(Leap::Vector(normalizedPosition.x, normalizedPosition.y, normalizedPosition.z));
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapInteractionBox.kl:59:1
FABRIC_EXT_EXPORT void LeapInteractionBox_center(
  KL::Traits< KL::Vec3 >::Result _result,
  KL::Traits< KL::LeapInteractionBox >::INParam this_
) {
  Handle<Leap::InteractionBox>* box = (Handle<Leap::InteractionBox>*)this_->handle;
  if(!box)  
    return;
  Leap::Vector result = box->t.center();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapInteractionBox.kl:69:1
FABRIC_EXT_EXPORT KL::Float32 LeapInteractionBox_width(
  KL::Traits< KL::LeapInteractionBox >::INParam this_
) {
  Handle<Leap::InteractionBox>* box = (Handle<Leap::InteractionBox>*)this_->handle;
  if(!box)  
    return 0.0f;
  return box->t.width();
}

// Defined at src\LeapInteractionBox.kl:79:1
FABRIC_EXT_EXPORT KL::Float32 LeapInteractionBox_height(
  KL::Traits< KL::LeapInteractionBox >::INParam this_
) {
  Handle<Leap::InteractionBox>* box = (Handle<Leap::InteractionBox>*)this_->handle;
  if(!box)  
    return 0.0f;
  return box->t.height();
}

// Defined at src\LeapInteractionBox.kl:89:1
FABRIC_EXT_EXPORT KL::Float32 LeapInteractionBox_depth(
  KL::Traits< KL::LeapInteractionBox >::INParam this_
) {
  Handle<Leap::InteractionBox>* box = (Handle<Leap::InteractionBox>*)this_->handle;
  if(!box)  
    return 0.0f;
  return box->t.depth();
}
