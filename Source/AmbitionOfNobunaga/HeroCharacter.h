// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "HeroCharacter.generated.h"

USTRUCT(BlueprintType)
struct FLevelCDs
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<float> CDs;

    float operator[](int32 n)
    {
        return CDs[n];
    }
};

USTRUCT(BlueprintType)
struct FSkillDescription
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> DescriptionLevel;

	FString& operator[](int32 n)
	{
		return DescriptionLevel[n];
	}
};

class AEquipment;

UCLASS()
class AMBITIONOFNOBUNAGA_API AHeroCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

public:

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called every frame
    virtual void Tick(float DeltaSeconds) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR
	bool Pickup(AEquipment* equ);

	UFUNCTION()
	void OnMouseClicked(UPrimitiveComponent* TouchComp);

	UFUNCTION(BlueprintCallable, Category = "Hero")
    void SelectionOn();

	UFUNCTION(BlueprintCallable, Category = "Hero")
    void SelectionOff();

	void CheckSelf(bool res, FString msg);

    UFUNCTION(BlueprintCallable, Category = "Hero")
    float GetSkillCDPercent(int32 n);

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly)
	UDecalComponent* SelectionDecal;

	// �^���W
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
    FString HeroName;

	// ���v����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
    FString HeroHistoryDescription;

	// �˳�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero", Replicated)
	TArray<AEquipment*> Equipments;

	// �j�Y�K
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
    UTexture2D * Head;

	// set by HUD
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	FVector2D	ScreenPosition;

	// �ӭ^�����ޯ�ƶq
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
    int32 Skill_Amount;

	//�ޯ�W�r
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
    TArray<FString> Skill_Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
    TArray<FSkillDescription> Skill_Description;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
    TArray<UTexture2D*> Skill_Texture;

	// �x�s�Ҧ��ޯ�C�ӵ��Ū�CD�ɶ�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
    TArray<FLevelCDs> Skill_LevelCDs;

	// �O�_�bCD��
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero")
    TArray<bool> Skill_CDing;

	// ��eCD��ơACD��Ƶ���Skill_MaxCD�ɴN�OCD����
    // Skill_CurrentCD will accumulation every frame
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero")
    TArray<float> Skill_CurrentCD;

	// ��e�ޯ�CD�ɶ�
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero")
    TArray<float> Skill_MaxCD;

	// ��e�Ҧ��ޯ��lCD�ɶ�
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero")
    TArray<float> Skill_BaseCD;

	// ��e�Ҧ����ޯ൥��
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero")
    TArray<int32> Skill_Level;

	// �i�H�ϥΪ��ޯ��I��
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero")
    int32 Skill_Points;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero")
	bool isSelection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float PickupObjectDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero", Replicated)
	AEquipment* WantPickup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero", Replicated)
	AEquipment* WantThrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero", Replicated)
	FVector ThrowDestination;
};
