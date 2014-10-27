/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#ifndef __EXTENSION_H__
#define __EXTENSION_H__

template <typename K>
struct Handle {
  K t;

  Handle() {}
  Handle(K other) { t = other; }
};

#endif