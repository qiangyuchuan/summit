#pragma once

#include <string>
#include <vector>

#include "carla/geom/Vector2D.h"
#include "carla/geom/Vector3D.h"
#include "carla/occupancy/OccupancyMap.h"

namespace carla {
namespace landmark {

class LandmarkMap {
public:

  static LandmarkMap Load(const std::string& file, const geom::Vector2D& offset = geom::Vector2D(0, 0));

  std::vector<geom::Vector3D> GetMeshTriangles(float height) const;
  LandmarkMap Filter(const occupancy::OccupancyMap& occupancy_map) const; 

private:

  std::vector<std::vector<geom::Vector2D>> _landmarks;
};

}
}



