// Fill out your copyright notice in the Description page of Project Settings.

#include "BigFloat.h"


// Sets default values for this component's properties
UBigFloat::UBigFloat()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

double UBigFloat::GetDouble() const
{
	return m_long_double;
}


// Called when the game starts
void UBigFloat::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBigFloat::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

