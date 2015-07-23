/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "LeapHand_functions.h"
#include "extension.h"
#include <Leap.h>

using namespace Fabric::EDK;

// Defined at src\LeapHand.kl:30:1
FABRIC_EXT_EXPORT void LeapHand_Destruct(
  KL::Traits< KL::LeapHand >::IOParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(hand)
  {
    delete(hand);
    this_->handle = NULL;
  }
}

// Defined at src\LeapHand.kl:53:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::SInt32 LeapHand_id(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return 0;
  return (KL::SInt32)hand->t.id();
}

// Defined at src\LeapHand.kl:67:1
FABRIC_EXT_EXPORT void LeapHand_pointables(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::LeapPointable > >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  Leap::PointableList list = hand->t.pointables();
  _result.resize(list.count());
  for(unsigned int i=0;i<list.count();i++)
  {
    _result[i] = KL::LeapPointable::Create();
    _result[i]->handle = new Handle<Leap::Pointable>(list[i]);
  }  
}

// Defined at src\LeapHand.kl:90:1
FABRIC_EXT_EXPORT void LeapHand_pointable(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam id
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  _result = KL::LeapPointable::Create();
  _result->handle = new Handle<Leap::Pointable>(hand->t.pointable(id));
}

// Defined at src\LeapHand.kl:103:1
FABRIC_EXT_EXPORT void LeapHand_fingers(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::LeapFinger > >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  Leap::FingerList list = hand->t.fingers();
  _result.resize(list.count());
  for(unsigned int i=0;i<list.count();i++)
  {
    _result[i] = KL::LeapFinger::Create();
    _result[i]->handle = new Handle<Leap::Finger>(list[i]);
  }  
}

// Defined at src\LeapHand.kl:125:1
FABRIC_EXT_EXPORT void LeapHand_finger(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFinger >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam id
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  _result = KL::LeapFinger::Create();
  _result->handle = new Handle<Leap::Finger>(hand->t.finger(id));
}

// Defined at src\LeapHand.kl:143:1
FABRIC_EXT_EXPORT void LeapHand_tools(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::LeapTool > >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  Leap::ToolList list = hand->t.tools();
  _result.resize(list.count());
  for(unsigned int i=0;i<list.count();i++)
  {
    _result[i] = KL::LeapTool::Create();
    _result[i]->handle = new Handle<Leap::Tool>(list[i]);
  }  
}

// Defined at src\LeapHand.kl:171:1
FABRIC_EXT_EXPORT void LeapHand_tool(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapTool >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam id
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  _result = KL::LeapTool::Create();
  _result->handle = new Handle<Leap::Tool>(hand->t.tool(id));
}

// Defined at src\LeapHand.kl:181:1
FABRIC_EXT_EXPORT void LeapHand_palmPosition(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  Leap::Vector result = hand->t.palmPosition();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapHand.kl:197:1
FABRIC_EXT_EXPORT void LeapHand_stabilizedPalmPosition(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  Leap::Vector result = hand->t.stabilizedPalmPosition();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapHand.kl:207:1
FABRIC_EXT_EXPORT void LeapHand_palmVelocity(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  Leap::Vector result = hand->t.palmVelocity();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapHand.kl:226:1
FABRIC_EXT_EXPORT void LeapHand_palmNormal(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  Leap::Vector result = hand->t.palmNormal();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapHand.kl:236:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapHand_palmWidth(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return 0.0f;
  return hand->t.palmWidth();
}

// Defined at src\LeapHand.kl:252:1
FABRIC_EXT_EXPORT void LeapHand_direction(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  Leap::Vector result = hand->t.direction();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapHand.kl:273:1
FABRIC_EXT_EXPORT void LeapHand_basis(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Mat44 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  Leap::Matrix result = hand->t.basis();
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

// Defined at src\LeapHand.kl:286:1
FABRIC_EXT_EXPORT void LeapHand_arm(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapArm >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  _result = KL::LeapArm::Create();
  _result->handle = new Handle<Leap::Arm>(hand->t.arm());
}

// Defined at src\LeapHand.kl:294:1
FABRIC_EXT_EXPORT void LeapHand_wristPosition(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  Leap::Vector result = hand->t.wristPosition();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapHand.kl:309:1
FABRIC_EXT_EXPORT void LeapHand_sphereCenter(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  Leap::Vector result = hand->t.sphereCenter();
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapHand.kl:322:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapHand_sphereRadius(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return 0.0f;
  return hand->t.sphereRadius();
}

// Defined at src\LeapHand.kl:337:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapHand_pinchStrength(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return 0.0f;
  return hand->t.pinchStrength();
}

// Defined at src\LeapHand.kl:351:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapHand_grabStrength(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return 0.0f;
  return hand->t.grabStrength();
}

// Defined at src\LeapHand.kl:372:1
FABRIC_EXT_EXPORT void LeapHand_translation(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return;
  Leap::Vector result = hand->t.translation(sinceFrame_->t);
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapHand.kl:390:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapHand_translationProbability(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return 0.0f;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return 0.0f;
  return hand->t.translationProbability(sinceFrame_->t);
}

// Defined at src\LeapHand.kl:411:1
FABRIC_EXT_EXPORT void LeapHand_rotationAxis(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return;
  Leap::Vector result = hand->t.rotationAxis(sinceFrame_->t);
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapHand.kl:434:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapHand_rotationAngle(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return 0.0f;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return 0.0f;
  return hand->t.rotationAngle(sinceFrame_->t);
}

// Defined at src\LeapHand.kl:434:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapHand_rotationAngle_withAxis(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::INParam axis
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return 0.0f;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return 0.0f;
  Leap::Vector cAxis;
  cAxis.x = axis.x;
  cAxis.y = axis.y;
  cAxis.z = axis.z; 
  return hand->t.rotationAngle(sinceFrame_->t, cAxis);
}

// Defined at src\LeapHand.kl:477:1
FABRIC_EXT_EXPORT void LeapHand_rotationMatrix(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Mat44 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return;
  Leap::Matrix result = hand->t.rotationMatrix(sinceFrame_->t);
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

// Defined at src\LeapHand.kl:495:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapHand_rotationProbability(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return 0.0f;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return 0.0f;
  return hand->t.rotationProbability(sinceFrame_->t);
}

// Defined at src\LeapHand.kl:521:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapHand_scaleFactor(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return 0.0f;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return 0.0f;
  return hand->t.scaleFactor(sinceFrame_->t);
}

// Defined at src\LeapHand.kl:539:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapHand_scaleProbability(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return 0.0f;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return 0.0f;
  return hand->t.scaleProbability(sinceFrame_->t);
}

// Defined at src\LeapHand.kl:549:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapHand_timeVisible(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return 0.0f;
  return hand->t.timeVisible();
}

// Defined at src\LeapHand.kl:560:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapHand_confidence(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return 0.0f;
  return hand->t.confidence();
}

// Defined at src\LeapHand.kl:570:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean LeapHand_isLeft(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return false;
  return hand->t.isLeft();
}

// Defined at src\LeapHand.kl:580:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean LeapHand_isRight(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::INParam this_
) {
  Handle<Leap::Hand>* hand = (Handle<Leap::Hand>*)this_->handle;
  if(!hand)
    return false;
  return hand->t.isRight();
}
