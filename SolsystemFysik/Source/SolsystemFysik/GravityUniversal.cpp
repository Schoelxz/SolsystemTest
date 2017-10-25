// Fill out your copyright notice in the Description page of Project Settings.

#include "GravityUniversal.h"
#include "GameFramework/Actor.h"

TArray<UGravityUniversal*> UGravityUniversal::GravityUniversalCollection = TArray<UGravityUniversal*>();
const long double UGravityUniversal::SCALE_DOWN_FACTOR = (1);
const long double UGravityUniversal::GRAVITY_CONSTANT(1);

// Sets default values for this component's properties
UGravityUniversal::UGravityUniversal()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


}

// Called when the game starts
void UGravityUniversal::BeginPlay()
{
	Super::BeginPlay();

	GravityUniversalCollection.Add(this);

	m_star_mass = 1000;

}

void UGravityUniversal::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (GravityUniversalCollection.Num() > 0)
		GravityUniversalCollection.Empty();
}


// Called every frame
void UGravityUniversal::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<FVector> UGravityUniversal::CalcResult()
{
	FVector distance;
	long double force;
	TArray<FVector> result;
	for (int i = 0; i < GravityUniversalCollection.Num(); i++)
	{

		// For each GravityUniversalComponent, that isn't us
		if (GravityUniversalCollection[i] == this)
			continue;

		distance = CalcDistance(GravityUniversalCollection[i]->GetActorOwner()->GetActorLocation());

		//forceResult = DistanceSquared(i) * GetActorOwner()->GetActorLocation().Normalize();

		force = GRAVITY_CONSTANT *
			((CalcMass(GravityUniversalCollection[i]->GetStarMass())) /
			(pow(CalcDistance(GravityUniversalCollection[i]->GetActorOwner()->GetActorLocation()).Size(), 2)));

		result.Add(distance.GetSafeNormal() * force);
	}
	
	//Normalizes distance difference and multiplies it with force
	
	return result;
}

long double UGravityUniversal::DistanceSquared(int iteration) const
{
	return GRAVITY_CONSTANT * 
		((CalcMass(GravityUniversalCollection[iteration]->GetStarMass())) /
		(pow(CalcDistance(GravityUniversalCollection[iteration]->GetActorOwner()->GetActorLocation()).Size(), 2)));
}

long double UGravityUniversal::CalcMass(long double mass) const
{
	return m_star_mass * mass;
}

FVector UGravityUniversal::CalcDistance(FVector location) const
{
	return location - GetActorOwner()->GetActorLocation();
}

const long double UGravityUniversal::GetStarMass() const
{
	return m_star_mass;
}

const AActor * UGravityUniversal::GetActorOwner() const
{
	return GetOwner();
}
