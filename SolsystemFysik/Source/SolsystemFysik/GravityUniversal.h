// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GravityUniversal.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOLSYSTEMFYSIK_API UGravityUniversal : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGravityUniversal();
	//UGravityUniversal(float mass);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "UniversalMovement")
		TArray<FVector> CalcResult();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CalculateMass")
		float star_mass;

	///TODO: Create a static list. Do new stuff. Make blueprints slim again!

private:
	static const long double SCALE_DOWN_FACTOR;
	static const long double GRAVITY_CONSTANT;
	long double m_star_mass;
	static TArray<UGravityUniversal*> GravityUniversalCollection;

	//Takes "this" mass and multiplies it with inputed mass
	long double CalcMass(long double mass) const;
	FVector CalcDistance(FVector location) const;
	const long double GetStarMass() const;
	const AActor* GetActorOwner() const;
	long double DistanceSquared(int iteration) const;
		
	
};
