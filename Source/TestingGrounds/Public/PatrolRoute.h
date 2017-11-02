// Copyright (C) 2017 JimmyTwoGuys.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"

/**
* A "Route Card" to help AI choose its next waypoint.
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TESTINGGROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:
	TArray<AActor*> GetPatrolPoints() const;

private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
		TArray<AActor*> PatrolPoints;

};