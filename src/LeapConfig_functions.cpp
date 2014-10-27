/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "LeapConfig_functions.h"
#include "extension.h"
#include <Leap.h>

using namespace Fabric::EDK;

// Defined at src\LeapConfig.kl:48:1
FABRIC_EXT_EXPORT void LeapConfig_Destruct(
  KL::Traits< KL::LeapConfig >::IOParam this_
) {
  Handle<Leap::Config>* config = (Handle<Leap::Config>*)this_->handle;
  if(config)
  {
    delete(config);
    this_->handle = NULL;
  }
}

// Defined at src\LeapConfig.kl:92:1
FABRIC_EXT_EXPORT KL::UInt32 LeapConfig_valueType(
  KL::Traits< KL::LeapConfig >::INParam this_,
  KL::Traits< KL::String >::INParam key
) {
  Handle<Leap::Config>* config = (Handle<Leap::Config>*)this_->handle;
  if(!config)
    return Leap::Config::TYPE_UNKNOWN;
  return (KL::UInt32)config->t.type(key.data());
}

// Defined at src\LeapConfig.kl:101:1
FABRIC_EXT_EXPORT KL::Boolean LeapConfig_getBool(
  KL::Traits< KL::LeapConfig >::INParam this_,
  KL::Traits< KL::String >::INParam key
) {
  Handle<Leap::Config>* config = (Handle<Leap::Config>*)this_->handle;
  if(!config)
    return false;
  return config->t.getBool(key.data());
}

// Defined at src\LeapConfig.kl:110:1
FABRIC_EXT_EXPORT KL::Boolean LeapConfig_setBool(
  KL::Traits< KL::LeapConfig >::INParam this_,
  KL::Traits< KL::String >::INParam key,
  KL::Traits< KL::Boolean >::INParam value
) {
  Handle<Leap::Config>* config = (Handle<Leap::Config>*)this_->handle;
  if(!config)
    return false;
  return config->t.setBool(key.data(), value);
}

// Defined at src\LeapConfig.kl:119:1
FABRIC_EXT_EXPORT KL::SInt32 LeapConfig_getInt32(
  KL::Traits< KL::LeapConfig >::INParam this_,
  KL::Traits< KL::String >::INParam key
) {
  Handle<Leap::Config>* config = (Handle<Leap::Config>*)this_->handle;
  if(!config)
    return 0;
  return config->t.getInt32(key.data());
}

// Defined at src\LeapConfig.kl:128:1
FABRIC_EXT_EXPORT KL::Boolean LeapConfig_setInt32(
  KL::Traits< KL::LeapConfig >::INParam this_,
  KL::Traits< KL::String >::INParam key,
  KL::Traits< KL::SInt32 >::INParam value
) {
  Handle<Leap::Config>* config = (Handle<Leap::Config>*)this_->handle;
  if(!config)
    return false;
  return config->t.setInt32(key.data(), value);
}

// Defined at src\LeapConfig.kl:137:1
FABRIC_EXT_EXPORT KL::Float32 LeapConfig_getFloat(
  KL::Traits< KL::LeapConfig >::INParam this_,
  KL::Traits< KL::String >::INParam key
) {
  Handle<Leap::Config>* config = (Handle<Leap::Config>*)this_->handle;
  if(!config)
    return 0.0f;
  return config->t.getFloat(key.data());
}

// Defined at src\LeapConfig.kl:146:1
FABRIC_EXT_EXPORT KL::Boolean LeapConfig_setFloat(
  KL::Traits< KL::LeapConfig >::INParam this_,
  KL::Traits< KL::String >::INParam key,
  KL::Traits< KL::Float32 >::INParam value
) {
  Handle<Leap::Config>* config = (Handle<Leap::Config>*)this_->handle;
  if(!config)
    return false;
  return config->t.setFloat(key.data(), value);
}

// Defined at src\LeapConfig.kl:155:1
FABRIC_EXT_EXPORT void LeapConfig_getString(
  KL::Traits< KL::String >::Result _result,
  KL::Traits< KL::LeapConfig >::INParam this_,
  KL::Traits< KL::String >::INParam key
) {
  Handle<Leap::Config>* config = (Handle<Leap::Config>*)this_->handle;
  if(!config)
    return;
  _result = config->t.getString(key.data()).c_str();
}

// Defined at src\LeapConfig.kl:164:1
FABRIC_EXT_EXPORT KL::Boolean LeapConfig_setString(
  KL::Traits< KL::LeapConfig >::INParam this_,
  KL::Traits< KL::String >::INParam key,
  KL::Traits< KL::String >::INParam value
) {
  Handle<Leap::Config>* config = (Handle<Leap::Config>*)this_->handle;
  if(!config)
    return false;
  return config->t.setString(key.data(), value.data());
}

// Defined at src\LeapConfig.kl:182:1
FABRIC_EXT_EXPORT KL::Boolean LeapConfig_save(
  KL::Traits< KL::LeapConfig >::INParam this_
) {
  Handle<Leap::Config>* config = (Handle<Leap::Config>*)this_->handle;
  if(!config)
    return false;
  return config->t.save();
}
