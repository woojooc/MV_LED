// Fill out your copyright notice in the Description page of Project Settings.


#include "BodyAnimInstance.h"
#include "DancerActor.h"

UBodyAnimInstance::UBodyAnimInstance()
{


}

void UBodyAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	owner = Cast<ADancerActor>(GetOwningComponent()->GetOwner());
	if (owner)
	{
		owner->ResetTime();
	}
}

void UBodyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (owner)
	{
		owner->AddTime(DeltaSeconds);
	}

	//GetTime
}

