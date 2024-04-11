// G-Spot Enterprises


#include "SpawnerBase.h"

// Sets default values
ASpawnerBase::ASpawnerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnerBase::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnerBase::SpawnEntity, 5.0f, true);
}

// Called every frame
void ASpawnerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnerBase::SpawnEntity()
{
	if (!EnemyBlueprint)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to spawn entity: blueprint could not be found"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("SpawnEntity called"));

	FVector Origin = GetActorLocation();
	FVector SpawnPosition = FVector(
		Origin.X + FMath::RandRange(128.0, 256.0),
		Origin.Y + FMath::RandRange(128.0, 256.0),
		Origin.Z + 100.0 // Prevents stuck in floor breaking navmesh
	);

	GetWorld()->SpawnActor<ACharacter>(EnemyBlueprint, SpawnPosition, FRotator::ZeroRotator);
}

