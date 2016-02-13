// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "HeroAction.generated.h"

class AHeroCharacter;
class AEquipment;

UENUM(BlueprintType)
enum class EHeroActionStatus : uint8
{
	Default,			// ��Q��l��
	MoveToPosition,		// ���ʨ���w�ؼ�
	MoveToActor,		// ���ʨ���w���H����
	FollowActor,		// ��ۤH��
	AttackActor,		// �����w���H
	MovingAttack,		// �䲾�������
	MoveAndAttack,		// A�I�a�O ���ʤ��J��ĤH���U�ӧ���
	SpellToPosition,	// ���w�a�I���ޯ�
	SpellToActor,		// ���w��
	SpellToDirection,	// ���V��
	SpellToSelf,		// ���ݫ��w�ؼЪ��ޯ�
	MoveToPickup,		// �߸�
	MoveToThrowEqu		// ���
};

/**
 * 
 */
UCLASS()
class AMBITIONOFNOBUNAGA_API UHeroAction : public UObject
{
	GENERATED_BODY()
public:
	EHeroActionStatus ActionStatus;

	AHeroCharacter* TargetHero;
	AEquipment* TargetEquipment;
	FVector		TargetPosition;

};
