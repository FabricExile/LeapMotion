/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "LeapArm_functions.h"
#include "extension.h"
#include <Leap.h>

using namespace Fabric::EDK;

// Defined at src\LeapArm.kl:17:1
FABRIC_EXT_EXPORT void LeapArm_Destruct(
  KL::Traits< KL::LeapArm >::IOParam this_
) {
  Handle<Leap::Arm>* arm = (Handle<Leap::Arm>*)this_->handle;
  if(arm)
  {
    delete(arm);
    this_->handle = NULL;
  }
}

// Defined at src\LeapArm.kl:32:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapArm_width(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapArm >::INParam this_
) {
  Handle<Leap::Arm>* arm = (Handle<Leap::Arm>*)this_->handle;
  if(!arm)
    return 0.0f;
  return arm->t.width();
}

// Defined at src\LeapArm.kl:41:1
FABRIC_EXT_EXPORT void LeapArm_direction(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapArm >::INParam this_
) {
  Handle<Leap::Arm>* arm = (Handle<Leap::Arm>*)this_->handle;
  if(!arm)
    return;
  Leap::Vector result = arm->t.direction();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapArm.kl:73:1
FABRIC_EXT_EXPORT void LeapArm_basis(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Mat44 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapArm >::INParam this_
) {
  Handle<Leap::Arm>* arm = (Handle<Leap::Arm>*)this_->handle;
  if(!arm)
    return;
  Leap::Matrix result = arm->t.basis();
  _result.row0.x = result.xBasis.x;
  _result.row1.x = result.xBasis.y;
  _result.row2.x = result.xBasis.z;
  _result.row0.y = result.yBasis.x;
  _result.row1.y = result.yBasis.y;
  _result.row2.y = result.yBasis.z;
  _result.row0.z = result.zBasis.x;
  _result.row1.z = result.zBasis.y;
  _result.row2.z = result.zBasis.z;
  _result.row0.t = result.origin.x;
  _result.row1.t = result.origin.y;
  _result.row2.t = result.origin.z;
}

// Defined at src\LeapArm.kl:85:1
FABRIC_EXT_EXPORT void LeapArm_elbowPosition(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapArm >::INParam this_
) {
  Handle<Leap::Arm>* arm = (Handle<Leap::Arm>*)this_->handle;
  if(!arm)
    return;
  Leap::Vector result = arm->t.elbowPosition();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapArm.kl:98:1
FABRIC_EXT_EXPORT void LeapArm_wristPosition(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapArm >::INParam this_
) {
  Handle<Leap::Arm>* arm = (Handle<Leap::Arm>*)this_->handle;
  if(!arm)
    return;
  Leap::Vector result = arm->t.wristPosition();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapArm.kl:108:1
FABRIC_EXT_EXPORT void LeapArm_center(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapArm >::INParam this_
) {
  Handle<Leap::Arm>* arm = (Handle<Leap::Arm>*)this_->handle;
  if(!arm)
    return;
  Leap::Vector result = arm->t.center();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}
