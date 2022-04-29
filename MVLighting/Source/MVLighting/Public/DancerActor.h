// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DancerActor.generated.h"

UCLASS()
class MVLIGHTING_API ADancerActor : public AActor
{
	GENERATED_BODY()


public:
	ADancerActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float curTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int curFrame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialParameterCollection* matParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* bodyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UIK_Foot* ik_foot_comp;

	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAnimInstance* animInst;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAnimSequence* basicSequence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAnimBlueprint* animBP;
	//*/

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void ResetTime();
	UFUNCTION(BlueprintCallable)
		void AddTime(float dTime);

};
