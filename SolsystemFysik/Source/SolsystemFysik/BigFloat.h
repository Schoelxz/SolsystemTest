// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BigFloat.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOLSYSTEMFYSIK_API UBigFloat : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBigFloat();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GetDoubleVar)
	//UFUNCTION(BlueprintCallable, Category = GetDoubleVar)
	double GetDouble() const;

private:
	double m_long_double;

		
	
};
