/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "LeapFrame_functions.h"
#include "extension.h"
#include <Leap.h>

using namespace Fabric::EDK;

// Defined at src\LeapFrame.kl:27:1
FABRIC_EXT_EXPORT void LeapFrame_Destruct(
  KL::Traits< KL::LeapFrame >::IOParam this_
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(frame)
  {
    delete(frame);
    this_->handle = NULL;
  }
}

// Defined at src\LeapFrame.kl:51:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::UInt64 LeapFrame_id(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return 0;
  return frame->t.id();
}

// Defined at src\LeapFrame.kl:61:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::UInt64 LeapFrame_timestamp(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return 0;
  return frame->t.timestamp();
}

// Defined at src\LeapFrame.kl:72:1
FABRIC_EXT_EXPORT void LeapFrame_hands(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::LeapHand > >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  Leap::HandList list = frame->t.hands();
  _result.resize(list.count());
  for(unsigned int i=0;i<list.count();i++)
  {
    _result[i] = KL::LeapHand::Create();
    _result[i]->handle = new Handle<Leap::Hand>(list[i]);
  }  
}

// Defined at src\LeapFrame.kl:94:1
FABRIC_EXT_EXPORT void LeapFrame_hand(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapHand >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam id
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  _result = KL::LeapHand::Create();
  _result->handle = new Handle<Leap::Hand>(frame->t.hand(id));
}

// Defined at src\LeapFrame.kl:107:1
FABRIC_EXT_EXPORT void LeapFrame_pointables(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::LeapPointable > >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  Leap::PointableList list = frame->t.pointables();
  _result.resize(list.count());
  for(unsigned int i=0;i<list.count();i++)
  {
    _result[i] = KL::LeapPointable::Create();
    _result[i]->handle = new Handle<Leap::Pointable>(list[i]);
  }  
}

// Defined at src\LeapFrame.kl:129:1
FABRIC_EXT_EXPORT void LeapFrame_pointable(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapPointable >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam id
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  _result = KL::LeapPointable::Create();
  _result->handle = new Handle<Leap::Pointable>(frame->t.pointable(id));
}

// Defined at src\LeapFrame.kl:142:1
FABRIC_EXT_EXPORT void LeapFrame_fingers(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::LeapFinger > >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  Leap::FingerList list = frame->t.fingers();
  _result.resize(list.count());
  for(unsigned int i=0;i<list.count();i++)
  {
    _result[i] = KL::LeapFinger::Create();
    _result[i]->handle = new Handle<Leap::Finger>(list[i]);
  }  
}

// Defined at src\LeapFrame.kl:164:1
FABRIC_EXT_EXPORT void LeapFrame_finger(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFinger >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam id
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  _result = KL::LeapFinger::Create();
  _result->handle = new Handle<Leap::Finger>(frame->t.finger(id));
}

// Defined at src\LeapFrame.kl:175:1
FABRIC_EXT_EXPORT void LeapFrame_tools(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::LeapTool > >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  Leap::ToolList list = frame->t.tools();
  _result.resize(list.count());
  for(unsigned int i=0;i<list.count();i++)
  {
    _result[i] = KL::LeapTool::Create();
    _result[i]->handle = new Handle<Leap::Tool>(list[i]);
  }  
}

// Defined at src\LeapFrame.kl:197:1
FABRIC_EXT_EXPORT void LeapFrame_tool(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapTool >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam id
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  _result = KL::LeapTool::Create();
  _result->handle = new Handle<Leap::Tool>(frame->t.tool(id));
}

// Defined at src\LeapFrame.kl:216:1
FABRIC_EXT_EXPORT void LeapFrame_gesture(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapGesture >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::SInt32 >::INParam id
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  _result = KL::LeapGesture::Create();
  _result->handle = new Handle<Leap::Gesture>(frame->t.gesture(id));
}

// Defined at src\LeapFrame.kl:229:1
FABRIC_EXT_EXPORT void LeapFrame_gestures(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::LeapGesture > >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  Leap::GestureList list = frame->t.gestures();
  _result.resize(list.count());
  for(unsigned int i=0;i<list.count();i++)
  {
    _result[i] = KL::LeapGesture::Create();
    _result[i]->handle = new Handle<Leap::Gesture>(list[i]);
  }  
}

// Defined at src\LeapFrame.kl:229:1
FABRIC_EXT_EXPORT void LeapFrame_gestures_sinceFrame(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::LeapGesture > >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  Handle<Leap::Frame>* cSinceFrame = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!cSinceFrame)
    return;
  Leap::GestureList list = frame->t.gestures(cSinceFrame->t);
  _result.resize(list.count());
  for(unsigned int i=0;i<list.count();i++)
  {
    _result[i] = KL::LeapGesture::Create();
    _result[i]->handle = new Handle<Leap::Gesture>(list[i]);
  }  
}

// Defined at src\LeapFrame.kl:252:1
FABRIC_EXT_EXPORT void LeapFrame_images(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::LeapImage > >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  Leap::ImageList list = frame->t.images();
  _result.resize(list.count());
  for(unsigned int i=0;i<list.count();i++)
  {
    _result[i] = KL::LeapImage::Create();
    _result[i]->handle = new Handle<Leap::Image>(list[i]);
  }  
}

// Defined at src\LeapFrame.kl:275:1
FABRIC_EXT_EXPORT void LeapFrame_translation(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return;
  Leap::Vector result = frame->t.translation(sinceFrame_->t);
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapFrame.kl:292:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapFrame_translationProbability(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return 0.0f;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return 0.0f;
  return frame->t.translationProbability(sinceFrame_->t);
}

// Defined at src\LeapFrame.kl:314:1
FABRIC_EXT_EXPORT void LeapFrame_rotationAxis(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return;
  Leap::Vector result = frame->t.rotationAxis(sinceFrame_->t);
  _result.x = result.x;
  _result.y = result.y;
  _result.z = result.z;
}

// Defined at src\LeapFrame.kl:338:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapFrame_rotationAngle(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return 0.0f;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return 0.0f;
  return frame->t.rotationAngle(sinceFrame_->t);
}

FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapFrame_rotationAngle_withAxis(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::INParam axis
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return 0.0f;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return 0.0f;
  Leap::Vector cAxis;
  cAxis.x = axis.x;
  cAxis.y = axis.y;
  cAxis.z = axis.z; 
  return frame->t.rotationAngle(sinceFrame_->t, cAxis);
}

// Defined at src\LeapFrame.kl:383:1
FABRIC_EXT_EXPORT void LeapFrame_rotationMatrix(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Mat44 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return;
  Leap::Matrix result = frame->t.rotationMatrix(sinceFrame_->t);
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

// Defined at src\LeapFrame.kl:400:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapFrame_rotationProbability(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return 0.0f;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return 0.0f;
  return frame->t.rotationProbability(sinceFrame_->t);
}

// Defined at src\LeapFrame.kl:425:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapFrame_scaleFactor(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return 0.0f;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return 0.0f;
  return frame->t.scaleFactor(sinceFrame_->t);
}

// Defined at src\LeapFrame.kl:442:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapFrame_scaleProbability(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam sinceFrame
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return 0.0f;
  Handle<Leap::Frame>* sinceFrame_ = (Handle<Leap::Frame>*)sinceFrame->handle;
  if(!sinceFrame)
    return 0.0f;
  return frame->t.scaleProbability(sinceFrame_->t);
}

// Defined at src\LeapFrame.kl:453:1
FABRIC_EXT_EXPORT void LeapFrame_interactionBox(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapInteractionBox >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  _result = KL::LeapInteractionBox::Create();
  _result->handle = new Handle<Leap::InteractionBox>(frame->t.interactionBox());
}

// Defined at src\LeapFrame.kl:468:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 LeapFrame_currentFramesPerSecond(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return 0.0f;
  return frame->t.currentFramesPerSecond();
}

// Defined at src\LeapFrame.kl:489:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean LeapFrame_isValid(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return false;
  return frame->t.isValid();
}

// Defined at src\LeapFrame.kl:499:1
FABRIC_EXT_EXPORT void LeapFrame_serialize(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::String >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  _result = frame->t.serialize().c_str();
}

// Defined at src\LeapFrame.kl:525:1
FABRIC_EXT_EXPORT void LeapFrame_deserialize(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::LeapFrame >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::String >::INParam str
) {
  Handle<Leap::Frame>* frame = (Handle<Leap::Frame>*)this_->handle;
  if(!frame)
    return;
  frame->t.deserialize(str.data());
}
