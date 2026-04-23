// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class HOMEWORK8_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void ShowGameOver();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Widget")
	TSubclassOf<UUserWidget>GameOverWidgetClass;

	AMyPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	UInputAction* SprintAction;

	virtual void BeginPlay() override;
};
