// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class PROJECT5_API AMyActor : public AActor
{
	GENERATED_BODY()

public:	
	
	AMyActor();
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void CMove(float Distance);
	void CTurn(float Angle);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	float LogTimer = 0.0f;


	// 지금 내가 무브 함수를 만들고 있는 건 알겠지? 이걸 사용해서 액터를 움직일거야. c++안에서 코드를 이용해서 저 무브함수를 실제로 사용하려면 어떻게 해야할지 알려줘.

};