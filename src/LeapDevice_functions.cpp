/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "LeapDevice_functions.h"
#include "extension.h"
#include <Leap.h>

using namespace Fabric::EDK;

// Defined at src\LeapDevice.kl:30:1
FABRIC_EXT_EXPORT void LeapDevice_Destruct(
  KL::Traits< KL::LeapDevice >::IOParam this_
) {
  Handle<Leap::Device>* device = (Handle<Leap::Device>*)this_->handle;
  if(device)
  {
    delete(device);
    this_->handle = NULL;
  }
}

// Defined at src\LeapDevice.kl:64:1
FABRIC_EXT_EXPORT KL::Float32 LeapDevice_horizontalViewAngle(
  KL::Traits< KL::LeapDevice >::INParam this_
) {
  Handle<Leap::Device>* device = (Handle<Leap::Device>*)this_->handle;
  if(!device)
    return 0.0f;
  return device->t.horizontalViewAngle();
}

// Defined at src\LeapDevice.kl:80:1
FABRIC_EXT_EXPORT KL::Float32 LeapDevice_verticalViewAngle(
  KL::Traits< KL::LeapDevice >::INParam this_
) {
  Handle<Leap::Device>* device = (Handle<Leap::Device>*)this_->handle;
  if(!device)
    return 0.0f;
  return device->t.verticalViewAngle();
}

// Defined at src\LeapDevice.kl:95:1
FABRIC_EXT_EXPORT KL::Float32 LeapDevice_range(
  KL::Traits< KL::LeapDevice >::INParam this_
) {
  Handle<Leap::Device>* device = (Handle<Leap::Device>*)this_->handle;
  if(!device)
    return 0.0f;
  return device->t.range();
}

// Defined at src\LeapDevice.kl:112:1
FABRIC_EXT_EXPORT KL::Float32 LeapDevice_distanceToBoundary(
  KL::Traits< KL::LeapDevice >::INParam this_,
  KL::Traits< KL::Vec3 >::INParam position
) {
  Handle<Leap::Device>* device = (Handle<Leap::Device>*)this_->handle;
  if(!device)
    return 0.0f;
  return device->t.distanceToBoundary(Leap::Vector(position.x, position.y, position.z));
}

// Defined at src\LeapDevice.kl:122:1
FABRIC_EXT_EXPORT KL::Boolean LeapDevice_isEmbedded(
  KL::Traits< KL::LeapDevice >::INParam this_
) {
  Handle<Leap::Device>* device = (Handle<Leap::Device>*)this_->handle;
  if(!device)
    return false;
  return device->t.isEmbedded();
}

// Defined at src\LeapDevice.kl:130:1
FABRIC_EXT_EXPORT KL::Boolean LeapDevice_isStreaming(
  KL::Traits< KL::LeapDevice >::INParam this_
) {
  Handle<Leap::Device>* device = (Handle<Leap::Device>*)this_->handle;
  if(!device)
    return false;
  return device->t.isStreaming();
}

// Defined at src\LeapDevice.kl:148:1
FABRIC_EXT_EXPORT KL::Boolean LeapDevice_isFlipped(
  KL::Traits< KL::LeapDevice >::INParam this_
) {
  Handle<Leap::Device>* device = (Handle<Leap::Device>*)this_->handle;
  if(!device)
    return false;
  return device->t.isFlipped();
}

// Defined at src\LeapDevice.kl:161:1
FABRIC_EXT_EXPORT KL::UInt32 LeapDevice_deviceType(
  KL::Traits< KL::LeapDevice >::INParam this_
) {
  Handle<Leap::Device>* device = (Handle<Leap::Device>*)this_->handle;
  if(!device)
    return 0;
  return (KL::UInt32)device->t.type();
}
