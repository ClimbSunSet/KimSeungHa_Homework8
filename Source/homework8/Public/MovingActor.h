// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class HOMEWORK8_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingActor();

	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "MoveDirection")
	FVector MoveDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "MoveSpeed")
	float MoveSpeed = 200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "MaxRange")
	float MaxRange;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
