// Spyridon Zervos ©


#include "Player/GenesisPlayerControllerBase.h"

#include "EnhancedInputSubsystems.h"

void AGenesisPlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	/** Adding input mapping context */
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AGenesisPlayerControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	
}
