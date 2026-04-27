// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FWaveData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int WaveClearItemValue;
	UPROPERTY()
	float WaveTimer;
};

class AMyPlayerController;

UCLASS()
class HOMEWORK8_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
	

private:
	int CurrentWave;
	int WaveMissionItemCount;
	float RemainingTime;
	int TakenItemCount;
	bool TimeOver = false;
	
public:
	AMyGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite,	category = "WaveDifficulty")
	TArray<FWaveData> WaveDatas; // 각 웨이브의 기본값을 저장할 구조체 배열

	void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void WaveStart();

	UFUNCTION(BlueprintCallable)
	void WaveEnd();

	UFUNCTION(BlueprintCallable)
	int GetCurrentWave();

	UFUNCTION(BlueprintCallable)
	int GetWaveMissionItemCount();

	UFUNCTION(BlueprintCallable)
	float GetRemainingTime();

	UFUNCTION(BlueprintCallable)
	int GetTakenItemCount();

	UFUNCTION(BlueprintCallable)
	void AddTakenItemCount();

	UFUNCTION(BlueprintCallable)
	void SetCurrentWave(int value);

	UFUNCTION(BlueprintCallable)
	void SetWaveMissionItemCount(int value);

	UFUNCTION(BlueprintCallable)
	void SetRemainingTime(float value);

	UFUNCTION(BlueprintCallable)
	void SetTakenItemCount(int value);

};
