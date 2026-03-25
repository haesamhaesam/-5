// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CMove(100.0f * DeltaTime);

	LogTimer += DeltaTime;
	if (LogTimer >= 1.0f)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green,
			FString::Printf(TEXT("MyActor Location: %s"), *GetActorLocation().ToString()));
		LogTimer = 0.0f;   //타이머 다시 0으로 초기화. 안 하면 1초 지났다고 생각해서 계속 로그띄움

		CTurn(-45.0f);
	}
}
// Called every frame





void AMyActor::CMove(float Distance)
{
	FVector NewLocation = GetActorLocation();
	NewLocation.X += Distance;
	SetActorLocation(NewLocation); 
}

void AMyActor::CTurn(float Angle)
{
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += Angle;
	SetActorRotation(NewRotation);
}