// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IK_Foot.generated.h"

typedef struct ST_IK_TraceInfo
{
	float fOffset;
	FVector pImpactLocation;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MVLIGHTING_API UIK_Foot : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UIK_Foot();

	class ADancerActor* owner;
	float m_fIKCapsuleHalkHeight = 83;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator m_pFootRotation_Left;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator m_pFootRotation_Right;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	ST_IK_TraceInfo IK_FootTrace(float fTraceDistance, FName sSocket);
	FRotator NormalToRotator(FVector pVector);
	void IK_Update_FootRotation(float fDeltaTime, FRotator pTargetValue, FRotator * pFootRotatorValue, float fInterpSpeed);

};

