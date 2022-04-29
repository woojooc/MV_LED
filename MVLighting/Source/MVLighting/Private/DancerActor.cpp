
#include "DancerActor.h"

#include "Animation/AnimInstance.h"
#include "IK_Foot.h"

#include "Materials/MaterialParameterCollection.h"
#include "Materials/MaterialParameterCollectionInstance.h"

ADancerActor::ADancerActor()
{
	PrimaryActorTick.bCanEverTick = true;

	ik_foot_comp = CreateDefaultSubobject<UIK_Foot>("IK_Foot_Comp");
	/*
	ConstructorHelpers::FObjectFinder<UAnimSequence> B_MONTAGE(TEXT("AnimSequence'/Game/RetargetTest/Anim_High_Rhythm_Dance_01_Retargeted.Anim_High_Rhythm_Dance_01_Retargeted'"));
	if (B_MONTAGE.Succeeded())
	{
		basicSequence = B_MONTAGE.Object;
	}

	TArray<UActorComponent*> actComp = GetComponentsByTag(USkeletalMeshComponent::StaticClass(),FName("BodyComp"));
	if(actComp.Num())
	{
		// Animation Setting
		bodyMesh = Cast<USkeletalMeshComponent>(actComp[0]);

		//�ִϸ��̼� ��� ����
		bodyMesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);

		//�ִϸ��̼� �������Ʈ �������� Ŭ������ �������� ���̱� ������ �� �������� _C�� �ٿ�����
		static ConstructorHelpers::FClassFinder<UAnimInstance> Dance_Anim_C(
			TEXT("AnimBlueprint'/Game/RetargetTest/retargetAnimBP.retargetAnimBP_C'"));
		if (Dance_Anim_C.Succeeded())
		{
			//�ִϸ��̼� �������Ʈ�� ����
			bodyMesh->SetAnimInstanceClass(Dance_Anim_C.Class);
		}
	}
	//*/
}

void ADancerActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	/*
	if(bodyMesh)
	{
		//bodyMesh->PlayAnimation(basicSequence,true);
		animInst = bodyMesh->GetAnimInstance();
	}
	//*/
}

void ADancerActor::BeginPlay()
{
	Super::BeginPlay();


}

void ADancerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*
	if(bodyMesh->IsPlaying() == false)
	{
		//bodyMesh->bPauseAnims = false;
		bodyMesh->PlayAnimation(basicSequence,true);
		ResetTime();
		return;
	}
	//*/


	//curTime += DeltaTime;

	/*
	//curTime = animInst->Montage_GetPosition(animInst->GetCurrentActiveMontage());
	//FFrameRate rate = animInst->GetCurrentActiveMontage()->GetSamplingFrameRate();
	//curFrame = animInst->GetCurrentActiveMontage()->GetFrameAtTime(curTime);
	//animInst->
		//

	//curFrame = basicSequence->GetFrameAtTime(curTime);
	//*/

	if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::D))
	{

	}

	UMaterialParameterCollectionInstance *pInst = GetWorld()->GetParameterCollectionInstance(matParam);
	pInst->SetScalarParameterValue(FName("Time"), curTime);
}

void ADancerActor::ResetTime()
{
	curTime = 0;
}

void ADancerActor::AddTime(float dTime)
{
	curTime += dTime;
}

