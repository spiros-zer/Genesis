// Spyridon Zervos ©

#pragma once

#include "CoreMinimal.h"
#include <GameFramework/PlayerController.h>
#include "GenesisPlayerControllerBase.generated.h"

class UInputMappingContext;
/**
 * The base player controller.
 */
UCLASS()
class GENESIS_API AGenesisPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

protected:

	virtual void BeginPlay() override;
	
	virtual void OnPossess(APawn* InPawn) override;
};
