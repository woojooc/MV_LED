#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BodyAnimInstance.generated.h"

UCLASS()
class MVLIGHTING_API UBodyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UBodyAnimInstance();

	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	class ADancerActor* owner;

};
