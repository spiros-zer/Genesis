// Copyright Epic Games, Inc. All Rights Reserved.

#include "GenesisGameMode.h"
#include "GenesisCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGenesisGameMode::AGenesisGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
