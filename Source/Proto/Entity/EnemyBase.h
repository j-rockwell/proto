// G-Spot Enterprises

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"

UCLASS()
class PROTO_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemyBase();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;	

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Properties", ReplicatedUsing = OnHealthChange)
	float Health;

	UFUNCTION(BlueprintCallable)
	void AddDamage(float Damage);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerAddDamage(float Damage);

protected:
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnHealthChange();
};

