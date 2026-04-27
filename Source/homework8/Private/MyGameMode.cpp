// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MyPlayerController.h"

AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = AMyPlayerController::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();

	PrimaryActorTick.bCanEverTick = true;

	CurrentWave = 0;
	TakenItemCount = 0;
	WaveMissionItemCount = 0;

	WaveDatas.SetNum(3);
	WaveDatas[0].WaveClearItemValue = 3;
	WaveDatas[1].WaveClearItemValue = 4;
	WaveDatas[2].WaveClearItemValue = 5;

	WaveDatas[0].WaveTimer = 240.0f;
	WaveDatas[1].WaveTimer = 230.0f;
	WaveDatas[2].WaveTimer = 220.0f;
}

void AMyGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RemainingTime -= DeltaTime;

	if (RemainingTime <= 0.0f && !TimeOver)
	{
		TimeOver = true;
		WaveEnd();
	}
}

void AMyGameMode::WaveStart()
{
	CurrentWave += 1;
	WaveMissionItemCount = WaveDatas[CurrentWave - 1].WaveClearItemValue;
	RemainingTime = WaveDatas[CurrentWave - 1].WaveTimer;
	TakenItemCount = 0;
	TimeOver = false;
}

void AMyGameMode::WaveEnd()
{
	if (RemainingTime <= 0.0f)
	{
		AMyPlayerController* PC = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
		if (PC)
		{
			PC->ShowGameOver();
		}
	}

	else
	{
		if (TakenItemCount >= WaveMissionItemCount)
		{
			if (CurrentWave >= 3)
			{
				UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
			}
			
			else
			{
				WaveStart();
			}
		}

		else
		{
			AMyPlayerController* PC = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
			if (PC)
			{
				PC->ShowGameOver();
			}
		}
	}
}

int AMyGameMode::GetCurrentWave()
{
	return CurrentWave;
}

int AMyGameMode::GetWaveMissionItemCount()
{
	return WaveMissionItemCount;
}

float AMyGameMode::GetRemainingTime()
{
	return RemainingTime;
}

int AMyGameMode::GetTakenItemCount()
{
	return TakenItemCount;
}

void AMyGameMode::AddTakenItemCount()
{
	TakenItemCount += 1;
}

void AMyGameMode::SetCurrentWave(int value)
{
	CurrentWave = value;

	return;
}

void AMyGameMode::SetWaveMissionItemCount(int value)
{
	WaveMissionItemCount = value;

	return;
}

void AMyGameMode::SetRemainingTime(float value)
{
	RemainingTime = value;

	return;
}

void AMyGameMode::SetTakenItemCount(int value) 
{
	TakenItemCount = value;

	return;
}
