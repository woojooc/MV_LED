// Fill out your copyright notice in the Description page of Project Settings.

#include "IK_Foot.h"

#include "DancerActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UIK_Foot::UIK_Foot()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UIK_Foot::BeginPlay()
{
	Super::BeginPlay();

	owner = Cast<ADancerActor>(GetOwner());
}

void UIK_Foot::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

}


// Called every frame
void UIK_Foot::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ST_IK_TraceInfo pTrace_Left = IK_FootTrace(55.0f, "foot_l");
	ST_IK_TraceInfo pTrace_Right = IK_FootTrace(55.0f, "foot_r");

	IK_Update_FootRotation(DeltaTime, NormalToRotator(pTrace_Left.pImpactLocation), &m_pFootRotation_Left, 13.0f);
	IK_Update_FootRotation(DeltaTime, NormalToRotator(pTrace_Left.pImpactLocation), &m_pFootRotation_Right, 13.0f);

}

ST_IK_TraceInfo UIK_Foot::IK_FootTrace(float fTraceDistance, FName sSocket)
{
	ST_IK_TraceInfo pTraceInfo;

	//! Set Linetraces startpoint and end point
	FVector pSocketLocation = owner->bodyMesh->GetSocketLocation(sSocket);
	FVector pLine_Start = FVector(pSocketLocation.X, pSocketLocation.Y, owner->GetActorLocation().Z);
	FVector pLine_End = FVector(pSocketLocation.X, pSocketLocation.Y
		, (owner->GetActorLocation().Z - m_fIKCapsuleHalkHeight) - fTraceDistance);

	//! Process Line Trace
	FHitResult pHitResult;
	TArray<AActor*> pIgnore;
	pIgnore.Add(GetOwner());

	bool bDebug = true;
	EDrawDebugTrace::Type eDebug = EDrawDebugTrace::None;
	if (bDebug == true) eDebug = EDrawDebugTrace::ForOneFrame;

	bool bResult = UKismetSystemLibrary::LineTraceSingle(GetWorld(), pLine_Start, pLine_End,
		UEngineTypes::ConvertToTraceType(ECC_Visibility), true, pIgnore, eDebug, pHitResult, true);

	//! Set ImpactNormal and Offset from HitResult
	pTraceInfo.pImpactLocation = pHitResult.ImpactNormal;
	if (pHitResult.IsValidBlockingHit() == true)
	{
		float fImpactLegth = (pHitResult.ImpactPoint - pHitResult.TraceEnd).Size();
		pTraceInfo.fOffset = 5.0f + (fImpactLegth - fTraceDistance);
	}
	else
	{
		pTraceInfo.fOffset = 0.0f;
	}

	return pTraceInfo;
}

FRotator UIK_Foot::NormalToRotator(FVector pVector)
{
	float fAtan2_1 = UKismetMathLibrary::DegAtan2(pVector.Y, pVector.Z);
	float fAtan2_2 = UKismetMathLibrary::DegAtan2(pVector.X, pVector.Z);
	fAtan2_2 *= -1.0f;
	FRotator pResult = FRotator(fAtan2_2, 0.0f, fAtan2_1);

	return pResult;
}

void UIK_Foot::IK_Update_FootRotation(float fDeltaTime, FRotator pTargetValue, FRotator * pFootRotatorValue, float fInterpSpeed)
{
	//! Set Foot Rotation value with FInterpTo
	FRotator pInterpRotator = UKismetMathLibrary::RInterpTo(*pFootRotatorValue, pTargetValue, fDeltaTime, fInterpSpeed);
	*pFootRotatorValue = pInterpRotator;
}
