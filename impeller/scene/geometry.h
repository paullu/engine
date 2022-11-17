// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <memory>

#include "impeller/geometry/vector.h"
#include "impeller/renderer/allocator.h"
#include "impeller/renderer/vertex_buffer.h"

namespace impeller {
namespace scene {

class CuboidGeometry;

class Geometry {
 public:
  static std::shared_ptr<CuboidGeometry> MakeCuboid(Vector3 size);

 private:
  virtual VertexBuffer GetVertexBuffer(
      std::shared_ptr<Allocator>& allocator) const = 0;
};

class CuboidGeometry final : public Geometry {
 public:
  void SetSize(Vector3 size);

 private:
  VertexBuffer GetVertexBuffer(
      std::shared_ptr<Allocator>& allocator) const override;

  Vector3 size_;
};

}  // namespace scene
}  // namespace impeller
