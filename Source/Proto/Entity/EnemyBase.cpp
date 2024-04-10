// G-Spot Enterprises


#include "EnemyBase.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	// DOREPLIFETIME(AEnemyBase, GetHealth());
}

void AEnemyBase::OnHealthChange()
{
	UE_LOG(LogTemp, Log, TEXT("OnHealthChange called"));
}

void AEnemyBase::AddDamage(float Damage)
{
	if (HasAuthority())
	{
		Health -= Damage;
		OnHealthChange();
	}
}

void AEnemyBase::ServerAddDamage_Implementation(float Damage)
{
	if (GetLocalRole() == ROLE_Authority)
	{
		Health -= Damage;
		OnHealthChange();
	}
}

bool AEnemyBase::ServerAddDamage_Validate(float Damage)
{
	return true;
}
