// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameState.h"
#include "AONGameState.generated.h"


class AActor;
/**
 * 
 */
UCLASS()
class AMBITIONOFNOBUNAGA_API AAONGameState : public AGameState
{
	GENERATED_BODY()
public:

	UFUNCTION(Server, WithValidation, Reliable, BlueprintCallable, Category = "AONGameState")
	void SetObjectLocation(AActor* actor, FVector pos);
	
	// �C1�I�O�q�W�[��q
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AONGameState")
	float StrengthToHP;
	// �C1�I�O�q�W�[�^��/sec
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AONGameState")
	float StrengthToHealingHP;

	// �C1�I���O�W�[�]�O
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AONGameState")
	float IntelligenceToMP;
	// �C1�I���O�W�[�^�]/sec
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AONGameState")
	float IntelligenceToHealingMP;

	// �C1�I�ӱ��W�[���m
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AONGameState")
	float AgilityToDefense;
	// �C1�I�ӱ��W�[��t
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AONGameState")
	float AgilityToAttackSpeed;
	// �C1�I�ӱ��W�[�]�t
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AONGameState")
	float AgilityToWalkSpeed;

	UFUNCTION(BlueprintCallable, Category = "AONGameState")
	float ArmorConvertToInjuryPersent(float armor);
	
};
