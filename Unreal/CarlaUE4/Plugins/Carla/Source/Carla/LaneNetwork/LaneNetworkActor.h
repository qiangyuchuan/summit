#pragma once

#include "LaneNetwork.h"
#include "ProceduralMeshComponent.h"
#include "Map/RoadTriangle.h"
#include "Map/OccupancyGrid.h"
#include "aabb/AABB.h"

#include "LaneNetworkActor.generated.h"

UCLASS(hidecategories = (Physics))
class CARLA_API ALaneNetworkActor : public AActor
{
	GENERATED_BODY()

public: 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CARLA")
	UProceduralMeshComponent* MeshComponent;
  
  ALaneNetworkActor(const FObjectInitializer& ObjectInitializer);
		
  void SetLaneNetwork(const FString& LaneNetworkPath);

  FVector2D RandomVehicleSpawnPoint() const;

  FRoadMap GetRoadMap(const FBox2D Bounds, float Resolution) const;

private:

  FLaneNetwork LaneNetwork;
  TArray<long long> LaneIDs; // Lookup for random spawn points.

  UMaterial* MeshMaterial;

  TArray<FRoadTriangle> RoadTriangles;
  aabb::Tree RoadTrianglesTree;

  static FVector2D ToUE2D(const FVector2D& Position) { 
    return 100 * FVector2D(Position.Y, Position.X);
  }
  
  static FVector ToUE(const FVector2D& Position) { 
    return 100 * FVector(Position.Y, Position.X, 0);
  }
};
