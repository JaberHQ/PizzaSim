// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_PlayerCharacter.generated.h"

UCLASS()
class PIZZASIM_API ACPP_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_PlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USpringArmComponent* springArmComp; // Spring arm component 

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UCameraComponent* cameraComp; // Camera component
private:
	void MoveForward(float inputAxis);
	void MoveRight(float inputAxis);


};
