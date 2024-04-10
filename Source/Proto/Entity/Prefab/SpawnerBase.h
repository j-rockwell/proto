// G-Spot Enterprises

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "SpawnerBase.generated.h"

UCLASS()
class PROTO_API ASpawnerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnerBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SpawnEntity();

	UPROPERTY(EditAnywhere, Category = "Enemy Properties")
	TSubclassOf<ACharacter> EnemyBlueprint;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FTimerHandle SpawnTimerHandle;
};
