// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CPP_PlayerCharacter.h"
// Sets default values
ACPP_PlayerCharacter::ACPP_PlayerCharacter()
{
	// Event tick
	PrimaryActorTick.bCanEverTick = true;

	// Instantiate class components
	springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	// Set location and rotation of mesh
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -90.0f), FQuat(FRotator(0.0f, -90.0f, 0.0f)));

	// Attach components to skeletal mesh
	springArmComp->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	cameraComp->AttachToComponent(springArmComp, FAttachmentTransformRules::SnapToTargetNotIncludingScale, USpringArmComponent::SocketName);

	// Set defaults
	springArmComp->bUsePawnControlRotation = true;
	springArmComp->TargetArmLength = 85.0f;

	// Set class variables
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->bIgnoreBaseRotation = true;

	
}

// Called when the game starts or when spawned
void ACPP_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPP_PlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPP_PlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

}

void ACPP_PlayerCharacter::MoveForward(float inputAxis)
{
	if((Controller != nullptr) && (inputAxis != 0.0f))
	{
		// Find forward
		const FRotator rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, rotation.Yaw, 0);

		// Get Forward Vector
		const FVector direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// Add movement input
		AddMovementInput(direction, inputAxis);
	}
}

void ACPP_PlayerCharacter::MoveRight(float inputAxis)
{
	if ((Controller != nullptr) && (inputAxis != 0.0f))
	{
		// Find right
		const FRotator rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, rotation.Yaw, 0);

		// Get Right Vector
		const FVector direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// Add movement input
		AddMovementInput(direction, inputAxis);

	}
}

