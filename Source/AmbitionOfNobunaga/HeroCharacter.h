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
	
	// for UI
	UFUNCTION()
	void OnMouseClicked(UPrimitiveComponent* TouchComp);

	UFUNCTION(BlueprintCallable, Category = "Hero")
    void SelectionOn();

	UFUNCTION(BlueprintCallable, Category = "Hero")
    void SelectionOff();

	void CheckSelf(bool res, FString msg);

	// for Game Logic
    UFUNCTION(BlueprintCallable, Category = "Hero")
    float GetSkillCDPercent(int32 n);

	UFUNCTION(BlueprintCallable, Category = "Hero")
    float GetHPPercent();

	UFUNCTION(BlueprintCallable, Category = "Hero")
    float GetMPPercent();

	// �̵��ŧ�s���]��t
	UFUNCTION(BlueprintCallable, Category = "Hero")
    void UpdateHPMPAS();

	// �̵��ŧ�s�O�Ӵ�
	UFUNCTION(BlueprintCallable, Category = "Hero")
    void UpdateSAI();

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly)
	UDecalComponent* SelectionDecal;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly)
	UArrowComponent* PositionOnHead;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly)
	UArrowComponent* PositionUnderFoot;

	// �^���W
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
    FString HeroName;
	// ���ʳt��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	int32 TeamId;
	// ���v����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
    FString HeroHistoryDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	int32 CurrentLevel;
	// ���ʳt��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	float CurrentMoveSpeed;
	// ��q
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	float CurrentMaxHP;
	// �]�O
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	float CurrentMaxMP;
	// ��q
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero|Current", Replicated)
	float CurrentHP;
	// �]�O
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	float CurrentMP;
	// �^��
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	float CurrentHealingHP;
	// �^�]
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	float CurrentHealingMP;
	// ��t
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	float CurrentAttackSpeed;
	// �����O
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	float CurrentAttack;
	// ���m�O
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	float CurrentArmor;
	// �~�[�O�q
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	float AdditionStrength;
	// �~�[�ӱ�
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	float AdditionAgility;
	// �~�[���O
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	float AdditionIntelligence;
	// �ثe�����Z��
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hero|Current")
	float CurrentAttackRadius;

	// �������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float HPBarLength;

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

	// �ثe�����Z��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float BaseAttackRadius;
	// ��t�[��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float AdditionAttackSpeed;
	// ��¦��t
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float BaseAttackSpeed;
	// ��¦�]�k���˭��v
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float BaseMagicInjuredRatio;
	// ��¦���z���˭��v
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float BasePhysicsInjuredRatio;
	// ��¦�˥�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float BaseArmor;
	// ��¦�����O
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float BaseAttack;
	// ��¦���ʳt��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float BaseMoveSpeed;

	// ��¦�^��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float BaseHealingHP;
	// ��¦�^�]
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float BaseHealingMP;
	// ��¦��q
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float BaseHP;
	// ��¦�]�O
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float BaseMP;
	// ��¦�O�q
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float BaseStrength;
	// ��¦�ӱ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float BaseAgility;
	// ��¦���O
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float BaseIntelligence;

	// �O�q
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float Strength;
	// �ӱ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float Agility;
	// ���O
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	float Intelligence;
	
	// �C�ӵ��Ŵ��ɪ�XXX���֥[
	// �C�ӵ��Ŵ��ɪ������O
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hero")
	TArray<float> LevelProperty_Attack;
	// �C�ӵ��Ŵ��ɪ��O�q
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hero")
	TArray<float> LevelProperty_Strength;
	// �C�ӵ��Ŵ��ɪ��ӱ�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hero")
	TArray<float> LevelProperty_Agility;
	// �C�ӵ��Ŵ��ɪ����O
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hero")
	TArray<float> LevelProperty_Intelligence;

	// �ޯ�W�r
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hero")
    TArray<FString> Skill_Name;

	// �ޯ�y�z
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hero")
    TArray<FSkillDescription> Skill_Description;
    
	// �ޯ�Ϥ�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hero")
    TArray<UTexture2D*> Skill_Texture;

	// �x�s�Ҧ��ޯ�C�ӵ��Ū�CD�ɶ�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hero")
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero", Replicated)
	AHeroCharacter* WantAttack;
};
