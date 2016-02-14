// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "HeroActionx.generated.h"


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
	MovingAttackActor,	// �䲾����������w�ĤH
	MoveAndAttack,		// A�I�a�O ���ʤ��J��ĤH���U�ӧ���
	SpellToPosition,	// ���w�a�I���ޯ�
	SpellToActor,		// ���w��
	SpellToDirection,	// ���V��
	SpellToSelf,		// ���ݫ��w�ؼЪ��ޯ�
	MoveToPickup,		// �߸�
	MoveToThrowEqu,		// ���
	ThrowEquToActor		// ��˵��H
};

/**
 *
 */
USTRUCT(BlueprintType)
struct FHeroAction
{
	GENERATED_USTRUCT_BODY()

	FHeroAction() :ActionStatus(EHeroActionStatus::Default), TargetHero(NULL), TargetEquipment(NULL),
		TargetValue(FVector::ZeroVector) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EHeroActionStatus ActionStatus;

	// for MoveToActor, FollowActor, AttackActor, MovingAttackActor, SpellToActor, ThrowEquToActor
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AHeroCharacter* TargetHero;

	// for MoveToPickup
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AEquipment* TargetEquipment;

	// for MoveToPosition, MoveAndAttack, SpellToPosition, SpellToDirection, MoveToThrowEqu
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector		TargetValue;

	bool operator==(const FHeroAction& rhs)
	{
		return rhs.ActionStatus == ActionStatus &&
			rhs.TargetHero == TargetHero &&
			rhs.TargetEquipment == TargetEquipment &&
			rhs.TargetValue == TargetValue;
	}
	bool operator!=(const FHeroAction& rhs)
	{
		return !(*this == rhs);
	}
};

UCLASS()
class UHeroActionx : public UObject
{
	GENERATED_BODY()

};
