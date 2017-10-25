// Copyright (C) 2017 JimmyTwoGuys.  All Rights Reserved.

#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "PatrollingGuard.h"  //TODO remove coupling
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// TODO protect against empty Patrol Routes

	// Get the Patrol Points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingGaurd = Cast<APatrollingGuard>(ControlledPawn);
	auto PatrollPoints = PatrollingGaurd->PatrolPointsCPP;

	// Set Next Waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrollPoints[Index]);

	// Cycle the Index
	auto NextIndex = (Index + 1) % PatrollPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	//UE_LOG(LogTemp, Warning, TEXT("Waypoint Index:  %i donkey"));
	return EBTNodeResult::Succeeded;
}


