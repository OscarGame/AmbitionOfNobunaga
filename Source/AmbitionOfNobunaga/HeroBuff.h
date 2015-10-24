// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "HeroBuff.generated.h"

/**
 * 
 */
UCLASS()
class AMBITIONOFNOBUNAGA_API UHeroBuff : public UObject
{
	GENERATED_BODY()
public:
	// Buff �u���v
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	int32 Priority;
	// �O�_�T���
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	bool BanMove;
	// �O�_�T�����
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	bool BanAttack;
	// �O�_�T��ϥΧޯ�
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	bool BanSkill;
	// �O�_�T��ϥιD��
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	bool BanEquipment;
	// �@�ޭ�
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	bool ShieldValue;
	// �O�_Ĳ�o�ˮ`���s�p��ƥ�
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	bool InjuredEvent;
	// ���z��X�ˮ`�[��
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	float PhysicalDamageOutputRatio;
	// �]�k��X�ˮ`�[��
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	float MagicDamageOutputRatio;
	// �ण��Q�k�N���w
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	bool CanBeSkillSight;
	// �ण��Q������w
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	bool CanBeAttackSight;

	// �O�_���|�[
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	bool CanSuperposition;
	// �|�[�h��
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	int32 Superposition;
	// �C�@�h����ɶ�
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	float Duration;

	// ���ʳt��
	UPROPERTY(Category = "HeroBuff", EditAnywhere, BlueprintReadOnly)
	float MoveRatio;
	
};
