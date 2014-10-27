/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "LeapBone_functions.h"
#include "extension.h"
#include <Leap.h>

using namespace Fabric::EDK;

// Defined at src\LeapBone.kl:34:1
FABRIC_EXT_EXPORT void LeapBone_Destruct(
  KL::Traits< KL::LeapBone >::IOParam this_
) {
  Handle<Leap::Bone>* bone = (Handle<Leap::Bone>*)this_->handle;
  if(bone)
  {
    delete(bone);
    this_->handle = NULL;
  }
}

// Defined at src\LeapBone.kl:64:1
FABRIC_EXT_EXPORT void LeapBone_prevJoint(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapBone >::INParam this_
) {
  Handle<Leap::Bone>* bone = (Handle<Leap::Bone>*)this_->handle;
  if(!bone)
    return;
  Leap::Vector result = bone->t.prevJoint();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapBone.kl:76:1
FABRIC_EXT_EXPORT void LeapBone_nextJoint(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapBone >::INParam this_
) {
  Handle<Leap::Bone>* bone = (Handle<Leap::Bone>*)this_->handle;
  if(!bone)
    return;
  Leap::Vector result = bone->t.nextJoint();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapBone.kl:86:1
FABRIC_EXT_EXPORT void LeapBone_center(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapBone >::INParam this_
) {
  Handle<Leap::Bone>* bone = (Handle<Leap::Bone>*)this_->handle;
  if(!bone)
    return;
  Leap::Vector result = bone->t.center();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapBone.kl:96:1
FABRIC_EXT_EXPORT void LeapBone_direction(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapBone >::INParam this_
) {
  Handle<Leap::Bone>* bone = (Handle<Leap::Bone>*)this_->handle;
  if(!bone)
    return;
  Leap::Vector result = bone->t.direction();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapBone.kl:106:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapBone_length(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapBone >::INParam this_
) {
  Handle<Leap::Bone>* bone = (Handle<Leap::Bone>*)this_->handle;
  if(!bone)
    return 0.0f;
  return bone->t.length();
}

// Defined at src\LeapBone.kl:116:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapBone_width(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapBone >::INParam this_
) {
  Handle<Leap::Bone>* bone = (Handle<Leap::Bone>*)this_->handle;
  if(!bone)
    return 0.0f;
  return bone->t.width();
}

// Defined at src\LeapBone.kl:127:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::UInt32 LeapBone_boneType(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapBone >::INParam this_
) {
  Handle<Leap::Bone>* bone = (Handle<Leap::Bone>*)this_->handle;
  if(!bone)
    return 0;
  return (KL::UInt32)bone->t.type();
}

// Defined at src\LeapBone.kl:162:1
FABRIC_EXT_EXPORT void LeapBone_basis(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Mat44 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapBone >::INParam this_
) {
  Handle<Leap::Bone>* bone = (Handle<Leap::Bone>*)this_->handle;
  if(!bone)
    return;
  Leap::Matrix result = bone->t.basis();
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
